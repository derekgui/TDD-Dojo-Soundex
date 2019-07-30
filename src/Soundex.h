#ifndef SOUNDEX_H
#define SOUNDEX_H
#include <string>

class Soundex
{
public:
    std::string encode(const std::string &word) const
    {
        return zeroPad(word);
    }

private:
    std::string zeroPad(const std::string &word) const
    {
        if (word.length() == 1)
            return word.substr(0, 1) + "000";
        else
        {
            if (word[1] == 'n')
                return word.substr(0, 1) + "500";
        }
    }
};

#endif