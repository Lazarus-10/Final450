// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int maxOnTheRow(int *heights, int n){
        stack<int> st;
        int left[n];
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                   st.pop();
            }
            left[i] = (st.empty()) ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        
        int right[n];
        int maxm = 0;
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                   st.pop();
            }
            right[i] = (st.empty()) ? n : st.top();
            st.push(i);
            maxm = max(maxm, heights[i]*(right[i] - left[i] - 1));
        }
        return maxm;
    }
    
    int maxArea(int arr[MAX][MAX], int n, int m) {
        int area = maxOnTheRow(arr[0], m);
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]){
                    arr[i][j] += arr[i-1][j];
                }
            }
            area = max(area, maxOnTheRow(arr[i], m));
        }
        return area;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends