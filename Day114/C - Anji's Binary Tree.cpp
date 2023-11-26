// failed on pretest 2
#include <bits/stdc++.h>
using namespace std;

int min_tree_operations(int cur, string &s, vector<pair<int, int>> &tree) {
    if (cur == -1) {
        return INT_MAX;
    }

    if (tree[cur] == make_pair(-1, -1)) {
        return 0;
    }

    int l = min_tree_operations(tree[cur].first, s, tree);
    int r = min_tree_operations(tree[cur].second, s, tree);

    if (s[cur] == 'L') {
        return min(l, r + 1);
    } else if (s[cur] == 'R') {
        return min(r, l + 1);
    } else {
        return min(l, r) + 1;
    }
}

int solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<pair<int, int>> tree;
    for (int i = 0; i < n; i++) {
        int left, right;
        cin >> left >> right;
        tree.push_back({left - 1, right - 1});
    }

    return min_tree_operations(0, s, tree);
}

int main() {
    int t;
    cin >> t;
    vector<int> ans;
    for (int i = 0; i < t; i++) {
        ans.push_back(solve());
    }
    for (int i = 0; i < t; i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
