#include <string.h>
#include "utils.h"

/*
 * Returns a valid id for a new product.
 * Preconditions: product: a pointer to an array of instances of the Product struct
 *                numberOfProducts: a positive integer
 * Post-conditions: an integer
 */
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

/*
 * A function that removes the trailing new line from fgets.
 * Preconditions: string: a pointer to a char array
 * Post-conditions: -
 */
void removeTrailingNewLine(char* string) {
    if (strlen(string) > 0) {
        string[strlen(string) - 1] = '\0';
    }
}