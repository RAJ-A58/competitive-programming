#include <bits/stdc++.h>
using namespace std;
//compare the indexes of the consecutive values
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        pos[val] = i;
    }

    int count = 1;
    for (int x = 1; x < n; x++)
    {
        if (pos[x + 1] < pos[x])
        {
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}