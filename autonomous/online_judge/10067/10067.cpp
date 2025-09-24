/* Solution problem "10067 Playing with Wheels"
30 de Junio del 2025
Daniel Alejandro Posada Noguera
*/

#include <bits/stdc++.h>

using namespace std;

struct configuration{
    int x[4];

    configuration(){
        for(int i = 0; i < 4; i++)
            x[i] = 0;
    }

    configuration(const int arr[4]){
        for(int i = 0; i < 4; i++)
            x[i] = arr[i];
    }

    configuration leftx(int p){
        configuration res = *this; 
        res.x[p] = (res.x[p] + 9) % 10; 
        return res;
    }

    configuration rightx(int p){ 
        configuration res = *this; 
        res.x[p] = (res.x[p] + 1) % 10;
        return res;
    }

    configuration change(int p, int type){
        configuration ans;
        if(type == 0)
            ans = leftx(p);
        else
            ans = rightx(p);
        return ans;
    }

    void print() const{
        printf("%d %d %d %d\n", x[0], x[1], x[2], x[3]);
    }

    int operator[](int idx) const{
        return x[idx];
    }

    bool operator==(const configuration &t) const{
        int i = 0;
        bool ans = true;
        while(i < 4 && ans){
            ans = (x[i] == t[i]);
            i++;
        }
        return ans;
    }

    bool operator<(const configuration &t) const{
        int i = 0;
        bool ans = false, stop = false;
        while(i < 4 && !stop){
            if(x[i] != t[i]){
                stop = true;
                ans = (x[i] < t[i]);
            }
            i++;
        }
        return ans;
    }
};

int init[4], target[4], configFrbddn[4];
set<configuration> forbiddens;

pair<bool, int> bfs(){
    bool found = false;
    configuration confInit(init), confTarget(target);
    map<configuration, int> dis;
    queue<configuration> q;
    dis[confInit] = 0;
    q.push(confInit);

    while(!q.empty() && !found){
        configuration u = q.front();
        q.pop();
        if(u == confTarget){
            found = true;
        }
        else{
            for(int d = 0; d < 2; d++){
                for(int i = 0; i < 4; i++){
                    configuration nConf = u.change(i, d);
                    if(dis.find(nConf) == dis.end() && forbiddens.find(nConf) == forbiddens.end()){
                        dis[nConf] = dis[u] + 1;
                        q.push(nConf);
                    }
                }
            }
        }
    }
    return make_pair(found, dis[confTarget]);
}

void solve(){
    pair<bool, int> sol = bfs();
    int ans = sol.first ? sol.second : -1;
    printf("%d\n", ans);
}

int main(){
    int cases, n, i, j, k;
    configuration aux;

    scanf("%d", &cases);
    for(i = 0; i < cases; i++){
        forbiddens.clear();
        for(k = 0; k < 4; k++)
            scanf("%d", &init[k]);

        for(k = 0; k < 4; k++)
            scanf("%d", &target[k]);

        scanf("%d", &n);
        for(j = 0; j < n; j++){
            for(k = 0; k < 4; k++)
                scanf("%d", &configFrbddn[k]);

            aux = configuration (configFrbddn);
            forbiddens.insert(aux);
        }
        solve();
    }
    return 0;
}