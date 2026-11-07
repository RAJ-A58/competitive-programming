#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool check(int M, int n, const vector<int> &a)
{
    vector<int> array;

    for (int i = 0; i < n - 1; i++)
    {
        if (abs(a[i] - a[i + 1]) > M)
        {
            array.push_back(i);
        }
    }

    if (array.empty())
        return true;
    if (array.size() > 2)
        return false;

    if (array.size() == 2)
    {
        int l = array[0] + 1;
        int r = array[1];

        if (l > r)
            return false;

        for (int i = l; i < r; i++)
        {
            if (abs(a[i] - a[i + 1]) > M / 2)
                return false;
        }

        if (l > 0 && abs(a[l - 1] - 2 * a[r]) > M)
            return false;
        if (r < n - 1 && abs(2 * a[l] - a[r + 1]) > M)
            return false;

        return true;
    }

    if (array.size() == 1)
    {
        int p = array[0];

        int l = p + 1;
        if (l < n)
        {
            for (int r = l; r < n; r++)
            {
                if (r > l && abs(a[r - 1] - a[r]) > M / 2)
                    break;

                bool ok = true;
                if (l > 0 && abs(a[l - 1] - 2 * a[r]) > M)
                    ok = false;
                if (r < n - 1 && abs(2 * a[l] - a[r + 1]) > M)
                    ok = false;

                if (ok)
                    return true;
            }
        }

        int r = p;
        if (r >= 0)
        {
            for (int l_idx = r; l_idx >= 0; l_idx--)
            {
                if (l_idx < r && abs(a[l_idx] - a[l_idx + 1]) > M / 2)
                    break;

                bool ok = true;
                if (l_idx > 0 && abs(a[l_idx - 1] - 2 * a[r]) > M)
                    ok = false;
                if (r < n - 1 && abs(2 * a[l_idx] - a[r + 1]) > M)
                    ok = false;

                if (ok)
                    return true;
            }
        }
    }

    return false;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int low = 0, high = 1e9;
    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (check(mid, n, a))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
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