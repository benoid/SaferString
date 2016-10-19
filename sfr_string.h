/* Copyright (c) 2016 David Benoit
   sfr_string.h
   
   Public implementation of sfr_string_t type.

   Will document code soon.
*/
#ifndef SFR_STRING_C
#define SFR_STRING_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sfr_string.h"

typedef void* sfr_string_t;

sfr_string_t* sfr_string_create(unsigned int capacity);
void sfr_string_destroy(sfr_string_t** glstr);
void sfr_string_assign_cstr(sfr_string_t* dest, char* cstr);

unsigned int sfr_string_strlen(sfr_string_t * str);
unsigned int sfr_string_capacity(sfr_string_t * str);

void sfr_string_append(sfr_string_t* dest, char c);
void sfr_string_copy(sfr_string_t* dest, sfr_string_t* src);
void sfr_string_append_str(sfr_string_t* dest, sfr_string_t* src);
void sfr_string_inject(sfr_string_t* dest, sfr_string_t* src, unsigned int index);
void sfr_string_prepend_str(sfr_string_t* dest, sfr_string_t* src);
void sfr_string_insert_char(sfr_string_t* dest, char c, unsigned int index);
const char* sfr_string_cstr(sfr_string_t* str);

int sfr_string_buffer_resize(sfr_string_t* target, unsigned int new_size, int no_truncate);


#endif
