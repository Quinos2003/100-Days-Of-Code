// D. Three Activities
// Winter holidays are coming up. They are going to last for n days.

// During the holidays, Monocarp wants to try all of these activities exactly once with his friends:

// go skiing;
// watch a movie in a cinema;
// play board games.

// Monocarp knows that, on the i
// -th day, exactly ai
//  friends will join him for skiing, bi
//  friends will join him for a movie and ci
//  friends will join him for board games.

// Monocarp also knows that he can't try more than one activity in a single day.

// Thus, he asks you to help him choose three distinct days x,y,z
//  in such a way that the total number of friends to join him for the activities (ax+by+cz) is maximized.


#include <bits/stdc++.h>
using namespace std;
long long n;
pair<long long, long long> A[200010], B[200010], C[200010];

void findMaxSolvable() {
    sort(A + 1, A + n + 1, greater<pair<long long, long long>>());
    sort(B + 1, B + n + 1, greater<pair<long long, long long>>());
    sort(C + 1, C + n + 1, greater<pair<long long, long long>>());

    long long res = 0;
    for (long long x = 1; x <= 3; x++) {
        for (long long y = 1; y <= 3; y++) {
            for (long long z = 1; z <= 3; z++) {
                if (A[x].second != B[y].second and A[x].second != C[z].second and B[y].second != C[z].second) {
                    res = max(res, A[x].first + B[y].first + C[z].first);
                }
            }
        }
    }
    cout << res <<endl;
    
}
int main() {
    long long ttt;
    cin >> ttt;

    while (ttt--) {
        cin >> n;
        for (long long i = 1; i <= n; i++) {
            cin >> A[i].first;
            A[i].second = i;
        }
        for (long long i = 1; i <= n; i++) {
            cin >> B[i].first;
            B[i].second = i;
        }
        for (long long i = 1; i <= n; i++) {
            cin >> C[i].first;
            C[i].second = i;
        }

        findMaxSolvable();
    }

    return 0;
}