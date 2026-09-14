#include <iostream>
#include <string>

using namespace std;

int main() {
    int low = 1;
    int high = 1000000000;
    
    while (low < high) {
        int mid = low + (high - low) / 2;
        
        cout << "? " << mid << endl;
        
        string answer;
        cin >> answer;
        
        if (answer == "YES") {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    
    cout << "! " << low << endl;
    
    return 0;
}