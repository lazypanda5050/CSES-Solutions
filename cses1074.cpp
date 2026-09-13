#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin >> n;

  vector<long long> p(n);
  for (long long i = 0; i < n; i++){
    cin >> p[i];
  }

  sort(p.begin(),p.end());

  long long av = p[n/2]; // the median
  long long ans = 0;
  for (long long i = 0; i < n; i++){
    ans += abs(p[i]-av);
  }

  cout << ans << '\n';
}
