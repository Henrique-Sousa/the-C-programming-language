#include <stdio.h>

int main() {

    unsigned char uchar_max;
    signed char schar_min, schar_max;
    unsigned short ushrt_max;
    signed short shrt_min, shrt_max;
    unsigned int uint_max;
    signed int int_min, int_max;
    unsigned long ulong_max;
    signed long long_min, long_max;
    unsigned long long ullong_max;
    signed long long llong_min, llong_max;

    printf("Ranges for C integer types on this machine: \n");

    uchar_max = 1; 
    while (uchar_max > 0) uchar_max++;
    --uchar_max;

    printf("unsigned char:\t\t [0, %hhu] \n",     uchar_max);
    
    schar_min = -1;
    while (schar_min < 0) schar_min--;
    ++schar_min;
    
    schar_max = 1; 
    while (schar_max > 0) schar_max++;
    --schar_max;

    printf("signed char:\t\t [%hhd, %hhd] \n",    schar_min, schar_max);

    shrt_max = (signed short) (pow(2,15) -1);
    while (shrt_max > 0) shrt_max++;
    --shrt_max;

    shrt_min = shrt_max + 1;
    while (shrt_min < 0) shrt_min--;
    ++shrt_min;
    
    printf("signed short:\t\t [%hd, %hd] \n",     shrt_min, shrt_max);

    ushrt_max = (unsigned short) (pow(2,16) -1); 
    while (ushrt_max > 0) ushrt_max++;
    --ushrt_max;

    printf("unsigned short:\t\t [0, %hu] \n",     ushrt_max);


    int_max = (signed int) (pow(2,15) -1); 
    while (int_max > 0) int_max++;
    --int_max;

    int_min = int_max + 1; 
    while (int_min < 0) int_min--;
    ++int_min;
    
    printf("signed int:\t\t [%d, %d] \n",         int_min, int_max);

    uint_max = (unsigned int) (pow(2,16) -1);
    while (uint_max > 0) uint_max++;
    --uint_max;

    printf("unsigned int:\t\t [0, %u] \n",        uint_max);


    long_max = (long) (pow(2,31) -1); 
    while (long_max > 0) long_max++;
    --long_max;

    long_min = long_max + 1;
    while (long_min < 0) long_min--;
    ++long_min;
    
    printf("signed long:\t\t [%ld, %ld] \n",      long_min, long_max);
    
    ulong_max = (long) (pow(2,32) -1); 
    while (ulong_max > 0) ulong_max++;
    --ulong_max;

    printf("unsigned long:\t\t [0, %lu] \n",      ulong_max);
    

    llong_max = (long) (pow(2,63) -1); 
    while (llong_max > 0) llong_max++;
    --llong_max;

    llong_min = llong_max + 1;
    while (llong_min < 0) llong_min--;
    ++llong_min;
    
    printf("signed long long:\t [%lld, %lld] \n", llong_min, llong_max);
    ullong_max = (long) (pow(2,64) -1); 
    while (ullong_max > 0) ullong_max++;
    --ullong_max;

    printf("unsigned long long:\t [0, %llu] \n",  ullong_max);

    return 0;
}

