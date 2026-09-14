#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,k;
    cin >> n >> k;
    vector<long long> arr(n);
    arr.reserve(n);
    long long x,a,b,c;
    cin >> x >> a >> b >> c;
    arr[0] = x;
    for (long long i = 1; i < n; i++) {
        arr[i] = (1LL * a * arr[i - 1] + b) % c;
    }
    long long sum=0;
    for(long long i=0;i<k;i++){
        sum+=arr[i];
    }
    long long ansxor=sum;
    for(long long i=k;i<n;i++){
        sum+=arr[i];
        sum-=arr[i-k];
        ansxor^=sum;
    }
    cout << ansxor << "\n";
}