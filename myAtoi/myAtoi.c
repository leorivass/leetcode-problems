/*
 *     String to Integer (atoi)
 *      Author: Carlos Rivas
 *        Date: 7 nov 2025
 */

#include <stdbool.h>
#include <limits.h>

int myAtoi(char* s) {
    
    int num = 0;
    bool negative_flag = false;
    bool already_found = false;
    
    for(; *s; s++) {

        if (*s == ' ' && !(already_found)) continue;
        
        if ((*s == '+' || *s == '-' || *s == ' ') && already_found) break;

        if ((*s == '+' || *s == '-') && !(already_found)) {
            already_found = true;
            if (*s == '-') negative_flag = true;
            continue;
        }

        if (*s >= '0' && *s <= '9') {
            int digit = *s - '0';
            already_found = true;

            if (negative_flag) {
                if (num < INT_MIN / 10 || (num == INT_MIN / 10 && digit > 8)) {
                    return INT_MIN;
                }
                num = num * 10 - digit;          
            } else {
                if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > 7)) {
                    return INT_MAX;
                }
                num = num * 10 + digit;
            }
        }
        else {
            break;
        }

    }

    return num;
}