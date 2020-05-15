#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<time.h>
#include<sys/param.h>
#include<dirent.h>
int main(void)
{
 char buf[MAXPATHLEN];
 getcwd(buf,MAXPATHLEN);
 DIR *d;
 struct dirent *dir;
 d=opendir(buf);
 if(d)
  {
  while((dir= readdir(d)))
     { 
       printf("%s \n", dir->d_name);
     }
    closedir(d);
  }
 return 0;
}
