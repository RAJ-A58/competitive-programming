#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    map<int, int> mp;
    int left=0;
    int max=0;
    vector<int> playlist(n);
    for(int i=0;i<n;i++){
        cin >> playlist[i];
    }
    for(int right=0;right < n;right++){
        mp[playlist[right]]++;
        while(mp[playlist[right]] > 1){
            mp[playlist[left]]--;
            left++;
        }
        if(max < right-left+1){
            max = right-left+1;
        }
    }
    cout << max << "\n";
}