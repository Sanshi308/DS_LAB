4) Write a program to find first non-repeating character in a string using Queue. Sample I/P: a a
b c Sample O/P: a -1 b b

#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    unordered_map<char,int> freq;

    for (char c : str) {
        freq[c]++;
        q.push(c);

        while (!q.empty() && freq[q.front()] > 1)
            q.pop();

        if (q.empty()) cout << -1 << " ";
        else cout << q.front() << " ";
    }
    cout << endl;
}

int main() {
    string str = "aabc";
    firstNonRepeating(str);
}
