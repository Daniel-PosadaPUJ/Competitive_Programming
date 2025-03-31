/*
Solución C - Problem C (Kicker)
Daniel Alejandro Posada Noguera 
Abril 16 de 2024

*/

#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std; 

void split( string &cad, vector<string> &w ){
    int i, n = cad.size();
    string aux = "";
    for( i = 0; i < n; i++ ){
        if( cad[ i ] == ' ' ){
            w.push_back( aux );
            aux = "";
        }
        else    
            aux.push_back( cad[ i ] );
    }
    w.push_back( aux );
}

bool decodeAndCompare( string &cad1, string &cad2, vector<char> &alphabet ){
    int i = 0, n = cad1.size(), m = cad2.size(), k;
    char aux;
    bool ans = true;
    vector<char> alp( 27 );
    vector<string> v, w;

    split( cad1, v );
    split( cad2, w );

    if( n == m && v.size() == w.size() ){
        k = v.size();
        while( i < k && ans ){
            if( v[ i ].size() != w[ i ].size() )
                ans = false;
            i++;
        }
        i = 0;
        while( i < n && ans ){
            aux = cad2[ i ];
            if( aux != ' ' ){
                if( alp[ aux - 97 ] == '\0' )
                    alp[ aux - 97 ] = cad1[ i ];
                else if( alp[ aux - 97 ] != cad1[ i ] )
                    ans = false;
            }
            i++;
        }
    }
    else
        ans = false;

    if( ans )
        alphabet = alp;


    return ans;
}

void kicker( vector<string> &v ){
    int i = 0, j, n = v.size(), k;
    bool flag = false; 
    char aux; 
    string key = "the quick brown fox jumps over the lazy dog", decode;
    vector<char> alphabet( 27 );
    vector<string> w( n );

    while( i < n && !flag ){
        if( decodeAndCompare( key, v[ i ], alphabet ) )
            flag = true;
        i++;
    }
    if( flag )
        for( i = 0; i < n; i++ ){
            k = v[ i ].size();
            decode = "";
            for( j = 0; j < k; j++ ){
                aux = v[ i ][ j ];
                if( aux != ' ' )
                    decode.push_back( alphabet[ v[ i ][ j ] - 97 ] );
                else
                    decode.push_back( ' ' ); 
            }
            cout << decode << endl;
        }
    else 
        cout << "No solution." << endl;

}

int main(){
    int cases;
    string aux = "~";
    vector<string> v;

    cin >> cases; 
    cin.ignore();
    cin.ignore();
    while( cases ){
        v.clear();
        getline( cin, aux );
        while( !aux.empty() ){ 
            v.push_back( aux );
            getline( cin, aux );
        }
        kicker( v );
        cout << "\n";
        cases--;
    }
    return 0;
}