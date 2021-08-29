#include <iostream>
using namespace std;
int lis(int arr[], int n){
    int dp[n];
    dp[0] = 1;
    int maxm = -1;
    for(int i=1; i<n; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[j] < arr[i] && dp[j] + 1 > dp[i]){
                dp[i] = dp[j] + 1;
            }
        }
        maxm = max(maxm, dp[i]);
    }
    return maxm;
    
}
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 , 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of lis is %d", lis(arr, n));
    return 0;
}