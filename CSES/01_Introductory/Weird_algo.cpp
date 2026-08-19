// Approach: Simulate the Collatz conjecture process. Use bitwise right shift for even numbers (division by 2) and multiply by 3 then add 1 for odd numbers until reaching 1.
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    while(n!=1){
        cout<< n << " ";
        if(n%2==0) n=n>>1;
        else n=n*3 +1;
    }
    cout << 1 << "\n";
    return 0;
}
