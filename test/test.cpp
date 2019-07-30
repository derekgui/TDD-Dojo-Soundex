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

    ASSERT_THAT(soundex.encode("A"), Eq("A"));
}

TEST_F(SoundexEncoding, PaddingOtherLettersWithZero)
{
    auto encoded = soundex.encode("I");

    ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}