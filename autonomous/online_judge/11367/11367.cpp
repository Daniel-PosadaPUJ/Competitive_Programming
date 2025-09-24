/*
Solution 11367 Full Tank?
Daniel Alejandro Posada Noguera
29 de Julio de 2025
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, s, e, c;
vector<vector<int>> cost(1001, vector<int> (101));
vector<int> fuelPrice(1000);
vector<vector<pair<int, int>>> graph(1000);

struct state{
    int ciudad, gasolina;
    
    state(){ ciudad = 0; gasolina = 0; }
    state(int x, int y){ ciudad = x; gasolina = y; }
    bool isGoal(){ return ciudad == e; }
    bool operator<(state const &other) const { 
        return (gasolina == other.gasolina) ? (ciudad < other.ciudad) : (gasolina < other.gasolina);
    }
    bool operator==(state const &other) const { return ciudad == other.ciudad && gasolina == other.gasolina; }
    state tanquear(){ return state(ciudad, gasolina + 1); }
};

int dijkstraFuel(){
    int ans = -1, i, j, du, dv, v;
    bool found = false;
    state u;
    priority_queue<pair<int, state>> pq;
    for(i = 0; i < n; i++)
        for(j = 0; j <= c; j++)
            cost[i][j] = -1;
    cost[s][0] = 0;
    pq.push(make_pair(0, state(s, 0)));
    
    while(!found && !pq.empty()){
        du = -pq.top().first;
        u = pq.top().second;
        pq.pop();
        if(u.isGoal()){
            found = true;
            ans = cost[u.ciudad][u.gasolina];
        }
        else{
            if(du == cost[u.ciudad][u.gasolina]){
                for(i = 0; i < graph[u.ciudad].size(); i++){
                    v = graph[u.ciudad][i].first;
                    dv = graph[u.ciudad][i].second;
                    if(u.gasolina >= dv && (cost[v][u.gasolina - dv] == -1 || du < cost[v][u.gasolina - dv])){
                        pq.push(make_pair(-du, state(v, u.gasolina - dv)));
                        cost[v][u.gasolina - dv] = du;
                    }
                }
                if(u.gasolina < c && (cost[u.ciudad][u.gasolina + 1] == -1 || du + fuelPrice[u.ciudad] < cost[u.ciudad][u.gasolina + 1])){
                    pq.push(make_pair(-(du + fuelPrice[u.ciudad]), u.tanquear()));
                    cost[u.ciudad][u.gasolina + 1] =  du + fuelPrice[u.ciudad];
                }
            }
        }
    }

    return ans;
}

void solveQuery(){
    int sol = dijkstraFuel();
    if(sol != -1)
        cout << sol << endl;
    else
        cout << "impossible" << endl;   
}

int main(){
    int i, u, v, d, q;
    cin >> n >> m;
    for(i = 0; i < n; i++){
        cin >> fuelPrice[i];
        graph[i].clear();
    }
    for(i = 0; i < m; i++){
        cin >> u >> v >> d;
        graph[u].push_back(make_pair(v, d));
        graph[v].push_back(make_pair(u, d));
    }
    cin >> q;
    for(i = 0; i < q; i++){
        cin >> c >> s >> e;
        solveQuery();
    }

    return 0;
}