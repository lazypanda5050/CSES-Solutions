#include <bits/stdc++.h>
using namespace std;

struct Event{
    int time;
    int type; // 1 for start, -1 for end
};

int main(){
    int n;
    cin >> n;
    vector<Event> events;
    for (int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b;
        events.push_back({a, 1});
        events.push_back({b, -1});
    }

    sort(events.begin(),events.end(), [](Event a, Event b){
        if (a.time == b.time) return a.type > b.type; // start before end
        return a.time < b.time;
    });

    int cur = 0;
    int maxActive = 0;
    for (const auto& e : events) {
        cur += e.type;
        maxActive = max(maxActive, cur);
    }

    cout << maxActive << endl;
}