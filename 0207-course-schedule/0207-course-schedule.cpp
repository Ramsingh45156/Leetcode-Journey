class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {

        vis[node] = 1; // Visiting
        for (int nei : adj[node]) {
            if (vis[nei] == 0) {
                if (!dfs(nei, adj, vis))
                    return false;
            }
            else if (vis[nei] == 1) {
                return false; // Cycle found
            }
        }
        vis[node] = 2; // Visited
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites) {
            int course = p[0];
            int pre = p[1];
            adj[pre].push_back(course);
        }
        vector<int> vis(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            if (vis[i] == 0) {
                if (!dfs(i, adj, vis))
                    return false;
            }
        }
        return true;
    }
};