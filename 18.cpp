#include <iostream>
#include <climits>
using namespace std;

class Solution{
public:    
    int maxSubarraySum(int a[], int size)
    {
        // int max_so_far = INT_MIN, max_ending_here = 0;
    
        // for (int i = 0; i < size; i++)
        // {
        //     max_ending_here = max_ending_here + a[i];
        //     if (max_so_far < max_ending_here)
        //         max_so_far = max_ending_here;
    
        //     if (max_ending_here < 0)
        //         max_ending_here = 0;
        // }
        // return max_so_far;

        int curr_max = a[0], max_so_far = a[0];
        for(int i=1; i<size; i++){
            curr_max = max(a[i], curr_max + a[i]);
            max_so_far = max(curr_max, max_so_far);
        }
        return max_so_far;
        
    }

    int maxSubArraySum(int a[], int size){
        int max_so_far = INT_MIN, max_ending_here = 0, start =0, end = 0, s=0;
 
        for (int i=0; i< size; i++ )
        {
            max_ending_here += a[i];
 
            if (max_so_far < max_ending_here)
            {
                max_so_far = max_ending_here;
                start = s;
                end = i;
            }
 
            if (max_ending_here < 0)
            {
                max_ending_here = 0;
                s = i + 1;
            }
        }
        cout << "Maximum contiguous sum is " << max_so_far << endl;
        cout << "Starting index "<< start << endl << "Ending index "<< end << endl;
        return max_so_far;

        // int max_so_far = a[0];
        // int curr_max = a[0];
        // int start = 0, end = 0;
        // for (int i = 0; i < size; i++)
        // {
        //     // curr_max   =  max(a[i], curr_max + a[i]);
        //     if(a[i] >= curr_max + a[i] ){
        //         if(a[i] > 0)
        //             start = i;
        //         curr_max = a[i];
        //     }else{
        //         curr_max = curr_max + a[i];
        //     }
        //     if(curr_max >= max_so_far){
        //         end = i;
        //         max_so_far = curr_max;
        //     }
        //     // max_so_far =  max(max_so_far, curr_max);
        // }
        // cout << "start: " << start << endl;
        // cout << "end: " << end << endl;
        // return max_so_far;
    }

};
int main()
{
    freopen("13_inp.txt","r",stdin);
    int t,n;
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        cin>>n; //input size of array
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        Solution ob;
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}