// Approach: Calculate the number of flagstones needed for length and width by taking the ceiling of division using (n+a-1)/a, then multiply them.
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n, m, a;
    cin >> n >> m >> a;
    
    long long length_stones = (n + a - 1) / a;
    long long width_stones = (m + a - 1) / a;
    
    cout << length_stones * width_stones << endl;
    
    return 0;
}
