/* Copyright (c) 2016 David Benoit
   sfr_string_test.c
   
   Implementation of sfr_string tests type
*/

#include <string.h>
#include "unit_test.h"
#include "../sfr_string.h"

typedef struct {
  char* data;
  unsigned int len;
  unsigned int capacity;
} sfr_string_private;

/* TEST CASE TEMPLATE *
struct test_info test_sfr_string_() {
  struct test_info test_results;
  sfr_string_t* str = NULL;

  test_info_init(&test_results, "test_sfr_string_");  
  str = sfr_string_create(10);
  assert(1, 
         "", 
          &test_results);
  

  sfr_string_destroy(&str);
  return test_results;
}
*/

struct test_info test_sfr_string_create() {
  struct test_info test_results;
  sfr_string_t* str = NULL;
  sfr_string_private* pr_str = NULL;
  int i;

  test_info_init(&test_results, "test_sfr_string_create");  

  str = sfr_string_create(10);
  pr_str = (sfr_string_private*) str;
  assert(str != NULL, 
         "sfr_string_create(10) returned NULL", &test_results);
  assert(pr_str->data != NULL, 
         "sfr_string_create(10) did not malloc str->data", &test_results);
  assert(pr_str->len == 0, 
         "sfr_string_create(10) did not create a string of length 0",&test_results);
  assert(pr_str->capacity == 10, 
         "sfr_string_create(10) did not create a string of capacity 10", &test_results);
  assert(pr_str->data[11] == '\0', 
         "sfr_string_create(10) did not null terminate str",&test_results);
  sfr_string_destroy(&str);  
  return test_results;
}

struct test_info test_sfr_string_destroy() {
  struct test_info test_results;
  sfr_string_t* str = NULL;
  sfr_string_private* pr_str = NULL;

  test_info_init(&test_results, "test_sfr_string_destroy");  

  str = sfr_string_create(10);
  sfr_string_destroy(&str);
  assert(str == NULL, "sfr_string_destroy() did not free string", &test_results);
  return test_results;
}

struct test_info test_sfr_string_assign_cstr() {
  struct test_info test_results;
  sfr_string_t* str = NULL;
  test_info_init(&test_results, "test_sfr_string_assign_cstr");  

  str = sfr_string_create(10);
  sfr_string_assign_cstr(str, "hello world");
  assert(strncmp(sfr_string_cstr(str), "hello world", 11) == 0, "sfr_string_assign_cstr() did not assign \"hello world\"", &test_results);

  sfr_string_destroy(&str);
  return test_results;
}



struct test_info test_sfr_string_strlen() {
  struct test_info test_results;
  sfr_string_t* str = NULL;

  test_info_init(&test_results, "test_sfr_string_strlen");  
  str = sfr_string_create(10);
  sfr_string_assign_cstr(str, "hello world");
  assert(sfr_string_strlen(str) == 11, 
         "sfr_string_strlen did not return 11 on string \"hello world\"", 
          &test_results);
  

  sfr_string_destroy(&str);
  return test_results;
}

struct test_info test_sfr_string_capacity() {
  struct test_info test_results;
  sfr_string_t* str = NULL;

  test_info_init(&test_results, "test_sfr_string_capacity");  
  str = sfr_string_create(10);
  assert(sfr_string_capacity(str) == 10, 
         "sfr_string_capacity did not return 10 on str", 
          &test_results);

  sfr_string_destroy(&str);
  return test_results;
}

struct test_info test_sfr_string_append() {
  struct test_info test_results;
  sfr_string_t* str = NULL;
  int i;

  test_info_init(&test_results, "test_sfr_string_append");  
  str = sfr_string_create(10);
  sfr_string_append(str, 'a');
  assert(strncmp(sfr_string_cstr(str), "a", 1) == 0,
         "sfr_string_append did not work when string is empty", 
          &test_results);
  for (i = 0; i < 19; ++i)
    sfr_string_append(str, 'a');
  assert(strncmp(sfr_string_cstr(str), "aaaaaaaaaaaaaaaaaaaa", 20) == 0,
         "sfr_string_append did not work when string is at capacity", 
          &test_results);

