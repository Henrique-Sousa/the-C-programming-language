#include <ctype.h>
#include <math.h>
#include "cientific_atof.h"

double cientific_atof(char s[]) {
    double val, power;
    int i, sign, expsign, exponent;
    for (i = 0; isspace(s[i]); i++) /*skip white space*/
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    expsign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (exponent = 0; isdigit(s[i]); i++)
        exponent = 10 * exponent + (s[i] - '0');
    return sign * (val / power) * pow(10, expsign * exponent);
}
