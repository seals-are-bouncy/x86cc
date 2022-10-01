#include "out.h"

void out_success(char *msg) {
    printf("\e[42;1m      \e[0m %s\n", msg);
}

void out_error(char *msg) {
    printf("\e[41;1m      \e[0m %s\n", msg);
}