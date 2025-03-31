/* 
Daniel Alejandro Posada Noguera 
Marzo 22 de 2024
C - Problem C (Die)

*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<iostream>


using namespace std;

//Preguntar una mejor forma de escribir una lista de condicionales, o de escribir este codigo más bello
int die( string &dir, vector<int> &num ){ 
    int ans = num[ 0 ];
    if( dir == "north" ){
        num[ 0 ] = 7 - num[ 1 ];
        num[ 1 ] = ans;
    }
    if( dir == "east" ){
        num[ 0 ] = num[ 2 ];
        num[ 2 ] = 7 - ans;
    }
    if( dir == "west" ){
        num[ 0 ] = 7 - num[ 2 ];
        num[ 2 ] = ans;
    }
    if( dir == "south" ){
        num[ 0 ] = num[ 1 ];
        num[ 1 ] = 7 - ans;
    }
    ans = num[ 0 ];
    return ans;
}

int main(){
    int i, n, top;
    string direction;
    char aux[ 10 ];
    vector<int> numbers;
    scanf( "%d", &n );
    while( n != 0 ){
        numbers = { 1, 2, 3 };
        for( i = 0; i < n; i++ ){
            scanf( "%s", aux );
            direction = string( aux );
            top = die( direction, numbers );
        }
        printf( "%d\n", top );
        scanf( "%d", &n );
    }
    return 0;
}