class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        queue<pair<int, int>> q;
        unordered_set<int> visited;
        q.push({x, 0});
        visited.insert(x);

        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            int value = current.first;
            int operations = current.second;

            if (value == y) {
                return operations;
            }

            auto tryToAdd = [&](int nextValue) {
                if (visited.find(nextValue) == visited.end()) {
                    q.push({nextValue, operations + 1});
                    visited.insert(nextValue);
                }
            };

            tryToAdd(value + 1);
            tryToAdd(value - 1);

            if (value % 5 == 0) {
                tryToAdd(value / 5);
            }

            if (value % 11 == 0) {
                tryToAdd(value / 11);
            }
        }

        return -1;
    }
};