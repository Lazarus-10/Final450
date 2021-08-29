// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
    bool isPalin(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j])return false;
            i++;
            j--;
        }
        return true;
    }
  public:
    string longestPalin (string S) {
        int n = S.length();
        int start;
        int size = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(isPalin(S, i, j)){
                    if(j-i+1 > size){
                        size = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return S.substr(start, size);
    }
};

// { Driver Code Starts.

int main()
{
    freopen("inputs/63.txt", "r", stdin);
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends