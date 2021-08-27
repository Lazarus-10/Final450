// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        int left[n], right[n];
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && (arr[i] <= arr[st.top()]))
            {
                st.pop();
            }
            if (st.empty())
            {
                left[i] = 0;
            }
            else
            {
                left[i] = st.top() + 1;
            }
            st.push(i);
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << left[i] << " ";
        // }
        // cout << endl;
        while (!st.empty())
        {
            st.pop();
        }
        long long int maxArea = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[i] <= arr[st.top()])
            {
                st.pop();
            }
            if (st.empty())
            {
                right[i] = n - 1;
            }
            else
            {
                right[i] = st.top() - 1;
            }
            st.push(i);
            maxArea = max(maxArea, (right[i] - left[i] + 1) * arr[i]);
        }

        return maxArea;
    }
};

// { Driver Code Starts.

int main()
{
    freopen("maxRect.txt", "r", stdin);
    long long t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends