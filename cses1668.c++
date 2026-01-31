#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    int a, b;
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        a--,b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    vector<int> colors(n, -1);
    queue<pair<int, int>> q; // {id, color}, color is 0 or 1
    for (int i = 0; i < n; i++){
        if (colors[i] != -1){
            continue;
        }

        q.push({i,0});
        colors[i] = 0;
        while (!q.empty()){
            auto [cur, curColor] = q.front(); q.pop();
            for (int neighbor : adj[cur]){
                if (colors[neighbor] == -1){
                    colors[neighbor] = (curColor^1);
                    q.push({neighbor, (curColor^1)});
                }
                else if (colors[neighbor] == curColor){
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }
            }
        }
    }


    for (int color : colors){
        cout << color+1 << ' ';
    }
}