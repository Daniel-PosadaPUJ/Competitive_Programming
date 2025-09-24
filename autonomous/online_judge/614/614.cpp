/* Solution Problem 614 Mapping the Route
4 de Julio del 2025
Daniel Alejandro Posada Noguera
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, step, c;

struct cell{
    string symbol;
    int walls;

    cell(){
        symbol = "   ";
        walls = 0;
    }

    cell(int w){
        symbol = "   ";
        walls = w;
    }

    void assignSymbol(string c){
        symbol = c;
    }

    bool hasWallDown(){
        return walls == 2 || walls == 3;
    }

    bool hasWallRight(){
        return walls == 1 || walls == 3;
    }

    void print(int col){
        cout << setw(3) << symbol;
        if(hasWallRight() || col == m - 1)
            cout << "|";
        else
            cout << " ";
    }
};

bool found = false;
vector<vector<int>> vis;
pair<int, int> start, goal, nPos;
vector<vector<cell>> maze(13, vector<cell> (13));
vector<pair<int, int>> dir = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

bool isValid(pair<int, int> &u, pair<int, int> &v, int idx){
    bool ans = (v.first > -1 && v.first < n) && (v.second > -1 && v.second < m);
    if(ans){
        if(idx == 0)
            ans &= !maze[v.first][v.second].hasWallRight();
        else if(idx == 1)
            ans &= !maze[v.first][v.second].hasWallDown();
        else if(idx == 2)
            ans &= !maze[u.first][u.second].hasWallRight();
        else
            ans &= !maze[u.first][u.second].hasWallDown();
    }
    return ans;
}

void dfs_maze(pair<int, int> x){
    vis[x.first][x.second] = step++;
    found = x == goal;
    int i = 0;
    while(i < 4 && !found){
        nPos = make_pair(x.first + dir[i].first, x.second + dir[i].second);
        if(isValid(x, nPos, i) && !vis[nPos.first][nPos.second])
            dfs_maze(nPos);
        i++;
    }
    if(found)
        maze[x.first][x.second].assignSymbol(to_string(vis[x.first][x.second]));
    else{
        maze[x.first][x.second].assignSymbol("???");
        step--;
    }
}

void printTopBotton(bool flag, int row){
    cout << "+";
    for(int i = 0; i < m; i++){
        if(!flag || maze[row][i].hasWallDown())
            cout << "---+";
        else
            cout << "   +";
    }
    cout << endl;
}

void print_maze(){
    int i, j, k;
    printTopBotton(false, 0);
    for(i = 0; i < n; i++){
        cout << "|";
        for(j = 0; j < m; j++)
            maze[i][j].print(j);
        cout << endl;
        if(i != n - 1)
            printTopBotton(true, i);
    }
    printTopBotton(false, n - 1);
} 

void solve(){
    found = false;
    step = 1;
    start.first--; start.second--;
    goal.first--; goal.second--;
    vis = vector<vector<int>> (n, vector<int> (m, 0));
    dfs_maze(start);
    cout << "Maze " << c << endl << endl;
    print_maze();
    cout << endl << endl;
}

int main(){
    c = 1;
    int i, j, aux;
    cin >> n >> m >> start.first >> start.second >> goal.first >> goal.second;
    while(n && m){
        for(i = 0; i < n; i++){
            for(j = 0; j < m; j++){
                cin >> aux;
                maze[i][j] = cell (aux);
            }
        }
        solve();
        c++;
        cin >> n >> m >> start.first >> start.second >> goal.first >> goal.second;
    }
    return 0;
}