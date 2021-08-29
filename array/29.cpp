#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq1(int arr[], int N)
    {
        set<int> st;
        for(int i=0; i<N; i++)
            st.insert(arr[i]);
        int prev = -2;
        int maxLength = 0;
        int currLength = 0;
        for(auto it = st.begin(); it != st.end(); it++){
            if((*it - prev) != 1){
                currLength = 0;
            }else{
                currLength++;
                maxLength = max(maxLength, currLength);
            }
            prev = *it;
        }
        return maxLength+1;
    }
    //better
    int findLongestConseqSubseq(int arr[], int N)
    {
        unordered_set<int> st;
        int ans = 1;
        for(int i=0; i<N; i++)
            st.insert(arr[i]);
        for(int i=0; i<N; i++){
            if(st.find(arr[i] - 1) == st.end()){
                int j = arr[i];
                while(st.find(j) != st.end()){
                    j++;
                }
                ans = max(ans, j - arr[i]);
            }
        }
        return ans;
    }
};

 
// Driver program
int main()
{
    freopen("29.txt", "r", stdin);
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.findLongestConseqSubseq(a, n) << endl;
    }
      
    return 0;
}