  sfr_string_destroy(&str);
  return test_results;
}


struct test_info test_sfr_string_copy() {
  struct test_info test_results;
  sfr_string_t* str1 = NULL;
  sfr_string_t* str2 = NULL;

  test_info_init(&test_results, "test_sfr_string_copy");  
  str1 = sfr_string_create(10);
  str2 = sfr_string_create(10);

  sfr_string_assign_cstr(str1, "hello world");
  sfr_string_copy(str2, str1);

  assert(strncmp(sfr_string_cstr(str2),"hello world" , 11) == 0, 
         "sfr_string_copy() did not copy \"hello world\"", 
          &test_results);

  sfr_string_destroy(&str1);
  sfr_string_destroy(&str2);
  return test_results;
}

struct test_info test_sfr_string_append_str() {
  struct test_info test_results;
  sfr_string_t* str1 = NULL;
  sfr_string_t* str2 = NULL;

  test_info_init(&test_results, "test_sfr_string_append_str");  
  str1 = sfr_string_create(10);
  str2 = sfr_string_create(10);
  sfr_string_assign_cstr(str1, "hello");
  sfr_string_assign_cstr(str2, " world");
  sfr_string_append_str(str1, str2);
  assert(strncmp(sfr_string_cstr(str1), "hello world", 11) == 0, 
         "sfr_string_append_str() did not append", 
          &test_results);
  

  sfr_string_destroy(&str1);
  sfr_string_destroy(&str2);
  return test_results;
}

struct test_info test_sfr_string_inject() {
  struct test_info test_results;
  sfr_string_t* str1 = NULL;
  sfr_string_t* str2 = NULL;

  test_info_init(&test_results, "test_sfr_string_inject");  
  str1 = sfr_string_create(10);
  str2 = sfr_string_create(10);
  sfr_string_assign_cstr(str1, "hd");
  sfr_string_assign_cstr(str2, "ello worl");
  sfr_string_inject(str1, str2, 1);
  assert(strncmp(sfr_string_cstr(str1), "hello world", 11) == 0, 
         "sfr_string_inject() did not inject", 
          &test_results);

  sfr_string_destroy(&str1);
  sfr_string_destroy(&str2);
  return test_results;
}

struct test_info test_sfr_string_buffer_resize() {
  struct test_info test_results;
  sfr_string_t* str = NULL;

  test_info_init(&test_results, "test_sfr_string_buffer_resize");  
  str = sfr_string_create(10);
  sfr_string_buffer_resize(str, 20,  1);
  assert(sfr_string_capacity(str) == 20, 
         "sfr_string_buffer_resize() did not resize buffer from 10 to 20", 
          &test_results);
  

  sfr_string_destroy(&str);
  return test_results;
}

struct test_info test_sfr_string_prepend_str() {
  struct test_info test_results;
  sfr_string_t* str1 = NULL;
  sfr_string_t* str2 = NULL;

  test_info_init(&test_results, "test_sfr_string_prepend_str");  
  str1 = sfr_string_create(10);
  str2 = sfr_string_create(10);
  sfr_string_assign_cstr(str1, "he");
  sfr_string_assign_cstr(str2, "llo world");
  sfr_string_inject(str2, str1, 0);
  assert(strncmp(sfr_string_cstr(str2), "hello world", 11) == 0, 
         "sfr_string_prepend_str() did not prepend string", 
          &test_results);

  sfr_string_destroy(&str1);
  sfr_string_destroy(&str2);
  return test_results;
}

struct test_info test_sfr_string_insert_char() {
  struct test_info test_results;
  sfr_string_t* str = NULL;

  test_info_init(&test_results, "test_sfr_string_insert_char");  
  str = sfr_string_create(10);
  sfr_string_assign_cstr(str, "ello world");
  sfr_string_insert_char(str, 'h', 0);
  assert(strncmp(sfr_string_cstr(str), "hello world", 11) == 0, 
         "sfr_string_insert_char() did not insert char", 
          &test_results);

  sfr_string_destroy(&str);
  return test_results;
}
