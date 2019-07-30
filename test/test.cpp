#include "gmock/gmock.h"
#include "Soundex.h"

TEST(SoundexEncoding, TestOneLetterInSigleLtterWord)
{
    Soundex soundex;

    ASSERT_THAT(soundex.encode("A"), testing::Eq("A"));
    ASSERT_THAT(soundex.encode("I"), testing::Eq("I"));
}