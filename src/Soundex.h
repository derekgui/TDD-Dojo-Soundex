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
    std::string zeroPad(const std::string &word) const
    {
        auto zeros = 4 - word.length();

        return head(word) + encodedDigits(tail(word)) + std::string(zeros, '0');
    }

    std::string head(const std::string &word) const
    {
        return word.substr(0, 1);
    }

    std::string tail(const std::string &word) const
    {
        return word.substr(1, 3);
    }

    std::string encodedDigit(const char letter) const
    {
        const std::unordered_map<char, std::string> encode_map{{'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"}, {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"}, {'d', "3"}, {'t', "3"}, {'l', "4"}, {'m', "5"}, {'n', "5"}, {'r', "6"}};

        auto it = encode_map.find(letter);
        return (it != encode_map.end()) ? it->second : "0";
    }

    std::string encodedDigits(const std::string &word) const
    {
        std::string result;

        if (word.length() > 0)
        {
            for (auto letter : word)
                result += encodedDigit(letter);
            return result;
        }

        return "";
    }
};

#endif