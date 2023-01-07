#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>




int main(){

  FILE *fp;

  char command[20];

  while(1){

    scanf("%s",command);

    if(strcmp(command,"createfile")==0){

         char f[7];
         scanf("%s",f);
           getchar();
             if(strcmp(f,"--file")==0){

                char path[200];
                char c;
                   if((c=getchar())=='"'){

                       getchar();
                        int i=0;

                        do{
                           c=getchar();
                           path[i]=c;
                           i++;
                        }while(c!='"');

                         int j=0;
                         char path1[200];

                            while(path[j]!='"'){
                                if(path[j]=='/'){

                                    path1[j]='\0';
                                    mkdir(path1);
                                }
                                path1[j]=path[j];
                                j++;
                            }
                            path1[j]='\0';
                            fp=fopen(path1,"w");

                   }else{

                        int i=0;

                        do{
                           c=getchar();
                           path[i]=c;
                           i++;
                        }while(c!='\n');

                        int j=0;
                         char path2[200];

                            while(path[j]!='\n'){
                                if(path[j]=='/'){

                                    path2[j]='\0';
                                    mkdir(path2);
                                }
                                path2[j]=path[j];
                                j++;
                            }
                            path2[j]='\0';
                            fp=fopen(path2,"w");
                   }


         }else{printf("Invalid command\n");}

    }else
    if(strcmp(command,"exit")==0){
        return 0;
    }
    else
    {
        char a;
        while((a=getchar())!='\n'){
        }
        printf("Invalid command\n");
    }
  }
}
