#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int max_d = 0;
    for (int i = 1; i < n; i++)
    {
        max_d = max(max_d, a[i] - a[i - 1]);
    }
    double ans = max_d / 2.0;
    ans = max(ans, (double)a[0]);
    ans = max(ans, (double)(l - a[n - 1]));
    cout << fixed << setprecision(10) << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}