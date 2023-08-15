#include <bits/stdc++.h>
#include <vector>
using namespace std;

int solution(vector<int> &arr, int X, int Y)
{
    int N = arr.size();
    int minsum = INT_MAX;

    for (int j = 0; j < N - (X * Y); j++)
    {
        int sum = 0;
        int mi = 0;

        for (int i = j; i < N; i += Y)
        {
            if (mi < X)
            {
                sum += arr[i];
                mi++;
            }
        }

        if (mi == X && sum < minsum)
        {
            minsum = sum;
        }
    }
    return minsum;
}

int main()
{
    vector<int> vect{4, 2, 3, 7};
    int x = 2;
    int y = 2;
    cout << solution(vect, x, y) << endl;
    return 0;
}