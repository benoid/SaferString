/* Copyright (c) 2016 David Benoit
   unit_test.c
   
   Implementation of unit test utilities
*/
#include <string.h>
#include <stdio.h>
#include "../ansi_colors.h"
#include "unit_test.h"

void test_info_init(struct test_info* t, char* test_name) {
  t->num_errors = 0;
  strncpy(t->test_name, test_name, ERR_LENGTH_MAX);
}

void assert(int expression, char* fail_notification, struct test_info* t) {
  if (!expression) {
    if (t->num_errors < MAX_NUM_ERRORS) {
      strncpy(t->error_list[t->num_errors], fail_notification, ERR_LENGTH_MAX);
      t->num_errors++;
    }
    else {
      printf("WARNING: cannot append test failure: %s to test_info."
             "  MAX_NUM_ERRORS reached\n", 
             fail_notification);
    }
  }
}   
