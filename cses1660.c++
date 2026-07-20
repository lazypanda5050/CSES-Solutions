#include <bits/stdc++.h>
using namespace std;

int main(){
  long long n,x;
  cin >> n >> x;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++){
    cin >> a[i];
  }

  long long start = 0, end = -1;
  long long sum = 0;
  long long cnt = 0;

  while (end < n){
    while (end < n && sum < x){
      end++;
      sum += a[end];
    }

    while (start <= end && sum > x){
      sum -= a[start];
      start++;
    }

    if (sum == x){
      cnt++;
      sum -= a[start];
      start++;
    }
  }

  cout << cnt << '\n';
}
