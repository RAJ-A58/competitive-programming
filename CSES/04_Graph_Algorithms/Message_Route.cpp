#include<bits/stdc++.h>
using namespace std;

int main(){
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    queue<int> q;
    q.push(1);
    
    // Use an explicit parent array instead of overloading 'vis'
    vector<int> parent(n + 1, 0);
    vector<bool> visited(n + 1, false);
    
    visited[1] = true;
    parent[1] = -1; // -1 indicates the start of the path
    
    while(!q.empty()){
        int node = q.front();
        q.pop(); // FIXED: Added q.pop() to prevent infinite loop
        
        for(auto child : adj[node]){
            if(!visited[child]){
                visited[child] = true;
                parent[child] = node; // Record where we came from
                q.push(child);
            }
        }
    }
    
    if(!visited[n]){
        cout << "IMPOSSIBLE\n";
    }
    else {
        vector<int> path;
        // Reconstruct the exact path by backtracking from 'n' to 1
        int curr = n;
        while(curr != -1){
            path.push_back(curr);
            curr = parent[curr];
        }
        
        reverse(path.begin(), path.end());
        
        // CSES requires the length of the path printed first
        cout << path.size() << "\n";
        for(int i = 0; i < path.size(); i++){
            cout << path[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}