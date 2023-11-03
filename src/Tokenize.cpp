//
// Created by 杨君鹏 on 2023/11/3.
//

#include "../header/Tokenize.h"
static Tokenize *apHashTable[KEY_HASH_SIZE];
/*
** This function looks up an identifier to determine if it is a
** keyword.  If it is a keyword, the token code of that keyword is
** returned.  If the input is not a keyword, TK_ID is returned.
*/
static Tokenize aKeywordTable[] = {
        { "ALL",               0, "TK_ALL",              0 },
        { "AND",               0, "TK_AND",              0 },
        { "AS",                0, "TK_AS",               0 },
        { "ASC",               0, "TK_ASC",              0 },
        { "BETWEEN",           0, "TK_BETWEEN",          0 },
        { "BY",                0, "TK_BY",               0 },
        { "CHECK",             0, "TK_CHECK",            0 },
        { "CONSTRAINT",        0, "TK_CONSTRAINT",       0 },
        { "COPY",              0, "TK_COPY",             0 },
        { "CREATE",            0, "TK_CREATE",           0 },
        { "DEFAULT",           0, "TK_DEFAULT",          0 },
        { "DELETE",            0, "TK_DELETE",           0 },
        { "DELIMITERS",        0, "TK_DELIMITERS",       0 },
        { "DESC",              0, "TK_DESC",             0 },
        { "DISTINCT",          0, "TK_DISTINCT",         0 },
        { "DROP",              0, "TK_DROP",             0 },
        { "EXCEPT",            0, "TK_EXCEPT",           0 },
        { "EXPLAIN",           0, "TK_EXPLAIN",          0 },
        { "FROM",              0, "TK_FROM",             0 },
        { "GLOB",              0, "TK_GLOB",             0 },
        { "GROUP",             0, "TK_GROUP",            0 },
        { "HAVING",            0, "TK_HAVING",           0 },
        { "IN",                0, "TK_IN",               0 },
        { "INDEX",             0, "TK_INDEX",            0 },
        { "INSERT",            0, "TK_INSERT",           0 },
        { "INTERSECT",         0, "TK_INTERSECT",        0 },
        { "INTO",              0, "TK_INTO",             0 },
        { "IS",                0, "TK_IS",               0 },
        { "ISNULL",            0, "TK_ISNULL",           0 },
        { "KEY",               0, "TK_KEY",              0 },
        { "LIKE",              0, "TK_LIKE",             0 },
        { "NOT",               0, "TK_NOT",              0 },
        { "NOTNULL",           0, "TK_NOTNULL",          0 },
        { "NULL",              0, "TK_NULL",             0 },
        { "ON",                0, "TK_ON",               0 },
        { "OR",                0, "TK_OR",               0 },
        { "ORDER",             0, "TK_ORDER",            0 },
        { "PRIMARY",           0, "TK_PRIMARY",          0 },
        { "SELECT",            0, "TK_SELECT",           0 },
        { "SET",               0, "TK_SET",              0 },
        { "TABLE",             0, "TK_TABLE",            0 },
        { "UNION",             0, "TK_UNION",            0 },
        { "UNIQUE",            0, "TK_UNIQUE",           0 },
        { "UPDATE",            0, "TK_UPDATE",           0 },
        { "USING",             0, "TK_USING",            0 },
        { "VACUUM",            0, "TK_VACUUM",           0 },
        { "VALUES",            0, "TK_VALUES",           0 },
        { "WHERE",             0, "TK_WHERE",            0 },
};
static int sqliteKeywordCode(const char *z,int n){
    int h;
    Tokenize *p;
    if(aKeywordTable[0].getTokenLen() == 0){
        /* Initialize the keyword hash table */
        int i;
        int n;
        //this is a fixed value
        n = sizeof(aKeywordTable)/sizeof (aKeywordTable[0]);
        for(i = 0; i < n; i ++){
            aKeywordTable[i].setTokenLen(strlen(aKeywordTable[i].getTokenName()));
            h = sqliteHashNoCase(aKeywordTable[i].getTokenName(),aKeywordTable[i].getTokenLen());
            h %= KEY_HASH_SIZE;
            aKeywordTable[i].setTokenNext(apHashTable[h]);
            apHashTable[h] = &aKeywordTable[i];
        }
    }
    h = sqliteHashNoCase(z,n) % KEY_HASH_SIZE;
    for(p = apHashTable[h]; p; p = p->getNext()){
        if(p->getTokenLen() == n )
    }
}

Tokenize::~Tokenize() {

}

Tokenize::Tokenize() {

}
