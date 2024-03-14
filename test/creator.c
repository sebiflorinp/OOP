#include <string.h>
#include "creator.h"

User create(int id, char name[10]) {
    User newUser;
    newUser.id = id;
    strcpy(newUser.name, name);
    return newUser;
}