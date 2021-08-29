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
