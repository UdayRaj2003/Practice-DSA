class Solution {
public:
    void f(int src, vector<vector<int>>& adj, vector<bool>& vis) {
        for (int nei : adj[src]) {
            if (vis[nei]) continue;
            vis[nei] = true;
            f(nei, adj, vis);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) { 
        vector<vector<int>> adj(n);
        for (auto &edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }
 
        vector<bool> vis(n, false);
        vis[k] = true;
        f(k, adj, vis);
 
        for (auto &edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!vis[u] && vis[v]) { 
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }
 
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};