#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int strncmp_srk(const char *str1, const char *str2, size_t n);

struct test_case_s {
    const char *str1;
    const char *str2;
    int n;
    int expected_result;
};

const struct test_case_s test_cases[] = {
    {"", "", 5, 0},
    {"", "test1", 5, -116},
    {"test2", "", 5, 116},
    {"test3", "test3", 5, 0},
    {"test4", "test4", 4, 0},
    {"test5", "test5", 6, 0},
    {"test6", "test6", 1, 0},
    {"test7", "xxxxxxxxx", 4, -4}
};





int strncmp_srk(const char *str1, const char *str2, size_t n) {

    // printf("first str : %s \n", str1);
    // printf("second str : %s \n", str2);
    // printf("num of characters to compare : %s \n", str_len_ptr);

    // char str_len = 0;
    // while (*str_len_ptr) {
    //     if (*str_len_ptr < '0' || *str_len_ptr > '9' ) {
    //         printf("invalid number : %s \n", str_len_ptr);
    //         return 0;
    //     }
    //     str_len = (str_len*10) + (*str_len_ptr - '0');
    //     str_len_ptr++;
    // }
 
    // printf("num of characters to compare : %d \n", str_len);

    char str_len = (char)n;

    char c = 0;
    while (str_len) {
        if (str1[c] == 0 || str2[c] == 0){
            // printf("num of characters compared : %d \n", c);
            // printf("false\n");
            return 0;
        }
        if (str1[c] != str2[c]) {
            // printf("num of characters compared : %d \n", c);
            // printf("false\n");
           return 0;
        }

        --str_len;
        ++c;
    }

    // printf("true\n");
    return 1;
}




// gcc strnicmp.c -o build/strn; build/strn

int main() {

    int num_of_test_cases = sizeof(test_cases) / sizeof(struct test_case_s);

    int num_failed = 0;
    int num_success = 0;

    for (int idx = 0; idx < num_of_test_cases; idx++) {

        const struct test_case_s *tc = &test_cases[idx];

        int result = strncmp_srk(tc->str1, tc->str2, tc->n);

        if (result != tc->expected_result) {
            printf("Test Case %2d Failed, expected = %d, returned = %d\n", idx, tc->expected_result, result);
            num_failed++;
        }
        else {
            num_success++;
        }
    }

    printf("Total = %d, Successfull = %d, Failed = %d\n", num_of_test_cases, num_success, num_failed);
}
