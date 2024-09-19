#include <gtest/gtest.h>
#include "StringCalculator.hpp"

// Test for empty input
TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
    int expectedResult = 0;
    std::string input = "";
    int result = addNumbers(input);

    ASSERT_EQ(result, expectedResult);
}

// Test for a single zero
TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
    int expectedResult = 0;
    std::string input = "0";
    int result = addNumbers(input);

    ASSERT_EQ(result, expectedResult);
}

// Test for the sum of two numbers
TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
    int expectedResult = 3;
    std::string input = "1,2";
    int result = addNumbers(input);

    ASSERT_EQ(result, expectedResult);
}

// Test for the sum with a custom delimiter
TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
    int expectedResult = 3;
    std::string input = "//;\n1;2";
    int result = addNumbers(input);

    ASSERT_EQ(result, expectedResult);
}

// Test for handling newline as a delimiter
TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
    int expectedResult = 6;
    std::string input = "1\n2,3";
    int result = addNumbers(input);

    ASSERT_EQ(result, expectedResult);
}

// Test for ignoring numbers greater than 1000
TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
    int expectedResult = 1;
    std::string input = "1,1001";
    int result = addNumbers(input);

    ASSERT_EQ(result, expectedResult);
}

// Test for exception with negative numbers
TEST(StringCalculatorAddTests, ExpectExceptionForNegativeNumbers) {
    std::string input = "-1,2";
    
    ASSERT_THROW({
        try {
            addNumbers(input);
        } catch (const std::invalid_argument& err) {
            EXPECT_EQ(std::string(err.what()), "negatives not allowed: -1");
            throw;
        }
    }, std::invalid_argument);
}
