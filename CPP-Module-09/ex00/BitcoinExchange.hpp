#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>
#include <string>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _database;

        std::string _trim(const std::string &str) const;
        bool _isValidDate(const std::string &date) const;
        bool _isValidValue(const std::string &valueStr, double &value) const;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        bool loadDatabase(const std::string &dbPath);
        void processInput(const std::string &inputPath);
};

#endif