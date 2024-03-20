#include <stdbool.h>
#include "repos.h"

/*
 * Attempts to return the product with the received id.
 * Preconditions: products: a pointer to an array of instance of the Product struct
 *                numberOfProducts: a positive integer
 *                id: a positive integer
 * Post-conditions: an integer
 */
int getProductById(Product* products, int numberOfProducts, int id) {
    // search the product
    int position = -1;
    for (int i = 0; i < numberOfProducts; i++) {
        if (products[i].id == id) {
            position = i;
        }
    }

    return position;
}

/*
 * Attempts to add the received product in the list of products
 * Preconditions: products: a pointer to an array with instances of the Product struct
 *                numberOfProducts: a positive integer
 *                newProduct: an instance of the Product struct
 * Post-conditions: a boolean
 */
bool addProductRepo(Product* products, int numberOfProducts, Product newProduct) {
    // check if there's already a product with the id of the newProduct
    for (int i = 0; i < numberOfProducts; i++) {
        if (products[i].id == newProduct.id) {
            return false;
        }
    }

    // add the new product
    products[numberOfProducts] = newProduct;
    return true;
}

/*
 * Attempts to update the product with the received id.
 * Preconditions: products: a pointer to an array with instances of Product structs
 *                numberOfProducts: a positive integer
 *                productToUpdateId: a positive integer
 *                newType: a char array
 *                newPrice: a positive float
 * Post-conditions: a boolean
 */
bool updateProductRepo(Product* products, int numberOfProducts, int productToUpdateId, int newQuantity, float newPrice) {
    // check if there is a product with the id of productToUpdateId
    int position = -1;
    for (int i = 0; i < numberOfProducts; i++) {
        if (products[i].id == productToUpdateId) {
            position = i;
        }
    }

    // if the product is found, update it
    if (position != -1) {
        products[position].quantity = newQuantity;
        products[position].price = newPrice;
        return true;
    }

    return false;
}

/*
 * Attempts to delete the product with the received id.
 * Preconditions: products: a pointer to an array with instance of the Product struct
 *                numberOfProducts: a positive integer
 *                productToDeleteId: a positive integer
 * Post-conditions: a boolean
 */
bool deleteProductRepo(Product* products, int numberOfProducts, int productToDeleteId) {
    // check if there is a product with the id of productToDeleteId
    int position = -1;
    for (int i = 0; i < numberOfProducts; i++) {
        if (products[i].id == productToDeleteId) {
            position = i;
        }
    }

    // if the product was found, delete it
    if (position != - 1) {
        for (int i = position; i < numberOfProducts; i++) {
            products[i] = products[i + 1];
            return true;
        }
    }

    return false;
}