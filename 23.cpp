#include <iostream>
using namespace std;

class Solution{
public:
    int getPairsCount(int arr[], int n, int k) {
        int hash[int(2e6)] = {0};
        for(int i=0; i<n; i++){
            hash[arr[i]]++;
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            if(arr[i] < k){
                cnt += hash[k - arr[i]];
            }
            // if(k  == 2*arr[i]){
            //     cnt += 2*(hash[arr[i]] - 1);
            //     hash[arr[i]]--;
            //     continue;
            // }
            if(k -arr[i] == arr[i]){
                cnt--;
            }
        }
        return cnt/2;
    }
};

// { Driver Code Starts.

int main() {
    freopen("23.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}  // } Driver Code Ends