#include <iostream>
#include <map>
using namespace std;
int Kth_smallest(map<int, int> m, int k)
{
	int freq = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		freq += (it->second);
		if (freq >= k)
		{
			return it->first;
		}
	}
	return -1;
}

int main()
{
	int arr[] = {1, -2, 3, 19, -19, 40 , 12, -21, 24, 13, -8};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k;
    cout << "Enter the value of K: ";
    cin >> k;
	map<int, int> mp;
	for (int i = 0; i < size; i++){
		mp[arr[i]] += 1;
	}
	cout << k << "th smallest element is " << Kth_smallest(mp, k) << endl;
	return 0;
}
