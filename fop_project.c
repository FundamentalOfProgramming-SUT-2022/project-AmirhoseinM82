#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>




int main(){



  char command[20];

  while(1){

    scanf("%s",command);

    if(strcmp(command,"createfile")==0){
         FILE *fp;
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
                            fclose(fp);

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
                            fclose(fp);
                   }


         }else{printf("Invalid command\n");}

    }else
    if(strcmp(command,"insertstr")==0){

        char f[7];
        scanf("%s",f);
        getchar();
        if(strcmp(f,"--file")==0){

            char path[200];
            char c;
            if((c=getchar())=='"'){
                    getchar();
                    int i=0;
                    while((c=getchar())!='"'){
                        path[i]=c;
                        i++;
                    }
                    path[i]='\0';
                    getchar();
            }else{
                    int i=0;
                    while((c=getchar())!=' '){
                        path[i]=c;
                        i++;
                    }
                    path[i]='\0';
            }


                           for(int i=0;i<6;i++) getchar();
                           char string[500];
                           char s;
                           if((s=getchar())=='"'){
                               int j=0;

                               while(1){
                                  char a,b,c;
                                  a=getchar();
                                  if(a=='\\'){
                                     b=getchar();
                                     if(b=='\\'){
                                        string[j]='\\';
                                        j++;
                                        string[j]=getchar();
                                        j++;
                                     }else{
                                        string[j]='\n';
                                        j++;
                                     }
                                  }else
                                  if(a=='"'){
                                     b=getchar();
                                     if(b==' '){
                                          c=getchar();
                                          if(c=='-'){
                                             break;
                                          }else{
                                            string[j]='"';
                                            j++;
                                            string[j]=' ';
                                            j++;
                                            string[j]=c;
                                            j++;
                                          }
                                     }
                                     else{
                                        string[j]='"';
                                        j++;
                                        string[j]=b;
                                        j++;
                                     }
                                  }else if(a!='\\' && a!='"'){
                                  string[j]=a;
                                  j++;
                                  }
                               }

                               string[j]='\0';
                           }else{
                               int j=0;
                               char a,b;
                               string[j]=s;
                               j++;
                               while((a=getchar())!=' '){
                                  if(a=='\\'){
                                    b=getchar();
                                    if(b=='\\'){
                                        string[j]='\\';
                                        j++;
                                        string[j]=getchar();
                                        j++;
                                    }else{
                                        string[j]='\n';
                                        j++;
                                    }
                                  }
                                  string[j]=a;
                                  j++;
                               }
                               string[j]='\0';
                               getchar();
                           }
                                    for(int i=0;i<5;i++) getchar();
                                    int line,pos;
                                    scanf("%d:%d",&line,&pos);


                                          FILE *fp,*temp;
                                          fp=fopen(path,"r+");

                                          temp=fopen("temp.txt","w");
                                          char firstcopy;
                                          firstcopy=fgetc(fp);
                                          while(firstcopy!=EOF){

                                             fputc(firstcopy,temp);
                                             firstcopy=fgetc(fp);
                                          }
                                          fclose(temp);
                                          fclose(fp);
                                                fp=fopen(path,"w");
                                                temp=fopen("temp.txt","r");
                                                char buffer[500];
                                                for(int i=1;i<line;i++){
                                                    fgets(buffer,500,temp);
                                                    fputs(buffer,fp);
                                                }

                                                for(int i=0;i<pos;i++){
                                                    char c;
                                                    c=fgetc(temp);
                                                    fputc(c,fp);
                                                }
                                                fputs(string,fp);

                                                char secondcopy;
                                                secondcopy=fgetc(temp);
                                                while(secondcopy!=EOF){
                                                    fputc(secondcopy,fp);
                                                    secondcopy=fgetc(temp);
                                                }
                                                fclose(fp);
                                                fclose(temp);
                                                remove("temp.txt");

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
