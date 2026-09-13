#include <bits/stdc++.h>
using namespace std;

class DSU{
  private:
    vector<int> parent;
    vector<int> size;
    int groups;
    int maxSize = 1;

  public:
    DSU(int n) : parent(n), size(n, 1) {
      for (int i = 0; i < n; i++){
        parent[i] = i;
      }
      groups = n;
    }

    int find(int x){
      return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }

    bool unite(int x, int y){
      int rootX = find(x);
      int rootY = find(y);
      if (rootX == rootY){
        return false;
      }

      if (size[rootX] < size[rootY]){
        swap(rootX, rootY);
      }
      size[rootX] += size[rootY];
      maxSize = max(maxSize, size[rootX]);
      parent[rootY] = rootX;
      groups--;
      return true;
    }

    bool connected(int x, int y){
      return find(x) == find(y);
    }

    int getGroups(){
      return groups;
    }

    int getMaxSize(){
      return maxSize;
    }
};

int main(){
  int n,m;
  cin >> n >> m;

  DSU dsu(n);
  int a,b;
  for (int i = 0; i < m; i++){
    cin >> a >> b;
    a--,b--;
    dsu.unite(a,b);
    cout << dsu.getGroups() << ' ' << dsu.getMaxSize() << '\n';
  }
}
