#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
/**************************************** Recursive ****************************************/
// Top-Down (Recursive Approach) , T.C: O(2^N)
int LIS_Recursive(vector<int> arr, int prev = -1, int curr = 0){
    if(curr == arr.size())return 0;

    int op1 = 0;
    if(prev == -1 || arr[curr] > arr[prev]){
        op1 = 1 + LIS_Recursive(arr, curr, curr+1);
    }

    int op2 =  LIS_Recursive(arr, prev, curr+1);
    return max(op1, op2);
}
/**************************************** Recursive ****************************************/

/**************************************** Memoization ****************************************/
// T.C : O(N^2), S.C: O(N^2)
int __LIS_Recursive_Memoized(const vector<int> &arr, const int &n,vector<vector<int> > &dp, int prev, int curr){
    if(curr == n)return 0;

    if(prev != -1 && dp[prev][curr] != -1){
        return dp[prev][curr];
    }

    int op1 = 0;
    if(prev == -1 || arr[curr] > arr[prev]){
        op1 = 1 + __LIS_Recursive_Memoized(arr, n, dp, curr, curr+1);
    }
    int op2 = __LIS_Recursive_Memoized(arr, n, dp, prev, curr+1);
    if(prev != -1)
        dp[prev][curr] = max(op1, op2);
    return max(op1, op2);
    
}
int LIS_Recursive_Memoized(vector<int> arr){
    int n = arr.size();
    vector<vector<int> > dp(n, vector<int>(n, -1));
    return __LIS_Recursive_Memoized(arr, n, dp, -1, 0);
}
/**************************************** Memoization ****************************************/

/**************************************** Iterative DP(bottom-up) ****************************************/
// T.C : O(N^2), S.C: O(N)
int LIS_Iterative(vector<int> arr){
    int n = arr.size();
    int dp[n];
    // https://stackoverflow.com/a/17288891
    // memset(dp, 1, sizeof dp); /******* never ever use like this *******/
    dp[0] = 1;
    int maxm = 1;
    for(int i=1; i<n; i++){
        dp[i] = 1;
        for(int j = 0; j<i; j++){
            if(arr[j] < arr[i] && 1 + dp[j] > dp[i]){
                dp[i] = 1 + dp[j];
            }
        }
        maxm = max(dp[i], maxm);
    }
    return maxm;
}
/**************************************** Iterative DP(bottom-up) ****************************************/

/**************************************** O(NlogN) ****************************************/
int search(vector<int> vec, int val){
    int l = 0, e = vec.size()-1;
    while(l <= e){
        int mid = l + (e-l)/2;
        if(vec[mid] < val && vec[mid+1] >= val)return mid+1;
        else if(vec[mid] < val)l = mid +1;
        else e = mid-1;
    }
    return vec.size();
}

int LIS_Best(vector<int> arr){
    vector<int> vec;
    vec.push_back(arr[0]);
    for(int i=1; i<arr.size(); i++){
        if(arr[i] > vec.back()){
            vec.push_back(arr[i]);
        }else{
            // int index = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
            int index = search(vec, arr[i]);
            vec[index] = arr[i];
        }
    }
    return vec.size();
}
/**************************************** O(NlogN) ****************************************/

int main()
{
    vector<int> arr {3,5,6,2,5,4,19,5,6,7,12};
    int n = arr.size();
    printf("Length of lis is %d\n", LIS_Recursive(arr));
    printf("Length of lis is %d\n", LIS_Recursive_Memoized(arr));
    printf("Length of lis is %d\n", LIS_Iterative(arr));
    printf("Length of lis is %d\n", LIS_Best(arr));
    return 0;
}