#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

unsigned long long power(unsigned long long base, int exponent, int modulo)
{
    unsigned long long result = 1;
    base = base % modulo;

    while (exponent > 0)
    {
        if (exponent & 1)
            result = (result * base) % modulo;
        exponent = exponent >> 1;
        base = (base * base) % modulo;
    }
    return result;
}

unsigned long long modInverse(unsigned long long num, int modulo)
{
    return power(num, modulo - 2, modulo);
}

unsigned long long nCrModPFermat(unsigned long long n, int r, int modulo)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;

    unsigned long long factorial[n + 1];
    factorial[0] = 1;
    for (int i = 1; i <= n; i++)
        factorial[i] = (factorial[i - 1] * i) % modulo;

    return (factorial[n] * modInverse(factorial[r], modulo) % modulo * modInverse(factorial[n - r], modulo) % modulo) % modulo;
}

void solve()
{
    int rows, cols;
    cin >> rows >> cols;
    string grid[rows];
    for (int i = 0; i < rows; i++)
    {
        cin >> grid[i];
    }
    if (rows == 1)
    {
        cout << 1;
        return;
    }
    set<int> setOfColumns;
    for (int i = 0; i < cols; i++)
    {
        if (grid[rows - 1][i] == '1')
        {
            setOfColumns.insert(i);
        }
    }

    for (int i = rows - 2; i >= 1; i--)
    {
        int onesCount = 0;
        int lastOneColumn = -1;
        for (int j = 0; j < cols; j++)
        {
            if (grid[i][j] == '1')
            {
                onesCount++;
                lastOneColumn = j;
            }
        }
        bool flag = false;
        for (auto column : setOfColumns)
        {
            if (grid[i][column] == '1')
            {
                flag = true;
            }
        }
        if (onesCount <= 1)
        {
            setOfColumns.clear();
        }
        else
        {
            if (!flag)
            {
                setOfColumns.clear();
            }

            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1')
                {
                    setOfColumns.insert(j);
                }
            }
        }
    }
    int onesCountFirstRow = 0;
    for (auto column : setOfColumns)
    {
        if (grid[0][column] == '1')
        {
            onesCountFirstRow++;
        }
    }
    cout << nCrModPFermat(setOfColumns.size(), onesCountFirstRow, MOD);
}

int main()
{
    int ttt;
    cin >> ttt;
    while (ttt--)
    {
        solve();
        cout << endl;
    }
    return 0;
}
