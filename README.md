# My C Custom Functions

This repository contains a small C utility library built from scratch. The goal is to practice implementing common string manipulation functions without relying on the standard C library versions, while keeping each function simple, readable, and reusable.

The project is organized into a header file for declarations and a source file for the implementations, making it easy to extend with additional custom functions over time.

## Implemented functions

- my_strlen: returns the length of a string excluding the null terminator
- my_strcmp: compares two strings character by character and returns match status
- my_strcpy: copies the contents of one string into another buffer
- reverse: reverses the characters in a string in place
- reverse_by_word: reverses the order of words in a string
- is_prefix: checks whether one string is a prefix of another
- remove_last_substr: removes the last occurrence of a substring from a string
- strip_chars: removes all characters that appear in a given set from a string

## Project structure

- include/my_libc.h: function declarations
- src/my_libc.c: implementations of the custom C string functions
