/* Generate all permutations of a given string. Write its algorithm, program. Find its time 
and space complexities. Explain with suitable example. */

#include <iostream>
#include <string>
using namespace std;

void generatePermutations(string& s, int index) {
    if (index == s.size()) {
        cout << s << endl;
        return;
    }

    for (int i = index; i < s.size(); ++i) {
        swap(s[index], s[i]);                     // Fix the i-th character
        generatePermutations(s, index + 1);       // Recurse
        swap(s[index], s[i]);                     // Backtrack
    }
}

int main() {
    string s = "abc";
    cout << "All permutations of \"" << s << "\":" << endl;
    generatePermutations(s, 0);
    return 0;
}