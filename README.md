# SaferString
A string library which implements the ```sfr_string_t``` type, a safer string than built in C-strings.  ```sfr_string_t```  provides automatic null termination, bounds checking, and buffer resizing to avoid C-string based errors.  

The library also has a few utility functions for ```sfr_string_t``` manipulation.

Note: SaferString functions currently only support pointers to ```sfr_string_t```.  Only use SaferStrings as ```sfr_string_t*```.  Non-pointer instances of ```sfr_string_t``` are not supported yet.

```sfr_string_t*``` can be dereferenced to act like ```char*```, since the buffer pointer is at the beginning of the struct.  This can be useful for passing ```sfr_string_t```s to functions like ```printf()```, but should never be used to access and modify the contents of ```sfr_string_t``` because it circumvents SaferString's safety features.  Regardless, it's better to use ```sfr_string_cstr(sfr_string_t*)```, which returns a ```const``` pointer to the buffer and ensures it is null terminated.
