#ifndef SOUNDEX_H
#define SOUNDEX_H
#include <string>
#include <unordered_map>

class Soundex
{
public:
    std::string encode(const std::string &word) const
    {
        return zeroPad(upperFont(head(word)) + tail(encodedDigits(word)));
    }

    std::string encodedDigit(const char letter) const
    {
        auto it = encode_map.find(std::tolower(letter));

        return it == encode_map.end() ? NotADigit : it->second;
    }

private:
    static const size_t MAX_LETTERS{4};

    const std::string NotADigit{"*"};

    const std::unordered_map<char, std::string> encode_map{{'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"}, {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"}, {'d', "3"}, {'t', "3"}, {'l', "4"}, {'m', "5"}, {'n', "5"}, {'r', "6"}};

    std::string zeroPad(const std::string &word) const
    {
        auto zerosNeeded = MAX_LETTERS - word.length();

        return word + std::string(zerosNeeded, '0');
    }

    std::string upperFont(const std::string &word) const
    {
        return std::string(1, std::toupper(static_cast<unsigned char>(word.front())));
    }

    std::string head(const std::string &word) const
    {
        return word.substr(0, 1);
    }

    std::string tail(const std::string &word) const
    {
        return word.substr(1);
    }

    std::string encodedDigits(const std::string &word) const
    {
        std::string encoding;
        encodeHead(encoding, word);
        encodeTail(encoding, word);

        return encoding;
    }

    void encodeHead(std::string &encoding, const std::string &word) const
    {
        encoding = encodedDigit(word.front());
    }

    void encodeTail(std::string &encoding, const std::string &word) const
    {
        for (size_t i = 1; i < word.length(); i++)
        {
            if (!isComplete(encoding))
                encodeLetter(encoding, word[i], word[i - 1]);
        }
    }

    void encodeLetter(std::string &encoding, char currentLetter, char lastLetter) const
    {
        auto digit = encodedDigit(currentLetter);
        if (digit != NotADigit && ((digit != lastDigit(encoding)) || isVowel(lastLetter)))
            encoding += digit;
    }

    bool isVowel(const char letter) const
    {

        std::string vowel{"aeiouy"};

        return vowel.find(letter) != std::string::npos;
    }

    std::string lastDigit(const std::string &result) const
    {
        if (result.empty())
            return "";

        return std::string(1, result.back());
    }

    bool isComplete(const std::string &result) const
    {
        return result.length() == MAX_LETTERS;
    }
};

#endif