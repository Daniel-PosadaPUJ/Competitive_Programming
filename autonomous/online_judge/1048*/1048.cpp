/*
Solution Problem 1048 Low Cost Air Travel}
Daniel Alejandro Posada Noguera
10 de Agosto del 2025
*/

#include <bits/stdc++.h>

using namespace std;

int n, s;
vector<int> itinerary(12);
unordered_map<int, vector<int>> citiesOnRoutes;
unordered_map<int, vector<pair<int, int>>> planesToTrip;

struct state{
    int city, plane, idx, planeAdvance;

    state(){ city = 0; plane = 0; idx = 0, planeAdvance = 0; }
    state(int c, int p, int i, int a){ city = c; plane = p; idx = i, planeAdvance = a; }
    bool isOnItinerary(){ return city == itinerary[idx]; }
    bool isGoal(){ return idx == n - 1 && isOnItinerary(); }
    bool isNull(){ return city == -1 || plane == -1 || idx == -1 || planeAdvance == -1; }
    bool operator<(state const &other) const { 
        bool aux1 = (city != other.city) ? (city < other.city) : (plane < other.plane);
        bool aux2 = (planeAdvance != other.planeAdvance) ? (planeAdvance < other.planeAdvance) : aux1;
        return (idx != other.idx) ? (idx < other.idx) : aux2; 
    }
    bool operator==(state const &other) const { return plane == other.plane && city == other.city && idx == other.idx && planeAdvance == other.planeAdvance; }
    state nextOnItinerary(){ return state(city, plane, idx + 1, planeAdvance); }
    state changePlane(int newPlane){ return state(city, newPlane, idx, 0); }
    state changeCity(int newCity, int newAdvance){ return state(newCity, plane, idx, newAdvance); }
    void print(){ printf("city: %d, plane: %d, idx: %d, planeAdvance: %d.\n", city, plane, idx, planeAdvance); }
};

map<state, pair<state, int>> routes;
priority_queue<pair<int, state>> pq;
map<state, int> cost;

void initializeVariables(){
    routes.clear(); cost.clear(); 
    while(!pq.empty())
        pq.pop();
}

void addInitialStates(){
    state st; 
    vector<pair<int, int>>::iterator it;
    pair<int, int> aux;
    for(it = planesToTrip[s].begin(); it != planesToTrip[s].end(); it++){
        aux = *it;
        st = state(s, aux.second, 0, 0);
        pq.push(make_pair(-aux.first, st));
        cost[st] = aux.first;
        routes[st] = make_pair(state(-1, -1, -1, -1), -1);
    }
}

vector<int> getRoute(state u){
    pair<state, int> aux = routes[u];
    vector<int> ans;
    int i = 0, prev = -1; 
    while(!aux.first.isNull()){
        if(aux.first.plane != prev)
            ans.push_back(aux.second);
        prev = aux.first.plane;
        aux = routes[aux.first];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

pair<int, vector<int>> dijkstrasItinerary(){
    pair<int, vector<int>> ans = make_pair(0, vector<int> ());
    bool found = false;
    state u, v;
    int i, du, dv;
    addInitialStates();
    while(!pq.empty() && !found){
        du = -pq.top().first;
        u = pq.top().second;
        pq.pop();
        if(u.isGoal()){
            found = true;
            ans.first = cost[u];
            ans.second = getRoute(u);
        }
        else if(u.isOnItinerary()){
            v = u.nextOnItinerary();
            if(cost.find(v) == cost.end() || du < cost[v]){
                pq.push(make_pair(-du, v));
                cost[v] = du;
                routes[v] = make_pair(u, u.plane);
            }
        }
        else{
            if(du == cost[u]){
                for(i = u.planeAdvance; i < citiesOnRoutes[u.plane].size(); i++){
                    v = u.changeCity(citiesOnRoutes[u.plane][i], i);
                    if(cost.find(v) == cost.end() || du < cost[v]){
                        pq.push(make_pair(-du, v));
                        cost[v] = du;
                        routes[v] = make_pair(u, u.plane);
                    }
                }
                for(i = 0; i < planesToTrip[u.city].size(); i++){
                    dv = planesToTrip[u.city][i].first;
                    v = u.changePlane(planesToTrip[u.city][i].second);
                    if(cost.find(v) == cost.end() || du + dv < cost[v]){
                        pq.push(make_pair(-(du + dv), v));
                        cost[v] = du + dv;
                        routes[v] = make_pair(u, u.plane);
                    }
                }
            }
        }
    }

    return ans;
}

void solve(int c, int t){
    pair<int, vector<int>> sol = dijkstrasItinerary();
    cout << "Case " << c << ", Trip " << t << ": Cost = " << sol.first << endl;
    cout << "  Tickets used: "; 
    for(int i = 0; i < sol.second.size(); i++){
        cout << sol.second[i];
        if(i + 1 != sol.second.size())
            cout << " ";
    }
    cout << endl;
}

int main(){
    int nt, ni, price, j, ntrip, tck, cases = 1, aux;
    pair<int, int> p;
    vector<int> cities;
    cin >> nt;
    while(nt != 0){
        citiesOnRoutes.clear(); planesToTrip.clear();
        for(tck = 1; tck <= nt; tck++){
            cin >> price >> n;
            cities = vector<int> (n);
            for(j = 0; j < n; j++){
                cin >> aux;
                cities[j] = aux;
                if(j == 0) 
                    planesToTrip[aux].push_back(make_pair(price, tck));
            }
            citiesOnRoutes[tck] = cities;
        }
        cin >> ni;
        for(ntrip = 1; ntrip <= ni; ntrip++){
            cin >> n;
            itinerary = vector<int> (n);
            for(j = 0; j < n; j++)
                cin >> itinerary[j];
            s = itinerary[0];
            initializeVariables();
            solve(cases, ntrip); 
        }
        cases++;
        cin >> nt;
    }

    return 0;
}