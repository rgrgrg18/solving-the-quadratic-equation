#pragma once

const double EPSILON = 0.000001;
enum roots_amount{ZERO = 0, ONE = 1, TWO = 2, INF = 3};

roots_amount solv_linear(double a, double b, double *x);
roots_amount solv_square(double a, double b, double c, double *x1, double *x2);
int is_num(double x, double num);

