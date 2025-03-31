/* 
Daniel Alejandro Posada Noguera 
Marzo 20 de 2024
A - Problem A (Antiarithmetic)

*/

#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>

using namespace std;

void print_Vector( vector<int> &v ){
    int i, n = v.size();
    printf( "[ ");
    for( i= 0; i < n; i++ ){
        printf( " %d,", v[ i ] );
    }
    printf( "]\n" );
}

int isAntiarithmetic( vector<int> &l, int n ){ 
    int ans = 1, i, j, aux, num;
    vector<int> pos(n);
    for( i = 0; i < n; i++ ){
        pos[ l[ i ] ] = i;
    }
    i = 0;
    while( ans && i < n - 2 ){
        j = i + 1;
        while( ans && j < n - 1 ){
            aux = 2*l[ j ] - l[ i ];
            if( 0 <= aux && aux < n && pos[ aux ] > j )
                ans = 0;
            j++;
        }
        i++;
    }
    return ans;
}

int main(){
    int i, aux, ans, n;
    vector<int> permutation;
    scanf( "%d: ", &n );
    while( n != 0 ){
        permutation.clear();
        for( i = 0; i < n; i++ ){
            scanf( "%d", &aux ); 
            permutation.push_back( aux );
        }
        ans = isAntiarithmetic( permutation, n );
        if( ans )
            printf( "yes\n" );
        else
            printf( "no\n" );
        scanf( "%d: ", &n );
    }        
    return 0;
}


/*Fuentes:
Para Pre y Post incrementos en c++: https://es.stackoverflow.com/questions/135230/operadores-de-pre-y-post-
incremento-c#:~:text=Pre%2Dincremento%3A%20Incrementa%20el%20valor,haber%20retornado%20su%20valor%20previamente.
Referencia de solución en python: https://www.cramirez.info/teaching/estructuras-de-datos/2024-1

*/