//
//  main.cpp
//  str3
//
//  Created by Алексей Татарников on 29.12.2022.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
//#include <qapplication.h>
//#include <qpushbutton.h>

char *produce_spaces(short size)
{
    char *ret_value = (char *)malloc(size);

    for (int i = 0; i < size; i++)
    {
        *(ret_value + i) = ' ';
    }
    
    *(ret_value + size) = '\0';

    return ret_value;
}

char *sub_string(const char *str, unsigned long pos, short length)
{
    char *ret_value = (char *) malloc(length + 1);
    memcpy(ret_value, &str[pos], length);
    ret_value[length] = '\0';
    
    return ret_value;
}

// str - the content to visualize
// direction - -1 left-to-right, 1 - right-to-left
// step(milliseconds) - we divide 1000 ms / step to get ms to delay drawing
// how_long (seconds) - how long to visualize the content
int running_string(char const *str_content, int direction, int step, int how_long)
{
    const char *start_marker = "***[";
    const char *end_marker = "]***";
    char *curr_spaces;
    char *curr_content;
    char *content_to_print;
    
            
    struct timeval stop, start;
    gettimeofday(&start, NULL);
    
//    sleep(3);
    
    unsigned long str_content_length = strlen(str_content);
    
    // print start content
    curr_spaces = produce_spaces(str_content_length);
    unsigned long start_length1 = strlen(start_marker) + strlen(curr_spaces) + strlen(end_marker);
    content_to_print = (char *)malloc(start_length1 + 1);
    snprintf(content_to_print, start_length1 + 1, "%s%s%s", start_marker, curr_spaces, end_marker);
    printf("%s\n", content_to_print);
    free(curr_spaces);
    
    // part1 - content + spaces
    for (long i = str_content_length - 1; i >= 0; i--)
    {
        curr_spaces = produce_spaces(i);
        curr_content = sub_string(str_content, i, str_content_length - i);
        
        unsigned long whole_content_length = strlen(start_marker) + strlen(curr_content) +
                                             strlen(curr_spaces)  + strlen(end_marker);
        
        content_to_print = (char *)malloc(whole_content_length + 1);
        snprintf(content_to_print, whole_content_length + 1, "%s%s%s%s", start_marker, curr_content, curr_spaces, end_marker);
//        clrtoeol();
        printf("%s\n", content_to_print);
//        printf("\33[2K\r");
//        printf("\033[A\033[2K\033[A\033[2K");
        //clear string
        //draw whole string
        
        free(curr_spaces);
        free(curr_content);
        free(content_to_print);
    }
    
    // part2 - spaces + content
    for (long i = 1; i < str_content_length; i++)
    {
        curr_spaces = produce_spaces(i);
        curr_content = sub_string(str_content, 0, str_content_length - i);
        
        unsigned long whole_content_length = strlen(start_marker) + strlen(curr_content) +
                                             strlen(curr_spaces)  + strlen(end_marker);
        
        content_to_print = (char *)malloc(whole_content_length + 1);
        snprintf(content_to_print, whole_content_length + 1, "%s%s%s%s", start_marker, curr_spaces, curr_content, end_marker);
//        clrtoeol();
        printf("%s\n", content_to_print);
        //clear string
        //draw whole string
        
        free(curr_spaces);
        free(curr_content);
        free(content_to_print);
    }
    
    // print start content
    curr_spaces = produce_spaces(str_content_length);
    content_to_print = (char *)malloc(start_length1 + 1);
    snprintf(content_to_print, start_length1 + 1, "%s%s%s", start_marker, curr_spaces, end_marker);
    printf("%s\n", content_to_print);
    free(curr_spaces);
    
    gettimeofday(&stop, NULL);
    printf("\ntook %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);

    return 0;
}

int main(int argc, const char * argv[]) {
//    QApplication app (argc, argv);
//
//    QPushButton button = new QPushButton();
//    button.setText("My text");
//    button.setToolTip("A tooltip");
//    button.show();
//
//    app.exec();
    
    running_string("abcd", 1, 100, 2);

    return 0;
}
