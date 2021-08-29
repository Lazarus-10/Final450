#include <iostream>
#include <algorithm>
using namespace std;

//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(int *arr, int n) {
        long long int maxm = arr[0], minm = arr[0], prod = arr[0];
        for(int i=1; i<n; i++){
            if(arr[i] < 0)
                swap(minm, maxm);
            maxm = max((long long)arr[i], arr[i]*maxm);
            minm = min((long long)arr[i], arr[i]*minm);
            if(maxm > prod)
                prod = maxm;
        }
        return prod;
	}
};

// { Driver Code Starts.

int main() {
    freopen("28.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends