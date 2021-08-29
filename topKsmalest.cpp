#include <iostream>
#include <queue>

using namespace std;

int main(){
    int arr[] = {1, 3, 19, -19, 40 , 12, -21, 24, 13};
    int size = sizeof(arr)/sizeof(arr[0]);
    priority_queue<int> pq;
    int k;
    cout << "Enter value of k: ";
    cin >> k;
    int cs = 0;
    for(int i=0; i<size; i++){
        if(cs < k){
            pq.push(arr[i]);
            cs++;
        }else if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    cout << k << " smallest elements are: ";
    while(!pq.empty()){
        cout << pq.top() << ", ";
        pq.pop();
    }
    cout << endl;

    //  int arr[] = {1, 3, 19, -19, 40 , 12, -21, 24, 13};
    // int size = sizeof(arr)/sizeof(arr[0]);
    // priority_queue<int, vector<int>, greater<int> > pq;
    // int k;
    // cout << "Enter value of k: ";
    // cin >> k;
    // int cs = 0;
    // for(int i=0; i<size; i++){
    //     pq.push(arr[i]);
    // }

    // cout << k << " smallest elements are: ";
    // while(cs < k && !pq.empty()){
    //     cout << pq.top() << ", ";
    //     pq.pop();
    //     cs++;
    // }
    // cout << endl;
}