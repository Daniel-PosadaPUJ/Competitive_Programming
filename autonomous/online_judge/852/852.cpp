/*
Solution Problem 852 Deciding victory in Go
Daniel Alejandro Posada Noguera
16 de Julio de 2025
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> board(9);
vector<vector<bool>> vis(9, vector<bool> (9, false));
pair<int, int> finalGoPoints, acPoints;
vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void initializeValues(){
    int i, j;
    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++)
            vis[i][j] = false;
    acPoints = make_pair(0, 0);
    finalGoPoints = make_pair(0, 0);
}

void bfsAux(int x, int y){
    bool foundBlack = false, foundWhite = false;
    int cnt = 0, k;
    queue<pair<int, int>> q;
    pair<int, int> u, v;
    q.push(make_pair(x, y));  
    vis[x][y] = true;
    while(!q.empty()){
        u = q.front();
        q.pop();
        for(k = 0; k < 4; k++){
            v = make_pair(u.first + dir[k].first, u.second + dir[k].second);
            if(-1 < v.first && v.first < 9 && -1 < v.second && v.second < 9){
                if(board[v.first][v.second] == 'X')
                    foundBlack = true;
                else if(board[v.first][v.second] == 'O')
                    foundWhite = true;
                else if(!vis[v.first][v.second]){
                    q.push(v);
                    vis[v.first][v.second] = true;
                }
            }
        }
        cnt++; 
    }
    if(foundBlack && !foundWhite)
        acPoints.first += cnt;
    else if(foundWhite && !foundBlack)
        acPoints.second += cnt;
}

pair<int, int> bfsGo(){
    int i, j;
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            if(board[i][j] != '.'){
                if(board[i][j] == 'X')
                    acPoints.first++;
                else if(board[i][j] == 'O')
                    acPoints.second++;
                vis[i][j] = true;
            }
            else if(!vis[i][j])
                bfsAux(i, j);
        }
    }
    return acPoints;
}

void solve(){
    initializeValues();
    finalGoPoints = bfsGo();
    cout << "Black " << finalGoPoints.first << " White " << finalGoPoints.second << endl;
}

int main(){
    int t, i;
    string row;
    cin >> t;
    while(t != 0){
        for(i = 0; i < 9; i++){
            cin >> row;
            board[i] = row;
        }
        solve();
        t--;
    }

    return 0;
}