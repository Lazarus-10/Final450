#include <iostream>
#include <algorithm>

using namespace std;
class Solution{
public:    
    int getMinDiff(int arr[], int n, int k){
        sort(arr, arr + n);
        int minEle, maxEle;
        int ans = arr[n-1] - arr[0];
        for(int i=0; i < n-1; i++){
            minEle = min(arr[0]+k, arr[i+1]-k);
            maxEle = max(arr[i]+k, arr[n-1]-k);
            if(minEle < 0){
                continue;
            }
            ans = min(ans, maxEle - minEle);
        }
        return ans;
    }
};

int main(){
    freopen("14_inp.txt","r",stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}