#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;

  vector<long long> a(n);
  long long ans = 0;
  for (long long i = 0; i < n; i++){
    cin >> a[i];
  }

  for (long long i = 1; i < n; i++){
    if (a[i] > a[i-1]){
      continue;
    }
    ans += a[i-1]-a[i];

    a[i] = a[i-1];
  }

  cout << ans << '\n';
}
