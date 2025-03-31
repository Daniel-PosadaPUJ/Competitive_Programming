/*
Subject Class Implementation

*/

#include<cstdio>
#include<cstdlib>
#include "subject.h"

Subject::Subject(){
    term = 0;
    matter = "";
}

Subject::Subject( int d, string m ){
    term = d;
    matter = m;
}

int Subject::getTerm(){
    return term;
}

string Subject::getMatter(){
    return matter;
}

void Subject::setSubject( int d, string m ){
    term = d;
    matter = m;
}

bool Subject::operator==( Subject &s ){
    bool ans = false;
    if( s.getMatter() == matter && s.getTerm() >= term + 5 )
        ans = true;
    return ans;
}