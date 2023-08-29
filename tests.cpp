#include <stdio.h>
#include "tests.h"
#include "output_color.h"

test_data all_data[] =
{
    {.a = 0,   .b = 0,     .c = 0,       .x1 = 0,     .x2 = 0,     .cnt = INF },
    {.a = 0,   .b = 0,     .c = 2,       .x1 = 0,     .x2 = 0,     .cnt = ZERO},
    {.a = 0,   .b = 1,     .c = 2,       .x1 = -2,     .x2 = 0,    .cnt = ONE },
    {.a = 2,   .b = 0,     .c = 8,       .x1 = 0,     .x2 = 0,     .cnt = ZERO},
    {.a = 2,   .b = 0,     .c = -8,      .x1 = -2,    .x2 = 2,     .cnt = TWO },
    {.a = 10,  .b = 50,    .c = 0,       .x1 = -5,    .x2 = 0,     .cnt = TWO },
    {.a = 2,   .b = 0,     .c = 0,       .x1 = 0,     .x2 = 0,     .cnt = ONE },
    {.a = 5,   .b = -4,    .c = 2,       .x1 = 0,     .x2 = 0,     .cnt = ZERO},
    {.a = 1,   .b = -0.75, .c = -0.625,  .x1 = -0.5,  .x2 = 1.25,  .cnt = TWO },
    {.a = 1,   .b = 0.25,  .c = -2.625,  .x1 = -1.75, .x2 = 1.5,   .cnt = TWO },
    {.a = 6.2, .b = 1.55,  .c = -16.275, .x1 = -1.75, .x2 = 1.5,   .cnt = TWO },
    {.a = 2,   .b = -0.3,  .c = -0.9,    .x1 = -0.6,  .x2 = 0.75,  .cnt = TWO },
    {.a = 1,   .b = 6.6,   .c = 10.88,   .x1 = -3.2,  .x2 = -3.4,  .cnt = TWO },
    {.a = -2,  .b = 3,     .c = 5,       .x1 = -1,    .x2 = 2.5,   .cnt = TWO },
    {.a = 10,  .b = 10,    .c = 10,      .x1 = 0,     .x2 = 0,     .cnt = ZERO},
};

const int TESTS_CNT = sizeof(all_data) / sizeof(test_data);

int test_one(){
    int true_cnt = 0;

    for (int j = 0; j < TESTS_CNT; j++) {

        double x1 = 0, x2 = 0;
        roots_amount cnt = solv_square(all_data[j].a, all_data[j].b, all_data[j].c, &x1, &x2);

        if ((is_num(x1, all_data[j].x1) && is_num(x2, all_data[j].x2)) || (is_num(x1, all_data[j].x2) && is_num(x2, all_data[j].x1)) && cnt == all_data[j].cnt){
            true_cnt += 1;

        } else {
            red();
            printf("Test %d failed \n",  true_cnt + 1);
            yellow();
            printf("[Output] ");
            reset();
            print_solutions(cnt, x1, x2);
            green();
            printf("[Expected] ");
            reset();
            print_solutions(all_data[j].cnt, all_data[j].x1, all_data[j].x2);
            break;
        }
    }
    return true_cnt;
}

int tests_start(){
    int cnt_of_true = test_one();
    if (cnt_of_true == TESTS_CNT) {
        green();
        printf("%d/%d tests complited\n", cnt_of_true, TESTS_CNT);
        reset();
        return 1;
    }
    return 0;
}

