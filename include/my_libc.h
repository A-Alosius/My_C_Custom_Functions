#pragma once

#include <stdlib.h>

// takes in a normal terminated string and outputs its 
// length excluding the null terminator
size_t my_strlen(const char* s);

// character-wise comparison two strings. Returns 1 on 
// match, 0 on mismatch, -1 on invalid inputs
int my_strcmp(const char* a, const char* b);

// deep copy of string content from source to destination
void my_strcpy(char* dst, const char* src);

// reverses the order of characters in a string in place
void reverse(char* s);

// reverses the order of words in a string in place
void reverse_by_word(char* s);

// checks whether prefix is at the beginning of str
unsigned char is_prefix(const char* prefix, const char* str);

// removes the last occurrence of substr from str
int remove_last_substr(char* str, const char* substr);

// removes any characters found in remove_chars from str
void strip_chars(char* str, const char* remove_chars);

// converts a string to an integer. Returns the integer 
// value of the string, or 0 if the string is not a valid 
// integer representation. THe input mus include only valid 
// characters, and may include leading whitespace, a sign, 
// and digits.
int str_to_int(const char* str);