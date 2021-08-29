#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfitBruteForce(vector<int>& prices) {
        int profit = 0;
        for(int i=0; i<prices.size() - 1; i++){
            for(int j=i+1; j<prices.size(); j++){
                if((prices[j] - prices[i]) > profit){
                    profit = prices[j] - prices[i];
                }
            }
        }
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)return 0;
        int maxProfitSoFar = 0, currProfit = 0;
        int buy = prices[0];
        for(int i=1; i<n; i++){
            maxProfitSoFar = max(maxProfitSoFar, prices[i]-buy);
            if((prices[i] - buy) < 0){
                buy = prices[i];
            }
        }
        return maxProfitSoFar;

    }
    //  https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
    int maxProfitMult(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1)return 0;
        int maxProfitSoFar = 0, netProfit = 0;
        for(int i=0; i<n-1; i++){
            int buy = prices[i];
            netProfit += max(0, prices[i+1]-buy);
        }
        return netProfit;

    }
};

int main(){
    freopen("22.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n;
        vector<int> v;
        for(int i=0; i<n; i++){
            cin >> x;
            v.push_back(x);
        }
        Solution obj;
        cout << obj.maxProfit(v) << endl;
    }
    return 0;
}