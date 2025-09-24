/*
Solution 10603 Fill
Daniel Alejandro Posada Noguera
Julio 25 del 2025
*/

#include <bits/stdc++.h>

using namespace std;

int cap[3], d;
vector<pair<int, int>> comb = {{0, 1}, {0, 2}, {1, 0}, {1, 2}, {2, 0}, {2, 1}};

struct state{
    int x[3];

    state(){ x[0] = 0; x[1] = 0; x[2] = 0; }
    state(int a, int b, int c){ x[0] = a; x[1] = b; x[2] = c; }
    state(int y[3]){ for(int i = 0; i < 3; i++) x[i] = y[i]; }
    bool operator==(state const &other) const { 
        return x[0] == other.x[0] && x[1] == other.x[1] && x[2] == other.x[2]; 
    }
    bool isTheGoal(){ return x[0] == d || x[1] == d || x[2] == d; }
    int operator[](int idx) const { return x[idx]; }
    bool operator<(state const &other) const {
        bool tmp = (x[1] != other.x[1]) ? x[1] < other.x[1] : x[2] < other.x[2];
        return (x[0] != other.x[0]) ? x[0] < other.x[0] : tmp;
    }
    int maxWaterLessD(){
        int m = -1, i;
        for(i = 0; i < 3; i++)
            m = (x[i] < d) ? max(m, x[i]) : m;
        return m;
    }
    pair<int, state> moveWater(int orig, int dest){
        int i, y[3], space = cap[dest] - x[dest], amount = min(x[orig], space);
        for(i = 0; i < 3; i++) y[i] = x[i];
        y[orig] -= amount; y[dest] += amount;
        return make_pair(amount, state(y));
    }
};

pair<int, int> dijkstraFill(){
    priority_queue<pair<int, state>> pq;
    map<state, int> dis;
    pair<int, int> ans = make_pair(INT_MAX, -1);
    bool found = false;
    state start(0, 0, cap[2]), s;
    int dist, dNear, i, orig, dest;
    pair<int, state> u, v;
    pq.push(make_pair(0, start));
    dis[start] = 0;

    while(!pq.empty() && !found){
        u = pq.top();
        dist = -u.first; s = u.second;
        pq.pop();
        if(s.isTheGoal()){
            found = true;
            ans = make_pair(dis[s], d);
        }
        else{
            if(dist == dis[s]){
                dNear = s.maxWaterLessD();
                if(dNear > ans.second || (dNear == ans.second && dist < ans.first))
                    ans = make_pair(dist, dNear);
                for(i = 0; i < 6; i++){
                    v = s.moveWater(comb[i].first, comb[i].second);
                    if(dis.find(v.second) == dis.end() || dis[v.second] > dist + v.first){
                        dis[v.second] = dist + v.first;
                        pq.push(make_pair(-(dist + v.first), v.second));
                    }
                }
            }
        }
    }
    return ans;
}

void solve(){
    pair<int, int> sol = dijkstraFill();
    printf("%d %d\n", sol.first, sol.second);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d", &cap[0], &cap[1], &cap[2], &d);
        solve();
    }
    return 0;
}