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

string countAndSayRecur(int n, string s = "1"){
    if(n == 1)return s;
    int i=0, j;
    int len = s.size();
    string ans = "";
    while(i < len){
        j = i;
        while(i < len && s[i] == s[j])i++;
        ans += to_string(i-j) + s[j];
    }
    return countAndSayRecur(n-1, ans);
}
void append(int cnt, char tmp, string &ans){
    string count = to_string(cnt);
    for(auto x: count){
        ans.push_back(x);
    }
    ans.push_back(tmp);
}
string say(string str){
    string ans;
    if(str.length() == 0)return "1";
    char tmp = str[0];
    int cnt = 1;
    for(int i=1; i<str.length(); i++){
        if(str[i] == tmp){
            cnt++;
        }
        else{
            append(cnt, tmp, ans);
            tmp = str[i];
            cnt = 1;
        }
    }
    append(cnt, tmp, ans);
    return ans;
}
string countAndSay(int n) {
    string ans = "";
    for(int i=1; i<=n; i++){
        ans = say(ans);
    }
    return ans;
    
}

int main(){
    cout << countAndSayRecur(5) << endl;
    cout << countAndSay(5) << endl;
    return 0;
}