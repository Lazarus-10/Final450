#include <iostream>

using namespace std;

void sort012(int arr[], int size){
    int i = 0, j= size-1, k = i;
    while(k <= j){
        if(arr[k] == 2){
            swap(arr[k], arr[j--]);
        }
        else if(arr[k] == 0){
            swap(arr[i++], arr[k++]);
        }else{
            k++;
        }
    }
}

int main(){
    int arr[] = {2, 1, 2, 0, 1, 0, 2};
    // int arr[] = {0, 2, 1, 2, 0};
    int size = sizeof(arr)/sizeof(arr[0]);
    sort012(arr,size);
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}