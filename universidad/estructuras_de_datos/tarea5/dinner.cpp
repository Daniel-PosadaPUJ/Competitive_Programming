/* 
A - Problem A (Dinner)
Daniel Alejandro Posada Noguera 
Abril 22 de 2024

*/

#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

class Team{
    private: 
        int amount;
        int pos; 
    public:
        Team(){
            amount = 0;
            pos = 1; 
        }
        Team( int am, int ps ){
            amount = am;
            pos = ps;
        }

        int getAmount(){
            return amount;
        }  
        int getPos(){
            return pos;
        }
        void setTeam( int am, int ps ){
            amount = am;
            pos = ps;
        }
        void decrease(){
            amount--;
        }

};

void printfVector( vector<int> &v ){
    int i; 
    for( i = 0; i < v.size() - 1; i++ )
        cout << v[ i ] << " "; 
    cout << v[ i ] << endl; 
}

bool compare( Team &t1, Team &t2 ){
    bool ans;

    if( t1.getAmount() != t2.getAmount() )
        ans = t1.getAmount() > t2.getAmount();
    else
        ans = t1.getPos() > t2.getPos();

    return ans;
}

int assign( Team &t, vector<int> &m, vector<vector<int>> &c ){
    int i = 0, n = m.size(), ans = 1;
    bool flag = false; 
    while( i < n && !flag ){
        if( m[ i ] > 0 && t.getAmount() > 0 ){
            c[ t.getPos() ].push_back( i + 1 );
            t.decrease();
            m[ i ]--;
        }

        if( t.getAmount() == 0 )
            flag = true;
        i++;
    }
    if( !flag )
        ans = 0;

    return ans;
}

void dinner( vector<Team> &teams, vector<int> &tables ){
    int ans = 1, i = 0, n = teams.size();
    Team aux; 
    vector<vector<int>> config( n );

    sort( teams.begin(), teams.end(), compare );

    while( i < n && ans ){
        aux = teams[ i ];
        ans = assign( aux, tables, config );
        i++;
    }

    cout << ans << endl; 
    if( ans ){
        for( i = 0; i < n; i++ )
            printfVector( config[ i ] );    
    }
}

int main(){
    int N, M, i, aux;
    Team auxt; 
    vector<int> tables;
    vector<Team> teams; 
    cin >> M >> N; 
    while( N != 0 && M != 0 ){
        for( i = 0; i < M; i++ ){
            cin >> aux;
            auxt.setTeam( aux, i );
            teams.push_back( auxt );    
        }
        for( i = 0; i < N; i++ ){
            cin >> aux;
            tables.push_back( aux );
        }

        dinner( teams, tables );

        teams.clear(); tables.clear();
        cin >> M >> N; 
    }
    return 0;
}

