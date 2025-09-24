/*
Solution 11792 Krochanska is Here!
Daniel Alejandro Posada Noguera
23 de Julio de 2025
*/

#include <bits/stdc++.h>

using namespace std;

int numStations;
vector<vector<int>> graph(10000);
unordered_set<int> prevInclude;
unordered_set<int> importantSt;

int bfs_krochanska(int s){ 
    vector<bool> visAll(numStations, false);
    unordered_set<int> visImportants = importantSt;
    queue<pair<int, int>> q;
    int ans = 0, u, du, v, i;  
    q.push(make_pair(s, 0)); visAll[s] = 0;
    visImportants.erase(s);
    while(!q.empty() && !visImportants.empty()){
        u = q.front().first;
        du = q.front().second;
        q.pop();
        if(visImportants.find(u) != visImportants.end()){
            ans += du;
            visImportants.erase(u);
        }
        for(i = 0; i < graph[u].size(); i++){
            v = graph[u][i];
            if(!visAll[v]){
                q.push(make_pair(v, du + 1));
                visAll[v] = true;
            }
        }
    }
    return ans;
}

void solve(){
    unordered_set<int>::iterator it;
    int sol = INT_MAX, ac, m = INT_MAX;
    for(it = importantSt.begin(); it != importantSt.end(); it++){
        ac = bfs_krochanska(*it);
        if(ac == m){
            sol = (sol < *it) ? sol : *it;
        }
        else{
            sol = (ac < m) ? *it : sol;  
            m = min(ac, m);
        }
    }
    cout << "Krochanska is in: " << sol + 1 << endl;
}

int main(){
    int cases, numLines, su, sv, i;
    cin >> cases;
    while(cases--){
        cin >> numStations >> numLines;
        importantSt.clear();
        prevInclude.clear();
        for(i = 0; i < numStations; i++)
            graph[i].clear();
        while(numLines--){
            cin >> su >> sv;
            while(sv != 0){
                graph[su - 1].push_back(sv - 1);
                graph[sv - 1].push_back(su - 1);
                if(prevInclude.find(su - 1) != prevInclude.end())
                    importantSt.insert(su - 1);
                else
                    prevInclude.insert(su - 1);
                su = sv;
                cin >> sv;
            }
            if(prevInclude.find(su - 1) != prevInclude.end())
                importantSt.insert(su - 1);
            else
                prevInclude.insert(su - 1);
        }
        solve();
    }
    return 0;
}