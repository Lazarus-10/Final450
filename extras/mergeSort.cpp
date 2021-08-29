#include <iostream>

using namespace std;
void merge(int arr[], int left, int mid, int right){
    int l1 = mid-left+1;
    int l2 = right - mid;
    int arr1[l1], arr2[l2];
    for(int i=left; i<=mid; i++){
        arr1[i-left] = arr[i];
    }
    for(int i=mid+1; i<=right; i++){
        arr2[i-mid-1] = arr[i];
    }
    int i = 0, j = 0, k = left;
    while((i < l1) && (j < l2)){
        if(arr1[i] < arr2[j]){
            arr[k++] = arr1[i++];
        }else{
            arr[k++] = arr2[j++];
        }
    }
    while(i < l1){
        arr[k++] = arr1[i++];
    }
    while(j < l2){
        arr[k++] = arr2[j++];
    }
}

void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = (left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }

}
int main(){
    int arr[] = {55, -9, -3, 0, 12, -11, 21, 4, 22};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, size-1);
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}