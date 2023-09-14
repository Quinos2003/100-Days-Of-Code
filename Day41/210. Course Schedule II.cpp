class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> indegree(n,0);
        vector<int> adj[n];
        vector<int> ans; // topo
        for(auto x : prerequisites){
            adj[x[1]].push_back(x[0]);
            indegree[x[0]]++;
        }

        queue<int> q ;

        for(int i =0 ; i < n ; i ++){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int t = q.front();
            q.pop();
            ans.push_back(t);

            for(auto x : adj[t]){
                indegree[x]--;
                if(indegree[x]==0) q.push(x);
            }
        }
        if (ans.size() == n) return ans;
		return {};
        // return ans;
    }
};