/*
Solution Problem 10356 Rough Roads
Daniel ALejandro Posada Noguera
22 de Julio del 2025
*/

#include <bits/stdc++.h>

using namespace std;

int c = 1, n, r;
vector<vector<pair<int, int>>> graph(502);

struct state{
    int node;
    bool goRiding;

    state(){ node = 0; goRiding = false;}
    state(int x, bool b){ node = x; goRiding = b;}
    bool operator==(const state &other) const { return node == other.node && goRiding == other.goRiding; }
    bool operator<(const state &other) const { return node != other.node ? node < other.node : goRiding < other.goRiding; }
};

map<state, int> dis;

int dijkstraRoads(){
    priority_queue<pair<int, state>> q;
    pair<int, state> u;
    bool found = false;
    state s, end(n - 1, false), start(0, false), v;
    int i, d, nxtDis, nxtNode;
    dis.clear();
    q.push(make_pair(0, start));
    dis[start] = 0;

    while(!q.empty() && !found){
        u = q.top();
        d = -u.first; s = u.second;
        q.pop();
        if(s == end)
            found = true;
        else{
            if(d == dis[s]){
                for(i = 0; i < graph[s.node].size(); i++){
                    nxtNode = graph[s.node][i].first; nxtDis = graph[s.node][i].second;
                    v = state(nxtNode, !s.goRiding);
                    if(dis.find(v) == dis.end() || d + nxtDis < dis[v]){
                        q.push(make_pair(-(d + nxtDis), v));
                        dis[v] = d + nxtDis;
                    }
                }
            }   
        }
    }
    return found ? dis[end] : -1;
}

void solve(){
    int sol = dijkstraRoads();
    printf("Set #%d\n", c++);
    if(sol != -1)
        printf("%d\n", sol);
    else
        printf("?\n");
}

int main(){
    int u, v, d, i;
    c = 1;
    while(scanf("%d %d", &n, &r) != EOF){
        for(i = 0; i < n; i++)
            graph[i].clear();
        for(i = 0; i < r; i++){
            scanf("%d %d %d", &u, &v, &d);
            graph[u].push_back(make_pair(v, d));
            graph[v].push_back(make_pair(u, d));
        }
        solve();
    }
    return 0;
}