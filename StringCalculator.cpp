#include "StringCalculator.h"
#include <algorithm>
#include <stdexcept>

namespace StringProcessing {
    bool isNullOrEmpty(const std::string& numbers) {
        return numbers.empty();
    }

    char extractCustomDelimiter(std::string& numbers) {
        if (numbers.substr(0, DELIMITER_PREFIX_LENGTH) == "//") {
            char delimiter = numbers[DELIMITER_PREFIX_LENGTH];
            numbers = numbers.substr(DELIMITER_PREFIX_LENGTH + 2); // Skip the custom delimiter part
            return delimiter;
        }
        return ',';
    }

    void replaceNewlinesWithCommas(std::string& numbers) {
        std::replace(numbers.begin(), numbers.end(), '\n', ',');
    }

    void replaceDelimiterWithCommas(std::string& numbers, char delimiter) {
        std::replace(numbers.begin(), numbers.end(), delimiter, ',');
    }
}

namespace NumberManipulation {
    int stringToInt(const std::string& number) {
        return std::stoi(number);
    }

    bool shouldIgnoreLargeNumber(const std::string& number) {
        return stringToInt(number) > MAX_NUMBER;
    }

    void collectNegativeNumbers(const std::string& number, std::string& negatives) {
        if (!number.empty() && number[0] == '-') {
            if (!negatives.empty()) {
                negatives += ", ";
            }
            negatives += number;
        }
    }

    void findAndCollectNegativeNumbers(const std::string& numbers, std::string& negatives) {
        std::string currentNumber;
        for (char ch : numbers) {
            if (ch == ',') {
                collectNegativeNumbers(currentNumber, negatives);
                currentNumber.clear();
            } else {
                currentNumber += ch;
            }
        }
        collectNegativeNumbers(currentNumber, negatives);
    }

    int addValidNumberToSum(int sum, const std::string& number) {
        if (!number.empty() && !shouldIgnoreLargeNumber(number)) {
            sum += stringToInt(number);
        }
        return sum;
    }

    int calculateSumFromNumbers(const std::string& numbers) {
        int sum = 0;
        std::string currentNumber;
        for (char ch : numbers) {
            if (ch == ',') {
                sum = addValidNumberToSum(sum, currentNumber);
                currentNumber.clear();
            } else {
                currentNumber += ch;
            }
        }
        return addValidNumberToSum(sum, currentNumber);
    }
}

int addNumbers(const std::string& numbers) {
    if (StringProcessing::isNullOrEmpty(numbers)) {
        return 0;
    }

    std::string processedNumbers = numbers;
    char delimiter = StringProcessing::extractCustomDelimiter(processedNumbers);
    StringProcessing::replaceNewlinesWithCommas(processedNumbers);
    StringProcessing::replaceDelimiterWithCommas(processedNumbers, delimiter);

    std::string negatives;
    NumberManipulation::findAndCollectNegativeNumbers(processedNumbers, negatives);
    if (!negatives.empty()) {
        throw std::invalid_argument("negatives not allowed: " + negatives);
    }

    return NumberManipulation::calculateSumFromNumbers(processedNumbers);
}

