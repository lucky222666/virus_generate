#include<stdio.h>
#include<fcntl.h>
int main(int argc,char *argv[]){char *s = "#include<stdio.h>%c#include<fcntl.h>%cint main(int argc,char *argv[]){char *s = %c%s%c;int fd;fd=open(argv[1],O_CREAT|O_RDWR,0666);dprintf(fd,s,10,10,34,s,34);return 0;}";int fd;fd=open(argv[1],O_CREAT|O_RDWR,0666);dprintf(fd,s,10,10,34,s,34);return 0;}
