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
bool isRotated(string s, string goal){
    if(s.length() != goal.length())return false;
    s += s;
    // if(s.find(goal) != string::-1)return true;
    if(s.find(goal) != string::npos)return true;
    return false;
}

bool isRotated2(string s, string goal){
    if(s.length() != goal.length())return false;
    queue<int> q1, q2;
    for(int i=0; i<s.size(); i++){
        q1.push(s[i]);
    }
    for(int j=0; j<goal.size(); j++){
        q2.push(goal[j]);
    }

    int l = goal.size();
    while(l--){
        int ch = q2.front();
        q2.pop();
        q2.push(ch);
        if(q1 == q2){
            return true;
        }
    }
    return false;
}
int main(){
    if(freopen("inputs/60.txt", "r", stdin)){
        int t; cin >> t;
        while(t--){
            string s, goal;
            cin.ignore();
            getline(cin, s);
            getline(cin, goal);
            cout << isRotated2(s, goal) << endl;
        }
    }
    return 0;
}