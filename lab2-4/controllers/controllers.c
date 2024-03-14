#include <stdlib.h>
#include "controllers.h"
#include "../domain/validators.h"
#include "../repos/repos.h"

/*
 * Attempts to add a new product in the list of products
 * Preconditions: products: a pointer to an array of instance of the Product struct
 *                numberOfProducts: a positive integer
 *                id: a positive integer
 *                type: a char array with the length of 20
 *                manufacturer: a char array with the length of 20
 *                model: a char array with the length of 20
 *                price: a positive float
 *                quantity: a positive integer
 * Post-conditions: a boolean
 */
bool addProductController(Product* products, int numberOfProducts, int id, char type[20], char manufacturer[20], char model[20],
               char price[20], char quantity[20]) {
    // create the new product
    Product newProduct = createProduct(id, type, manufacturer, model, atof(price), atoi(quantity));
    // add the new product
    bool result = addProductRepo(products, numberOfProducts, newProduct);
    return result;
}

bool updateProductController(Product* products, int numberOfProducts, int productToUpdateId, int newQuantity, float newPrice) {
    // attempt to update the product
    bool result = updateProductRepo(products, numberOfProducts, productToUpdateId, newQuantity, newPrice);
    return result;
}

//bool deleteProduct(Product* products, int numberOfProducts, int productToDeleteId);