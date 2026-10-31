#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x,y,z;
    cin >> x >> y >> z;
    char move;
        if (y >= z) move = 'R';
        else if (z >= x) move = 'S';
        else move = 'P';

        cout << string(x + y + z, move) << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}