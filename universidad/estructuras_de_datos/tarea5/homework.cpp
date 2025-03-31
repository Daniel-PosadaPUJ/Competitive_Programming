/*
Solución B - Problem B (Homework)
Daniel Alejandro Posada Noguera 
Abril 10 de 2024

*/

#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

class Subject{
    private:
        int term;
        string matter;
    public:
        Subject(){
            term = 0;
            matter = "";
        }
        Subject( int d, string m ){
            term = d;
            matter = m;
        }
        int getTerm(){
            return term;
        }
        string getMatter(){
            return matter;
        }
        void setSubject( int d, string m ){
            term = d;
            matter = m;
        }
        bool operator==( const Subject &s ){
            bool ans = false;
            if( s.matter == matter )
                ans = true;
            return ans;
        }
};

int main(){
    int cases, i, j, n, day;
    string matter;
    Subject aux;
    vector<Subject> v; 
    vector<Subject>:: iterator it;

    cin >> cases;
    for( i = 1; i <= cases; i++ ){
        cin >> n;
        for( j = 0; j < n; j++ ){
            cin >> matter >> day; 
            aux.setSubject( day, matter );
            v.push_back( aux );
        }
        cin >> day >> matter; 
        aux.setSubject( day, matter );
        it = find( v.begin(), v.end(), aux);
        if( it == v.end() || (*it).getTerm() > aux.getTerm() + 5) 
            cout << "Case " << i << ": Do your own homework!" << endl;
        else if( (*it).getTerm() <= aux.getTerm() )
            cout << "Case " << i << ": Yesss" << endl; 
        else
            cout << "Case " << i << ": Late" << endl;

        v.clear();
    }

    return 0;
}
