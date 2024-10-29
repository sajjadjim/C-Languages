#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charMap;  // Stores the latest index of each character
    int maxLength = 0;
    int start = 0; // Start of the current substring window

    for (int end = 0; end < s.size(); end++) {
        char currentChar = s[end];

        // If the character is found in the map and is within the current window
        if (charMap.find(currentChar) != charMap.end() && charMap[currentChar] >= start) {
            start = charMap[currentChar] + 1; // Move start to the right of duplicate character
        }

        charMap[currentChar] = end; // Update or add character's latest position
        maxLength = max(maxLength, end - start + 1); // Update maximum length if current window is longer
    }

    return maxLength;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int result = lengthOfLongestSubstring(s);
    cout << "The length of the longest substring without repeating characters is: " << result << endl;

    return 0;
}
