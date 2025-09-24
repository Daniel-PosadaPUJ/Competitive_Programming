/* Solution Problem 532 Dungeon Master
1 de Julio de 2025
Daniel Alejandro Posada Noguera
*/

#include <bits/stdc++.h>

using namespace std;

int sizes[3];  // L, R, C
               // norte,     sur,        arriba,     abajo,     izquierda,  derecha.
int dir[6][3] = { {0, 1, 0}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}, {0, 0, 1}, {0, 0, -1} };
vector<vector<string>> dungeon(30, vector<string> (30));

struct position{
    int x[3]; // z, x, y

    position(){
        for(int i = 0; i < 3; i++)
            x[i] = 0;
    }

    position(int a, int b, int c){
        x[0] = a;
        x[1] = b;
        x[2] = c;
    }

    position(const int arr[3]){
        for(int i = 0; i < 3; i++)
            x[i] = arr[i];
    }

    position change(int dir[3]){
        position newPos = *this;
        for(int i = 0; i < 3; i++)
            newPos.x[i] += dir[i];
        return newPos;
    }

    char thingCell(){
        return dungeon[x[0]][x[1]][x[2]];
    }

    bool isOnRange(){
        int i = 0;
        bool ans = true;
        while(i < 3 && ans){
            ans = x[i] >= 0 && x[i] < sizes[i];
            i++;
        }
        return ans;
    }

    int operator[](int idx) const{
        return x[idx];
    }

    bool operator<(const position& p) const{
        int i = 0;
        bool ans = false, stop = false;
        while(i < 3 && !stop){
            if(x[i] != p[i]){
                stop = true;
                ans = x[i] < p[i];
            }
            i++;
        }
        return ans;
    }

    void print(){
        for(int i = 0; i < 3; i++)
            cout << x[i];
        cout << endl;
        cout << "Cell: " << thingCell() << endl;
    }
};

position init;

pair<bool, int> bfs(){
    map<position, int> dis;
    queue<position> q;
    bool found = false;
    position exxit;
    dis[init] = 0;
    q.push(init);

    while(!q.empty() && !found){
        position u = q.front();
        q.pop();
        if(u.thingCell() == 'E'){
            found = true;
            exxit = u;
        }
        else{
            for(int i = 0; i < 6; i++){
                position nPos = u.change(dir[i]);
                if(nPos.isOnRange() && nPos.thingCell() != '#' && dis.find(nPos) == dis.end()){
                    dis[nPos] = dis[u] + 1;
                    q.push(nPos);
                }
            }
        }
    }
    return make_pair(found, dis[exxit]);
}

void solve(){
    pair<bool, int> sol = bfs();
    if(sol.first)
        cout << "Escaped in " << sol.second << " minute(s)." << endl;
    else
        cout << "Trapped!" << endl;
}

int main(){
    int i, j, k;
    string line; 
    cin >> sizes[0] >> sizes[1] >> sizes[2];
    while(sizes[0] || sizes[1] || sizes[2]){
        for(i = 0; i < sizes[0]; i++){
            for(j = 0; j < sizes[1]; j++){
                cin >> line;
                dungeon[i][j] = line;
                for(k = 0; k < sizes[2]; k++){
                    if(line[k] == 'S'){
                        init = position (i, j, k);
                    }
                }
            }
        }
        solve();
        cin >> sizes[0] >> sizes[1] >> sizes[2];
    }
    return 0;
}