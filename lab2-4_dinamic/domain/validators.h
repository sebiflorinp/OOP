#include <stdbool.h>
#include "models.h"

#ifndef LAB2_4_VALIDATORS_H
#define LAB2_4_VALIDATORS_H

bool validateId(char id[20]);

bool validateType(char type[20]);

bool validateManufacturer(char manufacturer[20]);

bool validateModel(char model[20]);

bool validatePrice(char price[20]);

bool validateQuantity(char quantity[20]);

bool validateOption(char option[20]);

#endif //LAB2_4_VALIDATORS_H
