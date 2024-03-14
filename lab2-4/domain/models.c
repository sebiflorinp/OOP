#include <string.h>
#include "models.h"

/*
 * Creates a new product
 * Preconditions: id: a positive integer
 *                type: a char array with the length of 20
 *                manufacturer: a char array with the length of 30
 *                model: a char array with the length of 20
 *                price: a positive float
 *                quantity: a positive integer
 * Post-conditions: an instance of the Product struct
 */
Product createProduct(int id, char type[20], char manufacturer[20], char model[20], float price, int quantity) {
    // assigns the values to the newProduct
    Product newProduct;
    newProduct.id = id;
    strcpy(newProduct.type, type);
    strcpy(newProduct.manufacturer, manufacturer);
    strcpy(newProduct.model, model);
    newProduct.price = price;
    newProduct.quantity = quantity;
    return newProduct;
}
