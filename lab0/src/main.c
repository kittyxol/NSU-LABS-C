#include <stdio.h>
#include <math.h>
#define FRACTPARTLEN 14
#define CHARNEWBASE 53
#define CHARLEN 256

int len(const char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int intpart_len(const char *str) {
    int i = 0;
    while (str[i]!='.' && str[i]!='\0') {
        i++;
    }
    return i;
}

int ctoi(const char c) {
    if(c >= '0' && c <= '9') {
        return c - '0';
    }
    if(c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    if(c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    return -1;
}
char itoc(int num){
    if (num < 10) {
        return '0' + num;
    } else {
        return 'a' + num - 10;
    }
}

int isValid(int base) {
    return 2 <= base && base <= 16;
}
char *concatStr(char *str1, char *str2)
{
    char *start = str1;
    while(*str1 != '\0')
    {
        str1++;
    }
    while(*str2 != '\0')
    {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
    return start;
}

long double toDec(const char *string, int base) {
    int intPartLen = intpart_len(string);
    int length = len(string);
    double power = 1;
    int fractPartStart = intPartLen + 1;
    long double res = 0;
    // вычисление целой части
    for (int i = intPartLen - 1; i >= 0; i--) {
        int digit = ctoi(string[i]);
        if (digit == -1 || digit >= base || string[length-1] == '.') {
            return -1; // проверка символа
        }
        res += digit * power;
        power *= base;
    }
    // вычисление дробной части
    if (fractPartStart < length) {
        long double fractPart = 0;
        long double power = 1.0 / base;
        for (int i = fractPartStart; i < length; i++) {
            int digit = ctoi(string[i]);
            if (digit == -1 || digit >= base) {
                return -1; // проверка символа
            }
            fractPart += digit * power;
            power /= base;
        }
        res += fractPart;
    }
    return res;
}

void fromDec(long double num, int base, char* result) {
    unsigned long long int intPart = (unsigned long long int)num;
    long double fractPart = num - intPart;
    char intPartInNewBase[CHARNEWBASE]; // целая часть в новой системе счисления
    // преобразование целой части
    if (intPart == 0) {
        result[0] = '0';
        result[1] = '\0';
    } else {
        int index = 0;
        while (intPart != 0) {
            unsigned long long int remainder = intPart % base;
            char tmp = itoc(remainder);
            intPartInNewBase[index] = tmp;
            intPart /= base;
            index++;
        }
      
        for (int i = 0; i < index; i++) {
            result[i] = intPartInNewBase[index - i - 1];
        }
        result[index] = '\0';
    }
    if (fractPart != 0.0) {
        char fractPartInNewBase[FRACTPARTLEN]; // дробная часть в новой системе счисления
        int partIndex = 0;
        fractPartInNewBase[0] = '.';
        
        // преобразование дробной части
        for (int i = 0; i < 12; i++) {
            if (fractPart == 0){
                break;
            }
            fractPart *= base;
            unsigned long long int digit = (unsigned long long int)fractPart;
            fractPart -= digit;
            char tmp = itoc (digit);
            fractPartInNewBase[i + 1] = tmp;
            partIndex++;
        }
        fractPartInNewBase[partIndex + 1] = '\0';
        
        // Concatenate the fractPartInNewBase array to result manually
        int result_length = len(result);
        int fract_length = len(fractPartInNewBase);
        
        for (int i = 0; i < fract_length; i++) {
            result[result_length + i] = fractPartInNewBase[i];
        }
        
        result[result_length + fract_length] = '\0';
    }
}



int main() {
    int base1, base2;
    char X[FRACTPARTLEN];
    int scanfBases = scanf("%d %d", &base1, &base2);
    int scanfString = scanf("%13s", X);
    if (scanfBases < 2 || scanfString <1){
        return -1;
    }
    long double decNum = toDec(X, base1);
    if (!isValid(base1) || !isValid(base2) || decNum == -1 || X[0] == '.') {
        printf("bad input\n");
        return 0;
    }
    char result[CHARLEN];
    fromDec(decNum, base2, result);
    printf("%s\n", result);
    return 0;
}
