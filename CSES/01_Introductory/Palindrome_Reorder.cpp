#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> freq(26, 0);
    for(char c : s){
        freq[c - 'A']++;
    }
    string ans="";
    string left="", right="";
    for(int i=0;i<26;i++){
        int pairs = freq[i] / 2;
        left+=string(pairs, 'A' + i);
        right+=string(pairs, 'A' + i);
        freq[i]-= pairs * 2;
    }
    reverse(right.begin(), right.end());
    for(int i=0;i<26;i++){
        if(freq[i]){
            ans+=string(1, 'A' + i);
            break;
        }
    }
    ans = left + ans + right;
    if(ans.size() != s.size()){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    cout << ans << endl;
}