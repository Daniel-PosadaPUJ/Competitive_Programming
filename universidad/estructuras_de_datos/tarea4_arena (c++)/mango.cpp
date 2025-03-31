/* 
Daniel Alejandro Posada Noguera 
Marzo 21 de 2024
E - Problem E (Mango)

*/

#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>

using namespace std;

int mango( vector<int> &t, vector<int> &c, int l ){ 
    int ans = 1, sum = 0;
    int i = 0, n = t.size(); 
    while( ans && i < n ){
        sum += t[ i ];
        if( t[ i ] > c[ i ] || sum > l ){ 
            ans = 0;
        }
        ++i;
    }
    return ans;
}

int main(){
    int cnt = 1, ans, i, cases, types, limit, aux; 
    vector<int> table, capacity;
    scanf( "%d", &cases );
    while( cases > 0 ){
        table.clear();
        capacity.clear();
        cin >> types >> limit; 
        for( i = 0; i < types; i++ ){
            scanf( "%d", &aux );
            table.push_back( aux );
        }
        for( i = 0; i < types; i++ ){
            scanf( "%d", &aux );
            capacity.push_back( aux );
        }
        ans = mango( table, capacity, limit );
        printf( "Case %d: ", cnt++ );
        if( ans )
            printf( "Yes\n" );
        else
            printf( "No\n" );
        cases--;
    }
    return 0;
}
