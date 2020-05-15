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
        if(dir->d_name [0]!='.'){
   
 
       int file=0;
          if((file=open(dir->d_name,O_RDONLY)) < -1)
               return 1;
    
    struct stat fileStat;
    if(fstat(file,&fileStat) < 0)    
        return 1;
 
    
    printf(" %d  %s \n",fileStat.st_ino,dir->d_name);
     
    }
   }
   closedir(d);  
  } 
 return 0;
}
