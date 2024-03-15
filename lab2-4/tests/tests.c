#include "tests.h"
#include "repoTests.h"
#include "validatorsTest.h"

void runAllTests() {
    // repo tests
    testGetProductById();
    testAddProductRepo();
    testUpdateProductRepo();
    testDeleteProductRepo();

    // validators tests
    testValidateId();
    testValidateManufacturer();
    testValidateModel();
    testValidateOption();
    testValidatePrice();
    testValidateQuantity();
    testValidateType();
}