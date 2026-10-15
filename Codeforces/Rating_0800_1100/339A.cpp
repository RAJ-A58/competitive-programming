#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    if (cin >> s) {
        int count1 = 0, count2 = 0, count3 = 0;
        for (int i = 0; i < s.length(); i += 2) {
            if (s[i] == '1') count1++;
            else if (s[i] == '2') count2++;
            else if (s[i] == '3') count3++;
        }
        string ans = "";
        while (count1--) ans += "1+";
        while (count2--) ans += "2+";
        while (count3--) ans += "3+";
        if (!ans.empty()) {
            ans.pop_back(); 
        }

        cout << ans << "\n";
    }
    return 0;
}