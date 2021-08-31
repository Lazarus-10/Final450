// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    private:

        void _find_subsequences(string S, int l, string tmp, vector<string> &ans){
            if(l == S.size()){
                if(tmp.length())ans.push_back(tmp);
            }
            else{
                _find_subsequences(S, l+1, tmp+S[l], ans);
                _find_subsequences(S, l+1, tmp, ans);
            }
        }
	public:

        vector<string> find_subsequences(string S){
            string temp = "";
            vector<string> ans; 
            _find_subsequences(S, 0, temp, ans);
            return ans;
        }
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_subsequences(S);
        cout << "-----------" << endl;
	    for(auto i: ans)
	    {
	    	cout<<i<<endl;
	    }
    }
	return 0;
}
  // } Driver Code Ends