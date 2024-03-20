#include <assert.h>
#include "utilsTests.h"
#include "../domain/models.h"
#include "../utils/utils.h"
#include "../controllers/controllers.h"

void testGetIdForNewProduct() {
    // Arrange
    Product products[100];
    addProductController(products, 0, 2, "Computer", "AAAA", "AAAA", "12.2", "1");

    // Act
    int actual1 = getIdForNewProduct(products, 1);

    // Assert
    assert(actual1 == 3);
}
