#include <bits/stdc++.h>
using namespace std;

const int MAX_ROOT = 1000000;
vector<bool> is_prime(MAX_ROOT + 1, true);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i * i <= MAX_ROOT; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_ROOT; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(); // <-- Call sieve() here before answering queries!

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    for (auto it : a) {
        long long root = round(sqrt(it)); 
        
        if (root * root == it && is_prime[root]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}