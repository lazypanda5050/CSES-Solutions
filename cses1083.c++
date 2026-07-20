#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  unordered_set<int> s;
  for (int i = 0; i < n; i++){
    int t;
    cin >> t;
    s.insert(t);
  }

  for (int i = 1; i <= n; i++){
    if (s.find(i) == s.end()){
      cout << i << '\n';
      return 0;
    }
  }
}
