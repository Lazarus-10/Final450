#include <iostream>
using namespace std;


void permute(string str, int l, int r){
    if(l == r)cout << str << endl;
    else{
        for(int i=l; i<=r; i++){
            swap(str[i], str[l]);
            permute(str, l+1, r);
            swap(str[i], str[l]);
        }
    }
}
int main()
{
    string str = "ABC";
    int n = str.size();
    permute(str, 0, n-1);
    return 0;
}