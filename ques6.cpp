/*Find the length of the longest substring without repeating characters. Write its 
algorithm, program. Find its time and space complexities. Explain with suitable 
example.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    vector<int> idx(255, -1);
    int maxlen = 0;
    int start = 0;

    for(int end=0; end<n; end++){
        if(idx[s[end]] >= start){
            start = idx[s[end]]+1;
        }
        idx[s[end]] = end;
        maxlen = max(maxlen, end-start+1);
    }
    return maxlen;
}

int main() {
    string s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);

    cout << "Length of longest substring without repeating characters: " << result << endl;
    return 0;
}