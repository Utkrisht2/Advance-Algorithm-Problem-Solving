/*Find the longest palindromic substring in a given string. Write its algorithm, program. 
Find its time and space complexities. Explain with suitable example. */

#include <iostream>
#include <string>
using namespace std;

string expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
    }
    return s.substr(left + 1, right - left - 1); // substring between the valid bounds
}

string longestPalindromicSubstring(const string& s) {
    if (s.empty()) return "";

    string longest = "";
    
    for (int i = 0; i < s.length(); ++i) {
        string odd = expandAroundCenter(s, i, i);
        string even = expandAroundCenter(s, i, i + 1);

        if (odd.length() > longest.length()) longest = odd;
        if (even.length() > longest.length()) longest = even;
    }

    return longest;
}

int main() {
    string s = "babad";
    string result = longestPalindromicSubstring(s);
    cout << "Longest Palindromic Substring: " << result << endl;
    return 0;
}
