#include <bits/stdc++.h>
using namespace std;

void tower(int n, int src, int aux, int tar){
  if (n == 1){
    cout << src << ' ' << tar << '\n';
  }
  else{
    tower(n-1, src, tar, aux);
    tower(1, src, aux, tar);
    tower(n-1, aux, src, tar);
  }
}

int main(){
  int n;
  cin >> n;
  cout << pow(2,n)-1 << '\n';
  tower(n,1,2,3);
}
