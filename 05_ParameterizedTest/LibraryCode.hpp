#pragma once

class Validator
{
private:
    /* data */
    int mLow, mHigh;
public:
    Validator(int mLow, int mHigh);
    bool inRange(int valueToTest);
};

