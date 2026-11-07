#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    long long l;
    cin >> n >> l;

    vector<long long> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] + a[i];
    }

    long long ans = 2e18;

    for (long long x = 0; x * x <= l - 1; x++)
    {
        int idx = upper_bound(a.begin(), a.end(), x) - a.begin();

        long long count = n - idx;
        long long sum = pref[n] - pref[idx];
        long long cost_all = sum - count * x;

        long long y;
        if (x == 0)
        {
            y = 2e18;
        }
        else
        {
            y = (l - 1) / x;
        }

        long long max_val = a[n - 1];
        long long current_cost = cost_all - max(0LL, max_val - x) + max(0LL, max_val - y);

        ans = min(ans, current_cost);
    }

    cout << ans << "\n";
}

int main()
{
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