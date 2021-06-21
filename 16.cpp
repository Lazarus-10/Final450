#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Array modified,sorted: Time : O(nlogn)
    int findDuplicate1(vector<int>& nums) {
        sort(nums.begin(),nums.end() );
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]){
                return nums[i];
            }
        }
        return 0;
    }

    // Array modified: Time : O(n)
    int findDuplicate2(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            if(nums[abs(nums[i])] < 0)
                return abs(nums[i]);
            nums[nums[i]] *= -1;
        }
        return 0;
    }

    // Memory used
    int findDuplicate3(vector<int>& nums) {
        unordered_map<int, bool> mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(nums[i]) == mp.end()){
               mp[nums[i]] = true;
               continue;
            }
            return nums[i];
        }
        return 0;
    }

    //Time Complexity: O(n), Auxiliary Space: O(1)
    int findDuplicate(vector<int> &nums){
        int tortoise = nums[0];
        int hare = nums[0];
        do{
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
        }while(tortoise != hare);
        int itr1 = nums[0];
        int itr2 = tortoise;  // or hare(as both are at same position now)
        while(itr1 != itr2){
            itr1 = nums[itr1];
            itr2 = nums[itr2];
        }
        return itr1; // or itr2(as both are at same positions where cycle started)
    }

};

int main(){
    freopen("16.txt", "r", stdin);
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
        cout<<obj.findDuplicate3(v) <<endl;
    }
    return 0;
}