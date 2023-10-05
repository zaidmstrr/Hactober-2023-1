#include <vector>
#include <queue>
// Shortest Path in Binary Matrix
using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 0) return -1;
    int m = grid[0].size();
    
    // Check if the start or end cell is blocked
    if (grid[0][0] == 1 || grid[n-1][m-1] == 1) return -1;
    
    // Define eight possible directions (up, down, left, right, diagonals)
    vector<int> dirX = {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int> dirY = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    // Create a queue for BFS
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    // Initialize the distance array
    vector<vector<int>> distance(n, vector<int>(m, -1));
    distance[0][0] = 1;
    
    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        int x = current.first;
        int y = current.second;
        
        // If we reach the destination, return the distance
        if (x == n - 1 && y == m - 1) {
            return distance[x][y];
        }
        
        // Explore all eight possible directions
        for (int i = 0; i < 8; ++i) {
            int newX = x + dirX[i];
            int newY = y + dirY[i];
            
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 0 && distance[newX][newY] == -1) {
                distance[newX][newY] = distance[x][y] + 1;
                q.push({newX, newY});
            }
        }
    }
    
    // If we cannot reach the destination
    return -1;
}
