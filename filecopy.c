#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
//You may also add more include directives as well.

// THIS VALUE CANNOT BE CHANGED.
// You should use this value when creating your buffer.
// And also to limit the amount of bytes each read CAN do.
#define BUFF_MAX 13
// ABOVE VALUE CANNOT BE CHANGED //



int main() {
  char input_1[30], input_2[30], Buf[27];
  int fd_in, fd_out;
  int count = 0;
  ssize_t ret_in;

  printf("Welcome to the File Copy Program by Nayan Pandey!\nEnter the name of the file to copy from: \n");
  scanf("%s", input_1);
  fd_in = open(input_1, O_RDONLY);
  if(fd_in == -1) {
    perror("Error");
    exit(1);
  }

  printf("Enter the name of the file to copy to: \n");
  scanf("%s", input_2);
  fd_out = open(input_2, O_WRONLY | O_CREAT | O_EXCL, 777);
  if(fd_out == -1) {
    perror("Error:");
    exit(1);
  }

  while((ret_in = read(fd_in, Buf, 27)) > 0) {
    write(fd_out, Buf, ret_in);
    count += ret_in;
  }

  printf("File Copy Successful, %d bytes copied\n", count);
  close(fd_in);
  close(fd_out);
  return 0;
}