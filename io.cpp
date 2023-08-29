#include <stdio.h>
#include "io.h"
#include "output_color.h"


void print_solutions(roots_amount cnt_of_roots, double x1, double x2) {

    switch(cnt_of_roots) {

        case ZERO:
            printf("there are no solutions\n");
            break;

        case ONE:
            printf("one root: %lf\n", x1);
            break;

        case TWO:
            if (x1 > x2) {
                swap_double(&x1, &x2);
            }
            printf("two roots: %lf; %lf\n", x1, x2);
            break;

        case INF:
            printf("INF roots\n");
            break;

    }

}

void get_input(double *coefficient) {
    while (scanf("%lf", coefficient) != 1) {
        printf("Input correct number! \n");
        clear_buffer();
    }
}

void clear_buffer() {
    while (getchar() != '\n') {
    }
}

void swap_double(double *x1, double *x2){
    double temp = *x1;
    *x1 = *x2;
    *x2 = temp;
}
