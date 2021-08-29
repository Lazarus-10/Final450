// { Driver Code Starts
#include <iostream>
#include <string>
#include <cstring>
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
   /***** Brute-Force Approach, T.C : O(N^3), S.C: O(1) *****/
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


    /***** DP based Approach, T.C : O(N^2), S.C: O(N^2) *****/
    string longestPalinDP(string S){
        int n = S.length();
        // dp[i][j] tell if string from [i...j] is a palindrome
        bool dp[n][n];
        memset(dp, false, sizeof dp);

        // all strings of length 1 are palindrome
        int maxLength = 1;
        for(int i=0; i<n; i++){
            dp[i][i] = true;
        }

        // Filling for size 2 strings
        int start = 0;
        for(int i=1; i<n; i++){
            if(S[i] == S[i-1]){
                dp[i-1][i] = true;
                start = i-1;
                maxLength = 2;
            }
        }

        // check for all substrings of length(k) > 2
        for(int k=3; k<=n; k++){
            // fix the starting index
            for(int i=0; i< n-k+1; i++){
                int j = i + k -1; // ending index of substring
                if(dp[i+1][j-1] && S[i] == S[j]){
                    dp[i][j] = true;

                    if(k > maxLength){
                        maxLength = k;
                        start = i;
                    }
                }

            }
        }

        return S.substr(start, maxLength);
    }

    /***** Another Approach, T.C : O(N^2), S.C: O(1) *****/

    string longestPalin3(string S) {
        int max_length = 1, start = 0;
        int n = S.size();
        int low, high;
        for(int i=1; i<n; i++){
            low = i-1;
            high = i;
            while(low >= 0 && high < n && S[low] == S[high]){
               low--;
               high++;
            }

            low++, high--;
            if(S[low] == S[high] && high-low+1 > max_length){
                start = low;
                max_length = high - low + 1;
            }

            low = i-1;
            high = i+1;
            while(low >= 0 && high < n && S[low] == S[high]){
                low--;
                high++;
            }

            low++, high--;
            if(S[low] == S[high] && high-low+1 > max_length){
                start = low;
                max_length = high - low + 1;
            }
        }

        return S.substr(start, max_length);
    }
    

};

// { Driver Code Starts.

int main()
{
    freopen("63.txt", "r", stdin);
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        Solution ob;
        cout << ob.longestPalin3(S) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends