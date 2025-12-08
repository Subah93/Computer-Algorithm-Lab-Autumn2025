#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> GRAPH(n + 1);
  vector<int> distance(n + 1, -1);
  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    GRAPH[a].push_back(b);
    GRAPH[b].push_back(a);
  }
  queue<int> BFS;
  BFS.push(1);
  distance[1] = 0;
  while (!BFS.empty()) {
    int current = BFS.front();
    BFS.pop();
    cout << "currently on:" << current << endl;
    for (auto node : GRAPH[current])
      if (distance[node] == -1) {
        distance[node] = distance[current] + 1;
        BFS.push(node);
      }
  }

  for (int i = 1; i <= n; i++)
    cout << "Node:" << i << " is " << distance[i]
         << " nodes away from node 1\n";
  return 0;
}
