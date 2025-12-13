#include <iostream>
#include <string>
#include "StringUtils.h"

using namespace std;
using namespace strutils;

int main() {
    cout << "=== Recursive String Tools ===\n\n";

    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    char ch;
    cout << "Enter a character to count: ";
    cin >> ch;
    cin.ignore(); // очистка \n после cin

    cout << "Number of '" << ch << "' occurrences: "
        << countChar(input, ch) << endl;

    cout << "Is \"" << input << "\" a palindrome? "
        << (isPalindrome(input) ? "Yes" : "No") << endl;

    cout << "Reversed string: " << reverseString(input) << endl;

    cout << "\nEnter a string to check for palindrome: ";
    getline(cin, input);
    cout << "Is \"" << input << "\" a palindrome? "
        << (isPalindrome(input) ? "Yes" : "No") << endl;

    string text, sub;
    cout << "\nEnter text to search in: ";
    getline(cin, text);
    cout << "Enter substring to find: ";
    getline(cin, sub);

    if (sub.empty()) {
        cout << "Error: substring cannot be empty!\n";
        return 1;
    }

    int pos = findSubstring(text, sub);
    if (pos != -1) {
        cout << "Substring \"" << sub << "\" found at position: " << pos << endl;
    }
    else {
        cout << "Substring \"" << sub << "\" not found\n";
    }

    return 0;
}