#include<bits/stdc++.h>
using namespace std;

void dfs(int node , vector<vector<int>>& adj, vector<bool>& vis){
    vis[node] = true;
    for(auto child: adj[node]){
        if(!vis[child]){
            dfs(child,adj,vis);
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int count = 0;
    vector<bool> vis(n+1,false);
    vector<int> leadnodes;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            count++;
            leadnodes.push_back(i);
            dfs(i,adj,vis);
        }
    }
    cout << count - 1 << endl;
    for(int i=0;i<count-1;i++){
        cout << leadnodes[i] << " " << leadnodes[i+1] << endl;
    }
}