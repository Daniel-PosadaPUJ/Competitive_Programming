/*
Solution Problem 11110 Equidivisions
Daniel Alejandro Posada Noguera
16 de Julio de 2025
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;
bool ans = true;
vector<int> amounts(100);
vector<vector<int>> square(100, vector<int> (100));
vector<vector<bool>> vis (100, vector<bool> (100));
vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

void initializeValues(){
    int i, j;
    ans = true;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            square[i][j] = 0;
            vis[i][j] = false;
        }
        amounts[i] = 0;
    }
}

bool bfsAux(int x, int y){
    int cnt = 0, num = square[x][y], i;
    pair<int, int> u, v;
    bool isPosValid;
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    vis[x][y] = true;
    while(!q.empty() && cnt != n){
        u = q.front();
        q.pop();
        for(i = 0; i < 4; i++){
            v = make_pair(u.first + dir[i].first, u.second + dir[i].second);
            isPosValid = (-1 < v.first && v.first < n) && (-1 < v.second && v.second < n);
            if(isPosValid && !vis[v.first][v.second] && square[v.first][v.second] == num){
                q.push(v);
                vis[v.first][v.second] = true;
            }
        }
        cnt++;        
    }
    return cnt == n;
}

bool bfsEquidiv(){
    int i = 0, j;
    bool flag = true;
    while(flag && i < n){
        j = 0;
        while(flag && j < n){
            if(!vis[i][j])
                flag = bfsAux(i, j);
            j++;
        }
        i++;
    }
    return flag;
}

void solve(){
    if(ans)
        ans = ans && bfsEquidiv();

    if(ans)
        printf("good\n");
    else
        printf("wrong\n");  
}

void printMatriz(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << square[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void verifyAmounts(){
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++){
            amounts[square[i][j]]++;
        }
    i = 0;
    while(i < n && ans){
        ans = (amounts[i] == n);
        i++;
    }
}

void addCells(string &line, int num){
    stringstream ss(line);
    int x, y;
    while(ss >> x >> y)
        square[x - 1][y - 1] = num;
}

int main(){
    int i, j;
    string line;
    scanf("%d", &n);
    cin.ignore();
    while(n != 0){
        k = 1;
        initializeValues();
        for(i = 0; i < n - 1; i++){
            getline(cin, line);
            addCells(line, k);
            k++;
        }
        verifyAmounts();
        solve();
        scanf("%d", &n);
        cin.ignore();
    }
    return 0;
}