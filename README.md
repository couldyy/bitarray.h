# bitarray
Simple stb-style, header-only libary to work with array of bits

##  What it is
This library allows creating and interactin with array of bits.
For example you need an array of 103 bits, you simply create it with
```c
    Bit_array arr;
    size_t size = 103;
    init_bit_array(&arr, size, 0);  // 0 - init with 0s
```
and you can interact with each bit by its index(Note that it will still be padded at last byte for alignement).
You can see all possible functions in `bitarray.h`.

## Example
```c
#define USE_U32         // you can define element size for alignement(choises: USE_U8, USE_U32, USE_U64)
#define BITARRAY_IMPLEMENTATION
#include "bitarray.h"

int main()
{
    size_t size = 50;
    Bit_array arr;
    init_bit_array(&arr, size, 0);
    print_bitarray(&arr);

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
```
