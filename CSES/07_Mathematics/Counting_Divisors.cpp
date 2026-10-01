#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        int sqrt_x = sqrt(x);
        int count = 0;
        for(int i = 1; i <= sqrt_x; i++){
            if(x % i == 0){
                count++;
                if(i != x / i) count++;
            }
        }
        cout << count << "\n";
    }
}