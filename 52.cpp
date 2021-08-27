// { Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include <iostream>
#include <queue>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];

struct CustomCompare
{
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs)
    {
        return mat[lhs.first][lhs.second] > mat[rhs.first][rhs.second];
    }
};

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue< pair<int, int> , vector<pair<int, int> >, CustomCompare > pq;
    
    for(int i=0; i<n; i++){
        pq.push({0, i});
    }
    for(int i = 1; i<k; i++){
        auto p = pq.top();
        pq.pop();

        if(p.first + 1 < n) pq.push({p.first+1, p.second});
    }
    return mat[pq.top().first][pq.top().second];
}
// driver program to test above function
int main()
{
    freopen("52.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}
// } Driver Code Ends




