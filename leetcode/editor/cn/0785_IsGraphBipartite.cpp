// 2025-09-29 20:21:27
#include <bits/stdc++.h>
#include <DisplayHelper.h>
// #include <ListOperations.h>
// #include <StringOperations.h>
// #include <TreeOperations.h>
// #include <RandomHelper.h>
// #include <ComparatorHelper.h>

using namespace std;
using namespace display;


//There is an undirected graph with n nodes, where each node is numbered 
//between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of 
//nodes that node u is adjacent to. More formally, for each v in graph[u], there is 
//an undirected edge between node u and node v. The graph has the following 
//properties: 
//
// 
// There are no self-edges (graph[u] does not contain u). 
// There are no parallel edges (graph[u] does not contain duplicate values). 
// If v is in graph[u], then u is in graph[v] (the graph is undirected). 
// The graph may not be connected, meaning there may be two nodes u and v such 
//that there is no path between them. 
// 
//
// A graph is bipartite if the nodes can be partitioned into two independent 
//sets A and B such that every edge in the graph connects a node in set A and a node 
//in set B. 
//
// Return true if and only if it is bipartite. 
//
// 
// Example 1: 
// 
// 
//Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
//Output: false
//Explanation: There is no way to partition the nodes into two independent sets 
//such that every edge connects a node in one and a node in the other. 
//
// Example 2: 
// 
// 
//Input: graph = [[1,3],[0,2],[1,3],[0,2]]
//Output: true
//Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}. 
//
// 
// Constraints: 
//
// 
// graph.length == n 
// 1 <= n <= 100 
// 0 <= graph[u].length < n 
// 0 <= graph[u][i] <= n - 1 
// graph[u] does not contain u. 
// All the values of graph[u] are unique. 
// If graph[u] contains v, then graph[v] contains u. 
// 
//
// Related Topics 深度优先搜索 广度优先搜索 并查集 图 👍 582 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) { // 处理每个节点，而不是只处理0节点
                q.push(i);
                color[i] = 0; // 起始节点颜色设为0

                while (!q.empty()) {
                    int cur = q.front(); q.pop();
                    for (int nb : graph[cur]) {
                        if (color[nb] == -1) {
                            color[nb] = 1 - color[cur];
                            q.push(nb);
                        } else if (color[nb] == color[cur]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

//leetcode submit region end(Prohibit modification and deletion)

int main() {
    vector<vector<int>> graph1 = {{1,2,3},{0,2},{0,1,3},{0,2}};
    vector<vector<int>> graph2 = {{1,3},{0,2},{1,3},{0,2}};
    cout << Solution().isBipartite(graph1) << endl;
    cout << Solution().isBipartite(graph2) << endl;

}

class Solution2 {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        // 将所有节点加入字典中，如果有冲突就错了
        unordered_map<int, int> mp;
        vector visited(graph.size(), false);

        queue<int> q;
        int id_g = 0;
        q.push(0); visited[0] = true; mp[0] = id_g;

        while (!q.empty()) {
            int l = q.size();
            id_g = 1 - id_g;
            for (int i = 0; i < l; i++) {
                int cur = q.front(); q.pop();
                for (const auto& nb : graph[cur]) {
                    if (mp.count(nb) && mp[nb] != id_g) return false;
                    if (!visited[nb]) {
                        q.push(nb); // 将所有的邻居加入队列
                        visited[nb] = true; // 记录来过了
                        mp[nb] = id_g; // 同时加入字典
                    }
                }
            }
        }

        return true;
    }
};