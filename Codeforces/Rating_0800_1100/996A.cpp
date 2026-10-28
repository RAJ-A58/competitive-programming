#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int bills = 0;
    
    bills += n / 100;
    n %= 100;
    
    bills += n / 20;
    n %= 20;
    
    bills += n / 10;
    n %= 10;
    
    bills += n / 5;
    n %= 5;
    
    bills += n / 1;
    
    cout << bills << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}