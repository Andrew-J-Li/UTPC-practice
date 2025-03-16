#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> graph(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    std::vector<bool> visited(n + 1, false);
    std::vector<int> parent(n + 1, -1);
    std::queue<int> q;
    
    q.push(1);
    visited[1] = true;
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        
        if (current == n) {
            break;
        }
        
        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;
                q.push(neighbor);
            }
        }
    }
    
    if (!visited[n]) {
        std::cout << "IMPOSSIBLE" << std::endl;
        return 0;
    }
    
    std::vector<int> path;
    int current = n;
    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }
    
    std::cout << path.size() << std::endl;
    
    for (int i = path.size() - 1; i >= 0; i--) {
        std::cout << path[i];
        if (i > 0) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    
    return 0;
}