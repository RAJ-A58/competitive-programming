#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int arr[]={4,7,44,77,47,74,444,447,474,477,744,747,774,777};
    int n;
    cin >> n;
    for(int i=0;i<14;i++){
        if(n%arr[i]==0){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}