//
//  rs1.h
//  str1
//
//  Created by Алексей Татарников on 31.12.2022.
//

#ifndef rs1_h
#define rs1_h

#include <stdio.h>

typedef struct sa_data {
    unsigned int size;
    char **array;
} RS_ARRAY;

char *produce_spaces(short size);
char *sub_string(const char *str, unsigned long pos, short length);
RS_ARRAY* split_string(char *str_content);
void free_rs(RS_ARRAY *ptr);
int check_ptr1(char** ptr);

#endif /* rs1_h */
