/*
Solution Parcial Práctico Opcional (Zlatan)
Daniel Alejandro Posada Noguera
Árboles y Grafos (AGRA)
*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int number_from_digits(vector<int> &digits){
    int i, n = digits.size(), number = 0;
    vector<int> pows = {1000, 100, 10, 1};
    for(i = 0; i < n; i++){
        number += digits[i] * pows[i];
    }
}

int bfs_Aux(vector<int> &init, vector<int> &targ, vector<int> &vis){

}

int solve(vector<int> &init, vector<int> &targ, vector<int> &forbid){

}

int convert_to_number(string &s){

}

int main(){
    int cases, aux, i, j, n, ans;
    vector<int> initial(4), target(4), forbiddens;
    cin >> cases;
    for(i = 0; i < cases; i++){
        for(j = 0; j < 4; j++) 
            cin >> initial[j];
        for(j = 0; j < 4; j++)
            cin >> target[j];
        cin >> n;
        forbiddens = vector<int> (n);
        for(i = 0; i < n; i++){
            cin >> aux;
            forbiddens[i] = convert_to_number(aux);
        }
        ans = solve(initial, target, forbiddens);
        cout << ans << endl;
        cin >> aux;
    }

    return 0;
}