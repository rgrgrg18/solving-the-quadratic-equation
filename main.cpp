#include <stdio.h>
#include <math.h>
#include "counting.h"
#include "io.h"
#include "tests.h"

int main() {

    if (!tests_start()) {
        return 0;
    }

    printf("Hi, enter coefficients of quadratic equal!\n");

    double a = 0, b = 0, c = 0;
    get_input(&a);
    get_input(&b);
    get_input(&c);

    double x1 = 0, x2 = 0;
    roots_amount cnt_of_roots = solv_square(a, b, c, &x1, &x2);

    print_solutions(cnt_of_roots, x1, x2);

    return 0;
}


