#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> nums;

long long solve(long long i, long long sum1, long long sum2){
  if (i == n){
    return abs(sum1-sum2);
  }

  long long g1 = solve(i+1,sum1+nums[i],sum2);
  long long g2 = solve(i+1,sum1,sum2+nums[i]);
  return min(g1,g2);
}

int main(){
  cin >> n;
  
  for (long long i = 0; i < n; i++){
    long long t;
    cin >> t;
    nums.emplace_back(t);
  }
  
  cout << solve(0,0,0);
}
