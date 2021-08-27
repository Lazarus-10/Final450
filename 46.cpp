// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    int median(vector<vector<int>> &matrix, int r, int c)
    {
        int n = r * c;
        int minm = INT_MAX;
        int maxm = INT_MIN;
        for (int i = 0; i < r; i++)
        {
            minm = min(minm, matrix[i][0]);
            maxm = max(maxm, matrix[i][c - 1]);
        }
        while (minm <= maxm)
        {
            int mid = (minm + maxm) / 2;
            int cnt = 0;
            for (int i = 0; i < r; i++)
            {
                cnt += upper_bound(matrix[i].begin(), matrix[i].begin() + c, mid) - matrix[i].begin();
            }
            if (cnt <= n / 2)
            {
                minm = mid + 1;
            }
            else
            {
                maxm = mid - 1;
            }
        }
        return minm;
    }
};

// { Driver Code Starts.

int main()
{
    freopen("46.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        cout << obj.median(matrix, r, c) << endl;
    }
    return 0;
} // } Driver Code Ends