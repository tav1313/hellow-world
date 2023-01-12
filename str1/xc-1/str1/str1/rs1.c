//
//  rs1.c
//  str1
//
//  Created by Алексей Татарников on 31.12.2022.
//

#include "rs1.h"

#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

char *
produce_spaces(short size)
{
    // TODO: size validation
    
    char *ret_value = malloc(sizeof *ret_value * size);

    for (int i = 0; i < size; i++)
    {
        *(ret_value + i) = ' ';
    }
    
    *(ret_value + size) = '\0';

    return ret_value;
}

char *
sub_string (const char *str,
            unsigned long pos,
            short length)
{
    // TODO: str, pos, length validation
    
    char *ret_value = malloc(sizeof *ret_value * (length + 1));
    memcpy(ret_value, &str[pos], length);
    ret_value[length] = '\0';
    
    return ret_value;
}

RS_ARRAY*
split_string (char *str_content)
{
    // TODO: str_content validation
    
    const char *start_marker = "***[";
    const char *end_marker = "]***";
    char *curr_spaces;
    char *curr_content;
    char *curr_content_to_print;
        
    unsigned long str_content_length = strlen(str_content);
    unsigned long stub_length;

    RS_ARRAY *ret_value = malloc(sizeof(RS_ARRAY));
    
    char **parts_strings = malloc(sizeof **parts_strings * (1 + 2 * str_content_length));
    short parts_strings_index = 0;
    
    // print start content
    curr_spaces = produce_spaces(str_content_length);
    stub_length = strlen(start_marker) + strlen(curr_spaces) + strlen(end_marker);
    curr_content_to_print = malloc(sizeof curr_content_to_print * (stub_length + 1));
    snprintf(curr_content_to_print, stub_length + 1, "%s%s%s", start_marker, curr_spaces, end_marker);
    printf("%s\n", curr_content_to_print);
    parts_strings[parts_strings_index] = malloc(sizeof(char*) * (strlen(curr_content_to_print) + 1));
    strcpy(parts_strings[parts_strings_index++], curr_content_to_print);
    
    free(curr_spaces);
    free(curr_content_to_print);
        
    // part1 - content + spaces
    for (long i = str_content_length - 1; i >= 0; i--)
    {
        curr_spaces = produce_spaces(i);
        curr_content = sub_string(str_content, i, str_content_length - i);
        
        unsigned long whole_content_length = strlen(start_marker) + strlen(curr_content) +
                                             strlen(curr_spaces)  + strlen(end_marker);
        
        curr_content_to_print = malloc(sizeof curr_content_to_print * (whole_content_length + 1));
        snprintf(curr_content_to_print, whole_content_length + 1, "%s%s%s%s", start_marker, curr_content, curr_spaces, end_marker);
        printf("%s\n", curr_content_to_print);
        parts_strings[parts_strings_index] = malloc(sizeof(char *) * (strlen(curr_content_to_print) + 1));
        strcpy(parts_strings[parts_strings_index++], curr_content_to_print);

        free(curr_spaces);
        free(curr_content);
        free(curr_content_to_print);
    }
    
    // part2 - spaces + content
    for (long i = 1; i < str_content_length; i++)
    {
        curr_spaces = produce_spaces(i);
        curr_content = sub_string(str_content, 0, str_content_length - i);
        
        unsigned long whole_content_length = strlen(start_marker) + strlen(curr_content) +
                                             strlen(curr_spaces)  + strlen(end_marker);
        
        curr_content_to_print = malloc(sizeof curr_content_to_print * (whole_content_length + 1));
        snprintf(curr_content_to_print, whole_content_length + 1, "%s%s%s%s", start_marker, curr_spaces, curr_content, end_marker);
        printf("%s\n", curr_content_to_print);
        parts_strings[parts_strings_index] = malloc(sizeof(char*) * (strlen(curr_content_to_print) + 1));
        strcpy(parts_strings[parts_strings_index++], curr_content_to_print);
        
        free(curr_spaces);
        free(curr_content);
        free(curr_content_to_print);
    }
    
    // print start content
    curr_spaces = produce_spaces(str_content_length);
    curr_content_to_print = malloc(sizeof *curr_content_to_print * (stub_length + 1));
    snprintf(curr_content_to_print, stub_length + 1, "%s%s%s", start_marker, curr_spaces, end_marker);
    printf("%s\n", curr_content_to_print);
    parts_strings[parts_strings_index] = malloc(sizeof(char *) * (strlen(curr_content_to_print) + 1));
    strcpy(parts_strings[parts_strings_index], curr_content_to_print);
    free(curr_spaces);
    free(curr_content_to_print);

    // TODO: typedef struct: **char, count
    // TODO: how to store a size (say, 'unsigned int') as a first array elm, if all other are char*?
    // TODO: how to pass char** as a parameter to the function to have it initialized in the external function? (currently it is NULL)
    ret_value->size = 1 + 2 * str_content_length;
    ret_value->array = parts_strings;

    return ret_value;
}

void 
free_rs(RS_ARRAY *ptr)
{
    // TODO: validate 'ptr'
    for (int i = 0; i < ptr->size; i++)
     {
         free(ptr->array[i]);
     }
    
    free(ptr->array);
    free(ptr);
}

// direction - -1 left-to-right, 1 - right-to-left
// step(milliseconds) - we divide 1000 ms / step to get ms to delay drawing
// how_long (seconds) - how long to visualize the content
void show1(char ** parts, int direction, int step, int how_long) {
    struct timeval stop, start;
    gettimeofday(&start, NULL);
    
    //        printf("\33[2K\r");
    //        printf("\033[A\033[2K\033[A\033[2K");
    //        clrtoeol();
    //        usleep(300000);
    //        sleep(1);
    //        gtk_text_set_placeholder_text ((GtkText *) wgt, content_to_print);
    //        gtk_button_set_label((GtkButton *)wgt, content_to_print);
    //        gtk_widget_queue_draw(wgt);
    //        clrtoeol();
    gettimeofday(&stop, NULL);
    printf("\ntook %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
}

int 
check_ptr1(char **ptr)
{
    ptr = malloc(1);
    ptr[0] = malloc(3);
    strcpy(ptr[0], "12");

    return 0;
}