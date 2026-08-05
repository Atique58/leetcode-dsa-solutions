class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) 
    {
        vector<vector<int>> graph(n);
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            graph[u].push_back(v); 
        }

        vector<bool> suspicious(n, false);
        queue<int> q;

        q.push(k);
        suspicious[k] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int neighbor : graph[current]) {
                if (!suspicious[neighbor]) {
                    suspicious[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        for (int u = 0; u < n; ++u) 
        {
            if (!suspicious[u]) 
            {
                for (int v : graph[u]) 
                {
                    if (suspicious[v]) 
                    {
                        vector<int> all_methods(n);
                        for (int i = 0; i < n; ++i) 
                        {
                            all_methods[i] = i;
                        }
                        return all_methods;
                    }
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) 
        {
            if (!suspicious[i]) 
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};