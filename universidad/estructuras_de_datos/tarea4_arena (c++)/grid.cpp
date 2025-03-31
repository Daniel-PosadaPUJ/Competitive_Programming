/* 
Daniel Alejandro Posada Noguera 
Marzo 23 de 2024
D - Problem D (Grid)

*/

#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>

using namespace std;

void moveTo( vector<int> &v, int i, int j ){
    int temp;
    while( j < i ){
        temp = v[ i ];
        v[ i ] = v[ i - 1 ];
        v[ i - 1 ] = temp; 
        i--;
    }
}

int grid( vector<int> &s, vector<int> &f ){
    int ans = 0, i, n = f.size(), aux;
    vector<int> pos(n+1);
    for( i = 0; i < n ; i++ )
        pos[ f[ i ] ] = i;
    i = 0;
    while( i < n ){
        aux = pos[ s[ i ] ];
        if( aux < i ){
            moveTo( s, i, aux );
            ans += i - aux;
            i = aux; 
        }
        else
            i++;
    }
    return ans;
}

int main(){
    int i, n, aux, mov;
    vector<int> start, finish;
    while( cin >> n ){
        start.clear();
        finish.clear();
        for( i = 0; i < n; i++ ){
            //cin >> aux; 
            scanf( "%d", &aux );
            start.push_back( aux );
        }
        for( i = 0; i < n; i++ ){
            scanf( "%d", &aux );
            //cin >> aux;
            finish.push_back( aux );
        }
        mov = grid( start, finish );
        printf( "%d\n", mov );
    }
    return 0;
}