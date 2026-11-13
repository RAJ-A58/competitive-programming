#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        pref[i] = (pref[i - 1] + (a[i - 1] % k)) % k;
    }

    vector<long long> freq(k, 0);
    long long count = 0;

    for (int i = k + 1; i <= n; i++)
    {
        freq[pref[i - k - 1]]++;
        count += freq[pref[i]];
    }

    cout << count << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

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