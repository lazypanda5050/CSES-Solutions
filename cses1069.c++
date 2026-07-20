#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  char curChar;
  int ans = -1;
  int count = 0;
  for (char c : s){
    if (c != curChar){
      ans = max(ans, count);
      curChar = c;
      count = 1;
    }
    else{
      count++;
    }
  }

  ans = max(ans, count);

  cout << ans << '\n';
}
