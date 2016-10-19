/* Copyright (c) 2016 David Benoit
   sfr_string.c
   
   Private implementation of sfr_string_t type
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sfr_string.h"

typedef struct {
  char* data;
  unsigned int len;
  unsigned int capacity;
} sfr_string_private;

unsigned int sfr_string_strlen(sfr_string_t * str) {
  return ((sfr_string_private*) str)->len;
}

unsigned int sfr_string_capacity(sfr_string_t * str) {
  return ((sfr_string_private*) str)->capacity;
}

sfr_string_t*
sfr_string_create(unsigned int capacity) {
  sfr_string_private* 
    new_str = malloc(sizeof(sfr_string_private));
  if (new_str == NULL)
    return NULL;
  new_str->data = malloc(sizeof(char) * (capacity + 1));
  if (new_str->data == NULL) {
    free(new_str);
    return NULL;
  }
  new_str->len = 0;
  new_str->capacity = capacity;
  new_str->data[0] = '\0';
  new_str->data[capacity] = '\0';
  return (sfr_string_t*) new_str;
}

void sfr_string_destroy(sfr_string_t** glstr) {
  sfr_string_private* 
    pr_glstr = (sfr_string_private*) *glstr;
  if (pr_glstr != NULL) {
    if (pr_glstr->data != NULL)
      free(pr_glstr->data);
    free(pr_glstr);
  }
  *glstr = NULL;
  return;
}  
  

int
sfr_string_buffer_resize(sfr_string_t* target, unsigned int new_size, int no_truncate) {
  sfr_string_private* 
    str = (sfr_string_private*) target;
  char* new_buffer;
  if ( str == NULL) {
    return -1;
  }
  else if (new_size == str->capacity) {
    return 1;
  }
  else if (no_truncate) {
    new_size = (new_size > str->len) ? new_size : str->len;
  
  }
  new_buffer = malloc(sizeof(char) * (new_size + 1));
  if (new_buffer == NULL)
    return -1;
  strncpy(new_buffer, str->data, new_size);
  new_buffer[new_size] = '\0';
  free(str->data);
  str->data = new_buffer;
  str->capacity = new_size;
  str->len = (new_size < str->len) ? new_size : str->len;
  return 1;
}


void sfr_string_append(sfr_string_t* dest, char c) {
  sfr_string_private* 
    str = (sfr_string_private*) dest;
  if (str == NULL)
    return;
  if (str->len >= str->capacity) {
    sfr_string_buffer_resize((sfr_string_t*)str, str->capacity * 2, 1);
  }
  str->data[str->len] = c;
  str->len++;
  str->data[str->len] = '\0';
} 

void sfr_string_copy(sfr_string_t* dest, sfr_string_t* src) {
  sfr_string_private* 
    pr_dest = (sfr_string_private*) dest;
  sfr_string_private* 
    pr_src = (sfr_string_private*) src;
  int i;

  if (pr_src == NULL || 
      pr_dest == NULL || 
      pr_src->data == NULL || 
      pr_dest->data == NULL)
    return;
  if (pr_dest->capacity < pr_src->len)
    sfr_string_buffer_resize((sfr_string_t*) pr_dest, pr_src->len, 1);
  for (i = 0; i < pr_src->len; ++i)
    sfr_string_append((sfr_string_t*) pr_dest, pr_src->data[i]);
}

void sfr_string_append_str(sfr_string_t* dest, sfr_string_t* src) {
  sfr_string_private* 
    pr_dest = (sfr_string_private*) dest;
  sfr_string_private* 
    pr_src = (sfr_string_private*) src;
  int i;
  sfr_string_t* temp;

  if (pr_src == NULL || 
      pr_dest == NULL || 
      pr_src->data == NULL || 
      pr_dest->data == NULL)
    return;
  sfr_string_buffer_resize((sfr_string_t*) pr_dest, pr_dest->len + pr_src->len,1);
  for (i = 0; i < pr_src->len; ++i)
    sfr_string_append((sfr_string_t*) pr_dest, pr_src->data[i]);

}

void sfr_string_assign_cstr(sfr_string_t* dest, char* cstr) {

  int i;
    if (dest == NULL ||
      cstr == NULL)
    return; 
  for (i = 0; cstr[i] != '\0'; ++i)
    sfr_string_append(dest, cstr[i]);
}

void sfr_string_inject(sfr_string_t* dest, sfr_string_t* src, unsigned int index) {
  sfr_string_private* 
    pr_dest = (sfr_string_private*) dest;
  sfr_string_private* 
    pr_src = (sfr_string_private*) src;
  char* chars_to_relocate;
  int i;
  sfr_string_t* temp;

  if (pr_src == NULL || 
      pr_dest == NULL || 
      pr_src->data == NULL || 
      pr_dest->data == NULL||
      index > pr_dest->len)
    return;

  temp = sfr_string_create(pr_dest->len - index);
  if (temp == NULL) 
    return;
  chars_to_relocate = pr_dest->data + index;
  sfr_string_assign_cstr(temp, chars_to_relocate);
  
  pr_dest->len = index;
  sfr_string_buffer_resize(dest, pr_dest->len + pr_src->len, 1);
  sfr_string_append_str((sfr_string_t*) pr_dest, (sfr_string_t*) pr_src);
  sfr_string_append_str((sfr_string_t*) pr_dest, temp);
  
}

void sfr_string_prepend_str(sfr_string_t* dest, sfr_string_t* src) {
  if (dest == NULL || src == NULL) 
    return;

  sfr_string_inject(dest, src, 0);

}

void sfr_string_insert_char(sfr_string_t* dest, char c, unsigned int index) {
  sfr_string_t* temp = sfr_string_create(1);
  if (dest == NULL || 
      index > sfr_string_strlen(dest) || 
      temp == NULL) 
    return;
  sfr_string_append(temp,c);
  sfr_string_inject(dest,temp,index);
}

const char* sfr_string_cstr(sfr_string_t* str) {
  sfr_string_private* 
    pr_str = (sfr_string_private*) str;
  pr_str->data[pr_str->capacity + 1] = '\0';
  return (const char*) pr_str->data;
}
