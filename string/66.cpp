// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
private:    
    void _find_permutation(string S, vector<string> &ans, const int &n, int l){
        if(l == n-1)ans.push_back(S);
        else{
            for(int k = l; k<n; k++){
                swap(S[l], S[k]);
                _find_permutation(S, ans, n, l+1);
                swap(S[k], S[l]);
            }
        }
    }
public:
    vector<string>find_permutation(string S)
    {
        vector<string> ans;
        _find_permutation(S, ans, S.length(), 0);
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
	    vector<string> ans = ob.find_permutation(S);
        cout << "---------------" << endl;
	    for(auto i: ans)
	    {
	    	cout<<i<<endl;
	    }
    }
	return 0;
}
  // } Driver Code Ends