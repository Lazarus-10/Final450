#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

/**************************************** Recursive ****************************************/
// Top-Down (Recursive Approach) , T.C: O(2^N)
int LCS_Recursive(string X, string Y, int m, int n){
    //base case
    if(m == 0 || n == 0)return 0;

    // Decision Tree implementation
    if(X[m-1] == Y[n-1]){
        return 1 + LCS_Recursive(X, Y, m-1, n-1);
    }else{
        return max(LCS_Recursive(X, Y, m-1, n), LCS_Recursive(X, Y, m, n-1));
    }
}
/**************************************** Recursive ****************************************/

/**************************************** Memoization ****************************************/
// T.C : O(N^2), S.C: O(N^2)
int __LCS_Recursive_Memoized(const string &X, const string &Y, int m, int n, vector<vector<int> > &dp){
    if(m == 0 || n == 0)return dp[m][n] = 0;
    if(dp[m][n] != -1)return dp[m][n];

    if(X[m-1] == Y[n-1]){
        return dp[m][n] = 1 + __LCS_Recursive_Memoized(X, Y, m-1, n-1, dp);
    }else{
        return dp[m][n] = max(__LCS_Recursive_Memoized(X, Y, m-1, n, dp), __LCS_Recursive_Memoized(X, Y, m, n-1, dp));
    }
}
int LCS_Recursive_Memoized(string X, string Y, int m, int n){
    vector<vector<int> > dp(m+1, vector<int>(n+1, -1));
    return __LCS_Recursive_Memoized(X, Y, m, n, dp);
}
/**************************************** Memoization ****************************************/

/**************************************** Tabulation(Bottom-Up) ****************************************/
//Time Complexity : O(m*n)
//Auxiliary Space: O(m*n)

int LCS_BottomUP(string X, string Y, int m, int n){
    int dp[m+1][n+1];
    for(int i=0; i<=m; i++){
        dp[i][0] = 0;
    }
    for(int i=0; i<=n; i++){
        dp[0][i] = 0;
    }
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(X[i-1] == Y[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
/**************************************** Tabulation(Bottom-Up) ****************************************/

int main()
{
    string X = "AGGTAB";
    string Y = "GXTXAYB";
     
    cout<<"Length of LCS is "<< LCS_Recursive( X, Y, X.length(), Y.length()) << endl;
    cout<<"Length of LCS is "<< LCS_Recursive_Memoized( X, Y, X.length(), Y.length())<< endl;
    cout<<"Length of LCS is "<< LCS_BottomUP( X, Y, X.length(), Y.length()) << endl;
     
    return 0;
}