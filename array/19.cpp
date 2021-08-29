#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    static bool compareInterval(vector<int> v1, vector<int> v2){
        return v1[0] <= v2[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) { 
        // cout << "len = " << intervals.size() << endl;
        vector<vector<int> > v;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int maxEnd = intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] <= maxEnd){
                maxEnd = max(maxEnd, intervals[i][1]);
            }else{
                v.push_back({start, maxEnd});
                start = intervals[i][0];
                maxEnd = intervals[i][1];
            }
        }
        v.push_back({start, maxEnd});
        return v;
    }
};

// { Driver Code Starts.
int main() {
    freopen("19.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n,start, end;
        cin>>n;
        vector<vector<int> > v(n);
        for(int i=0; i<n; i++){
            cin >> start >> end;
            v[i].push_back(start);
            v[i].push_back(end);
        }
        Solution obj;
        vector<vector<int> > answer = obj.merge(v);
        for(auto x:answer){
            for(auto y:x)
                cout << y << " ";
            cout << endl;
        }
    }
    return 0;
}  // } Driver Code Ends