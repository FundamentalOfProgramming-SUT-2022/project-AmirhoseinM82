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
                            if(fp=fopen(path1,"r")){
                                fclose(fp);
                                printf("file exists\n");
                            }else{
                            fp=fopen(path1,"w");
                            fclose(fp);
                            }

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
                            if(fp=fopen(path2,"r")){
                                fclose(fp);
                                printf("file exists\n");
                            }else{
                            fp=fopen(path2,"w");
                            fclose(fp);
                            }
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

                                          if(fp=fopen(path,"r")){
                                              fclose(fp);
                                          }else{
                                              printf("file does not exist\n");
                                              continue;
                                          }

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

                 if(fp=fopen(path,"r")){
                        fclose(fp);
                 }else{
                        printf("file does not exist\n");
                        continue;
                }

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
                   FILE *fp;
                   if(fp=fopen(path,"r")){
                        fclose(fp);
                   }else{
                        printf("file does not exist\n");
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

                   FILE *fp;
                   if(fp=fopen(path,"r")){
                        fclose(fp);
                   }else{
                        printf("file does not exist\n");
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

                   if(fp=fopen(path,"r")){
                        fclose(fp);
                   }else{
                        printf("file does not exist\n");
                        continue;
                   }

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
    if(strcmp(command,"find")==0){

         for(int i=0;i<7;i++) getchar();
         char string[200];
         char s;
         int tedad;
         if((s=getchar())=='"'){
             int i=0;
             while(1){
                char a,b;
                a=getchar();
                if(a=='\\'){
                    b=getchar();
                    if(b=='n'){
                        string[i]='\n';
                        i++;
                    }else
                    if(b=='"'){
                        string[i]='"';
                        i++;
                    }else
                    if(b=='\\'){
                        string[i]='\\';
                        i++;
                        string[i]=getchar();
                        i++;
                    }else
                    {
                       string[i]=b;
                       i++;
                    }
                }else
                if(a=='"'){
                    getchar();
                        break;
                }else{
                string[i]=a;
                i++;
                }

             }
             string[i]='\0';
             tedad=i;
         }else{
              int i=0;
              string[i]=s;
              i++;
              char a;
              while((a=getchar())!=' '){
                  string[i]=a;
                  i++;
              }
              string[i]='\0';
              tedad=i;
         }

         for(int i=0;i<7;i++) getchar();
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
                    c=getchar();

            }else{
                    int i=0;
                    c=getchar();
                    while(c!=' ' && c!='\n'){
                        path[i]=c;
                        i++;
                        c=getchar();
                    }
                        path[i]='\0';
            }

            int count=0,at=0,atn=1,byword=0,all=0;


            if(c=='\n'){
                printf("%d %d %d %d %d %s %s\n",count,at,atn,byword,all,string,path);
            }else{
                char dastoor[50];
                gets(dastoor);

                int k=0;
                while(dastoor[k]!='\0'){
                    if(dastoor[k]=='-'){
                        if(dastoor[k+2]=='o') count=1;
                        if(dastoor[k+2]=='t'){
                            at=1;
                            atn=dastoor[k+4]-'0';
                        }
                        if(dastoor[k+2]=='y') byword=1;
                        if(dastoor[k+2]=='l') all=1;
                    }
                    k++;
                }
               printf("%d %d %d %d %d %s %s\n",count,at,atn,byword,all,string,path);
            }

            FILE *fp;
            if(fp=fopen(path,"r")){
                fclose(fp);
            }else{
                printf("file does not exist\n");
                fclose(fp);
                continue;
            }

            int jaighah[20];
            int vajeh[20];
            int tedad_yaft=0;

            if(string[0]=='*'){
               FILE *fp;
               fp=fopen(path,"r");

               char c;
               int v=0,j=0,bn=0;
               int tedadva=1;
               c=fgetc(fp);
               int i=1;
               while(c!=EOF){

                      if(c==string[i]){
                      i++;
                      int cursor=ftell(fp);
                      int words=tedadva;
                      char s;
                      int compare=0;
                           while(string[i]!='\0'){

                                if(string[i-1]!='*' || (string[i]!=' ' && string[i]!='\n')){
                                   s=fgetc(fp);
                                }

                                if(s==' ' || s=='\n') tedadva++;
                                if(s=='\n') bn++;

                                if(s!=string[i]){
                                     compare=1;
                                     c=s;
                                     break;
                                }else{
                                     i++;
                                }

                               if(string[i]=='*' && (string[i+1]=='\0' || string[i+1]=='\n' || string[i+1]==' ')){
                                     while(s!=' ' && s!='\n' && s!=EOF){
                                          s=fgetc(fp);
                                          if(s==' ' || s=='\n') tedadva++;
                                          if(s=='\n') bn++;
                                     }
                                     i++;
                               }

                              if(string[i]=='*' && (string[i-1]=='\n' || string[i-1]==' ')){
                                     i++;
                                     s=fgetc(fp);
                                     if(s==' ' || s=='\n') tedadva++;
                                     if(s=='\n') bn++;

                                     while(s!=string[i] && s!=' ' && s!='\n' && s!=EOF){
                                          s=fgetc(fp);
                                          if(s==' ' || s=='\n') tedadva++;
                                          if(s=='\n') bn++;
                                    }

                             if(s==' ' || s=='\n' || s==EOF){
                                  compare=1;
                                  c=s;
                                  break;
                            }else{
                                  i++;
                            }

                            }
                       }

                        if(string[i]=='\0'){

                             if(string[i-1]=='*'){

                             }else{

                                c=fgetc(fp);

                                if(c==' ' || c=='\n' || c==EOF){
                                tedadva++;
                                if(c=='\n') bn++;

                                }else{
                                compare=1;
                                }
                             }
                       }

                           if(compare==0){
                               jaighah[j]=cursor-(bn+1)*1+1;
                               j++;
                               vajeh[v]=words;
                               v++;
                           }

                }else{
                         c=fgetc(fp);
                         if(c==' ' || c=='\n') tedadva++;
                         if(c=='\n') bn++;
                     }
                    i=1;

              }

                  tedad_yaft=j;

              }else{
                     FILE *fp;
                     fp=fopen(path,"r");

                     int v=0,j=0,bn=0;
                     int tedadva=1;
                     char c;
                     c=fgetc(fp);
                     int i=0;
                while(c!=EOF){
                        if(c==string[i]){
                                i++;
                                int cursor=ftell(fp);
                                int words=tedadva;
                                char s;
                                int compare=0;
                           while(string[i]!='\0'){

                                if(string[i-1]!='*' || (string[i]!=' ' && string[i]!='\n')){
                                   s=fgetc(fp);
                                }

                                if(s==' ' || s=='\n') tedadva++;
                                if(s=='\n') bn++;

                                if(s!=string[i]){
                                     compare=1;
                                     c=s;
                                     break;
                                }else{
                                     i++;
                                }

                               if(string[i]=='*' && (string[i+1]=='\0' || string[i+1]=='\n' || string[i+1]==' ')){
                                     while(s!=' ' && s!='\n' && s!=EOF){
                                          s=fgetc(fp);
                                          if(s==' ' || s=='\n') tedadva++;
                                          if(s=='\n') bn++;
                                     }
                                     i++;
                               }

                              if(string[i]=='*' && (string[i-1]=='\n' || string[i-1]==' ')){
                                     i++;
                                     s=fgetc(fp);
                                     if(s==' ' || s=='\n') tedadva++;
                                     if(s=='\n') bn++;

                                     while(s!=string[i] && s!=' ' && s!='\n' && s!=EOF){
                                          s=fgetc(fp);
                                          if(s==' ' || s=='\n') tedadva++;
                                          if(s=='\n') bn++;
                                    }

                             if(s==' ' || s=='\n' || s==EOF){
                                  compare=1;
                                  c=s;
                                  break;
                            }else{
                                  i++;
                            }

                            }
                       }

                        if(string[i]=='\0'){

                             if(string[i-1]=='*'){

                             }else{

                                c=fgetc(fp);

                                if(c==' ' || c=='\n' || c==EOF){
                                tedadva++;
                                if(c=='\n') bn++;

                                }else{
                                compare=1;
                                }
                             }
                       }

                           if(compare==0){
                               jaighah[j]=cursor-(bn+1)*1+1;
                               j++;
                               vajeh[v]=words;
                               v++;
                           }

                }else{

                    while(c!=' ' && c!='\n' && c!=EOF) c=fgetc(fp);
                         if(c==' ' || c=='\n') tedadva++;
                         if(c=='\n') bn++;
                    if(c!=EOF) c=fgetc(fp);
                }
                i=0;


            }



                  tedad_yaft=j;
        }

            if(all==1 && byword==1 && count==0 && at==0){
                if(tedad_yaft==0){
                    printf("not found\n");
                }else{
                    for(int i=0;i<tedad_yaft;i++){
                        printf("%d ",vajeh[i]);
                    }
                    printf("\n");
                }
            }else
            if(all==1 && byword==0 && count==0 && at==0){
                if(tedad_yaft==0){
                    printf("not found\n");
                }else{
                    for(int i=0;i<tedad_yaft;i++){
                       printf("%d ",jaighah[i]);
                    }
                    printf("\n");
                }
            }else
            if(all==0 && byword==0 && count==1 && at==0){
                if(tedad_yaft==0){
                    printf("not found\n");
                }else{
                    printf("%d\n",tedad_yaft);
                }
            }else
            if(all==0 && byword==0 && count==0 && at==1){
                if(tedad_yaft<atn){
                    printf("not found\n");
                }else{
                    printf("%d\n",jaighah[atn]);
                }
            }else
            if(all==0 && byword==1 && count==0 && at==0){
                if(tedad_yaft==0){
                    printf("not found\n");
                }else{
                    printf("%d\n",vajeh[0]);
                }
            }else
            if(all==0 && byword==0 && count==0 && at==0){

               if(tedad_yaft==0){
                    printf("not found\n");
                }else{
                    printf("%d\n",jaighah[0]);
                }

            }else{printf("invalid combination of attributes\n");}




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
