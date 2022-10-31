#include <stdexcept>
#include "LibraryCode.hpp"

Validator::Validator(int mLow, int mHigh): mLow{mLow}, mHigh{mHigh}
{
}

bool Validator::inRange(int valueToTest)
{
    return mLow <= valueToTest && valueToTest <= mHigh;
}