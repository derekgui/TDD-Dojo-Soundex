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
    EXPECT_THAT(soundex.encode("Ab"), Eq("A100"));
}