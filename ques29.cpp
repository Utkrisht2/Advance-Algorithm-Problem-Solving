/*Write a program to check if an integer is a palindrome without converting it to a string. 
Write its algorithm, program. Find its time and space complexities. Explain with 
suitable example. */

#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0))
        return false;

    int reversedHalf = 0;
    while (x > reversedHalf) {
        reversedHalf = reversedHalf * 10 + x % 10;
        x /= 10;
    }

    // For even-length: x == reversedHalf
    // For odd-length: x == reversedHalf / 10 (middle digit can be ignored)
    return x == reversedHalf || x == reversedHalf / 10;
}

int main() {
    int num = 1221;
    if (isPalindrome(num))
        cout << num << " is a palindrome." << endl;
    else
        cout << num << " is not a palindrome." << endl;
    return 0;
}
