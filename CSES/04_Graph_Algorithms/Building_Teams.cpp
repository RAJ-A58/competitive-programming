#include<bits/stdc++.h>
using namespace std;

int main(){
    //fast input output
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    //Your Solution goes here
    vector<int> team(n,-1);
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        u--;v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(team[i]==-1){
            team[i]=0;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(int neighbor:adj[node]){
                    if(team[neighbor]==-1){
                        team[neighbor]=1-team[node];
                        q.push(neighbor);
                    }
                    else if(team[neighbor]==team[node]){
                        cout << "IMPOSSIBLE\n";
                        return 0;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << team[i]+1 << " ";
    }
    cout << "\n";
} 