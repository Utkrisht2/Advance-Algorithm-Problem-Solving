/*Find the longest common prefix among a list of strings. Write its algorithm, program. 
Find its time and space complexities. Explain with suitable example. */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(const vector<string>& strs) {
    if (strs.empty()) return "";

    for (int i = 0; i < strs[0].size(); ++i) {
        char c = strs[0][i];
        for (int j = 1; j < strs.size(); ++j) {
            // If i >= current string's length OR mismatch occurs
            if (i >= strs[j].size() || strs[j][i] != c) {
                return strs[0].substr(0, i);
            }
        }
    }

    return strs[0]; // All characters matched
}

int main() {
    vector<string> words = {"flower", "flow", "flight"};
    string result = longestCommonPrefix(words);
    cout << "Longest Common Prefix: " << result << endl;
    return 0;
}
