/*
Subject Class

*/

#include<string>

using namespace std;

class Subject{
    private:
        int term;
        string matter;
    public:
        Subject();
        Subject( int, string );
        int getTerm();
        string getMatter();
        void setSubject( int, string );
        bool operator==( Subject & );
};