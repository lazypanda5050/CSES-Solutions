#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> ans;

void dfs(int node){
  for (int child : adj[node]){
    dfs(child);
    ans[node] += ans[child]+1;
  }
}

int main(){
  int n;
  cin >> n;
  
  adj.resize(n);
  ans.resize(n);
  for (int i = 1; i < n; i++){
    int p;
    cin >> p;
    adj[p-1].push_back(i);
  }

  dfs(0);

  for (int i = 0; i < n; i++){
    cout << ans[i] << ' ';
  }
  return 0;

}
