#include <iostream>
#include <string>

using namespace std;

void solve()
{
    string s;
    cin >> s;

    int n = s.length();
    bool can_add = false;
    bool can_sub = false;

    for (int i = 1; i < n - 1; i++)
    {
        if (s[i - 1] == s[i] && s[i] == s[i + 1])
        {
            can_add = true;
        }
        if (s[i - 1] != s[i] && s[i] != s[i + 1])
        {
            can_sub = true;
        }
    }
    cout << 1 + can_add + can_sub << "\n";
}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            solve();
        }
    }
    return 0;
}