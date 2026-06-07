#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n,x;
  cin >> x >> n;

  priority_queue<long long, vector<long long>, greater<long long>> pq;
  for (long long i = 0; i < n; i++){
    long long a;
    cin >> a;
    pq.push(a);
  }

  long long ans = 0;
  long long a, b;
  while (pq.size() > 1){
    a = pq.top(); pq.pop();
    b = pq.top(); pq.pop();

    // cout << a << ' ' << b << '\n';
    ans += (a+b);
    pq.push(a+b);
  }

  cout << ans << '\n';
  return 0;
}
