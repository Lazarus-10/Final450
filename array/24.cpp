#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution
{
public:    
    // using set
    vector<int> commonElements1(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        set <int> st(A, A+n1);
        vector<int> res;
        for(int i=0; i<n2; i++){
            if(st.count(B[i])){
                res.push_back(B[i]);
                st.erase(B[i]);
            }
        }
        set<int> st2(res.begin(), res.end());
        res.clear();
        for(int i=0; i<n3; i++){
            if(st2.count(C[i])){
                res.push_back(C[i]);
                st2.erase(C[i]);
            }
        }
        return res;
    }

    // without any data structure
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        vector<int> res;
        int i = 0, j = 0, k = 0;
        while(i<n1 && j<n2 && k<n3){
            if(A[i] == B[j] && B[j] == C[k]){
                res.push_back(A[i]);
                i++;
                j++; 
                k++;
            }
            else if(A[i] <= B[j] && A[i] <= C[k]){
                i++;
            }else if(B[j] <= C[k] && B[j] <= A[i]){
                j++;
            }else{
                k++;
            }
            while(i>0 && i<n1 && A[i] == A[i-1])i++;
            while(i>0 && i<n2 && B[j] == B[j-1])j++;
            while(i>0 && i<n3 && C[k] == C[k-1])k++;
        }
        return res;
    }

};

// { Driver Code Starts.

int main ()
{
    freopen("24.txt", "r", stdin);
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  // } Driver Code Ends