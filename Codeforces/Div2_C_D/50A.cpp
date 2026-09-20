#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    // Total area is M * N, each domino takes 2 squares
    cout << (M * N) / 2 << "\n";

    return 0;
}