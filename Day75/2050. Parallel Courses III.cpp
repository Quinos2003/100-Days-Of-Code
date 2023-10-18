class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        // Basically need to find the longest path
        // Topo sort obviously 
        vector<int> inDegree(n);
        vector<vector<int>> graph(n, vector<int>());
        for (auto& edge : relations) {
            int row = edge[0] - 1, col = edge[1] - 1;
            graph[row].push_back(col);
            inDegree[col]++;
        }

        vector<int> dist(n);
        queue<int> q;

        for (int u = 0; u < n; u++) {
            if (inDegree[u] == 0) {
                q.push(u);
                dist[u] = time[u];
            }
        }
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            for (int v : graph[u]) {
                dist[v] = max(dist[v], dist[u] + time[v]);
                if (--inDegree[v] == 0) 
                    q.push(v);
            }
        }
        int mx =0;
        for( int i =0 ; i < n ; i ++) mx= max(mx,dist[i]);
        return mx;
    }
};