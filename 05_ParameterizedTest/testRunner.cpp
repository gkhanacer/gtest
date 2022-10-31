#include <gtest/gtest.h>
// #include <gmock/gmock.h>
#include "LibraryCode.hpp"

using testing::Values;

// Validator (5, 10)
// 4, 5, 7, 10, 11 => five test cases
// Generate them

class ValidatorFixture: public testing::TestWithParam<std::tuple<int, bool>>
{
public:
protected:
    Validator mValidator{5, 10};
};

TEST_P(ValidatorFixture, TestInRange)
{
    std::tuple<int, bool> tuple = GetParam();
    int param = std::get<0>(tuple);
    bool expectedValue = std::get<1>(tuple);

    std::cout << "Param = " << param << " Expected value = " << expectedValue << '\n';
    bool isInside = mValidator.inRange(param);
    ASSERT_EQ(isInside, expectedValue);
}

INSTANTIATE_TEST_CASE_P(InRangeTrue, ValidatorFixture, Values(
                                                        std::make_tuple(-100, false),
                                                        std::make_tuple(-4, false),
                                                        std::make_tuple(5, true),
                                                        std::make_tuple(6, true),
                                                        std::make_tuple(7, true),
                                                        std::make_tuple(8, true),
                                                        std::make_tuple(9, true),
                                                        std::make_tuple(10, true),
                                                        std::make_tuple(11, false),
                                                        std::make_tuple(11111, false)
                                                        )
);

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
