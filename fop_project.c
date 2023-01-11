#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

void removestr(char path[],int line,int pos,int size,char bof){

                   FILE *fp,*temp;
                   fp=fopen(path,"r");
                   int curser=0;
                   int bn=0;
                   while(bn!=line-1){

                        char c;
                        c=fgetc(fp);
                        if(c=='\n') bn++;
                        curser++;

                   }
                   curser+=pos;
                   fclose(fp);
                   fp=fopen(path,"r");
                   temp=fopen("temp.txt","w");
                   if(bof=='b'){
                      char c;
                      for(int i=0;i<curser-size;i++){
                          c=fgetc(fp);
                          fputc(c,temp);
                      }
                      fseek(fp,curser+1,SEEK_SET);
                      c=fgetc(fp);
                      while(c!=EOF){
                         fputc(c,temp);
                         c=fgetc(fp);
                      }
                      fclose(fp);
                      fclose(temp);
                   }else{
                      char c;
                      for(int i=0;i<curser;i++){
                          c=fgetc(fp);
                          fputc(c,temp);
                      }
                      fseek(fp,curser+size+line-1,SEEK_SET);
                      c=fgetc(fp);
                      while(c!=EOF){
                         fputc(c,temp);
                         c=fgetc(fp);
                      }
                      fclose(fp);
                      fclose(temp);
                   }

                   fp=fopen(path,"w");
                   temp=fopen("temp.txt","r");
                   char copy;
                   copy=fgetc(temp);
                   while(copy!=EOF){
                     fputc(copy,fp);
                     copy=fgetc(temp);
                   }
                   fclose(fp);
                   fclose(temp);
                   remove("temp.txt");

}

void copystr(char path[],int line,int pos,int size,char bof){

                  FILE *fp,*clipboard;
                  fp=fopen(path,"r");
                  clipboard=fopen("clipboard.txt","w");

                  int curser=0;
                  int bn=0;
                  while(bn!=line-1){
                        char c;
                        c=fgetc(fp);
                        if(c=='\n') bn++;
                        curser++;
                  }
                  curser+=pos;

                  if(bof=='b'){
                      fseek(fp,curser-size,SEEK_SET);
                      char co;
                      for(int i=0;i<size;i++){
                          co=fgetc(fp);
                          fputc(co,clipboard);
                      }
                      fclose(fp);
                      fclose(clipboard);
                  }else
                  if(bof=='f'){
                      fseek(fp,curser+line-1,SEEK_SET);
                      char co;
                      for(int i=0;i<size;i++){
                          co=fgetc(fp);
                          fputc(co,clipboard);
                      }
                      fclose(fp);
                      fclose(clipboard);
                  }
}


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
                           char string[2048];
                           char s;
                           if((s=getchar())=='"'){
                               int j=0;

                               while(1){
                                  char a,b,c;
                                  a=getchar();
                                  if(a=='"'){
                                    break;
                                  }
                                  if(a=='\\'){
                                     b=getchar();
                                     if(b=='\\'){
                                        string[j]='\\';
                                        j++;
                                        string[j]=getchar();
                                        j++;
                                     }else if(b=='n'){
                                        string[j]='\n';
                                        j++;
                                     }else if(b=='"'){
                                        string[j]='"';
                                        j++;
                                     }
                                  }else {
                                  string[j]=a;
                                  j++;
                                  }
                               }

                               string[j]='\0';
                               getchar();
                               getchar();
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
                                                char buffer[1000];
                                                for(int i=1;i<line;i++){
                                                    fgets(buffer,1000,temp);
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
    if(strcmp(command,"cat")==0){
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
            }else{
                    int i=0;
                    while((c=getchar())!='\n'){
                        path[i]=c;
                        i++;
                    }
                    path[i]='\0';
            }

                 char buffer[2048];

                 FILE *fp;
                 fp=fopen(path,"r");
                 if(fp==NULL){
                    printf("File not found\n");
                    continue;
                 }
                 int i=0;
                 char character;
                 character=fgetc(fp);
                 while(character!=EOF){
                    buffer[i]=character;
                    i++;
                    character=fgetc(fp);
                 }
                 fclose(fp);
                 for(int j=0;j<i;j++){
                    printf("%c",buffer[j]);
                 }
                 printf("\n");

             }else{printf("Invalid command\n");}

    }else
    if(strcmp(command,"removestr")==0){

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
                   int line,pos;
                   scanf("%d:%d",&line,&pos);
                   for(int i=0;i<7;i++) getchar();
                   int size;
                   scanf("%d",&size);
                   char bof;
                   getchar();
                   getchar();
                   bof=getchar();
                   if(bof!='b' && bof!='f'){
                    printf("invalid direction\n");
                    continue;
                   }

                   removestr(path,line,pos,size,bof);

             }else{printf("Invalid command\n");}
    }else
    if(strcmp(command,"copystr")==0 || strcmp(command,"cutstr")==0){
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
                   int line,pos;
                   scanf("%d:%d",&line,&pos);
                   for(int i=0;i<7;i++) getchar();
                   int size;
                   scanf("%d",&size);
                   char bof;
                   getchar();
                   getchar();
                   bof=getchar();
                   if(bof!='b' && bof!='f'){
                    printf("invalid direction\n");
                    continue;
                   }


                        if(strcmp(command,"copystr")==0){
                            copystr(path,line,pos,size,bof);
                        }else
                        if(strcmp(command,"cutstr")==0){
                            copystr(path,line,pos,size,bof);
                            removestr(path,line,pos,size,bof);
                        }


             }else{printf("Invalid command\n");}

    }else
    if(strcmp(command,"pastestr")==0){

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
                   int line,pos;
                   scanf("%d:%d",&line,&pos);

                   FILE *fp,*temp,*clipboard;
                   fp=fopen(path,"r");
                   clipboard=fopen("clipboard.txt","r");
                   temp=fopen("temp.txt","w");
                   char buffer[1000];
                   for(int i=1;i<line;i++){
                       fgets(buffer,1000,fp);
                       fputs(buffer,temp);

                   }
                   char co;
                   for(int i=0;i<pos;i++){
                       co=fgetc(fp);
                       fputc(co,temp);

                   }
                   char co1;
                   co1=fgetc(clipboard);
                   while(co1!=EOF){
                       fputc(co1,temp);
                       co1=fgetc(clipboard);

                   }

                   char co3;
                   co3=fgetc(fp);
                   while(co3!=EOF){
                       fputc(co3,temp);
                       co3=fgetc(fp);
                   }

                   fclose(temp);
                   fclose(fp);
                   fclose(clipboard);

                   fp=fopen(path,"w");
                   temp=fopen("temp.txt","r");
                   char co2;
                   co2=fgetc(temp);
                   while(co2!=EOF){
                       fputc(co2,fp);
                       co2=fgetc(temp);

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
