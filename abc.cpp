#include <bits/stdc++.h>
using namespace std;

vector<int> getValidPaths(int route_nodes, vector<int> route_from,
                          vector<int> route_to, vector<int> route_weight,
                          vector<int> query_from, vector<int> query_to)
{
    // Create adjacency list with weights
    vector<vector<pair<int, int>>> graph(route_nodes + 1);
    for (int i = 0; i < route_from.size(); i++)
    {
        graph[route_from[i]].push_back({route_to[i], route_weight[i]});
        graph[route_to[i]].push_back({route_from[i], route_weight[i]});
    }

    // DFS function to count paths
    function<int(int, int, int, vector<bool> &)> dfs =
        [&](int curr, int target, int reqWeight, vector<bool> &visited)
    {
        if (curr == target)
            return 1;

        int paths = 0;
        visited[curr] = true;

        for (auto &[next, weight] : graph[curr])
        {
            if (!visited[next] && (reqWeight == -1 || weight == reqWeight))
            {
                paths += dfs(next, target, weight == reqWeight ? reqWeight : weight, visited);
            }
        }

        visited[curr] = false;
        return paths;
    };

    // Process each query
    vector<int> results;
    for (int i = 0; i < query_from.size(); i++)
    {
        vector<bool> visited(route_nodes + 1, false);
        results.push_back(dfs(query_from[i], query_to[i], -1, visited));
    }

    return results;
}

int main()
{
    // Example from the problem
    int n = 3; // nodes
    vector<int> route_from = {1, 1, 1, 2, 2, 3};
    vector<int> route_to = {2, 2, 3, 1, 3, 2};
    vector<int> route_weight = {2, 1, 3, 1, 3, 1};

    // Queries
    vector<int> query_from = {1, 1, 2};
    vector<int> query_to = {2, 3, 3};

    vector<int> results = getValidPaths(n, route_from, route_to, route_weight,
                                        query_from, query_to);

    // Print results
    for (int i = 0; i < results.size(); i++)
    {
        cout << "Valid paths from " << query_from[i]
             << " to " << query_to[i] << ": "
             << results[i] << endl;
    }

    return 0;
}
