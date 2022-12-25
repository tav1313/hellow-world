//
//  main.c
//  str1
//
//  Created by Алексей Татарников on 22.12.2022.
//

#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>

// running string
// a string itself - a string to run
// a content to show - spaces + part of the string

char* produceSpaces(char * str_content)
{
    char ret_value[strlen(str_content)];

    for (int i = 0; i < strlen(ret_value); i++)
    {
        ret_value[i] = ' ';
    }

    return ret_value;
}

// str - the content to visualize
// direction - -1 left-to-right, 1 - right-to-left
// step(milliseconds) - we divide 1000 ms / step to get ms to delay drawing
// how_long (seconds) - how long to visualize the content
int runningString(char* str_content, int direction, int step, int how_long)
{
    const char start_marker[] = "***[";
    const char end_marker[] = "]***";
    
    char * ptr1 = "hhddd";
        
    
    int counter = 0;
    clock_t start_s = clock();
    
    struct timeval stop, start;
    gettimeofday(&start, NULL);
    
    char *spaces;
    char *content;
    
//    char subbuff[5];
//    memcpy( subbuff, &buff[10], 4 );
//    subbuff[4] = '\0';
    
    // print start - content - end
    short idx = 0;
    // part1 - content + spaces
    while (0)
    {
        
        //  str.substring() str.length()  - idx - symbols - form content part
        // form 'spaces' part spaces
    }
    
    // part2 - spaces + content
    
    
    while (counter++ < how_long)
    {
        usleep(1000); // 1ms
        sleep(1);
        printf("\n%d", counter);
    }
    
    clock_t stop_s = clock();
    
    //do stuff
    gettimeofday(&stop, NULL);
    printf("\ntook %lu us\n", (stop.tv_sec - start.tv_sec) * 1000000 + stop.tv_usec - start.tv_usec);
    
    printf("1");
    printf("2");
    printf("\b");
    printf("\n");
//    scanf("%s", ar1);
//    scanf("%s", ar1);
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    runningString("abcd", 1, 100, 2);
    return 0;
}
