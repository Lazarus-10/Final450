#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid, int i=0, int j=0) {
        static int ans = 0;
        int n = grid.size();
        if(i >=n || j>=n)return 0;
        if(grid[i][j] == -1) return -1;
        if(i==n-1 && j==n-1)return ans + grid[i][j];
        int t = max(cherryPickup(grid, i+1, j) , cherryPickup(grid, i, j+1));
        if( t == -1)return ans;
        return ans + grid[i][j] + t;
    }
};

int main(){
    freopen("cherry.txt", "r", stdin);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.cherryPickup(grid) << endl;
    }
    return 0;
}