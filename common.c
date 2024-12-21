#include <stdint.h>
#include <common.h>

static uint32_t _myrand_seed = 1234;

void my_srand(uint32_t new_seed)
{
    _myrand_seed = new_seed;
}

uint32_t my_rand(void)
{
    _myrand_seed = (uint32_t)(1103515245 * _myrand_seed + 12345);
    return _myrand_seed;
}

void SetStack_AAAA(uint32_t *start, uint32_t *end) {
    while (start < end) {
        *start = 0xAAAAAAAA;
         start++;
    }
}

uint32_t GetStackUsage(uint32_t *start, uint32_t *end) {
    uint32_t *ptr = start;
    uint32_t count = 0;
    while (ptr < end) {
        if(*ptr != 0xAAAAAAAA){
            count++;
        }
        ptr++;
    }
    return count * sizeof(uint32_t);
}


