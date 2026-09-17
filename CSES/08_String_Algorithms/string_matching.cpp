#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, p;
    if (!(cin >> s >> p)) return 0;

    int n = s.size();
    int m = p.size();

    // Edge case: if pattern is longer than string, it can't be found
    if (n < m || m == 0) {
        cout << 0 << "\n";
        return 0;
    }

    // Step 1: Precompute the LPS (Longest Prefix which is also Suffix) array
    // This tells the algorithm how far to safely skip ahead when a mismatch occurs.
    vector<int> lps(m, 0);
    int len = 0; 
    int i = 1;
    while (i < m) {
        if (p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // Fallback to the previous longest prefix
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    // Step 2: Search using KMP
    int count = 0;
    i = 0; // index for string s
    int j = 0; // index for pattern p
    
    while (i < n) {
        if (p[j] == s[i]) {
            j++;
            i++;
        }
        
        // If we found a full match
        if (j == m) {
            count++;
            // Reset j to look for overlapping matches (e.g., finding "aa" in "aaa")
            j = lps[j - 1]; 
        } 
        // If there's a mismatch after some matches
        else if (i < n && p[j] != s[i]) {
            if (j != 0) {
                j = lps[j - 1]; // Use LPS to skip characters
            } else {
                i++; // If no matches at all, move to the next character in s
            }
        }
    }

    cout << count << "\n";
    return 0;
}