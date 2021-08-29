// C++ program to find number of operations
// to make an array palindrome
#include <iostream>
using namespace std;

// Returns minimum number of count operations
// required to make arr[] palindrome
int findMinOps(int arr[], int n)
{
	int ans = 0;
    int start = 0, end = n-1;
    while(start <= end){
        if(arr[start] == arr[end]){
            start++, end--;
        }
        else if(arr[start] > arr[end]){
            end--;
            arr[end] += arr[end+1];
            ans++;
        }
        else{
            start++;
            arr[start] += arr[start-1];
            ans++;
        }
    }
    return ans;
}

// Driver program to test above
int main()
{
	int arr[] = {1, 4, 5, 9, 1};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Count of minimum operations is "
		<< findMinOps(arr, n) << endl;
	return 0;
}
