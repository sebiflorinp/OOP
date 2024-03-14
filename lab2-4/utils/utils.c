#include "utils.h"

int getIdForNewProduct(Product* product, int numberOfProducts) {
    // find the max id in the list of products
    int maxId = 0;
    for (int i = 0; i < numberOfProducts; i++) {
        if (product[i].id > maxId) {
            maxId = product[i].id;
        }
    }
    return ++maxId;
}

void removeTrailingNewLine(char* string) {
    if (strlen(string) > 0) {
        string[strlen(string) - 1] = '\0';
    }
}