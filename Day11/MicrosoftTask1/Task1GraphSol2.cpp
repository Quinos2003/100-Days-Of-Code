#include <bits/stdc++.h>
using namespace std;

int solution(int N, vector<int> &A, vector<int> &B)
{
    vector<pair<int, int>> p;
    for (int i = 0; i < A.size(); i++)
    {
        p.push_back(make_pair(A[i], B[i]));
    }
    vector<int> edges(N, 0);
    for (auto i : p)
    {
        edges[i.first]++;
        edges[i.second]++;
    }
    int cnt = 0;

    while (*min_element(edges.begin(), edges.end()) < 2)
    {
        int flag = 0;
        vector<int> st;
        for (int i = 0; i < N; i++)
        {
            if (edges[i] < 2)
            {
                edges[i] = INT_MAX;
                flag = 1;
                for (int j = 0; j < p.size(); j++)
                {
                    if (p[j].first == i)
                    {
                        st.push_back(p[j].second);
                        p.erase(p.begin() + j);
                    }
                    if (p[j].second == i)
                    {
                        st.push_back(p[j].first);
                        p.erase(p.begin() + j);
                    }
                }
            }
        }
        for(auto x: st)
        {
            edges[x]--;
        }
        if (flag == 1)
        {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int N = 7;
    vector<int> A = {0, 1, 2, 1 , 4, 4};
    vector<int> B = {1, 2, 0, 4, 5, 6};
    cout << solution(N, A, B) << endl;
    return 0;
}
