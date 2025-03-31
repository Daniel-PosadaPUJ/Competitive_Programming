/* 
Solución E - Problem E (Success)
Daniel Alejandro Posada Noguera
Abril 11 de 2024

*/

#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Letter{
    private:
        int amount;
        char simbol;
    public:
        Letter(){
            amount = 0;
            simbol = '~';
        }
        Letter( char s ){
            amount = 1;
            simbol = s;
        }
        int getAmount(){
            return amount;
        }
        char getSimbol(){
            return simbol;
        }
        void initialize( char s ){
            amount = 1;
            simbol = s;
        }
        void increase(){
            amount++;
        }
        bool operator<( const Letter &l ){
            bool ans = false;
            if( l.amount < amount )
                ans = true;
            return ans; 
        }
};

void countSelect( string &cad, vector<Letter> &v ){
    int i = 1, n = cad.size();
    Letter aux( cad[ 0 ] ); 
    while( i < n ){ 
        if( cad[ i ] != aux.getSimbol() ){
            v.push_back( aux );
            aux.initialize( cad[ i ] );
        }
        else
            aux.increase();
        i++;
    }
    v.push_back( aux );
}

void success( string &cad1, string &cad2 ){
    int i = 0, j, n = cad2.size(), m;
    bool flag;
    vector<Letter> v, w;
    string s = cad2, ans = cad2;
    sort( cad1.begin(), cad1.end() ); 
    sort( s.begin(), s.end() );

    countSelect( cad1, v ); 
    countSelect( s, w );

    sort( v.begin(), v.end() );
    sort( w.begin(), w.end() );

    m = w.size();
    while( i < n ){
        flag = false;
        j = 0;
        while( j < m && !flag ){
            if( ans[ i ] == w[ j ].getSimbol() ){
                ans[ i ] = v[ j ].getSimbol();
                flag = true;
            }
            j++;
        }
        i++;
    }
    cout << ans << endl;  
}

int main(){
    int cases;
    string cad1, cad2;

    cin >> cases;
    while( cases ){
        cin >> cad1;
        cin >> cad2;
        success( cad1, cad2 );
        cases--; 
    }

    return 0; 
}