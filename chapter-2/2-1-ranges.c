#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

   printf("Ranges for C basic types on this machine: \n");

   printf("signed char:\t\t [%hhd, %hhd] \n", SCHAR_MIN, SCHAR_MAX);
   printf("unsigned char:\t\t [0, %hhu] \n", UCHAR_MAX);
   printf("signed short:\t\t [%hd, %hd] \n", SHRT_MIN, SHRT_MAX);
   printf("unsigned short:\t\t [0, %hu] \n", USHRT_MAX);
   printf("signed int:\t\t [%d, %d] \n", INT_MIN, INT_MAX);
   printf("unsigned int:\t\t [0, %u] \n", UINT_MAX);
   printf("signed long:\t\t [%ld, %ld] \n", LONG_MIN, LONG_MAX);
   printf("unsigned long:\t\t [0, %lu] \n", ULONG_MAX);
   printf("signed long long:\t [%lld, %lld] \n", LLONG_MIN, LLONG_MAX);
   printf("unsigned long long:\t [0, %llu] \n", ULLONG_MAX);
   
   printf("float:\t\t\t [%g, %g] \n", FLT_MIN, FLT_MAX);
   printf("double:\t\t\t [%g, %g] \n", DBL_MIN, DBL_MAX);
   printf("long double:\t\t [%Lg, %Lg] \n", LDBL_MIN, LDBL_MAX);

   return 0;
}
