/* Implement two stacks in a single array. Write its algorithm, program. Find its time and 
space complexities. Explain with suitable example. */

#include <iostream>
using namespace std;

class TwoStacks {
    int* arr;
    int size;
    int top1, top2;

public:
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    void push1(int x) {
        if (top1 < top2 - 1) {
            arr[++top1] = x;
        } else {
            cout << "Stack Overflow in Stack 1\n";
        }
    }

    void push2(int x) {
        if (top1 < top2 - 1) {
            arr[--top2] = x;
        } else {
            cout << "Stack Overflow in Stack 2\n";
        }
    }

    int pop1() {
        if (top1 >= 0)
            return arr[top1--];
        else {
            cout << "Stack Underflow in Stack 1\n";
            return -1;
        }
    }

    int pop2() {
        if (top2 < size)
            return arr[top2++];
        else {
            cout << "Stack Underflow in Stack 2\n";
            return -1;
        }
    }
};

int main() {
    TwoStacks ts(10);
    ts.push1(5);
    ts.push2(10);
    ts.push1(15);
    ts.push2(20);

    cout << "Popped from Stack 1: " << ts.pop1() << endl; // 15
    cout << "Popped from Stack 2: " << ts.pop2() << endl; // 20

    return 0;
}
