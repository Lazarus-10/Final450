#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <climits>
#include <cstring>

using namespace std;
bool isShuffle(string first, string second, string result){
    int m = first.size();
    int n = second.size();
    if(m + n != result.length())return false;
    first += second;
    sort(first.begin(), first.end());
    sort(result.begin(), result.end());
    return first == result;
}

// if strings are immutable
bool isShuffle2(string first, string second, string result){
    int m = first.size();
    int n = second.size();
    sort(first.begin(), first.end());
    sort(second.begin(), second.end());
    sort(result.begin(), result.end());

    int i=0, j=0, k=0;
    while(k != result.length()){
        if(i < m && first[i] == result[k]){
            i++;
        }
        else if(j < n && second[j] == result[k]){
            j++;
        }
        else return false;
        k++;
    }
    if(i < m || j<n)return false;
    return true;
}
int main(){
    freopen("inputs/61.txt", "r", stdin);
    int t; cin >> t;
    cin.ignore();
    while(t--){
        string first, second, result;
        cin >> first >> second >> result;
        cout << isShuffle2(first, second, result) << endl;
    }
    return 0;
}