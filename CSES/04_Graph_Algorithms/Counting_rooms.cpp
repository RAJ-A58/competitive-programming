#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    // BFS Question start a BFS search each time you come across a "."
    int count=0;
    vector<vector<char>> a(n,vector<char> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }
    vector<vector<bool>> vis(n,vector<bool> (m,false));
    queue<pair<int,int>> q;
    int sx[]={-1,0,1,0};
    int dy[]={0,1,0,-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='.' && !vis[i][j]){
                count++;
                q.push({i,j});
                vis[i][j]=true;
                while(!q.empty()){
                    auto [x,y]=q.front();
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx=x+sx[k];
                        int ny=y+dy[k];
                        if(nx>=0 && nx<n && ny>=0 && ny<m && a[nx][ny]=='.' && !vis[nx][ny]){
                            vis[nx][ny]=true;
                            q.push({nx,ny});
                        }
                    }
                }
            }
        }
    }
    cout << count << "\n";
}