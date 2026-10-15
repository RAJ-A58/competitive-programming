#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k, l, c, d, p, nl, np;
    if (cin >> n >> k >> l >> c >> d >> p >> nl >> np) {
        int drink_toasts = (k * l) / (n * nl);
        int lime_toasts = (c * d) / n;
        int salt_toasts = p / (n * np);
        
        cout << min({drink_toasts, lime_toasts, salt_toasts}) << endl;
    }
    return 0;
}