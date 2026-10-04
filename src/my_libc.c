#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "my_libc.h"

// expects a null terminated string 
// and counts all elements excluding 
// the null terminator
size_t my_strlen(const char* s){
    if (s == NULL){
        printf("Invalid input string\n");
        return -1;
    }

    size_t len = 0;

    while(s[len] != 0){
        len++;
    }
    return len;
}

// expects null terminated inputs
// compare character by character
// any mismatch terminates loop
// length mismatch is automatic inequality
int my_strcmp(const char* a, const char* b){
    if (a == NULL || b == NULL){
        printf("Invalid input strings\n");
        return -1;
    }

    if (my_strlen(a) != my_strlen(b)){
        return 0;
    }

    for (int i = 0; a[i] != 0; i++){
        if (a[i] != b[i]){
            return 0;
        }
    }
    return 1;
}

// because we take no size parameter, 
// function is unsafe as we can tell
// whether dst can contain src
void my_strcpy(char* dst, const char* src){
    if (dst == NULL || src == NULL || my_strlen(src) < 1){
        printf("Invalid input strings\n");
        exit(1);
    }

    for (int i = 0; ; i++){
        dst[i] = src[i];

        // copy everything including null terminator
        if (src[i] == 0){
            break;
        }
    }
}

// takes a null terminated string and range
// verify if characters in range are uppercase 
// alphabet and increment by difference between 'a' and 'A'
// to convert to lowercase. Loop through half of range and reverse
// characters by indexing from both sides and using temporary
// character for swapping. Going through half of the str range
// is sufficient as we swap. 
// case where end and start are equal or have a difference of 1
// is trivial and accounted for
void reverse(char* s){
    if (s == NULL){
        printf("Invalid input strings\n");
        exit(1);
    }
    char c;
    int n = my_strlen(s);

    if (n == 1){
        s[0] = (s[0] >= 'A' && s[0] <= 'Z') ? s[0] + 'a' - 'A' : s[0];
    }

    for (int i = 0; i < n/2; i++){
        c = s[i];
        if (s[n-i-1] >= 'A' && s[n-i-1] <= 'Z'){
            s[i] = s[n-i-1] + 'a' - 'A';
        }
        else
            s[i] = s[n-i-1];
        
        if (c >= 'A' && c <= 'Z'){
            s[n-i-1] = c  + 'a' - 'A';
        }
        else
            s[n-i-1] = c;
    }
}

// takes a string and range (start, end)
// within the string to reverse
// verify if characters in range are uppercase 
//alphabet and increment by difference between 'a' and 'A'
// to convert to lowercase. Loop through half of range and reverse
// characters by indexing from both sides and using temporary
// character for swapping. Going through half of the str range
// is sufficient as we swap. 
// case where end and start are equal or have a difference of 1
// is trivial and accounted for
static void reverse_range(char* s, int start, int end){
    if (s == NULL){
        printf("Invalid input strings\n");
        exit(1);
    }
    char c;

    if (end - start == 1){
        c = (s[end] >= 'A' && s[end] <= 'Z') ? s[end] + 'a' - 'A' : s[end];
        s[end] = (s[start] >= 'A' && s[start] <= 'Z') ? s[start] + 'a' - 'A' : s[start];
        s[start] = c;
        return;
    }

    if (end == start){
        s[start] = (s[start] >= 'A' && s[start] <= 'Z') ? s[start] + 'a' - 'A' : s[start];
        return;
    }

    for (int i = 0; i < (end - start)/2; i++){
        c = s[start + i];
        if (s[end-i] >= 'A' && s[end-i] <= 'Z'){
            s[start + i] = s[end-i] + 'a' - 'A';
        }
        else
            s[start + i] = s[end-i];
        
        if (c >= 'A' && c <= 'Z'){
            s[end-i] = c  + 'a' - 'A';
        }
        else
            s[end-i] = c;
    }
}

// split str by spaces and revert subsections
// the strategy: avoid leading spaces, identify 
// and record index of first valid string
// do same for the end of the string when a new
// space is encountered. Pass the whole string
// and target range to reverse_range function
// repeat till end of string
void reverse_by_word(char* str){
    if (str == NULL){
        printf("Invalid input strings\n");
        exit(1);
    }

    // use to avoid counting leading space as characters
    // while it is zero, we are looking at space
    int letters_found = 0;
    
    // start and end of section to reverse
    int start = -1; 
    int end = -1;

    for (size_t i = 0; i < my_strlen(str) + 1; i++){
        // ignore leading spaces
        if (!letters_found && isspace(str[i])){
            continue;
        }
        // valid string found
        letters_found = 1;

        // set start of valid string region
        // this portion will be skipped until
        // we identify the end of the string and
        // reverse it
        if (start == -1){
            start = i;
            continue;
        }

        // new space or null terminator marks end
        // of valid string. reverse it and reset start
        if (isspace(str[i]) || str[i] == '\0'){
            end = i-1;
            reverse_range(str, start, end);
            start = -1;
            letters_found = 0;
        }
    }
}

