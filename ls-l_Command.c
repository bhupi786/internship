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
 
    
    printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
    printf(".  ");
    printf("%d  ",fileStat.st_nlink);
    printf("%d  ",fileStat.st_uid);
    printf("%d  ",fileStat.st_gid);
    printf("%d  ",fileStat.st_size);
    printf("%s",ctime(&fileStat.st_mtime));
    printf("\b %s  ",dir->d_name); 
    }
   }
   closedir(d);  
  } 
 return 0;
}
