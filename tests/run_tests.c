/* Copyright (c) 2016 David Benoit
   run_tests.c
   
   Run all of the sfr_string tests
*/
#include <stdio.h>
#include <string.h>
#include "unit_test.h"
#include "sfr_string_test.h"
#include "../ansi_colors.h"

typedef struct test_info (*unit_test)(void);

const unit_test sfr_string_tests[] = {
  test_sfr_string_create,
  test_sfr_string_destroy,
  test_sfr_string_assign_cstr,
  test_sfr_string_strlen,
  test_sfr_string_capacity,
  test_sfr_string_append,
  test_sfr_string_copy,
  test_sfr_string_append_str,
  test_sfr_string_buffer_resize,
  test_sfr_string_inject,
  test_sfr_string_insert_char,
  test_sfr_string_prepend_str
};

int execute_test(struct test_info (*test)());

int main(int argc, char* argv[])
{
  int i, passed=0, failed=0, errors=0;
  for (i = 0; i < sizeof(sfr_string_tests) / sizeof(unit_test); ++i) {
    int current_test_errors = execute_test(sfr_string_tests[i]);
    if (current_test_errors > 0) {
      ++failed;
      errors += current_test_errors;
    }
    else {
      ++passed;
    }
  } 
  printf("\nTOTAL PASSED: %d\nTOTAL FAILED: %d\nTOTAL ERRORS: %d\n", passed, failed, errors); 
  return 0;
}

int execute_test(struct test_info (*test)()) {
  struct test_info t = test();
  int i;
  if (t.num_errors == 0) {
    printf("PASSED %s\n", t.test_name);
    return 0;
  }
  else   {
    printf("FAILED: %s WITH ERRORS: \n", t.test_name);
    for (i = 0; i < t.num_errors; ++i)
      printf("%s\n", t.error_list[i]);
    return t.num_errors;
  }
  
}
