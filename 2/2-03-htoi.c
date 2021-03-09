#include <stdio.h>

int htoi(char s[]);

int main() {

    char s1[] = "1F";
    char s2[] = "0Xab";  
    char s3[] = "0x03D"; 
    char s4[] = "abxc";
    char s5[] = "0x1GA";
    char s6[] = "0008c39be";

    printf("%s in decimal is 31: %d\n", s1, htoi(s1) == 31);
    printf("%s in decimal is 171: %d\n", s2, htoi(s2) == 171);
    printf("%s in decimal is 61: %d\n", s3, htoi(s3) == 61);
    printf("%s in decimal is 0: %d\n", s4, htoi(s4) == 0);
    printf("%s in decimal is 0: %d\n", s5, htoi(s5) == 0);
    printf("%s in decimal is 9189822: %d\n", s6, htoi(s6) == 9189822);
    
    return 0;

}

int htoi(char s[]) {
    int result = 0;
    int i = 0;
    int shift;
    if (s[0] == '0') {
        ++i;
        if (s[1] == 'x' || s[1] == 'X') {
            ++i;
        }
    }
    while(s[i] != '\0') {
        if (s[i] >= '0' && s[i] <= '9') {
            shift = '0';
        } else if (s[i] >= 'A' && s[i] <= 'F') {
            shift = 55;
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            shift = 87;
        } else {
            return 0;
        }
        result = 16 * result + (s[i] - shift);
        ++i;
    }
    return result;
}
