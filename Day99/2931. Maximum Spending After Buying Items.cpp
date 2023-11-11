class Solution {
public:
    long long maxSpending(std::vector<std::vector<int>>& values) {
        vector<int> flat;
        for (const auto &row : values) {
            flat.insert(flat.end(), row.begin(), row.end());
            flat.push_back(row);
        }

        sort(flat.begin(), flat.end());

        long long total_values = 0;
        for (int day = 1; day <= flat.size(); ++day) {
            total_values += static_cast<long long>(flat[day - 1]) * day;
        }

        return total_values;
    }
};