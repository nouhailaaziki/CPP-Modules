#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
    *this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        this->_database = other._database;
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{}

// Helper to remove leading/trailing spaces
std::string BitcoinExchange::_trim(const std::string& str) const
{
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == std::string::npos)
        return ("");
    size_t last = str.find_last_not_of(" \t\r\n");
    return (str.substr(first, (last - first + 1)));
}

bool BitcoinExchange::_isValidDate(const std::string& date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return (false);

    std::stringstream ss(date);
    int year, month, day;
    char dash1, dash2;

    if (!(ss >> year >> dash1 >> month >> dash2 >> day)
        || dash1 != '-' || dash2 != '-' || !ss.eof())
        return (false);

    if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
        return (false);

    // Handle short months
    if (month == 4 || month == 6 || month == 9 || month == 11)
        if (day > 30)
            return (false);

    // Handle February leap years
    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeap && day > 29)
            return (false);
        if (!isLeap && day > 28)
            return (false);
    }

    return (true);
}

bool BitcoinExchange::_isValidValue(const std::string& valueStr, double& value) const
{
    if (valueStr.empty())
    {
        std::cout << "Error: bad input => " << valueStr << "\n";
        return (false);
    }

    char* endptr;
    value = std::strtod(valueStr.c_str(), &endptr);
    
    // Check if no conversion could be performed or leftover characters exist
    if (endptr == valueStr.c_str() || *endptr != '\0')
    {
        std::cout << "Error: bad input => " << valueStr << "\n";
        return (false);
    }
    if (value < 0)
    {
        std::cout << "Error: not a positive number.\n";
        return (false);
    }
    if (value > 1000)
    {
        std::cout << "Error: too large a number.\n";
        return (false);
    }
    return (true);
}

bool BitcoinExchange::loadDatabase(const std::string& dbPath)
{
    std::ifstream file(dbPath.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: could not open database file: " << dbPath << "\n";
        return (false);
    }

    std::string line;
    if (!std::getline(file, line))
        return (false);

    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, rateStr;
        if (std::getline(ss, date, ',') && std::getline(ss, rateStr))
        {
            rateStr = _trim(rateStr); // this to strip '\r'
            char *end;
            double rate = std::strtod(rateStr.c_str(), &end);

            if (*end != '\0')
                continue;

            if (_isValidDate(date))
                _database[date] = rate;
        }
    }
    file.close();
    return (true);
}

void BitcoinExchange::processInput(const std::string& inputPath)
{
    std::ifstream file(inputPath.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: could not open file.\n";
        return ;
    }

    if (_database.empty())
    {
        std::cout << "Error: database is empty.\n";
        return ;
    }

    std::string line;
    if (!std::getline(file, line) || _trim(line) != "date | value")
    {
        std::cout << "Error: invalid file header format.\n";
        return ;
    }

    while (std::getline(file, line))
    {
        if (_trim(line).empty())
            continue;

        size_t delimiterPos = line.find('|');
        if (delimiterPos == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << "\n";
            continue;
        }

        std::string date = _trim(line.substr(0, delimiterPos));
        std::string valueStr = _trim(line.substr(delimiterPos + 1));

        if (!_isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << "\n";
            continue;
        }

        double value;
        if (!_isValidValue(valueStr, value))
            continue;

        std::map<std::string, double>::const_iterator it = _database.lower_bound(date);

        if (it == _database.end())
            --it;
        else if (it->first != date)
        {
            if (it != _database.begin())
                --it;
            else
            {
                std::cout << "Error: bad input => " << date << std::endl;
                continue;
            }
        }

        double result = value * it->second;
        std::cout << date << " => " << value << " = " << result << "\n";
    }
    file.close();
}