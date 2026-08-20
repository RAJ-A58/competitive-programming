// Compare consective characters in a string and find the length of the longest substring of identical characters.
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    if (cin >> s) {
        int max_len = 1;
        int curr_len = 1;
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                curr_len++;
            } else {
                curr_len = 1;
            }
            max_len = max(max_len, curr_len);
        }
        cout << max_len << "\n";
    }
    return 0;
}