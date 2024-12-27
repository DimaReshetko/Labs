#include <iostream>
#include <string>
#include <vector>

std::vector<int> buildBadCharTable(const std::string& pattern) {
    int patternLength = pattern.length();
    std::vector<int> mas(256, patternLength);

    for (int i = 0; i < patternLength - 1; i++) {
        *(mas.data() + static_cast<unsigned char>(pattern[i])) = patternLength - 1 - i;
    }

    return mas;
}


int boyerMooreSearch(const std::string& text, const std::string& pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();

    if (patternLength == 0) {
        return 0; 
    }

    std::vector<int> badCharTable = buildBadCharTable(pattern);

    int shift = 0;
    while (shift <= textLength - patternLength) {
        int j = patternLength - 1;

        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            return shift; 
        }
        else {

            char badChar = text[shift + patternLength - 1];
            shift += std::max(1, badCharTable[static_cast<unsigned char>(badChar)]);
        }
    }

    return -1; 
}

int main() {
    std::string text = "ABAAABCD";
    std::string pattern = "ABC";

    int index = boyerMooreSearch(text, pattern);

    if (index != -1) {
        std::cout << "Substring found at position: " << index << std::endl;
    }
    else {
        std::cout << "Substring not found." << std::endl;
    }

    return 0;
}