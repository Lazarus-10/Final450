#include <iostream>
#include <vector>
using namespace std;
#define INFINIT 1e7

class Solution{
  public:
    // Top-Down O(k^n)  k is maximum branch
    int minJumpsTD(int arr[], int n, int i=0){
        if(i >= n)return INFINIT;
        if(i == n-1)return 0;
        int steps = arr[i];
        int minVal = 1e7;
        for(int j=1; j<=steps; j++){
            minVal = min(minVal, minJumpsTD(arr, n, i+j));
        }
        return 1 + minVal;
    }
    // bottom up  O(n^2) time, O(n) space
    int minJumpsDP(int arr[], int n){
        if(arr[0] == 0)return -1;
        vector<int> jump(n, INFINIT);
        jump[0] = 0;
        for (int i = 1; i < n; i++){
            for(int j=0; j<i; j++){
                if(i <= j + arr[j]){
                    jump[i] = min(jump[i], jump[j] + 1);
                }
            }
        }
        return jump[n-1] >= n ? -1 : jump[n-1];
    }

    // Linear Time
    int minJumpsLIN(int arr[], int n){
        if(arr[0] == 0) return -1;
        if(n == 1) return 0;
        int maxIndexSoFar, jump, stepsLeft;
        maxIndexSoFar = arr[0];
        stepsLeft = arr[0];
        jump = 1;

        for(int i=1; i<n-1; i++){
            stepsLeft--;
            maxIndexSoFar = max(maxIndexSoFar, i + arr[i]);
            if(stepsLeft == 0){
                jump++;
                if(i >= maxIndexSoFar)return -1;
                stepsLeft = maxIndexSoFar - i;
            }
        }
        return jump;
    }
};


// Driver Code Starts.

int main()
{
    freopen("15_inp.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumpsDP(arr, n)<<endl;
    }
    return 0;
}