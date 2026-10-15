#include <iostream>
#include <vector>

using namespace std;

// DFS function to find all connected snow drifts
void dfs(int node, const vector<pair<int, int>> &points, vector<bool> &visited)
{
    visited[node] = true;

    // Check this snow drift against every other snow drift
    for (int i = 0; i < points.size(); i++)
    {
        if (!visited[i])
        {
            // If they share an X or Y coordinate, an edge exists
            if (points[node].first == points[i].first ||
                points[node].second == points[i].second)
            {
                dfs(i, points, visited); // Recursively visit the connected drift
            }
        }
    }
}

int main()
{
    // Optimize standard I/O operations
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n))
        return 0;

    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].first >> points[i].second;
    }

    vector<bool> visited(n, false);
    int components = 0;

    // Iterate through every snow drift
    for (int i = 0; i < n; i++)
    {
        // If we find an unvisited drift, we found a new isolated cluster
        if (!visited[i])
        {
            components++;            // Count this new component
            dfs(i, points, visited); // Mark all drifts connected to this one as visited
        }
    }

    // The answer is always (Total Components - 1)
    cout << components - 1 << "\n";

    return 0;
}