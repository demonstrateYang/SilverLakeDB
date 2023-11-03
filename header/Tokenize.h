//
// Created by 杨君鹏 on 2023/11/3.
//

#ifndef SILVERLAKEDB_TOKENIZE_H
#define SILVERLAKEDB_TOKENIZE_H
#define KEY_HASH_SIZE 37

#include <cstring>
#include "Utils.h"



class Tokenize {
private:
    char *kName;            /* The keyword name */
    int len;                /* Number of characters in the keyword */
    char *tokenType;          /* The token value for this keyword */
    Tokenize *Pnext;        /* Next keyword with the same hash */

public:
    Tokenize();
    ~Tokenize();
    Tokenize(char *name,int len,char * type,Tokenize* p){
        this->kName = name;
        this->len = len;
        this->tokenType = type;
        this->Pnext = p;
    }
    int getTokenLen() const{return this->len;}
    char *getTokenName() const{return this->kName;}
    char *getTokenType() const{return this->tokenType;}
    Tokenize *getNext() const{return this->Pnext;}

    void setTokenLen(int len){this->len = len;}
    void setTokenName(char *name){this->kName = name;}
    void setTokenNext (Tokenize *p){this->Pnext = p;}
    static int sqliteKeywordCode(const char *z,int n);
};


#endif //SILVERLAKEDB_TOKENIZE_H
