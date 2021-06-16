#include <iostream>
#include <unordered_map>
using namespace std;

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[a[i]]++;
        }
        int count = mp.size();
        for(int i=0; i<m; i++){
            if(mp.find(b[i]) == mp.end()){
                mp[b[i]]++;
                count++;
            }
        }
    
        return count;
    }
};

int main() {
	freopen("11_inp.txt", "r", stdin);
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends