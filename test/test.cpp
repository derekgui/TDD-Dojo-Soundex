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

    ASSERT_THAT(encoded, Eq("A000"));
}

TEST_F(SoundexEncoding, PaddingOtherLettersWithZero)
{
    auto encoded = soundex.encode("I");

    ASSERT_THAT(encoded, Eq("I000"));
}

TEST_F(SoundexEncoding, TestTwoletterWord)
{
    auto encoded = soundex.encode("An");

    ASSERT_THAT(encoded, Eq("A500"));
}