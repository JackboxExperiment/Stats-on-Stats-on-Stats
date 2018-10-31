#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char * get_size(char * buffer, double size) {
  if (size < 1024){
    sprintf(buffer, "%f B", size);
    return buffer;
  }
  
  size /= 1024.0;
  if (size < 1024) {
    sprintf(buffer, "%f KB", size);
    return buffer;
  }
  size /= 1024.0;
  if (size < 1024) {
    sprintf(buffer, "%f MB", size);
    return buffer;
  }
  size /= 1024.0;
  sprintf(buffer, "%f GB", size);

  return buffer;
}


int main() {
  char * info;
  struct stat buffer;

  stat("stat.c", &buffer);

  printf("Evaluating Stats...\n");
  printf("Size of Stat.c: %ld\n", buffer.st_size);
  printf("Permissions (octal):  %o\n", buffer.st_mode);
  printf("Last Access time: %s\n", ctime( &buffer.st_atime) );

  printf("Presenting file size: %s\n", get_size(info, buffer.st_size));
  return 0;
}
