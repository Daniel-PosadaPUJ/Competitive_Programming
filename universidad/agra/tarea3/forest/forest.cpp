/*
Solution B - Problem B (Forest)
Daniel Alejandro Posada Noguera
Árboles y Grafos (AGRA)
*/

/* PREGUNTAS:
- Mejorar y aprender el uso de scanf, printf.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int cases, N, M;
    int i, j, k;
    string tree;
    vector<string> row;
    vector<vector<string>> forest;

    cin >> cases;
    for(i = 1; i <= cases; i++){
        cin >> N >> M;    
        forest.clear();
        for(j = 0; j < N; j++){
            row.clear();
            for(k = 0; k < M; k++){ 
                cin >> tree;
                row.push_back(tree);
            }
            forest.push_back(row);
        }
        
    }

    return 0;
}
