#include <iostream>

using namespace std;

void moveAllNegative(int arr[], int size){
    for(int i=0, j=1; j<size; j++){
        if(arr[j] < 0){
            swap(arr[i++], arr[j]);
        }
    }
}

int main(){
    int arr[] = {-12, 11, -13, -5, 6, -7, 5, -3, -6};
    int size = sizeof(arr)/sizeof(arr[0]);
    moveAllNegative(arr, size);
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}