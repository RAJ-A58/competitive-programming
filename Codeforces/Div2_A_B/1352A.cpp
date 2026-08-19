// Approach: Extract digits one by one. If a digit is non-zero, it forms a round number when multiplied by its corresponding power of 10.
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int i=0;
        int count=0;
        int num=n;
        while(num!=0){
            int dig=num%10;
            if(dig!=0){
                count++;
            }
            num/=10;
        }
        cout<< count << endl;
        while(n!=0){
            int dig=n%10;
            if(dig!=0){
                cout << dig*pow(10,i) << " ";
            }
            n/=10;
            i++;
        }
        cout << endl;
    }
}
