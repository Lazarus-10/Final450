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

#define MAX 256

using namespace std;
bool checkEqual(int arr1[], int arr2[]){
    for(int i=0; i<MAX; i++){
        if(arr1[i] != arr2[i])return false;
    }
    return true;
}
bool isshuffle(string str, string pat){
    int n = str.size();
    int m = pat.size();

    if(m > n)return false;
    int countP[MAX]= {0}, countCW[MAX] = {0};
    for(int i = 0; i<m; i++){
        countP[pat[i]]++;
        countCW[str[i]]++;
    }
    for(int i=m; i<n; i++){
        if(checkEqual(countP, countCW))return true;
        countCW[str[i]]++;
        countCW[str[i-m]]--;
    }
    if(checkEqual(countP, countCW))return true;
    return false;
}
int main(){
    freopen("inputs/isShuffleOfSubstring.txt", "r", stdin);
    int t; cin >> t;
    cin.ignore();
    while(t--){
        string str, pat;
        cin >> str >> pat;
        cout << isshuffle(str, pat) << endl;
    }
    return 0;
}