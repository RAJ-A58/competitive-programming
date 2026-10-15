#include<bits/stdc++.h>
using namespace std;

int main(){
    int col;
    cin >> col;
    vector<int> a(col);
    for(int i = 0; i < col; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < col; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}