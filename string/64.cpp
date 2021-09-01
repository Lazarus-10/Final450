// Refer to Longest Common subsequence in Extras folder for more possible methods
#include <iostream>
#include <string>
using namespace std;

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n = str.length();
		    int dp[n+1][n+1];
            for(int i=0; i<=n; i++){
                dp[i][0] = dp[0][i] = 0;
            }
          
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    if(str[i-1] == str[j-1] && i != j){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }else{
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
            return dp[n][n];
		}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends