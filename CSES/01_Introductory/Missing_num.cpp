// Approach: Calculate the expected sum of 1 to n using the formula n*(n+1)/2, then subtract the sum of the given numbers to find the missing one.
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    long long sum=0;
    cin >> n;
    for(int i=1;i<n;i++){
        int x;
        cin >> x;
        sum+=x;
    }
    long long sum2=n*(n+1)/2;
    cout << sum2-sum << "\n";
}
