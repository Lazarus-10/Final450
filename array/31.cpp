// { Driver Code Starts
// A C++ program to print elements with count more than n/k

#include <iostream>

using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    int maxProfit(int arr[], int n) {
       int dp[n];
       dp[n-1] = 0;
       int Max_price = arr[n-1];
       for(int i=n-2; i>=0; i--){
           Max_price = max(Max_price, arr[i]);
           dp[i] = max(dp[i+1], Max_price - arr[i]);
       }
       int Min_price = arr[0];
       for(int i=1; i<n; i++){
           Min_price = min(Min_price, arr[i]);
           dp[i] = max(dp[i-1], dp[i]+ (arr[i] - Min_price));
       }
       return dp[n-1];
    }
    
    int maxProfit2(int arr[], int n) {
       int dp[n];
       dp[0] = 0;
       int min_price = arr[0];
       for(int i=1; i<n; i++){
           min_price = min(min_price, arr[i]);
           dp[i] = max(dp[i-1], arr[i] - min_price);
       }

       int max_price = arr[n-1];
       for(int i= n-2; i>=0; i--){
            max_price = max(max_price, arr[i]);
            dp[i] = max(dp[i+1], max_price-arr[i]+dp[i]);
       }
       return dp[0];

    }
};


// { Driver Code Starts.
int main() {
    freopen("31.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.maxProfit(arr, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends