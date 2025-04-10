/*
4 de Abril de 2025
Solution C-Problem C (Fredericton) [Árboles y Grafos 2025-1]
Daniel Alejandro Posada Noguera (8980619)
*/

/* COMPLEJIDAD COMPUTACIONAL

*/

#include <cstdio>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n_cities;
vector<string> topoCities;
map<string, int> cities;
vector<vector<pair<int, int>>> graph(250);

int solve(int query){
    int answer = -1;
    
    return answer;
}

int main(){
    int i, j, cases, mFlights, costFlight, kQuerys, query, solution;
    string city, destination;

    cin >> cases;
    cin.ignore();
    for(i = 1; i <= cases; i++){
        cout << "Scenario #" << i << endl;
        cin >> nCities;

        cities.clear();
        topoCities.clear();
        for(j = 0; j < nCities; i++){
            graph[j].clear();
        }

        for(j = 0; j < nCities; j++){
            cin >> city;
            cities[city] = j;
            topoCities.push_back(city);
        }
        cin >> mFlights;
        for(j = 0; j < mFlights; j++){
            cin >> city >> destination >> costFlight;
            graph[cities[city]].push_back(make_pair(cities[destination], costFlight));
        }
        cin >> kQuerys;
        for(j = 0; j < kQuerys; j++){
            cin >> query;
            solution = solve(query);
            cout << "Total cost of flight(s) is $" << solution << endl;
        }
            
    }   

    return 0;
}