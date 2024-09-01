#include <iostream>
using namespace std;
#include <map>
#include <string>

char countAndFindMaxOccurrence(string& str) {
    // Declare a map to store the frequency of each character
    map<char, int> occurrenceMap;

    // Iterate over each character in the string
    for (char ch : str) {
        // Update the count in the map
        occurrenceMap[ch]++;
    }

    // Variable to store the character with the highest occurrence
    char maxChar = '\0';
    int maxCount = 0;

    // Find the character with the highest occurrence
    for (const auto pair : occurrenceMap) {
        if (pair.second > maxCount) {
            maxCount = pair.second;
            maxChar = pair.first;
        }
    }

    // Print the count of each character
    std::cout << "Character occurrences:\n";
    for (const auto& pair : occurrenceMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Return the character with the highest occurrence
    return maxChar;
}

int main() {
    string str = "NNSENWWN";
    char maxChar = countAndFindMaxOccurrence(str);
    std::cout << "Character with the highest occurrence: " << maxChar << std::endl;
    return 0;
}
