#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> deg(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }

    int max_deg = 0;
    int isolated_count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (deg[i] == 0)
        {
            isolated_count++;
        }
        if (deg[i] > max_deg)
        {
            max_deg = deg[i];
        }
    }

    if (isolated_count > 0)
    {
        cout << "Brain Melt\n";
    }
    else if (m == n - 1 && max_deg == n - 1)
    {
        cout << "2\n";
    }
    else
    {
        cout << "Many\n";
    }
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