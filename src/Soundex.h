#ifndef SOUNDEX_H
#define SOUNDEX_H
#include <string>
#include <unordered_map>

class Soundex
{
public:
    std::string encode(const std::string &word) const
    {
        return zeroPad(word);
    }

private:
    const std::unordered_map<char, std::string> encode_map{
        {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"}, {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"}, {'d', "3"}, {'t', "3"}, {'l', "4"}, {'m', "5"}, {'n', "5"}, {'r', "6"}};
    std::string zeroPad(const std::string &word) const
    {

        if (word.length() == 1)
            return head(word) + "000";

        char key = word[1];
        auto it = encode_map.find(key);

        if (it != encode_map.end())
            return head(word) + it->second + "00";

        return "";
    }

    std::string head(const std::string &word) const
    {
        return word.substr(0, 1);
    }
};

#endif