// assumes null terminated inputs
// check each character in prefix against
// corresponding content of str
// any mismatch ends the function and returns 0
unsigned char is_prefix(const char* prefix, const char* str){
    if (prefix == NULL || str == NULL){
        printf("Invalid input strings\n");
        exit(1);
    }
    for (int i = 0; prefix[i] != 0; i++){
        if (prefix[i] != str[i]){
            return 0;
        }
    }
    return 1;
}

// removes last occurence of substr in-place
// use size of substr to increment counter each time
// characters match in order and reset when match breaks
// before len of substr. When match is found,keep track
// of index of last character (we can infer the first 
// using len of substr). Reset counter and continue search
// until end of str to search for later matches unless
// len of str - current index less than len of substr in
// which case match is impossible. 
// if match found, shift all characters after match to the 
// left by the length of substr and return index of last character
// return -1 otherwise
int remove_last_substr(char* str, const char* substr){
    if (str == NULL || substr == NULL){
        printf("Invalid input strings\n");
        exit(1);
    }

    size_t str_len = my_strlen(str);
    size_t substr_len = my_strlen(substr);

    // if substr is longer than string, match is impossible
    if (substr_len > str_len){
        return -1;
    }

    // reset when mismatch before len or when match before end of str
    size_t match_count = 0;

    // track latest match
    int latest_match = -1;

    for (size_t i = 0; i <= str_len; i++){
        if (str[i] == substr[match_count]){
            match_count++;
        }
        else{
            match_count = 0;
        }
        if (match_count == substr_len){
            latest_match = i;
            match_count = 0;
        }
        if ((str_len - i) < substr_len && !match_count){
            break;
        }
    }

    // remove substr if found
    if (latest_match == -1){
        return -1;
    }

    for (size_t i = latest_match+1; i < str_len + 1; i++){
        str[i - substr_len] = str[i];
    }
    return latest_match - substr_len + 1;
}

// remove every character in remove_chars from str
// perhaps a function that checks if a char is 
// in a string might be helpful here but that sounds
// inefficient. Can I do this without nested looping?
void strip_chars(char* str, const char* remove_chars){
    if (str == NULL || remove_chars == NULL){
        printf("Invalid input strings\n");
        exit(1);
    }
    
    // replace all characters to be removed with 2
    for (size_t i = 0; str[i] != '\0'; i++){
        size_t j = 0;
        while (remove_chars[j] != '\0'){
            if (remove_chars[j] == str[i]){
                str[i] = 2;
                break;
            }
            j++;
        }
    }

    // loop through and handle shifting
    int to_be_replaced, target_found = 0;

    for (size_t i = 0; str[i] != '\0'; i++){
        // if we encouter a space to be replaced for the first time
        // set to_be_replaced to it so we can replace it
        if (str[i] == 2 && !target_found){
            to_be_replaced = i;
            target_found = 1;
            continue;
        }

        // after catching the first space to be replaced,
        // we shift and the address of the shifted content
        // becomes the new target for replacement
        // no need to search for replace sites any more
        // we just shift valid content to the new replace sites
        if (str[i] != 2 && target_found){
            str[to_be_replaced] = str[i];
            to_be_replaced = i;
        }
    }
    // add null terminator at final replace site
    str[to_be_replaced] = '\0';
    
}

// takes in a string of digits and converts it to an integer
// currently supports only positive integers
int str_to_int(const char *string){
    int sign = 1;
    if (string == NULL){
        printf("Invalid input string\n");
        exit(1);
    }

    int i = 0, first_digit = 0;

    // ignore leading space
    while (string[i] != '\0' && isspace(string[i])){
        i++;
    }

    // parse first digit and check for sign. If negative, set sign to -1
    // account for negative sign if it is the first nonspace character
    if (string[i] == '-'){
        sign = -1;
        i++;
    }
    else if (string[i] == '+'){
        i++;
    }
    first_digit = i;

    while (string[i] != '\0'){
        // reject non digit characters
        if (string[i] < '0' || string[i] > '9'){
            printf("Invalid input string\n");
            exit(1);
        }
        i++;
    }

    // variable to store result
    int num = 0, power = 1;

    for (int j = i-1; j >= first_digit; j--){
        if (string[j] < '0' || string[j] > '9'){
            printf("Invalid input string\n");
            exit(1);
        }
        num += (int)(string[j]-48) * power;
        power *= 10;
    }
    return sign * num;
}
