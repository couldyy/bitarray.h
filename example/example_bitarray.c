//#define USE_U64
#define BITARRAY_IMPLEMENTATION
#include "../bitarray.h"
#include <time.h>

#define N 1

int main()
{
    size_t size = 1 << 31;
    Bit_array *arr = init_bit_array_heap(size, 0);
    //print_bitarray(arr);
    //for(size_t i = 0; i < arr->bitcount; i++) {
    //    set_bit(arr, i, 1);
    //}
    ////print_bitarray(arr);
    //for(size_t i = 0; i < arr->bitcount; i++) {
    //    set_bit(arr, i, 0);
    //}
    //print_bitarray(arr);
    clock_t start = clock();
    for(int i = 1; i <= 1; i++) {
        set_bit(arr, arr->bitcount - i, 1);
        //print_bitarray(arr);
        int index = find_first_bit(arr, 1);
        if(index < 0) {
            printf("not found\n");
        }
        int bit = get_bit(arr, index);
    }
    clock_t end = clock();
    //printf("i: %d  %d (%d full)\n", index, arr->bitcount, arr->size*ELEMENT_SIZE);

    //printf("found: %d [%d] (real: %d)\n", index, bit, arr->bitcount - 10);
    printf("time taken for %d iterations: %llf ms\n", N, (long double)(end - start) / (long double)1000.0f);

    return 0;
}

