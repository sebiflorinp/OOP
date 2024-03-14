#include <stdio.h>
#include "creator.h"

int main() {
    User toPrint = create(1, "aaaa");
    printf("%d %s", toPrint.id, toPrint.name);
    return 0;
}
