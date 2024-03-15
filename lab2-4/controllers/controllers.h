#include <stdbool.h>
#include "../domain/models.h"

#ifndef LAB2_4_CONTROLLERS_H
#define LAB2_4_CONTROLLERS_H

bool addProductController(Product* products, int numberOfProducts, int id, char type[20], char manufacturer[20], char model[20],
                char price[20], char quantity[20]);

bool updateProductController(Product* products, int numberOfProducts, int productToUpdateId, int newQuantity, float newPrice);

bool deleteProductController(Product* products, int numberOfProducts, int productToDeleteId);

int getAvailableProducts(Product* products, Product* result, int numberOfProducts, char ordering[20]);

int getProductsFiltered(Product* products, Product* result, int numberOfProducts, char criteria[20], char valueToCompareWith[20]);

#endif //LAB2_4_CONTROLLERS_H
