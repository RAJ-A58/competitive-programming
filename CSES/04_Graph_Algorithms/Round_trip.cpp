#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> vis;
vector<int> parent;
int cycle_start = -1, cycle_end = -1;

bool dfs(int u, int p)
{
    vis[u] = 1;
    parent[u] = p; // Keep track of the path

    for (int v : adj[u])
    {
        if (v == p)
            continue; // Skip the edge we just came from

        if (vis[v])
        {
            // Found a back-edge to an already visited node
            cycle_start = v;
            cycle_end = u;
            return true;
        }

        if (!vis[v])
        {
            if (dfs(v, u))
                return true;
        }
    }
    return false;
}

int main()
{
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n >> m))
        return 0;

    adj.resize(n + 1);
    vis.assign(n + 1, 0);
    parent.assign(n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    // Check all unvisited components
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1))
            {
                // Reconstruct the cycle using the parent array
                vector<int> cycle;
                cycle.push_back(cycle_start);

                for (int v = cycle_end; v != cycle_start; v = parent[v])
                {
                    cycle.push_back(v);
                }
                cycle.push_back(cycle_start);

                cout << cycle.size() << "\n";
                for (int v : cycle)
                {
                    cout << v << " ";
                }
                cout << "\n";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}