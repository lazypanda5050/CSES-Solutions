#include <bits/stdc++.h>
using namespace std;

int n;

pair<int, int> bfs(int start, const vector<vector<int>>& adj){
  vector<bool> visited(n,false);
  queue<pair<int, int>> q;
  pair<int, int> ans = {start, 0};

  q.push({start,0});
  visited[start] = true;
  while (!q.empty()){
    auto [cur, dist] = q.front(); q.pop();

    for (int neighbor : adj[cur]){
      if (!visited[neighbor]){
        visited[neighbor] = true;
        q.push({neighbor, dist+1});

        if (dist+1 > ans.second){
          ans = {neighbor, dist+1};
        }
      }
    }
  }

  return ans;
}

int main(){
  cin >> n;
  vector<vector<int>> adj(n);
  for (int i = 0; i < n-1; i++){
    int a,b;
    cin >> a >> b;
    a--,b--;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }

  pair<int, int> s = bfs(0,adj);
  pair<int, int> e = bfs(s.first,adj);

  cout << e.second << '\n';
}
