#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // Optimize standard I/O operations for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m))
        return 0;

    vector<string> grid(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> grid[i];
    }

    // Iterate through every cell in the grid
    for (int r = 0; r < n; ++r)
    {
        for (int c = 0; c < m; ++c)
        {

            // Check if it is an "Even" square (Parity 0)
            if ((r + c) % 2 == 0)
            {
                // We must use 'A' or 'B'.
                // Ensure it is different from the current character.
                if (grid[r][c] == 'A')
                {
                    grid[r][c] = 'B';
                }
                else
                {
                    grid[r][c] = 'A';
                }
            }
            // Otherwise, it is an "Odd" square (Parity 1)
            else
            {
                // We must use 'C' or 'D'.
                // Ensure it is different from the current character.
                if (grid[r][c] == 'C')
                {
                    grid[r][c] = 'D';
                }
                else
                {
                    grid[r][c] = 'C';
                }
            }
        }
    }

    // Print the final transformed grid
    for (int i = 0; i < n; ++i)
    {
        cout << grid[i] << "\n";
    }

    return 0;
}