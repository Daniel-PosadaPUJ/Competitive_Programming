/*
02 de Febrero de 2025
Solution D-Problem D (Cakey) [Árboles y Grafos 2025-1]
Daniel Alejandro Posada Noguera (8980619)
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int cakey(vector<int> &entry, vector<int> &exit){
    bool dontContinue;
    pair<int, int> auxPair;
    unordered_map<int, int> countTimes;
    unordered_map<int, int>::iterator it;
    priority_queue<pair<int, int>> sortTimes;
    int i = 0, j = 0, cookingTime, amountAux;

    while(i < exit.size()){
        dontContinue = false;
        j = 0;
        while(j < entry.size() && !dontContinue){
            cookingTime = exit[i] - entry[j];
            dontContinue = cookingTime < 0;
            if(!dontContinue){
                countTimes[cookingTime]++;
            }
            j++;
        }
        i++;
        
    }
    for(it = countTimes.begin(); it != countTimes.end(); it++){
        cookingTime = it->first;
        amountAux = it->second;
        auxPair = make_pair(amountAux, -cookingTime);
        sortTimes.push(auxPair);
    }
    cookingTime = -(sortTimes.top().second);
    return cookingTime;
}

int main(){
    int i = 0, N = 0, M = 0, value = 0;
    vector<int> sensorEntrada, sensorSalida;
    while(cin >> N >> M){
        sensorEntrada.clear();
        sensorSalida.clear();
        for(i = 0; i < N; i++){
            cin >> value;
            sensorEntrada.push_back(value);
        }
        for(i = 0; i < M; i++){
            cin >> value;
            sensorSalida.push_back(value);
        }
        cout << cakey(sensorEntrada, sensorSalida) << endl;
    }

    return 0;
}