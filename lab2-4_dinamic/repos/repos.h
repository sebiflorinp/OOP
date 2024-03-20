#include "../domain/models.h"
#include <stdbool.h>

#ifndef LAB2_4_REPOS_H
#define LAB2_4_REPOS_H

int getProductById(Product* products, int numberOfProducts, int id);

bool addProductRepo(Product* products, int numberOfProducts, Product newProduct);

bool updateProductRepo(Product* products, int numberOfProducts, int productToUpdateId, int newQuantity, float newPrice);

bool deleteProductRepo(Product* products, int numberOfProducts, int productToDeleteId);

#endif //LAB2_4_REPOS_H
