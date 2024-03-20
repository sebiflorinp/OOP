#include <assert.h>
#include "controllerTests.h"
#include "../controllers/controllers.h"

void testAddProductController() {
    // Arrange
    Product products[100];

    // Act
    bool actual1 = addProductController(products, 0, 1, "Computer", "AAAA", "AAAA", "12.2", "10");
    bool actual2 = addProductController(products, 1, 1, "Computer", "AAAA", "AAAA", "12.2", "10");

    // Assert
    assert(actual1 == true);
    assert(actual2 == false);

}

void testUpdateProductController() {
    // Arrange
    Product products[100];
    addProductController(products, 0, 1, "Computer", "AAAA", "AAAA", "12.2", "10");

    // Act
    bool actual1 = updateProductController(products, 1, 1, 5,5.6f);
    bool actual2 = updateProductController(products, 1, 2, 5,5.6f);

    // Assert
    assert(actual1 == true);
    assert(actual2 == false);

}

void testDeleteProductController() {
    // Arrange
    Product products[100];
    addProductController(products, 0, 1, "Computer", "AAAA", "AAAA", "12.2", "10");

    // Act
    bool actual1 = deleteProductController(products, 1, 1);
    bool actual2 = deleteProductController(products, 1, 2);

    // Assert
    assert(actual1 == true);
    assert(actual2 == false);
}

void testGetAvailableProducts() {
    // Arrange
    Product products[100];
    Product result[100];
    addProductController(products, 0, 1, "Computer", "AAAA", "AAAA", "12", "10");
    addProductController(products, 1, 2, "Computer", "BBBB", "BBBB", "11", "0");
    addProductController(products, 2, 3, "Computer", "CCCC", "CCCC", "12", "122");
    addProductController(products, 3, 4, "Computer", "DDDD", "DDDD", "2", "1");
    addProductController(products, 4, 5, "Computer", "DDDD", "DDDD", "1", "1");


    // Act
    int actual1 = getAvailableProducts(products, result, 5, "ascending");

    // Assert
    assert(actual1 == 4);
    assert(result[0].id == 5);
    assert(result[1].id == 4);
    assert(result[2].id == 1);
    assert(result[3].id == 3);

    // Act
    int actual2 = getAvailableProducts(products, result, 5, "descending");

    // Assert
    assert(actual2 == 4);
    assert(result[0].id == 3);
    assert(result[1].id == 1);
    assert(result[2].id == 4);
    assert(result[3].id == 5);
}

void testGetProductsFiltered() {
    // Arrange
    Product products[100];
    Product result[100];
    addProductController(products, 0, 1, "Computer", "AAAA", "AAAA", "12.2", "10");
    addProductController(products, 1, 2, "Computer", "BBBB", "BBBB", "12", "0");
    addProductController(products, 2, 3, "Computer", "CCCC", "CCCC", "11", "12");

    // Act
    int actual1 = getProductsFiltered(products, result, 3, "manufacturer", "AAAA");

    // Assert
    assert(actual1 == 1);
    assert(result[0].id == 1);

    // Act
    int actual2 = getProductsFiltered(products, result, 3, "price", "12");

    // Assert
    assert(actual1 == 1);
    assert(result[0].id == 2);

    // Act
    int actual3 = getProductsFiltered(products, result, 3, "quantity", "0");

    // Assert
    assert(actual1 == 1);
    assert(result[0].id == 2);
}
