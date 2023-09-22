class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];

        for(auto it : flights) adj[it[0]].push_back({it[1],it[2]});
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        // {stops{curr_node, cost}}
        vector<int> dist (n,1e9);
        dist[src]=0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if(stops>k) continue;

            for(auto x : adj[node]){
                int adjNode = x.first;
                int dcost = x.second;
                if(cost+ dcost< dist[adjNode] && stops<=k) {
                    dist[adjNode] = cost+dcost ;
                    q.push({stops+1,{adjNode, dist[adjNode]}});
                }
            }
        }
        if(dist[dst]==1e9) return -1;   
        return dist[dst];
    }
};

