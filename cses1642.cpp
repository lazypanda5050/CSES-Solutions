#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  unordered_map<int, pair<int, int>> pairs;

  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      int tar = x - a[i] - a[j];
      if (pairs.find(tar) != pairs.end()){
        cout << pairs[tar].first + 1 << ' ' << pairs[tar].second + 1 << ' ' << i + 1 << ' ' << j + 1 << '\n';
        return 0;
      }
    }

    for (int j = 0; j < i; j++){
      pairs[a[i] + a[j]] = {j, i};
    }
  }

  cout << "IMPOSSIBLE\n";
  return 0;
}
