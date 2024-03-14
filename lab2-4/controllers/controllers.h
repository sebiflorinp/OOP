#include <stdbool.h>
#include "../domain/models.h"

#ifndef LAB2_4_CONTROLLERS_H
#define LAB2_4_CONTROLLERS_H

bool addProductController(Product* products, int numberOfProducts, int id, char type[20], char manufacturer[20], char model[20],
                char price[20], char quantity[20]);

bool updateProductController(Product* products, int numberOfProducts, int productToUpdateId, int newQuantity, float newPrice);

bool deleteProduct(Product* products, int numberOfProducts, int productToDeleteId);

#endif //LAB2_4_CONTROLLERS_H
