#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long a = 2;
    long long res = 1;
    long long MOD = 1e9 + 7;
    while (n > 0)
    {
        if (n & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        n = n >> 1;
    }
    cout << res << endl;
    return 0;
}