#define USE_U32
#define BITARRAY_IMPLEMENTATION
#include "bitarray.h"

int main()
{
    size_t size = 50;
    Bit_array arr;
    init_bit_array(&arr, size, 0);
    print_bitarray(&arr);
    for(size_t i = 0; i < arr.bitcount; i++) {
        set_bit(&arr, i, 1);
    }
    //print_bitarray(&arr);
    for(size_t i = 0; i < arr.bitcount; i++) {
        set_bit(&arr, i, 0);
    }
    //print_bitarray(&arr);
    set_bit(&arr, arr.bitcount - 10, 1);
    print_bitarray(&arr);
    int index = find_first_bit(&arr, 1);
    if(index < 0) {
        printf("not found\n");
    }
    printf("i: %d  %d (%d full)\n", index, arr.bitcount, arr.size*ELEMENT_SIZE);
    int bit = get_bit(&arr, index);

    printf("found: %d [%d] (real: %d)\n", index, bit, arr.bitcount - 10);

    return 0;
}

