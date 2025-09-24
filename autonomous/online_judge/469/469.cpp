/*
Solution Problem 469 Wetlands of Florida
1 de Julio de 2025
Daniel Alejandro Posada Noguera
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> florida;
vector<pair<int, int>> querys;
int n, m, k;
vector<pair<int, int>> d = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int count_water(pair<int, int> pos){
    int cnt = 0;
    vector<vector<bool>> vis (n, vector<bool> (m, false));
    queue<pair<int, int>> q;
    vis[pos.first][pos.second] = true;
    q.push(pos);

    while(!q.empty()){
        pair<int, int> u = q.front();
        q.pop();
        if(florida[u.first][u.second] == 'W')
            cnt += 1;
        for(int i = 0; i < 8; i++){
            int ni = u.first + d[i].first;
            int nj = u.second + d[i].second;
            if(ni >= 0 && nj >= 0 && ni < n && nj < m && florida[ni][nj] != 'L' && !vis[ni][nj]){
                q.push(make_pair(ni, nj));
                vis[ni][nj] = true;
            }
        }
    }
    return cnt;
}

vector<int> solve(){
    vector<int> sol;
    for(int i = 0; i < k; i++)
        sol.push_back(count_water(querys[i]));
    return sol;
}

int main(){
    int cases, c;
    bool case_stop;
    string line;
    getline(cin, line);
    cases = stoi(line);

    getline(cin, line);
    for(c = 0; c < cases; c++){
        case_stop = false;
        florida.clear();
        querys.clear();
        while(!case_stop){
            getline(cin, line);
            if(line.size() > 0){
                if(line[0] == 'W' or line[0] == 'L')
                    florida.push_back(line);
                else{
                    istringstream iss(line);
                    int a, b;
                    iss >> a >> b;
                    querys.push_back(make_pair(a - 1, b - 1));
                }
            }
            else
                case_stop = true;
        }
        n = florida.size();
        m = florida[0].size();
        k = querys.size();
        vector<int> solutions = solve();
        for(int j = 0; j < k; j++)
            cout << solutions[j] << endl;
        if(c < cases - 1) 
            cout << endl;
    }
    return 0;
}

