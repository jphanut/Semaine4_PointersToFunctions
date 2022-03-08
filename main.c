#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t funct1(uint8_t n) {
   return n;
}

uint8_t funct2(uint8_t n) {
   return n+0;
}

uint8_t funct3(uint8_t n) {
   return n+1;
}

int cmp_func(uint8_t  (*funct_ptr1)(uint8_t ), uint8_t  (*funct_ptr2)(uint8_t )) {
    if ( funct_ptr1 == NULL ||  funct_ptr2 == NULL) return 0;
    for (int i=0; i <= 255; i++) {
        if ( funct_ptr1(i) != funct_ptr2(i) ) return 0;
    }
    return 1;
}

int main()
{
    uint8_t (*funct_ptr1)(uint8_t ) = &funct1;
    uint8_t (*funct_ptr2)(uint8_t ) = &funct2;
    uint8_t (*funct_ptr3)(uint8_t ) = &funct3;
    int rc = 0;
    rc = cmp_func(funct_ptr1, funct_ptr2);
    printf("Return code of comparaison of result beween funct1 and funct2: %d\n", rc);
    rc = cmp_func(funct_ptr1, funct_ptr3);
    printf("Return code of comparaison of result beween funct1 and funct3: %d\n", rc);
    rc = cmp_func(funct_ptr2, funct_ptr3);
    printf("Return code of comparaison of result beween funct2 and funct3: %d\n", rc);
    return 0;
}
