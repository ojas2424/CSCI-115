#include <bits/stdc++.h>
using namespace std;

void paraBrack(int t, int u, int s, int* para, char& matName)
{
    if (t == u) {
        cout << matName++;
        return;
    }

    cout << "(";
    paraBrack(t, *((para + t * s) + u), s,
        para, matName);

    paraBrack(*((para + t * s) + u) + 1, u, s,
        para, matName);
    cout << ")";
}

void matMultiplyOrder(int arr[], int n)
{
    int mat[n][n];

    int paranthesis[n][n];
    for (int i = 1; i < n; i++)
        mat[i][i] = 0;

    for (int x = 2; x < n; x++)
    {
        for (int y = 1; y < n - x + 1; y++)
        {
            int j = y + x - 1;
            mat[y][j] = INT_MAX;
            for (int z = y; z <= j - 1; z++)
            {
                int q = mat[y][z] + mat[z + 1][j]
                    + arr[y - 1] * arr[z] * arr[j];
                if (q < mat[y][j])
                {
                    mat[y][j] = q;
                    paranthesis[y][j] = z;
                }
            }
        }
    }
    char name = 'A';

    cout << "best paranthesis order : ";
    paraBrack(1, n - 1, n, (int*)paranthesis, name);
    cout << endl;
    cout << "best number of multiplication : " << mat[1][n - 1];
}

int main()
{
    int a[] = { 1, 2, 3, 4, 3 };
    int n = sizeof(a) / sizeof(a[0]);
    matMultiplyOrder(a, n);
    return 0;
}