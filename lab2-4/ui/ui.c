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
    int numberOfProducts = 0;
    while (running) {
        printf(
            "You can interact with it by using the following commands:\n"
           "  1. Add new product.\n"
           "  2. Update product.\n"
           "  3. Delete product.\n"
           "  4. Display available products.\n"
           "  5. Display products filtered by a certain criteria.\n"
           "  6. Exit the application.\n"
           );
        printf("Choose an option:\n");
        char option[20];
        fgets(option, 20, stdin);
        printf("%s", option);
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
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
            }
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

