#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    string p, q;
    cin >> p >> q;

    string target = "isx";
    vector<int> a(26, 0);

    for (char c : p)
        a[c - 'a']++;
    for (char c : q)
        a[c - 'a']--;
    for (int x : a)
    {
        if (x < 0)
        {
            cout << "NO\n";
            return;
        }
    }
    vector<int> wanted(26, 0);
    for (char c : target)
        wanted[c - 'a']++;

    if(a==wanted){
        cout << "YES" << "\n";
    }
    else{
        cout << "NO" << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}