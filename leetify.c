/*  This program converts an input text file to leetspeak, and outputs it to leetified.txt  */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

  FILE *file_to_read = fopen(argv[1], "r");
  FILE *file_to_write = fopen("leetified.txt", "w");

  if (file_to_read == NULL || file_to_write == NULL) printf("Error opening files");
  char c;
  while ((c = fgetc(file_to_read)) != EOF) {
    switch(c) {

      case 'L': case 'l': case 'I': case 'i':
        c = '1';
        break;
      case 'E': case 'e':
        c = '3';
        break;
      case 'O': case 'o':
        c = '0';
        break;
      case 'T': case 't':
        c = '7';
        break;
      case 'S': case 's':
        c = '5';
        break;
      case 'A': case 'a':
        c = '4';
        break;
      default:
        break;
    }

    fputc(c, file_to_write);
  }

  fclose(file_to_read);
  fclose(file_to_write);

  return EXIT_SUCCESS;
}
