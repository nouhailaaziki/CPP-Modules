#ifndef REPLACER_HPP
# define REPLACER_HPP

# include <string>

class Replacer {
    private:
        std::string s1;
        std::string s2;
        std::string in_filename;
        std::string out_filename;
    public:
        Replacer(char *arg1, char *arg2, char *arg3);
        
        const std::string&  getS1(void) const;
        const std::string&  getS2(void) const;
        const std::string&  getInFilename(void) const;  
        const std::string&  getOutFilename(void) const;
        
        bool    replaceFileContent() const;
};

#endif