#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        long long sum = 0;
        bool canSplit = false;
        bool interiorCanSplit = false;

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];

            if (a[i] >= 2)
            {
                canSplit = true;
                if (i > 0 && i + 1 < n)
                {
                    interiorCanSplit = true;
                }
            }
        }

        if (!canSplit)
        {
            cout << -1 << '\n';
        }
        else if (n == 2 || interiorCanSplit)
        {
            cout << sum - 1 << '\n';
        }
        else
        {
            cout << sum - (n-1) << '\n';
        }
    }

    return 0;
}