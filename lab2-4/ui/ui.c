#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "ui.h"
#include "../domain/validators.h"
#include "../controllers/controllers.h"
#include "../utils/utils.h"

void app() {
    printf("This is a electronics store shop.\n");

    bool running = true;
    Product products[100];
    Product productsAfterQuery[100];
    int numberOfProducts = 0;
    int availableProducts;
    // needed for fgets to pause the execution of the program
    char dummyInput[100];
    while (running) {
        printf(
            "Choose one of the following commands:\n"
           "  1. Add new product.\n"
           "  2. Update product.\n"
           "  3. Delete product.\n"
           "  4. Display available products.\n"
           "  5. Display products filtered by a certain criteria.\n"
           "  6. Exit the application.\n"
           );
        char option[20];
        fgets(option, 20, stdin);
        removeTrailingNewLine(option);
        if (validateOption(option)) {
            switch (atoi(option)) {
                // add new product feature
                case 1:

                    // get type
                    printf("Input the type of the product, the product can be a Laptop, a Computer or a Fridge.\n");
                    char type[20];
                    fgets(type, 20, stdin);
                    removeTrailingNewLine(type);

                    // get id for new product
                    int id = getIdForNewProduct(products, numberOfProducts);

                    // get manufacturer
                    printf("Input the manufacturer of the product.\n");
                    char manufacturer[20];
                    fgets(manufacturer, 20, stdin);
                    removeTrailingNewLine(manufacturer);

                    // get model
                    printf("Input the model of the product.\n");
                    char model[20];
                    fgets(model, 20, stdin);
                    removeTrailingNewLine(model);

                    // get price
                    printf("Input the price of the product.\n");
                    char price[20];
                    fgets(price, 20, stdin);
                    removeTrailingNewLine(price);

                    // get quantity
                    printf("Input the quantity of the product.\n");
                    char quantity[20];
                    fgets(quantity, 20, stdin);
                    removeTrailingNewLine(quantity);

                    // check if the input data is valid
                    if (
                            validateType(type) &&
                            validateManufacturer(manufacturer) &&
                            validateModel(model) &&
                            validatePrice(price) &&
                            validateQuantity(quantity)
                            ) {
                        // add the product if the data is valid
                        bool result = addProductController(products, numberOfProducts, id, type, manufacturer, model, price, quantity);
                        if (result) {
                            printf("The product was added successfully.\n");
                            numberOfProducts++;
                        } else {
                            printf("The product was not added.\n");
                        }

                    } else {
                        printf("The input data is invalid.\n");
                    }
                    break;
                // update product
                case 2:
                    // check if there are any products to update
                    if (numberOfProducts == 0) {
                        printf("There are no products to update.\n");
                    } else {
                        // display products and get the id
                        printf("Input the id of the product that will be updated.\n");
                        displayProducts(products, numberOfProducts);
                        char idChar[20];
                        fgets(idChar, 20, stdin);
                        removeTrailingNewLine(idChar);

                        // get the new price
                        char newPrice[20];
                        printf("Input the updated price of the chosen product.\n");
                        fgets(newPrice, 20, stdin);
                        removeTrailingNewLine(newPrice);

                        // get the new quantity
                        char newQuantity[20];
                        printf("Input the updated quantity of the chosen product\n");
                        fgets(newQuantity, 20, stdin);
                        removeTrailingNewLine(newQuantity);

                        // check if the data is valid and if it is attempt the update
                        if (validatePrice(newPrice) && validateQuantity(newQuantity)) {
                            bool result = updateProductController(
                                    products,
                                    numberOfProducts,
                                    atoi(idChar),
                                    atoi(newQuantity),
                                    atof(newPrice)
                                    );
                            if (!result) {
                                printf("The update was unsuccessful\n");
                            } else {
                                printf("The update was successful\n");
                            }
                        }
                    }
                    break;
                // delete product
                case 3:
                    // check if there are any products to display
                    if (numberOfProducts == 0) {
                        printf("There are no products to delete.\n");
                    } else {
                        // display the products and obtain the id of the product that will be deleted
                        char idChar[20];
                        printf("Input the id of the product that will be deleted.\n");
                        displayProducts(products, numberOfProducts);
                        fgets(idChar, 20, stdin);
                        removeTrailingNewLine(idChar);

                        // attempt to delete the product with the input id
                        if (validateId(idChar)) {
                            bool result = deleteProductController(products, numberOfProducts, atoi(idChar));
                            if (result) {
                                printf("The selected product was deleted successfully.\n");
                                numberOfProducts--;
                            } else {
                                printf("The deletion was unsuccessful.\n");
                            }
                        } else {
                            printf("The input id was invalid.\n");
                        }
                    }
                    break;
                case 4:
                    // get the ordering of the list
                    printf("Input the ordering of the available products: ascending / descending\n");
                    char ordering[20];
                    fgets(ordering, 20, stdin);
                    removeTrailingNewLine(ordering);
                    // check if the input is valid
                    if (strcmp(ordering, "ascending") == 0 || strcmp(ordering, "descending") == 0) {
                         // get the number of available products and the result
                        availableProducts = getAvailableProducts(products, productsAfterQuery,numberOfProducts,
                                                                 ordering);
                        // display a table if there are any products available, otherwise show a message
                        if (availableProducts > 0) {
                            displayProducts(productsAfterQuery, availableProducts);
                        } else {
                            printf("There are no products available.\n");
                        }
                    } else {
                        printf("The input ordering is invalid.\n");
                    }

                    break;
                case 5:
                    // get the criteria
                    printf("Input the criteria by which the products will be filtered: manufacturer / price / quantity\n");
                    char criteria[20];
                    fgets(criteria, 20 , stdin);
                    removeTrailingNewLine(criteria);
                    // check if the input is valid
                    if (
                            strcmp(criteria, "manufacturer") == 0 ||
                            strcmp(criteria, "price") == 0 ||
                            strcmp(criteria, "quantity") == 0
                            ) {
                        // get the value by which the products should be filtered
                        char valueToFilterBy[20];
                        int numberOfFilteredProducts = 0;
                        if (strcmp(criteria, "manufacturer") == 0) {
                            printf("Input the manufacturer of the product.\n");
                            fgets(valueToFilterBy, 20, stdin);
                            removeTrailingNewLine(valueToFilterBy);
                            // check if the manufacturer is valid
                            if (validateManufacturer(valueToFilterBy)) {
                                // get the number of filtered products and the result
                                numberOfFilteredProducts = getProductsFiltered(products, productsAfterQuery,
                                                                               numberOfProducts, criteria,
                                                                               valueToFilterBy);
                            } else {
                                printf("The input manufacturer is invalid.\n");
                            }
                        } else if (strcmp(criteria, "price") == 0) {
                            printf("Input the price of the product.\n");
                            fgets(valueToFilterBy, 20, stdin);
                            removeTrailingNewLine(valueToFilterBy);
                            // check if the price is valid
                            if (validatePrice(valueToFilterBy)) {
                                // get the number of filtered products and the result
                                numberOfFilteredProducts = getProductsFiltered(products, productsAfterQuery,
                                                                               numberOfProducts, criteria,
                                                                               valueToFilterBy);
                            } else {
                                printf("The input price is invalid.\n");
                            }
                        } else if (strcmp(criteria, "quantity") == 0) {
                            printf("Input the quantity of the product.\n");
                            fgets(valueToFilterBy, 20, stdin);
                            removeTrailingNewLine(valueToFilterBy);
                            // check if the quantity is valid
                            if (validateQuantity(valueToFilterBy)) {
                                // get the number of filtered products and the result
                                numberOfFilteredProducts = getProductsFiltered(products, productsAfterQuery,
                                                                               numberOfProducts, criteria,
                                                                               valueToFilterBy);
                            } else {
                                printf("The input quantity is invalid.\n");
                            }
                        }
                        // display a message if there are no products after the filtering and display the remaining ones otherwise
                        if (numberOfFilteredProducts == 0) {
                            printf("There are no products after the filtering.\n");
                        } else {
                            displayProducts(productsAfterQuery, numberOfFilteredProducts);
                        }
                    } else {
                        printf("The input criteria is invalid.\n");
                    }
                    break;
                case 6:
                    running = false;
                    printf("Thank you for using this application.\n");
                    break;
            }
            printf("Press ENTER to continue.\n");
            fgets(dummyInput, 100, stdin);

        }
    }
}

void displayProducts(Product* products, int numberOfProducts) {
    printf("+----------+--------------+------------------------+------------------------+---------------+---------------+\n");
    printf("|  %-6s  |  %-10s  |  %-20s  |  %-20s  |  %-11s  |  %-11s  |\n", "Id", "Type", "Manufacturer", "Model", "Price", "Quantity");
    printf("+----------+--------------+------------------------+------------------------+---------------+---------------+\n");
    for (int i = 0; i < numberOfProducts; i++) {
        printf(
                "|  %-6d  |  %-10s  |  %-20s  |  %-20s  |  %-11f  |  %-11d  |\n",
                products[i].id,
                products[i].type,
                products[i].manufacturer,
                products[i].model,
                products[i].price,
                products[i].quantity
                );
        printf("+----------+--------------+------------------------+------------------------+---------------+---------------+\n");
    }
    if (numberOfProducts == 0) {
        printf("|  %-6s  |  %-10s  |  %-20s  |  %-20s  |  %-11s  |  %-11s  |\n", " ", " ", " ", " ", " ", " ");
        printf("+----------+--------------+------------------------+------------------------+---------------+---------------+\n");

    }
}

