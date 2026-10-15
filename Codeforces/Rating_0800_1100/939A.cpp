#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Optimize standard I/O operations
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;

    // 1-based indexing for simplicity
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
    }

    // Check every plane for a cycle of length 3
    for (int i = 1; i <= n; i++)
    {
        int a = i;
        int b = f[a];
        int c = f[b];

        // Does the third plane like the first plane?
        if (f[c] == a)
        {
            cout << "YES\n";
            return 0; // Found a triangle, exit immediately
        }
    }

    cout << "NO\n";
    return 0;
}