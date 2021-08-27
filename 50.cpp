#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotate90Clockwise(vector<vector<int>> &arr)
{
    int row = arr.size();
    int col = arr[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = i; j < col; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    for (int i = 0; i < row; i++)
    {
        reverse(arr[i].begin(), arr[i].end());
    }
}

void rotate90Clockwise2(vector<vector<int>> &arr)
{
    int N = arr.size();
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j >= 0; j--)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }
}

void printMatrix(vector<vector<int>> arr)
{
    for (auto x : arr)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}

int main()
{
    int N = 4;
    vector<vector<int>> arr{{1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12},
                            {13, 14, 15, 16}};
    rotate90Clockwise(arr);
    printMatrix(arr);
    return 0;
}