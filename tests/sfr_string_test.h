/* Copyright (c) 2016 David Benoit
   sfr_string_test.h
   
   Declaration of sfr_string tests
*/
#ifndef SFR_STRING_TEST_H
#define SFR_STRING_TEST_H

#include "unit_test.h"

struct test_info test_sfr_string_create();
struct test_info test_sfr_string_destroy();
struct test_info test_sfr_string_assign_cstr();
struct test_info test_sfr_string_strlen();
struct test_info test_sfr_string_capacity();
struct test_info test_sfr_string_append();
struct test_info test_sfr_string_copy();
struct test_info test_sfr_string_append_str();
struct test_info test_sfr_string_buffer_resize();
struct test_info test_sfr_string_inject();
struct test_info test_sfr_string_prepend_str();
struct test_info test_sfr_string_insert_char();

#endif
