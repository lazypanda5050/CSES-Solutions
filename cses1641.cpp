#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> a(n);

  for (int i = 0; i < n; i++){
    cin >> a[i].first;
    a[i].second = i;
  }

  sort(a.begin(), a.end());

  for (int i = 0; i < n; i++){
    // i = third pointer
    int l = 0, r = n-1;
    int tar = x-a[i].first;
    while (l < r){
      // skip overlap w/ 3rd
      if (l == i){
        l++;
      }
      else if (r == i){
        r--;
      }
      if (l == r){
        break;
      }
      int sum = a[l].first + a[r].first;

      if (sum > tar){
        // make sum smaller
        r--;
      }
      else if (sum < tar){
        // make sum larger
        l++;
      }
      else{
        // found
        cout << a[l].second+1 << ' ' << a[r].second+1 << ' ' << a[i].second+1 << '\n';
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}
