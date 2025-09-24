/*
Solution 10278 Fire Station
Daniel Alejandro Posada Noguera
Agosto 19 de 2025
*/

#include <bits/stdc++.h>

using namespace std;

int nf, ni, cases, globalMax;
vector<vector<pair<int, int>>> city(500);
unordered_set<int> fireStations;

vector<int> init_dijsktra(){
    int du, dv, u, v, i;
    unordered_set<int>::iterator it;
    priority_queue<pair<int, int>> pq;
    vector<int> dist(ni, -1);
    for(it = fireStations.begin(); it != fireStations.end(); it++){
        pq.push(make_pair(0, *it));
        dist[*it] = 0;
    }
    while(!pq.empty()){
        du = -pq.top().first;
        u = pq.top().second;
        pq.pop();
        for(i = 0; i < city[u].size(); i++){
            v = city[u][i].first;
            dv = city[u][i].second;
            if(dist[v] == -1 || du + dv < dist[v]){
                pq.push(make_pair(-(du + dv), v));
                dist[v] = du + dv;
            }
        }
    }
    for(i = 0; i < ni; i++)
        globalMax = max(globalMax, dist[i]);
    return dist;
}

int dijsktraFireStation(int candidate, vector<int> dist){
    int i, m = -1;
    int du, dv, u, v;
    unordered_set<int>::iterator it;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, candidate));
    dist[candidate] = 0;
    while(!pq.empty()){
        du = -pq.top().first;
        u = pq.top().second;
        pq.pop();
        for(i = 0; i < city[u].size(); i++){
            v = city[u][i].first;
            dv = city[u][i].second;
            if(dist[v] == -1 || du + dv < dist[v]){
                pq.push(make_pair(-(du + dv), v));
                dist[v] = du + dv;
            }
        }
    }
    for(i = 0; i < ni; i++)
        m = max(m, dist[i]);
    return m;
}

void solve(){
    int inter, localMin; globalMax = -1;
    vector<int> dist = init_dijsktra();
    pair<int, int> sol = {1, globalMax};
    for(inter = 0; inter < ni; inter++){
        if(fireStations.find(inter) == fireStations.end()){
            localMin = dijsktraFireStation(inter, dist);
            if(localMin < sol.second)
                sol = {inter + 1, localMin};
        }
    }
    cout << sol.first << endl;
    if(cases) cout << endl;
}

void print(){
    cout << "Inicio resolución " << endl;

    cout << "Grafo" << endl;
    for(int i = 0; i < ni; i++){
        cout << "adyacentes a " << i << endl;
        for(pair<int, int> v: city[i]){
            cout << v.first << " " << v.second << endl;
        }
        cout << endl;
    }
    cout << "fire stations " << endl;
    for(auto it = fireStations.begin(); it != fireStations.end(); it++){
        cout << *it << endl;
    }
}

int main(){
    int i, u, v, c, f;
    string line;
    cin >> cases;
    while(cases--){
        cin >> nf >> ni;
        fireStations.clear();
        for(i = 0; i < ni; i++)
            city[i].clear();
        for(i = 0; i < nf; i++){
            cin >> f;
            fireStations.insert(f - 1);
        }
        cin.ignore();
        while(getline(cin, line) && !line.empty()){
            stringstream ss(line);
            ss >> u >> v >> c;
            city[u - 1].push_back(make_pair(v - 1, c));
            city[v - 1].push_back(make_pair(u - 1, c));
        }
        solve();
    }
    return 0;
}