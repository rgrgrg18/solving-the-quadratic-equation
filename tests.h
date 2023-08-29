#pragma once

#include "counting.h"
#include "io.h"


struct test_data{
    double a, b, c;
    double x1, x2;
    roots_amount cnt;
};

int test_one();
int tests_start();
