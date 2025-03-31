/*
14 de Febrero de 2025
Solution A-Problem A (Bit) [Árboles y Grafos 2025-1]
Daniel Alejandro Posada Noguera (8980619)
*/

/* Complejidad Computacional:
Dado que cada celda de la matriz es visitada un número constante de veces y no hay solapamiento innecesario
entre las submatrices, la complejidad total depende únicamente del tamaño de la matriz, lo que resulta en O(N*M), 
donde N es el número de filas de la matriz y M es el número de columnas.
*/

/* PREGUNTAS
1. Para inputs que sean un único caracter, ¿Es irrelevante escoger usar un char o un string?
*/

#include <vector>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

void readB(int numCols, string &input, vector<string> &bitMap){
    int i = 0, j = 0;
    string row;
    while(i < input.size()){
        row.push_back(input[i]);
        if((i + 1) % numCols == 0 || (i + 1) == input.size()){
            bitMap[j] = row;
            row.clear();
            j++;
        }
        i += 1;
    }
}

string descompressB(vector<string> &bitMapB) {
    string result;
    for(int i = 0; i < bitMapB.size(); i++){
        result += bitMapB[i];
    }
    return result;
}

void transformToB(int &l, int rowPos, int colPos, int n, int m, string &bitMapD, vector<string> &bitMapB){
    char simbol = bitMapD[l];
    l += 1;
    if(simbol == '1' || simbol == '0'){
        int i = 0, j;
        while(i < n){
            j = 0;
            while(j < m){
                bitMapB[rowPos + i][colPos + j] = simbol;
                j++;
            }
            i++;
        } 
    }
    else{
        int ceilN = ceil(n/2.0), ceilM = ceil(m/2.0), floorN = floor(n/2.0), floorM = floor(m/2.0);
        if(n > 1 && m > 1){
            transformToB(l, rowPos, colPos, ceilN, ceilM, bitMapD, bitMapB);
            transformToB(l, rowPos, colPos + ceilM, ceilN, floorM, bitMapD, bitMapB);
            transformToB(l, rowPos + ceilN, colPos, floorN, ceilM, bitMapD, bitMapB);
            transformToB(l, rowPos + ceilN, colPos + ceilM, floorN, floorM, bitMapD, bitMapB);
        }
        else if(m == 1){
            transformToB(l, rowPos, colPos, ceilN, m, bitMapD, bitMapB);
            transformToB(l, rowPos + ceilN, colPos, floorN, m, bitMapD, bitMapB);
        }
        else{
            transformToB(l, rowPos, colPos, n, ceilM, bitMapD, bitMapB);
            transformToB(l, rowPos, colPos + ceilM, n, floorM, bitMapD, bitMapB);
        }
    }
}

string transformToD(int rowPos, int colPos, int n, int m, vector<string> &bitMapB){
    string ans;
    if(n == 1 && m == 1){
        ans = string(1, bitMapB[rowPos][colPos]);
    }
    else{
        string topl, topr, botl, botr;
        int ceilN = ceil(n/2.0), ceilM = ceil(m/2.0), floorN = floor(n/2.0), floorM = floor(m/2.0);
        if(n > 1 && m > 1){
            topl = transformToD(rowPos, colPos, ceilN, ceilM, bitMapB);
            topr = transformToD(rowPos, colPos + ceilM, ceilN, floorM, bitMapB);
            botl = transformToD(rowPos + ceilN, colPos, floorN, ceilM, bitMapB);
            botr = transformToD(rowPos + ceilN, colPos + ceilM, floorN, floorM, bitMapB);
            if(topl == topr && topr == botl && botl == botr && botr == topl && (topl == "1" || topl == "0")){
                ans = topl;
            }
            else{
                ans = "D" + topl + topr + botl + botr;
            }
        }
        else if(m == 1){
            topl = transformToD(rowPos, colPos, ceilN, m, bitMapB);
            botl = transformToD(rowPos + ceilN, colPos, floorN, m, bitMapB);
            if(topl == botl && (topl == "1" || topl == "0")){
                ans = topl;
            }
            else{
                ans = "D" + topl + botl;
            }
        }
        else{
            topl = transformToD(rowPos, colPos, n, ceilM, bitMapB);
            topr = transformToD(rowPos, colPos + ceilM, n, floorM, bitMapB);
            if(topl == topr && (topl == "1" || topl == "0")){
                ans = topl;
            }
            else{
                ans = "D" + topl + topr;
            }
        }
    }   
    return ans;
}

void printOutput(string representationForm, int n, int m, string &bitMapD, vector<string> &bitMapB){
    int i;
    string line, bitMapToShow;
    bool flag = representationForm == "D";
    representationForm = flag ? "B" : "D";
    bitMapToShow = flag ? descompressB(bitMapB) : bitMapD;

    printf("%s %3d %3d\n", representationForm.c_str(), n, m);
    for(i = 0; i < bitMapToShow.size(); i++){
        line.push_back(bitMapToShow[i]);
        if((i + 1) % 50 == 0 || (i + 1) == bitMapToShow.size()){
            printf("%s\n", line.c_str());
            line.clear();
        }
    }
}

void solve(string representationForm, int n, int m, string &generalInput){
    int l = 0;
    string bitMapD;
    vector<string> bitMapB(n, string(m, '0'));
    if(representationForm == "B"){
        readB(m, generalInput, bitMapB);
        bitMapD = transformToD(0, 0, n, m, bitMapB);
    }
    else{
        bitMapD = generalInput;
        transformToB(l, 0, 0, n, m, bitMapD, bitMapB);
    }
    printOutput(representationForm, n, m, bitMapD, bitMapB);
}

int main(){
    int N, M;
    bool flag;
    string line, generalInput, representationForm, formAux;
    cin >> representationForm;
    while(representationForm != "#"){
        cin >> N >> M;
        generalInput.clear();
        flag = true;
        while(flag){
            cin >> line;
            if(line != "B" && line != "D" && line != "#"){
            generalInput += line;
            }
            else{
                flag = false;
                formAux = representationForm;
                representationForm = line;
            }
        }
        solve(formAux, N, M, generalInput);
    }

    return 0;
}