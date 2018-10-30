#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
  struct stat buffer;

  stat("README.md", &buffer);

  printf("Evaluating README...\n");
  printf("Size of README: %ld\n", buffer.st_size);
  printf("Mode:  %d\n", buffer.st_mode);
  printf("Creation time: %s\n", ctime( &buffer.st_atime) );

  
}
