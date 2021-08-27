#include <iostream>
using namespace std;

int main()
{
    int *x, *y, *z, *a, b[3] = {2, 4, 6};
    a = new int[3]; //creating an array of 3 elements
    x = a;
    for (int k = -2; k < 1; k++)
    {
        a[k + 2] = (k + 3) % 3 + 2 * k;
        cout << a[k + 2] << "\t";
    }
    z = &b[1];
    y = x + 2;
    cout << endl << *x << "\t" << *y << endl;
    *x = *x - 4;
    cout << *z << endl;
    *(++z) = *(--y) + *x;
    cout << *z << endl;
    *y++ = *&b[2] * (*--z);
    cout << *x << "\t" << *y << endl;
    for (int j = 0; j < 3; j++)
        cout << a[j] << "\t" << b[j] << endl;
    delete[] a;
    x = y = NULL;
    return 0;
}