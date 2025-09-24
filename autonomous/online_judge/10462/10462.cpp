/*
Solution 10462 Is There A Second Way Left?
Daniel Alejandro Posada Noguera
3 de Septiembre de 2025
*/

#include <bits/stdc++.h>

using namespace std;

struct Edge{
    int u, v, c;

    Edge(){ u = 0; v = 0; c = 0; }
    Edge(int x, int y, int val){ u = x; v = y; c = val; }
    bool operator<(Edge &other){ return c < other.c; }
};

vector<int> p(100), rango(100);

void makeSet(int v){
    p[v] = v;
    rango[v] = 0;
}

int findSet(int v){
    int ans;
    if(v == p[v])
        ans = v;
    else{
        p[v] = findSet(p[v]);
        ans = p[v];
    }
    return ans;
}

void unionSet(int u, int v){
    u = findSet(u);
    v = findSet(v);

    if(u != v){
        if(rango[v] < rango[u])
            swap(u, v);
        p[v] = u;
        if(rango[u] == rango[v])
            rango[u]++;
    }
}

int n, m;
vector<Edge> aristas;

int kruskal_second_sum(vector<Edge> &aristas, vector<Edge> mst){
    int i, u, v, p1, p2, total;
    vector<Edge>::iterator it;

    for(i = 0; i < n; i++)
        makeSet(i);
    
    sort(aristas.begin(), aristas.end());

    for(it = aristas.begin(); it != aristas.end(); it++){
        u = it->u;
        v = it->v;
        if(findSet(u) != findSet(v)){
            mst.push_back(*it);
            total += it->c;
            unionSet(u, v);
        }
    }
    return total; 
}

void solve(){

}

int main(){
    int t, cases = 1, i, u, v, c;
    cin >> t;
    while(cases <= t){
        cin >> n >> m;
        aristas.clear();
        while(m--){
            cin >> u >> v >> c;
            // Pueden haber aristas repetidas con distinto peso.
            aristas.push_back(Edge(u, v, c));
            aristas.push_back(Edge(v, u, c));
        }
        cout << "Case #" << cases << " : ";
        solve();
        cases++;
    }
    return 0;
}