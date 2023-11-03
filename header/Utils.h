//
// Created by 杨君鹏 on 2023/11/3.
//

#ifndef SILVERLAKEDB_UTILS_H
#define SILVERLAKEDB_UTILS_H
int sqliteHashNoCase(const char *z, int n);
int sqliteStrICmp(const char *zLeft, const char *zRight);
int sqliteStrNICmp(const char *zLeft, const char *zRight, int N);
#endif //SILVERLAKEDB_UTILS_H
