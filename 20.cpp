#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    /*
    STEP 1: starting from the last, find the number which is less than its adjacent right, e.g in 5, 4, 7, 5, 3, 2, it is 4 at index 1(which also means that, from index 2, the numbers are sorted in descending order)
    STEP 2: Now find the next greater number of 4 in it's rightpart(in this case it's 5).
    STEP 3: swap them
    STEP 4: we know that the numbers from the index of 4 is already in descending order.
    so just reverse them, and this is the final answer
    */
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
            return;
        if(nums[n-1] > nums[n-2]){
            swap(nums[n-1], nums[n-2]);
            return;
        }
        int i = n - 2;
        for(; i >= 0; i--){
            if(nums[i] < nums[i+1]){
                break;
            }
        }
        if(i >= 0){
            int j=i+1;
            for(; j<n; j++){
                if(nums[j] <= nums[i] ){
                    break;
                }
            }
            swap(nums[j-1], nums[i]);
        }
        // sort(nums.begin()+i+1, nums.end());  // sort will make it O(nlogn)
        reverse(nums.begin()+i+1, nums.end());
       
    }
};

// { Driver Code Starts.
int main() {
    freopen("20.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n;
        vector<int> v;
        for(int i=0; i<n; i++){
            cin >> x;
            v.push_back(x);
        }
        Solution obj;
        obj.nextPermutation(v);
        for(auto x:v){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends