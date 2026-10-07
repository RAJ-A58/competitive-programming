#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<string, int>> rounds(n);
    map<string, int> final_scores;
    
    for(int i = 0; i < n; i++){
        cin >> rounds[i].first >> rounds[i].second;
        final_scores[rounds[i].first] += rounds[i].second;
    }
    
    int max_score = INT_MIN;
    for(auto const& [name, score] : final_scores){
        if(score > max_score){
            max_score = score;
        }
    }
    
    map<string, int> running_scores;
    for(int i = 0; i < n; i++){
        running_scores[rounds[i].first] += rounds[i].second;
        if(running_scores[rounds[i].first] >= max_score && final_scores[rounds[i].first] == max_score){
            cout << rounds[i].first << "\n";
            break;
        }
    }
    
    return 0;
}