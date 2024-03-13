#ifndef LAB2_4_MODELS_H
#define LAB2_4_MODELS_H

typedef struct {
    int id;
    char type[20];
    char manufacturer[30];
    char model[20];
    float price;
}Product;

void createProduct(Product* newProduct);

#endif //LAB2_4_MODELS_H
