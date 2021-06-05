#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include<sys/wait.h>

int main()
{
    pid_t p;
    char input_str[100];
    int fd1[2];
    if (pipe(fd1) == -1)
    {
        fprintf(stderr, "Pipe Failed");
        return 1;
    }
    printf("String to be piped: ");
    scanf("%[^\n]%*c", input_str);
    p = fork();
    if (p < 0)
    {
        fprintf(stderr, "Fork Failed");
        return 1;
    }

    // Parent process
    else if (p > 0)
    {
        close(fd1[0]); // Close reading end of pipe

        // Write input string and close writing end of pipe.
        write(fd1[1], input_str, strlen(input_str) + 1);
        close(fd1[1]);

        // Wait for child to send a string
        wait(NULL);
    }
    else
    {
        close(fd1[1]);  // Close writing end of first pipe
  
        // Read a string using first pipe
        char concat_str[100];
        read(fd1[0], concat_str, 100);
  
        // Close both reading ends
        close(fd1[0]);
        printf("Child printed: %s", concat_str);
        exit(0);
    }
}