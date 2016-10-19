/* Copyright (c) 2016 David Benoit
   unit_test.h

   Some unit testing utilities
*/
#ifndef UNIT_TEST_H
#define UNIT_TEST_H
 #include "../ansi_colors.h"

#define ERR_LENGTH_MAX 128
#define MAX_NUM_ERRORS 64


struct test_info {
  char test_name[ERR_LENGTH_MAX];
  unsigned int num_errors;
  char error_list[MAX_NUM_ERRORS][ERR_LENGTH_MAX];
};

void test_info_init(struct test_info* t, char* test_name);
void assert(int expression, char* fail_notification, struct test_info* t);
  

#endif
