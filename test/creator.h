#ifndef TEST_CREATOR_H
#define TEST_CREATOR_H

typedef struct {
    int id;
    char name[10];
}User;

User create(int id, char name[10]);
#endif //TEST_CREATOR_H
