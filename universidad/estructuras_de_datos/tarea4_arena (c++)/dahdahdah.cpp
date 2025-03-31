/* 
Daniel Alejandro Posada Noguera 
Marzo 24 de 2024
B - Problem B (Dahdahdah)

*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<iostream>

using namespace std;

void replaceCode( string &aux, string &ans ){
    vector<string> dic = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-",
         ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", 
         "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", 
         ".-..-.", ".--.-." };
    vector<char> alp = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
        'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', 
        '5', '6', '7', '8', '9', '.', ',', '?', '`', '!', '/', '(', ')', '&', ':', ';', '=', 
        '+', '-', '_', '"', '@' };
    char comilla[] = "'";
    int i = 0, n = dic.size(), flag = 0;
    while( i < n && !flag ){
        if( aux == dic[ i ] ){
            flag = 1;
            if( i == 39 )
                ans += comilla;
            else 
                ans += alp[ i ];
        }
        i++;
    }
}

string dahdahdah( string &mor ){
    int i = 0, n = mor.size();
    char simbol;
    string ans, aux;
    while( i < n ){
        simbol = mor[ i ];
        if( simbol == ' ' ){
            if( !aux.empty() ){
              replaceCode( aux, ans );
              aux = "";
            }
            if( mor[ i + 1 ] == ' ' )
                ans += " ";
        }
        else
            aux.push_back( simbol );
        i++;
    }
    replaceCode( aux, ans );

    return ans;
}

int main(){
    int n, i = 1;
    string morse, trad;
    scanf( "%d", &n );
    cin.ignore();
    while( i <= n ){
        getline( cin, morse );
        trad = dahdahdah( morse );
        printf( "Message #%d\n", i++ );
        cout << trad << endl;
    }
    return 0;
}