#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "my_libc.h"

int main(void) {
    assert(my_strlen("hello") == 5);
    assert(my_strlen("") == 0);

    assert(my_strcmp("hello", "hello") == 1);
    assert(my_strcmp("hello", "world") == 0);
    assert(my_strcmp("", "") == 1);

    char copy_dst[32];
    my_strcpy(copy_dst, "copy me");
    assert(strcmp(copy_dst, "copy me") == 0);

    char copy_empty[32];
    my_strcpy(copy_empty, "hello");
    assert(strcmp(copy_empty, "hello") == 0);

    char reverse_test[] = "abcdef";
    reverse(reverse_test);
    assert(strcmp(reverse_test, "fedcba") == 0);

    char reverse_empty[] = "";
    reverse(reverse_empty);
    assert(strcmp(reverse_empty, "") == 0);

    char reverse_single[] = "Z";
    reverse(reverse_single);
    assert(strcmp(reverse_single, "z") == 0);

    char words[] = "hello world";
    reverse_by_word(words);
    assert(strcmp(words, "olleh dlrow") == 0);

    char words_two[] = "one two three";
    reverse_by_word(words_two);
    assert(strcmp(words_two, "eno owt eerht") == 0);

    char words_empty[] = "";
    reverse_by_word(words_empty);
    assert(strcmp(words_empty, "") == 0);

    assert(is_prefix("he", "hello") == 1);
    assert(is_prefix("", "hello") == 1);
    assert(is_prefix("world", "hello") == 0);

    char remove_test[] = "banana";
    assert(remove_last_substr(remove_test, "na") == 4);
    assert(strcmp(remove_test, "bana") == 0);

    char remove_missing[] = "abc";
    assert(remove_last_substr(remove_missing, "xyz") == -1);

    char remove_valid[] = "abcd";
    assert(remove_last_substr(remove_valid, "bc") == 1);
    assert(strcmp(remove_valid, "ad") == 0);

    assert(str_to_int("0") == 0);
    assert(str_to_int("42") == 42);
    assert(str_to_int("12345") == 12345);
    assert(str_to_int("-42") == -42);
    assert(str_to_int("+42") == 42);
    assert(str_to_int("  -42") == -42);
    assert(str_to_int("\t+7") == 7);
    assert(str_to_int("-0") == 0);

    puts("All valid API tests passed.");
    return 0;
}
