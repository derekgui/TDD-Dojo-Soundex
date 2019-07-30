#ifndef SOUNDEX_H
#define SOUNDEX_H
#include <string>
#include <unordered_map>

class Soundex
{
public:
    std::string encode(const std::string &word) const
    {
        return zeroPad(head(word) + encodedDigits(tail(word)));
    }

private:
    static const size_t MAX_LETTERS{4};

    const std::unordered_map<char, std::string> encode_map{{'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"}, {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"}, {'d', "3"}, {'t', "3"}, {'l', "4"}, {'m', "5"}, {'n', "5"}, {'r', "6"}};

    std::string zeroPad(const std::string &word) const
    {
        auto zerosNeeded = MAX_LETTERS - word.length();

        return word + std::string(zerosNeeded, '0');
    }

    std::string head(const std::string &word) const
    {
        return word.substr(0, 1);
    }

    std::string tail(const std::string &word) const
    {
        return word.substr(1, 3);
    }

    bool isLetterFound(const char letter) const
    {
        return encode_map.find(letter) != encode_map.end();
    }

    std::string encodedDigit(const char letter) const
    {
        return isLetterFound(letter) ? encode_map.find(letter)->second : "0";
    }

    std::string encodedDigits(const std::string &word) const
    {
        std::string result;

        for (auto letter : word)
        {
            if (isComplete(result))
                break;
            result += encodedDigit(letter);
        }

        return result;
    }

    bool isComplete(const std::string &result) const
    {
        return result.length() == MAX_LETTERS - 1;
    }
};

#endif