/* 
Solución D - Problem D (Store)
Daniel Alejandro Posada Noguera
Abril 19 de 2024

*/

/*
Dudas: 
1. ¿Qué tan recomendable es usar una clase que "una" las demás clases, o una función que "una" a las demás.
2. Si quisiera crear una función auxiliar para una clase, debería hacerlo en la clase misma, aparte, como atributo público o privado.
*/

/* 
Lista de cosas por hacer:
4. Remove Song of a Record que recorre un disco en específico y borra una canción de dicho disco. 
6. Display the collection que imprime en un orden específico todos los discos y las canciones asociadas:
    -> Quisiera crear la función de comparación que organizaría dicha configuración específica, para luego agregar los discos
    y las canciones siguiendo dicho orden, dependiendo si la función da true o false. 
    ->Los discos deben ordenarse primero por los artistas en orden ascendente, luego por año de producción en orden descendente, 
    luego por el número de canciones en orden ascendente, luego por la duración total de las canciones en el disco en orden descendente y 
    finalmente por el id en orden descendente.
    -- Las canciones se ordenaran primero por la duración en orden ascendente, luego por el título en orden ascendente y finalmente por
    el id en orden descendente.

*/

#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std; 

class Song{
    private:
        int year;
        int duration;
        string code;
        string title;
        string artist;
        string gender;
        vector<string> rec;
    public:
        Song(){
            year = 0;
            duration = 0;
            code = "";
            title = "";
            artist = "";
            gender = "";
            rec = {};
        }
        Song( string &c, string &t, string &a, string &g, int y, int d ){
            year = y;
            duration = d;
            code = c;
            title = t;
            artist = a;
            gender = g;
            rec = {};
        }
        void initialize( string &c, string &t, string &a, string &g, int y, int d ){
            year = y;
            duration = d;
            code = c;
            title = t;
            artist = a;
            gender = g;
            rec = {};
        }
        int getYear(){
            return year;
        }
        int getDuration(){
            return duration;
        }
        string getCode(){
            return code;
        }
        string getTittle(){
            return title;
        }
        string getArtist(){
            return artist;
        }
        void associateRecord( string &c ){
            int i = 0, n = rec.size(); 
            bool flag = false;
            vector<string>:: iterator it; 

            while( i <= n && !flag ){
                if( c < rec[ i ] ){
                    rec.insert( rec.begin() + i, c );
                    flag = true;
                }
                i++;    
            }
            if( !flag )
                rec.push_back( c );      
        }
        void removeRecord( string &c ){
            int i = 0, n = rec.size();
            bool flag = false;
            vector<string>:: iterator it = remove( rec.begin(), rec.end(), c );
            rec.erase( it, rec.end() );
        }
        void printRecords(){
            int i, n = rec.size();

            for( i = 0; i < n; i++ )
                cout << rec[ i ] << " ";
            cout << endl;
        }
};

class Record{
    private:
        int year;
        int units;
        int duration;
        vector<Song> v;
        string code;
        string label; 
        string title;
        string artist;   
    public:
        Record(){
            year = 0; 
            units = 0;
            duration = 0;
            v = {};
            code = "";
            label = "";
            title = "";
            artist = "";
        }
        Record( string &c, string &t, string &l, string &a, int y, int u ){
            year = y; 
            units = u;
            duration = 0;
            v = {};
            code = c;
            label = l;
            title = t;
            artist = a;
        }
        void initialize( string &c, string &t, string &l, string &a, int y, int u ){
            year = y; 
            units = u;
            duration = 0;
            v = {};
            code = c;
            label = l;
            title = t;
            artist = a;
        }
        int getYear(){
            return year;
        }
        int getLenght(){
            return v.size();
        }
        int getDuration(){
            return duration;
        }
        string getCode(){
            return code;
        };
        string getTitle(){
            return title;
        }
        string getArtist(){
            return artist; 
        }
        void associateSong( Song &s ){
            v.push_back( s );
        }
        void removeSon( Song &s ){
            int i = 0, n = v.size();
            bool flag = false;
            
        }

};

class Collection{
    private:
        vector<Song> songs; 
        vector<Record> records;
    public:
        Collection(){
            songs = {};
            records = {}; 
        }
        void AddSong( Song &s ){
            songs.push_back( s );
        }
        void AddRecord( Record &r ){
            records.push_back( r );
        }
        void AssociateRecordSong( Song &s, Record &r ){
            string tmp = r.getCode();
            s.associateRecord( tmp );
            r.associateSong( s );
        }
        void Query( Song &s ){
            s.printRecords();
        }
        void Clear(){
            songs.clear();
            records.clear();
        }

};

int main(){
    int cases, duration, year, units;
    string simbol, idSong, idRecord, title, artist, gender, label;
    Song auxSong; 
    Record auxRecord;
    Collection store;

    cin >> cases;
    while( cases ){
        cin >> simbol;
        store.Clear();
        while( simbol != "#" ){
            if( simbol == "+" ){
                cin >>  idSong >> title >> artist >> gender >> year >> duration;
                auxSong.initialize( idSong, title, artist, gender, year, duration );
                store.AddSong( auxSong );
            }
            else if( simbol == "*" ){
                cin >> idRecord >> title >> label >> artist >> year >> units;
                auxRecord.initialize( idRecord, title, label, artist, year, units );
                store.AddRecord( auxRecord );
            }
            else if( simbol == "+>" ){
                cin >> idRecord >> idSong;
            }
            else if( simbol == "->" ){
                cin >> idRecord >> idSong;
            }
            else if( simbol == "?" ){
                cin >> idSong;
            }
            else if( simbol == "&" ){

            }
            cin >> simbol;
        }
        

        cases--;
    }

    return 0;
}