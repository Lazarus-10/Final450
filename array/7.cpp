#include <iostream>
using namespace std;

// taking first of the pair as minimum and second as maximum
pair<int, int> getMinMax(int arr[], int n){
    int i;
    pair<int, int> minmax;
    if(n%2){
        minmax.first = minmax.second = arr[0];
        i = 1;
    }else{
        minmax.first = (arr[0] < arr[1]) ? arr[0] : arr[1];
        minmax.second = (arr[0] < arr[1]) ? arr[1] : arr[0];
        i = 2;
    }

    // Now we are left with even number of elements from i
    for(; i < n-1; i += 2){
        if(arr[i] > arr[i+1]){
            if(arr[i] > minmax.second)
                minmax.second = arr[i];
            if(arr[i + 1] < minmax.first)
                minmax.first = arr[i+1];
        }else{
            if(arr[i+1] > minmax.second)
                minmax.second = arr[i+1];
            if(arr[i] < minmax.first)
                minmax.first = arr[i];
        }
    }
    return minmax;
}

int main()
{
    int arr[] = {1, -2, 3, 19, -19, 40 , 12, -21, 24, 13, -8};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    pair<int, int> minmax = getMinMax(arr, arr_size);
    cout << "Minimum element is " << minmax.first << endl;
    cout << "Maximum element is " << minmax.second << endl;
    return 0;
}