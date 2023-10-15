#include <iostream>
#include <vector>

using namespace std;

const int INF = INT_MAX;

int minCostMultistageGraph(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> dp(n, INF);

    // Initialize the last stage with a cost of 0.
    dp[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (graph[i][j] != -1) {
                dp[i] = min(dp[i], graph[i][j] + dp[j]);
            }
        }
    }

    return dp[0];
}

int main() {
    vector<vector<int>> graph = {
        {-1, 1, 2, 5, -1, -1},
        {-1, -1, -1, -1, 4, 11},
        {-1, -1, -1, -1, 9, 5},
        {-1, -1, -1, -1, -1, 3},
        {-1, -1, -1, -1, -1, 4},
        {-1, -1, -1, -1, -1, -1}
    };

    int minCost = minCostMultistageGraph(graph);
    cout << "Minimum cost in the multistage graph: " << minCost << endl;

    return 0;
}
