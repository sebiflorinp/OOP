#include <stdlib.h>
#include <string.h>
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

/*
 * Attempts to update the product with the received id
 * Preconditions: products: a pointer to the array of instances of the Product struct
 *                numberOfProducts: a positive integer
 *                productToUpdateId: a positive integer
 *                newQuantity: a positive integer
 *                newPrice: a positive float
 * Post-conditions: a boolean
 */
bool updateProductController(Product* products, int numberOfProducts, int productToUpdateId, int newQuantity, float newPrice) {
    // attempt to update the product
    bool result = updateProductRepo(products, numberOfProducts, productToUpdateId, newQuantity, newPrice);
    return result;
}

/*
 * Attempts to delete the product with the received id
 * Preconditions: products: a pointer to the array of instances of the Product struct
 *                numberOfProducts: a positive integer
 *                productToDeleteId: a positive integer
 * Post-conditions: a boolean
 */
bool deleteProductController(Product* products, int numberOfProducts, int productToDeleteId) {
    // attempt to delete the product
    bool result = deleteProductRepo(products, numberOfProducts, productToDeleteId);
    return result;
}

/*
 * Puts in the result array pointer all available products sorted ascending or descending
 * Preconditions: products: a pointer to the array of instances of the Product struct
 *                result: a pointer to the array of instances of the Product struct
 *                numberOfProducts: a positive integer
 *                ordering: a char array with the length of 20
 * Post-conditions: an integer
 */
int getAvailableProducts(Product* products, Product* result, int numberOfProducts, char ordering[20]) {
    // go through all products and only copy those that are still available
    int availableProducts = 0;
    for (int i = 0; i < numberOfProducts; i++) {
        if (products[i].quantity > 0) {
            result[i] = products[i];
            availableProducts++;
        }
    }
    // check the ordering and sort the products accordingly
    if (strcmp(ordering, "ascending") == 0) {
        // sort in ascending order
        for (int i = 0; i < availableProducts - 1; i++) {
            for (int j = i + 1; j < availableProducts; j++) {
                if (result[i].price > result[j].price) {
                    Product aux = result[i];
                    result[i] = result[j];
                    result[j] = aux;

                } else if (result[i].price == result[j].price) {
                    if (result[i].quantity > result[j].quantity) {
                        Product aux = result[i];
                        result[i] = result[j];
                        result[j] = aux;
                    }
                }
            }
        }
    } else {
        // sort in descending order
        for (int i = 0; i < availableProducts - 1; i++) {
            for (int j = i + 1; j < availableProducts; j++) {
                if (products[i].price < products[j].price) {
                    Product aux = products[i];
                    products[i] = products[j];
                    products[j] = aux;

                } else if (products[i].price == products[j].price) {
                    if (products[i].quantity < products[j].quantity) {
                        Product aux = products[i];
                        products[i] = products[j];
                        products[j] = aux;
                    }
                }
            }
        }
    }

    return availableProducts;
}

/*
 * Puts in the result array pointer the products filtered by a certain criteria
 * Preconditions: products: a pointer to the array of instances of the Product struct
 *                result: a pointer to the array of instances of the Product struct
 *                numberOfProducts: a positive integer
 *                criteria: a char array with the length of 20
 *                valueToCompareWith: a char array with the length of 20
 * Post-conditions: an integer
 */
int getProductsFiltered(Product* products, Product* result, int numberOfProducts, char criteria[20], char valueToCompareWith[20]) {
    int numberOfFilteredProducts = 0;
    if (strcmp(criteria, "manufacturer") == 0) {
        // filter by manufacturer
        for (int i = 0; i < numberOfProducts; i++) {
            if (strcmp(products[i].manufacturer, valueToCompareWith) == 0) {
                result[numberOfFilteredProducts] = products[i];
                numberOfFilteredProducts++;
            }
        }
    } else if (strcmp(criteria, "price") == 0) {
        // filter by price
        for (int i = 0; i < numberOfProducts; i++) {
            if (products[i].price == atof(valueToCompareWith)) {
                result[numberOfFilteredProducts] = products[i];
                numberOfFilteredProducts++;
            }
        }
    } else if (strcmp(criteria, "quantity") == 0) {
        // filter by quantity
        for (int i = 0; i < numberOfProducts; i++) {
            if (products[i].quantity == atoi(valueToCompareWith)) {
                result[numberOfFilteredProducts] = products[i];
                numberOfFilteredProducts++;
            }
        }
    }

    return numberOfFilteredProducts;
}
