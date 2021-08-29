#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
   
public:
    // O(n^2)
	void merge(int arr1[], int arr2[], int n, int m) {
        for(int i=0; i<n; i++){
            if(arr1[i] > arr2[0]){
                swap(arr1[i], arr2[0]);
                // sort(arr2, arr2 + m);
                int j=1;
                int num = arr2[0];
                for(; j<m && arr2[j] < num; j++){
                    arr2[j-1] = arr2[j];
                }
                arr2[j-1] = num;
                
            }
        }
	}

    // Time: O(n), Space: O(m+n)
    void merge2(int arr1[], int arr2[], int n, int m) {
        int arr[m+n];
        int i=0, j=0, k=0;
        while(i < n && j < m){
            if(arr1[i] < arr2[j]){
                arr[k++] = arr1[i++];
            }else{
                arr[k++] = arr2[j++];
            }
        }

        while(i < n){
            arr[k++] = arr1[i++];
        }
        while(j < m){
            arr[k++] = arr2[j++];
        }

        for(int i=0; i<n; i++){
            arr1[i] = arr[i];
        }
        for(int i=n, j=0; j<m; j++,i++){
            arr2[j] = arr[i];
        }
	}

    void merge3(int arr1[], int arr2[], int n, int m) {
       int i=n-1, j=0;
       while(i >=0 && j < m){
           if(arr1[i] > arr2[j]){
               swap(arr1[i], arr2[j]);
           }
            i--;
            j++;
       }
       sort(arr1, arr1+n);
       sort(arr2, arr2+m);
	}


};

// { Driver Code Starts.
int main() {
    freopen("17.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge3(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends