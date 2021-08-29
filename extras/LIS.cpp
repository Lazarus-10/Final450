#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int lis(int arr[], int n){
    // int dp[n];
    // dp[0] = 1;
    // int maxm = 1;
    // for(int i=1; i<n; i++){
    //     dp[i] = 1;
    //     for(int j=0; j<i; j++){
    //         if(arr[j] < arr[i] && dp[j] + 1 > dp[i]){
    //             dp[i] = dp[j] + 1;
    //         }
    //     }
    //     maxm = max(maxm, dp[i]);
    // }
    // return maxm;

    int dp[n];
    // https://stackoverflow.com/a/17288891
    // memset(dp, 1, sizeof dp); // never ever use like this
    dp[0] = 1;
    cout << dp[0] << " ";
    int maxm = 1;
    for(int i=1; i<n; i++){
        dp[i] = 1;
        for(int j = 0; j<i; j++){
            if(arr[j] < arr[i] && 1 + dp[j] > dp[i]){
                dp[i] = 1 + dp[j];
            }
        }
        maxm = max(dp[i], maxm);
        cout << dp[i] << " ";
    }
    cout << endl;
    return maxm;
    
}

int search(vector<int> vec, int val){
    cout << "searching for " << val << "in ";
    for(auto x: vec){
        cout << x << " " ;
    }
    cout << endl;
    int l = 0, e = vec.size()-1;
    if(e == 0)return 0;
    while(l <= e){
        int mid = l + (e-l)/2;
        if(vec[mid] < val && vec[mid+1] > val)return mid+1;
        else if(vec[mid] <= val)l = mid +1;
        else e = mid-1;
    }
    return 0;
}

int lis2(int arr[], int n){
    vector<int> vec;
    vec.push_back(arr[0]);
    for(int i=1; i<n; i++){
        if(arr[i] > vec.back()){
            vec.push_back(arr[i]);
        }else{
            int index = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
            vec[index] = arr[i];
        }
    }

    return vec.size();

}
int main()
{
    int arr[] = {3,5,6,2,5,4,19,5,6,7,12};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of lis is %d", lis2(arr, n));
    return 0;
}