/*
Solution 10801 Lift Hopping
Daniel Alejandro Posada Noguera
26 de Julio del 2025
*/

#include <bits/stdc++.h>

using namespace std;

int n, k, mF;
vector<int> times;
vector<vector<int>> elevators(5);
vector<vector<int>> floors(101);

struct state{
    int flr, elev;

    state(){ flr = -1; elev = -1; }
    state(int f, int e){ flr = f; elev = e; }
    bool isEnd(){ return flr == k; }
    int floorsTo(int f){ return abs(flr - f); }
    bool operator<(state const &other) const { return (flr == other.flr) ? (elev < other.elev) : (flr < other.flr); }
    bool operator==(state const &other) const { return flr == other.flr && elev == other.elev; }
    state changeFloor(int f){ return state(f, elev); }
    state changeElevator(int e){ return state(flr, e); }
    void print(){ cout << "f: " << flr << " elv: " << elev << endl; }
};

void clearValues(){
    int i, j;
    mF = -1;
    times.clear();
    for(i = 0; i < n; i++)
        elevators[i].clear();
    for(j = 0; j < 101; j++)
        floors[j].clear();
}

void split(string &l, vector<int> &v, bool isFloors){
    int aux;
    stringstream ss(l);
    while(ss >> aux){
        mF = isFloors ? max(mF, aux) : mF;
        v.push_back(aux);
    }
}

void addFloorsElevators(int idx){
    int i;
    for(i = 0; i < elevators[idx].size(); i++)
        floors[elevators[idx][i]].push_back(idx);
}

int dijkstraElevators(){
    int ans = -1, du, duv, i;
    bool found = false;
    state u, v;
    map<state, int> dis;
    priority_queue<pair<int, state>> q;
    for(i = 0; i < floors[0].size(); i++){
        dis[state(0, floors[0][i])] = 0;
        q.push(make_pair(0, state(0, floors[0][i])));
    }
    while(!q.empty() && !found){
        du = -q.top().first;
        u = q.top().second;
        q.pop();
        if(u.isEnd()){
            found = true;
            ans = du;
        }
        else{
            for(i = 0; i < elevators[u.elev].size(); i++){
                v = u.changeFloor(elevators[u.elev][i]);
                duv = du + u.floorsTo(elevators[u.elev][i]) * times[u.elev];
                if(dis.find(v) == dis.end() || dis[v] > duv){
                    dis[v] = duv;
                    q.push(make_pair(-duv, v));
                }
            }
            for(i = 0; i < floors[u.flr].size(); i++){
                v = u.changeElevator(floors[u.flr][i]);
                duv = du + 60;
                if(dis.find(v) == dis.end() || dis[v] > duv){
                    dis[v] = duv;
                    q.push(make_pair(-duv, v));
                }
            }
        }
    }
    return ans;
}

void solve(){
    int sol = dijkstraElevators();
    if(sol < 0)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << sol << endl;
}

int main(){
    int i;
    string line;
    while(cin >> n >> k){
        cin.ignore();
        clearValues();
        getline(cin, line);
        split(line, times, false);
        for(i = 0; i < n; i++){
            elevators[i].clear();
            getline(cin, line);
            split(line, elevators[i], true);
            addFloorsElevators(i);
        }
        solve();
    }
    return 0;
}