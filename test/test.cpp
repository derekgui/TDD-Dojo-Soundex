#include "gmock/gmock.h"
#include "Soundex.h"

using ::testing::Eq;

class SoundexEncoding : public ::testing::Test
{
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, TestOneLetterInSigleLtterWord)
{
    auto encoded = soundex.encode("A");

    ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PaddingOtherLettersWithZero)
{
    auto encoded = soundex.encode("I");

    ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplaceConsonantsWithCorrespondDigits)
{
    EXPECT_THAT(soundex.encode("An"), Eq("A500"));
    EXPECT_THAT(soundex.encode("Ab"), Eq("A100"));
    EXPECT_THAT(soundex.encode("Ac"), Eq("A200"));
}

TEST_F(SoundexEncoding, MultipleLettersInSingleWord)
{
    auto encoded = soundex.encode("Abcd");

    ASSERT_THAT(encoded, Eq("A123"));
}

TEST_F(SoundexEncoding, NotALetter)
{
    auto encoded = soundex.encode("A#");

    ASSERT_THAT(encoded, Eq("A000"));
}

TEST_F(SoundexEncoding, MoreThanFourLettersWord)
{
    auto encoded = soundex.encode("Abcdl");

    ASSERT_THAT(encoded.length(), Eq(4u));
}

TEST_F(SoundexEncoding, DropVowelLetters)
{
    auto encoded = soundex.encode("Aaeiouyhwbcd");

    ASSERT_THAT(encoded, Eq("A123"));
}

TEST_F(SoundexEncoding, CombineDuplicateDigits)
{
    auto encoded = soundex.encode("Abfcgdt");

    ASSERT_THAT(encoded, Eq("A123"));
}