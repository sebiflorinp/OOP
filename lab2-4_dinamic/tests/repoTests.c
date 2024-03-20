#include "repoTests.h"
#include "assert.h"
#include "../domain/models.h"
#include "../repos/repos.h"

void testGetProductById() {
    // Arrange
    Product product1;
    product1.id = 2;
    Product product2;
    product2.id = 1;
    Product products[100];
    addProductRepo(products, 0, product1);
    addProductRepo(products, 1, product2);

    // Assert
    assert(1 == getProductById(products, 2, 1));
    assert(-1 == getProductById(products, 2, 10));
}

void testAddProductRepo() {
    // Arrange
    Product product1 = createProduct(1, "Computer", "AAAA", "AAAA", 12.0f, 12);
    Product products[100];

    // Assert
    assert(addProductRepo(products, 0, product1) == true);
    assert(addProductRepo(products, 1, product1) == false);
}

void testUpdateProductRepo() {
    // Arrange
    Product product1 = createProduct(1, "Computer", "AAAA", "AAAA", 12.0f, 12);
    Product products[100];
    addProductRepo(products, 0, product1);

    // Assert
    assert(updateProductRepo(products, 1, 1, 30,30) == true);
    assert(updateProductRepo(products, 1, 2, 30, 30) == false);
}

void testDeleteProductRepo() {
    // Arrange
    Product product1 = createProduct(1, "Computer", "AAAA", "AAAA", 12.0f, 12);
    Product products[100];
    addProductRepo(products, 0, product1);

    // Assert
    assert(deleteProductRepo(products, 1, 1) == true);
    assert(deleteProductRepo(products, 1, 10) == false);
}