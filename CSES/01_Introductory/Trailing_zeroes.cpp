#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    long long count5 = 0;
    
    // Efficiently count all factors of 5 in n!
    while (n >= 5) {
        count5 += n / 5;
        n /= 5;
    }
    cout << count5 << "\n";
    return 0;
}