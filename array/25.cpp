#include <iostream>

using namespace std;

class Solution{
public:    
    void rearrange(int arr[], int n){
        int i=0, j = n-1;
        while(i<j){
            while(i < n && arr[i] >= 0)
                i++;
            while(j >= 0 && arr[j] < 0)
                j--;
            if(i < j){
                swap(arr[i], arr[j]);
            }
        }
        j = 0;
        for(; j<i && i < n; j+=2){
            swap(arr[j], arr[i]);
            i++;
        }
    }
};
int main(){
    freopen("25.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin >> arr[i];
        Solution obj;
        obj.rearrange(arr, n);
        for(int i=0; i<n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

}