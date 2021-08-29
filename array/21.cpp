#include <iostream>

using namespace std;

// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.
/*   Naive approach  O(N) */
// long long inversionCount(long long arr[], long long N)
// {
//     long long count = 0;
//     for(int i=0; i<N-1; i++){
//         for(int j = i+1; j<N;j++){
//             if(arr[j] < arr[i]){
//                 count++;
//             }
//         }
//     }
//     return count;
// }
class Solution{
public:
    long long int merge(long long arr[], long long left, long long mid, long long right){
        long long cnt = 0;
        long long l1 = mid-left+1;
        long long l2 = right - mid;
        long long arr1[l1], arr2[l2];
        for(long long i=left; i<=mid; i++){
            arr1[i-left] = arr[i];
        }
        for(long long i=mid+1; i<=right; i++){
            arr2[i-mid-1] = arr[i];
        }
        long long i = 0, j = 0, k = left;
        while((i < l1) && (j < l2)){
            if(arr1[i] <= arr2[j]){
                arr[k++] = arr1[i++];
            }else{
                arr[k++] = arr2[j++];
                cnt += l1-i;
            }
        }
        while(i < l1){
            arr[k++] = arr1[i++];
        }
        while(j < l2){
            arr[k++] = arr2[j++];
        }
        return cnt;
    }

    long long int mergeSort(long long arr[], long long left, long long right){
        long long inversionCount = 0;
        if(left < right){
            long long mid = (left+right)/2;
            inversionCount += mergeSort(arr, left, mid);
            inversionCount += mergeSort(arr, mid+1, right);
            inversionCount += merge(arr, left, mid, right);
        }
        return inversionCount;

    }

    // O(NlogN)
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr, 0, N-1);
    }
};


// { Driver Code Starts.

int main() {
    freopen("21.txt","r", stdin);
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}