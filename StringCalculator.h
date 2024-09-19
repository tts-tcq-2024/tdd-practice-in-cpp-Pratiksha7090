#ifndef STRING_CALCULATOR_HPP
#define STRING_CALCULATOR_HPP

#include <string>

namespace StringProcessing {
    const int DELIMITER_PREFIX_LENGTH = 2; 
    bool isNullOrEmpty(const std::string& numbers);
    char extractCustomDelimiter(std::string& numbers);
    void replaceNewlinesWithCommas(std::string& numbers);
    void replaceDelimiterWithCommas(std::string& numbers, char delimiter);
}

namespace NumberManipulation {
    const int MAX_NUMBER = 1000; 
    int stringToInt(const std::string& number);
    bool shouldIgnoreLargeNumber(const std::string& number);
    void collectNegativeNumbers(const std::string& number, std::string& negatives);
    void findAndCollectNegativeNumbers(const std::string& numbers, std::string& negatives);
    int addValidNumberToSum(int sum, const std::string& number);
    int calculateSumFromNumbers(const std::string& numbers);
}
int addNumbers(const std::string& numbers);

#endif // STRING_CALCULATOR_HPP

