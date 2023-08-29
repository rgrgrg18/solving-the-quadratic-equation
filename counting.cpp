#include <stdio.h>
#include <math.h>
#include "counting.h"

int is_num(double x, double num) {
    return abs(x - num) < EPSILON;
}


inline double get_discriminant(double a, double b, double c) {
    return b * b - 4 * a * c;
}

roots_amount solv_linear(double a, double b, double *x) {

    if (is_num(a, 0)) {
        if (is_num(b, 0)) {
            return INF;
        }
        return ZERO;
    }
    *x = - b / a;
    return ONE;
}

roots_amount solv_square(double a, double b, double c, double *x1, double *x2) {

    if (is_num(a, 0)) {
        return solv_linear(b, c, x1);
    }

    double d = get_discriminant(a, b, c);

    if (is_num(d, 0)) {
        *x1 = -b / (2 * a);
        return ONE;

    } else if (d < 0) {
        return ZERO;

    } else {
        double root_of_discriminant = sqrt(d);
        *x1 = (-b + root_of_discriminant) / (2 * a);
        *x2 = (-b - root_of_discriminant) / (2 * a);
        return TWO;

    }
}
