#include <iostream>
using namespace std;

void rotate(int arr[], int n);

int main()
{
    freopen("12_inp.txt", "r", stdin);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[n] , i;
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);
        rotate(a, n);
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}

void rotate(int arr[], int n){
    int last = arr[n-1];
    for(int i=n-1; i > 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = last;
}

void rotate2(int arr[], int n)
{
    int i = 0, j = n-1; // i and j pointing to first and last element respectively
      while(i != j){
      swap(arr[i], arr[j]);
      i++;
    }
}
