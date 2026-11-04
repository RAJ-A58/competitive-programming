#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve()
{
    int n;
    cin >> n;

    long long k = 0;
    long long X = 0;
    for (int i = 1; i <= n; i++)
    {
        k |= i;
        X ^= i;
    }

    long long basis_val[35] = {0};
    vector<int> basis_subset[35];

    for (int i = 1; i <= n; i++)
    {
        long long v = i ^ (2LL * i);
        vector<int> cur_subset = {i};

        for (int b = 30; b >= 0; b--)
        {
            if ((v >> b) & 1)
            {
                if (basis_val[b] == 0)
                {
                    basis_val[b] = v;
                    basis_subset[b] = cur_subset;
                    break;
                }
                else
                {
                    v ^= basis_val[b];
                    vector<int> next_sub;
                    set_symmetric_difference(cur_subset.begin(), cur_subset.end(),
                                             basis_subset[b].begin(), basis_subset[b].end(),
                                             back_inserter(next_sub));
                    cur_subset = next_sub;
                }
            }
        }
    }

    long long target1 = X ^ (2LL * k);
    long long target2 = X ^ (2LL * k + 1);

    auto get_ans = [&](long long T) -> vector<int>
    {
        vector<int> ans;
        for (int b = 30; b >= 0; b--)
        {
            if ((T >> b) & 1)
            {
                if (basis_val[b])
                {
                    T ^= basis_val[b];
                    vector<int> next_ans;
                    set_symmetric_difference(ans.begin(), ans.end(),
                                             basis_subset[b].begin(), basis_subset[b].end(),
                                             back_inserter(next_ans));
                    ans = next_ans;
                }
            }
        }
        if (T == 0)
            return ans;
        return {-1};
    };

    vector<int> ans = get_ans(target1);
    if (!ans.empty() && ans[0] == -1)
    {
        ans = get_ans(target2);
    }

    vector<int> d(n + 1, 0);
    if (!ans.empty() && ans[0] != -1)
    {
        for (int x : ans)
        {
            d[x] = 1;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << d[i] << (i == n ? "" : " ");
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int noTsts;
    if (cin >> noTsts)
    {
        while (noTsts--)
        {
            solve();
        }
    }

    return 0;
}