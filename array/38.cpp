// { Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;


int minSwap(int *arr, int n, int k);

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        cout << minSwap(arr, n, k) << "\n";
    }
	return 0;
}
// } Driver Code Ends


int minSwap(int *arr, int n, int k) {
    int window_size = 0;
    for(int i=0; i<n; i++){
        if(arr[i] <= k)window_size++;
    }
    
    int max_swap = 0;
    for(int i=0; i<window_size; i++){
        if(arr[i] > k)max_swap++;
    }
    int minS = max_swap;
    for(int i=window_size; i<n; i++){
        if(arr[i-window_size] > k){
            max_swap--;
        }
        if(arr[i] > k)max_swap++;
        minS = min(minS, max_swap);
    }
    return minS;
}
