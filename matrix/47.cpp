// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
    int first(vector<int> arr){
        int low = 0, high = arr.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] == 1 && arr[mid -1] == 0){
                return mid;
            }else if(arr[mid] == 0){
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return -1;
    }
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int row = arr.size(), col = arr[0].size();
	    int index = 0;
	    int max = -1;
	    int max_row_index = -1;
	    for(int i=0;i<row; i++){
	        index = first(arr[i]);
	        if(index != -1 && col - index > max){
	            max = col - index;
	            max_row_index = i;
	        }
	    }
	    return max_row_index;
	}

    // solution 2
    int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int ans = -1;
	    int i=0, j = m-1;
	    while(i < n && j >= 0){
	        if(arr[i][j] == 0){
	            i += 1;
	        }else{
	            j -= 1;
	            ans = i;
	        }
	    }
	    return ans;
	    
	}

};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends