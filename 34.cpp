// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

class Solution{

    // Function to find the trapped water between the blocks.
    public:
    int trappingWater(int arr[], int n){
        int leftMax = 0, rightMax = 0;
        int lo = 0, hi = n-1;
        int water = 0;
        while(lo <= hi){
            if(arr[lo] < arr[hi]){
                if(arr[lo] <= leftMax){
                    water += (leftMax - arr[lo]);
                }else{
                    leftMax = arr[lo];
                }
                lo++;
            }else{
                if(arr[hi] <= rightMax){
                    water += (rightMax - arr[hi]);
                }else{
                    rightMax = arr[hi];
                }
                hi--;
            }
        }
        return water;
        
        // int leftMax[n] = {0};
        // int rightMax[n] = {0};
        // int rMax = arr[n-1];
        // for(int i=n-1; i>=0; i--){
        //     rMax = max(rMax, arr[i]);
        //     rightMax[i] = rMax;
        // }
        // int lMax = arr[0];
        // for(int i=0; i<n; i++){
        //     lMax = max(lMax, arr[i]);
        //     leftMax[i] = lMax;
        // }
        // int ans = 0;
        // for(int i=0; i<n; i++){
        //     ans += (min(leftMax[i], rightMax[i]) - arr[i]);
        // }
        
        // return ans;
        
        
        
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends