#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>

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
                      for(int i=0;i<size;i++){
                        char x=fgetc(fp);
                      }
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
                      for(int i=0;i<size;i++){
                        char x=fgetc(fp);
                      }
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
                  fclose(fp);
                  fp=fopen(path,"r");

                  if(bof=='b'){

                      for(int i=0;i<curser-size;i++){
                          char x=fgetc(fp);
                      }
                      char co;
                      for(int i=0;i<size;i++){
                          co=fgetc(fp);
                          fputc(co,clipboard);
                      }
                      fclose(fp);
                      fclose(clipboard);
                  }else
                  if(bof=='f'){

                      for(int i=0;i<curser;i++){
                          char x=fgetc(fp);
                      }
                      char co;
                      for(int i=0;i<size;i++){
                          co=fgetc(fp);
                          fputc(co,clipboard);
                      }
                      fclose(fp);
                      fclose(clipboard);
                  }
}

void find(char path[],char string[],int *t,int v[],int jai[]){
      int check=0;
            int jaighah[200];
            int vajeh[200];
            int vaje[200];
            int jaigha[200];
            int tedad_yaft=0;

            if(string[0]=='*'){
                    check=1;
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

                               s=fgetc(fp);
                               if(s!=string[i]){
                                  compare=1;
                                  if(s==' ' || s=='\n') tedadva++;
                                  if(s=='\n') bn++;
                                  break;
                               }
                               i++;
                            }


                           if(compare==0){
                               jaighah[j]=cursor-(bn+1)*1+1;
                               j++;
                               vajeh[v]=words;
                               v++;
                           }

                       }
                         c=fgetc(fp);
                         if(c==' ' || c=='\n') tedadva++;
                         if(c=='\n') bn++;

                         i=1;

                 }

                  tedad_yaft=j;

                  for(int i=0;i<j;i++){
                    if(i<j-1){
                      if(vajeh[i]==vajeh[i+1]){
                          vajeh[i]=0;
                          jaighah[i]=0;
                      }
                    }
                  }

                  int m=0;
                  int jo=0;
                  for(int i=0;i<j;i++){
                      if(vajeh[i]!=0){
                         vaje[m]=vajeh[i];
                         jaigha[m]=jaighah[i];
                         m++;
                      }
                  }
                  tedad_yaft=m;

             }else{
                 check=2;
                FILE *fp;
                fp=fopen(path,"r");

                int setare=0;
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
                                 int flag=0;

                                 if(string[i]=='*' && (string[i+1]==' ' || string[i+1]=='\0')){
                                        setare=1;
                                    if(string[i+1]=='\0'){
                                        s=fgetc(fp);
                                        while(s!=' ' && s!='\n' && s!=EOF) s=fgetc(fp);
                                        if(s==' ' || s=='\n') tedadva++;
                                        if(s=='\n') bn++;
                                        break;
                                    }else
                                    if(string[i+1]==' '){
                                        s=fgetc(fp);
                                        while(s!=' ' && s!='\n' && s!=EOF) s=fgetc(fp);
                                        if(s==' ' || s=='\n') tedadva++;
                                        if(s=='\n') bn++;
                                        i++;
                                        i++;
                                    }
                                 }

                                 if(string[i]=='*' && string[i-1]==' '){
                                        setare=1;
                                    char reshte[50];
                                    char zirreshte[30];
                                    int k=0;
                                    int f=0;
                                    char *p;

                                    i++;

                                    while(1){
                                        if(string[i]==' ' || string[i]=='\0') break;
                                        zirreshte[f]=string[i];
                                        i++;
                                        f++;
                                    }

                                    s=fgetc(fp);
                                    while(s!=' ' && s!='\n'){
                                            if(s==EOF){
                                                flag=1;
                                                c=s;
                                                break;
                                            }
                                            reshte[k]=s;
                                            k++;
                                            s=fgetc(fp);
                                    }
                                    reshte[k]='\0';
                                    zirreshte[f]='\0';
                                    if(s==' ' || s=='\n') tedadva++;
                                    if(s=='\n') bn++;
                                    p=strstr(reshte,zirreshte);
                                    if(p){
                                        break;
                                    }else{
                                      compare=1;
                                      break;
                                    }
                                 }
                                 if(flag==1) break;

                                 s=fgetc(fp);
                                 if(s!=string[i]){
                                    compare=1;
                                    if(s==' ' || s=='\n') tedadva++;
                                    if(s=='\n') bn++;
                                    break;
                                 }
                                 if(s==' ' || s=='\n') tedadva++;
                                 if(s=='\n') bn++;
                                 i++;

                         }


                           if(compare==0){
                               jaighah[j]=cursor-(bn+1)*1+1;
                               j++;
                               vajeh[v]=words;
                               v++;
                           }

                     }

                    if(c!=EOF) c=fgetc(fp);
                    if(c==' ' || c=='\n') tedadva++;
                    if(c=='\n') bn++;

                    i=0;


               }

             if(setare==1){
                int k=1;
                for(int i=0;i<j;i++){
                 if(vajeh[i]==vajeh[k]){
                   while(vajeh[i]==vajeh[k]){
                      vajeh[k]=0;
                      jaighah[k]=0;
                      k++;
                   }
                 }
                     i=k-1;
                   k++;
                }

             }

                  tedad_yaft=j;

        }
        if(check==1){
            *t=tedad_yaft;
            for(int i=0;i<tedad_yaft;i++){
                v[i]=vaje[i];
            }
            for(int i=0;i<tedad_yaft;i++){
                jai[i]=jaigha[i];
            }
        }
        if(check==2){
            *t=tedad_yaft;
            for(int i=0;i<tedad_yaft;i++){
                v[i]=vajeh[i];
            }
            for(int i=0;i<tedad_yaft;i++){
                jai[i]=jaighah[i];
            }
        }
}

void tree(char *basePath,const int root,int depth,char khoroji[]){

    char a1=179,a2=195,a3=196;

    if(depth==-1){

    }else{
        if(root==2*(depth+1)){
            return;
        }
    }

    int i;
    char path[1000];
    struct dirent *dp;
    DIR *dir=opendir(basePath);

    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            for (i=0; i<root; i++)
            {
                if (i%2 == 0 || i == 0){
                    strcat(khoroji,"|");
                }else{
                    strcat(khoroji," ");
                }
            }
            strcat(khoroji,"|-");
            strcat(khoroji,"-");
            strcat(khoroji,dp->d_name);
            strcat(khoroji,"\n");

            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            tree(path,root+2,depth,khoroji);
        }
    }

    closedir(dir);
}

void treemain(char *basePath,const int root,int depth){

    char a1=179,a2=195,a3=196;

    if(depth==-1){

    }else{
        if(root==2*(depth+1)){
            return;
        }
    }

    int i;
    char path[1000];
    struct dirent *dp;
    DIR *dir=opendir(basePath);

    if (!dir)
        return;

    while ((dp = readdir(dir)) != NULL)
    {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0)
        {
            for (i=0; i<root; i++)
            {
                if (i%2 == 0 || i == 0){
                    printf("%c", 179);
                }else{
                    printf(" ");
                }
            }

            printf("%c%c%s\n", 195, 196, dp->d_name);
            strcpy(path, basePath);
            strcat(path, "/");
            strcat(path, dp->d_name);
            treemain(path,root+2,depth);
        }
    }

    closedir(dir);
}


void insertstr(char path[],char string[],int line,int pos){
                   FILE *fp,*temp,*backup;

                    if(fp=fopen(path,"r")){
                        fclose(fp);
                    }else{
                        printf("file does not exist\n");
                        return;
                    }

                    fp=fopen(path,"r");
                    char w;
                    int khat=1,caracter=0;
                    w=fgetc(fp);
                    caracter++;
                    int flag=0;
                    while(w!=EOF){
                        w=fgetc(fp);
                        caracter++;

                        if(w=='\n'){
                           if(khat==line){
                              if(pos>caracter){
                                 flag=1;
                              }
                           }
                           khat++;
                           caracter=0;
                        }
                    }
                    fclose(fp);
                    if(flag==1){
                        printf("invalid position\n");
                        return;
                    }
                    if(line>khat){
                        printf("invalid position\n");
                        return;
                    }
                    if(pos>caracter && line==khat){
                        printf("invalid position\n");
                        return;
                    }



                    char bpath[200];
                    strcpy(bpath,path);
                    bpath[0]='t';
                    fp=fopen(path,"r");
                    backup=fopen(bpath,"w");
                    char b;
                    b=fgetc(fp);
                    while(b!=EOF){
                        fputc(b,backup);
                        b=fgetc(fp);
                    }
                    fclose(fp);
                    fclose(backup);

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
                    char buffer[100000];
                    for(int i=1;i<line;i++){
                            fgets(buffer,100000,temp);
                            fputs(buffer,fp);
                    }

                    for(int i=0;i<pos;i++){
                            char c;
                            c=fgetc(temp);
                            if(c==EOF) break;
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
}

void cat(char path[],char cater[]){

                 FILE *fp;

                 if(fp=fopen(path,"r")){
                        fclose(fp);
                 }else{
                        printf("file does not exist\n");
                        return;
                }

                 fp=fopen(path,"r");
                 if(fp==NULL){
                    printf("File not found\n");
                    return;
                 }
                 int i=0;
                 char character;
                 character=fgetc(fp);
                 while(character!=EOF){
                    cater[i]=character;
                    i++;
                    character=fgetc(fp);
                 }
                 cater[i]='\0';
                 fclose(fp);
}

void grep(char string[],char option,char khoroji[]){

            struct GREP {
                 char file[50];
                 char sentence[1000];
            } ;

            struct GREP g[20];
            int m=0;

                   while(1){
                       char path[200];
                       char c;
                       char s;
                       c=getchar();
                       if(c=='=') break;
                       if(c=='"'){
                           getchar();
                           int i=0;
                           while((c=getchar())!='"'){
                              path[i]=c;
                              i++;
                           }
                           path[i]='\0';
                          s=getchar();
                       }else{
                           int i=0;
                           while(c!=' ' && c!='\n'){
                               c=getchar();
                               if(c==' ' || c=='\n') break;
                               path[i]=c;
                               i++;
                           }
                           s=c;
                           path[i]='\0';
                       }

                            FILE *fp;
                            fp=fopen(path,"r");
                            if(fp==NULL){
                                printf("file does not exist\n");
                                break;
                            }

                            char jomle[1000];
                            char x;

                            while(1){

                               x=fgetc(fp);
                               int k=0;
                               while(x!='\n' && x!=EOF){
                                   jomle[k]=x;
                                   x=fgetc(fp);
                                   k++;
                               }
                               jomle[k]='\0';
                               char *p=strstr(jomle,string);
                               if(p){
                                   strcpy(g[m].file,path);
                                   strcpy(g[m].sentence,jomle);
                                   m++;
                                }
                               if(x==EOF) break;
                            }
                            fclose(fp);
                            //if(s=='\n') break;

                   }

                   if(m==0){
                      printf("not found this pattern\n");
                      return;
                   }
                   if(option=='c'){
                       //printf("%d\n",i);
                       int n=m;
                       int e=0;
                       while(n>0){
                          e*=10;
                          e+=n%10;
                          n/=10;
                       }
                       while(e>0){
                          char temp=e%10+'0';
                          strcat(khoroji,temp);
                          e/=10;
                       }


                   }else
                   if(option=='i'){
                       for(int j=0;j<m;j++){
                           //printf("%s\n",g[j].file);
                           strcat(khoroji,g[j].file);
                           strcat(khoroji,"\n");
                       }
                   }else{
                      for(int j=0;j<m;j++){
                          //printf("%s : %s\n",g[j].file,g[j].sentence);
                          strcat(khoroji,g[j].file);
                          strcat(khoroji," : ");
                          strcat(khoroji,g[j].sentence);
                          strcat(khoroji,"\n");
                      }
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

                        if(fp=fopen(path,"r")){
                            fclose(fp);
                            printf("file already exists\n");
                            continue;
                        }

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

                        int k=0;
                        char bpath[200];

                            while(path[k]!='"'){
                                if(path[k]=='/'){
                                    bpath[k]='\0';
                                    mkdir(bpath);
                                }
                                if(k==0){
                                    bpath[k]='t';
                                    k++;
                                }
                                bpath[k]=path[k];
                                k++;
                            }
                            bpath[k]='\0';

                            fp=fopen(bpath,"w");
                            fclose(fp);

                   }else{

                        int i=0;

                        do{
                           c=getchar();
                           path[i]=c;
                           i++;
                        }while(c!='\n');

                        if(fp=fopen(path,"r")){
                            fclose(fp);
                            printf("file already exists\n");
                            continue;
                        }

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

                        int k=0;
                        char bpath[200];

                            while(path[k]!='\n'){
                                if(path[k]=='/'){
                                    bpath[k]='\0';
                                    mkdir(bpath);
                                }
                                if(k==0){
                                    bpath[k]='t';
                                    k++;
                                }
                                bpath[k]=path[k];
                                k++;
                            }
                            bpath[k]='\0';

                            fp=fopen(bpath,"w");
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
                           char string[100000];
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

                 insertstr(path,string,line,pos);


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
                    printf("%c",character);
                    i++;
                    character=fgetc(fp);
                 }
                 fclose(fp);
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
                   FILE *fp,*backup;
                   if(fp=fopen(path,"r")){
                        fclose(fp);
                   }else{
                        printf("file does not exist\n");
                        continue;
                    }

                    char bpath[200];
                    strcpy(bpath,path);
                    bpath[0]='t';
                    fp=fopen(path,"r");
                    backup=fopen(bpath,"w");
                    char b;
                    b=fgetc(fp);
                    while(b!=EOF){
                         fputc(b,backup);
                         b=fgetc(fp);
                    }
                    fclose(fp);
                    fclose(backup);

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

                   FILE *fp,*backup;
                   if(fp=fopen(path,"r")){
                        fclose(fp);
                   }else{
                        printf("file does not exist\n");
                        continue;
                   }

                   char bpath[200];
                   strcpy(bpath,path);
                   bpath[0]='t';
                   fp=fopen(path,"r");
                   backup=fopen(bpath,"w");
                   char b;
                   b=fgetc(fp);
                   while(b!=EOF){
                        fputc(b,backup);
                        b=fgetc(fp);
                   }
                   fclose(fp);
                   fclose(backup);

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

                   FILE *fp,*temp,*clipboard,*backup;

                   if(fp=fopen(path,"r")){
                        fclose(fp);
                   }else{
                        printf("file does not exist\n");
                        continue;
                   }

                   char bpath[200];
                   strcpy(bpath,path);
                   bpath[0]='t';
                   fp=fopen(path,"r");
                   backup=fopen(bpath,"w");
                   char b;
                   b=fgetc(fp);
                   while(b!=EOF){
                        fputc(b,backup);
                        b=fgetc(fp);
                   }
                   fclose(fp);
                   fclose(backup);

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

            }

            FILE *fp;
            if(fp=fopen(path,"r")){
                fclose(fp);
            }else{
                printf("file does not exist\n");
                fclose(fp);
                continue;
            }



        int t;
        int v[200];
        int jai[200];

        find(path,string,&t,v,jai);

            if(all==1 && byword==1 && count==0 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    for(int i=0;i<t;i++){
                        printf("%d ",v[i]);
                    }
                    printf("\n");
                }
            }else
            if(all==1 && byword==0 && count==0 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    for(int i=0;i<t;i++){
                       printf("%d ",jai[i]);
                    }
                    printf("\n");
                }
            }else
            if(all==0 && byword==0 && count==1 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    printf("%d\n",t);
                }
            }else
            if(all==0 && byword==0 && count==0 && at==1){
                if(t<atn){
                    printf("not found\n");
                }else{
                    printf("%d\n",jai[atn-1]);
                }
            }else
            if(all==0 && byword==1 && count==0 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    printf("%d\n",v[0]);
                }
            }else
            if(all==0 && byword==1 && count==0 && at==1){
                if(t<atn){
                    printf("not found\n");
                }else{
                    printf("%d\n",v[atn-1]);
                }
            }else
            if(all==0 && byword==0 && count==0 && at==0){

               if(t==0){
                    printf("not found\n");
                }else{
                    printf("%d\n",*(jai));
                }

            }else{printf("invalid combination of attributes\n");}




    }else
    if(strcmp(command,"replace")==0){

        for(int i=0;i<8;i++) getchar();
         char string1[200];
         char s1;
         int tedad1;
         if((s1=getchar())=='"'){
             int i=0;
             while(1){
                char a,b;
                a=getchar();
                if(a=='\\'){
                    b=getchar();
                    if(b=='n'){
                        string1[i]='\n';
                        i++;
                    }else
                    if(b=='"'){
                        string1[i]='"';
                        i++;
                    }else
                    if(b=='\\'){
                        string1[i]='\\';
                        i++;
                        string1[i]=getchar();
                        i++;
                    }else
                    {
                       string1[i]=b;
                       i++;
                    }
                }else
                if(a=='"'){
                    getchar();
                        break;
                }else{
                string1[i]=a;
                i++;
                }

             }
             string1[i]='\0';
             tedad1=i;
         }else{
              int i=0;
              string1[i]=s1;
              i++;
              char a;
              while((a=getchar())!=' '){
                  string1[i]=a;
                  i++;
              }
              string1[i]='\0';
              tedad1=i;
         }

         for(int i=0;i<7;i++) getchar();
         char string2[200];
         char s2;
         int tedad2;
         if((s2=getchar())=='"'){
             int i=0;
             while(1){
                char a,b;
                a=getchar();
                if(a=='\\'){
                    b=getchar();
                    if(b=='n'){
                        string2[i]='\n';
                        i++;
                    }else
                    if(b=='"'){
                        string2[i]='"';
                        i++;
                    }else
                    if(b=='\\'){
                        string2[i]='\\';
                        i++;
                        string2[i]=getchar();
                        i++;
                    }else
                    {
                       string2[i]=b;
                       i++;
                    }
                }else
                if(a=='"'){
                    getchar();
                        break;
                }else{
                string2[i]=a;
                i++;
                }

             }
             string2[i]='\0';
             tedad2=i;
         }else{
              int i=0;
              string2[i]=s2;
              i++;
              char a;
              while((a=getchar())!=' '){
                  string2[i]=a;
                  i++;
              }
              string2[i]='\0';
              tedad2=i;
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

            int at=0,atn=1,all=0;


            if(c=='\n'){

            }else{
                char dastoor[50];
                gets(dastoor);

                int k=0;
                while(dastoor[k]!='\0'){
                    if(dastoor[k]=='-'){
                        if(dastoor[k+2]=='t'){
                            at=1;
                            atn=dastoor[k+4]-'0';
                        }
                        if(dastoor[k+2]=='l') all=1;
                    }
                    k++;
                }

            }

            int t;
            int v[200];
            int jai[200];

            FILE *fp,*temp,*backup;

            if(fp=fopen(path,"r")){
                fclose(fp);
            }else{
                printf("file does not exists\n");
                continue;
            }

            char bpath[200];
            strcpy(bpath,path);
            bpath[0]='t';
            fp=fopen(path,"r");
            backup=fopen(bpath,"w");
            char b;
            b=fgetc(fp);
            while(b!=EOF){
                fputc(b,backup);
                b=fgetc(fp);
            }
            fclose(fp);
            fclose(backup);

            find(path,string1,&t,v,jai);


            int fasele=0;
            for(int i=0;i<strlen(string1);i++){
                if(string1[i]==' ' || string1[i]=='\n') fasele++;
            }

            if(all==1 && at==0){
                if(t==0) printf("not found str1\n");
                else
                {

                  fp=fopen(path,"r");
                  temp=fopen("temp.txt","w");

                  int i=0;
                  int space=0;
                        while(1){
                            char c;
                            c=fgetc(fp);
                            if(c==EOF){
                               break;
                            }
                            fputc(c,temp);

                            if(c==' ' || c=='\n') space++;
                            if(i<t){
                            if(space==v[i]-1){
                               char x;
                               for(int i=0;i<=fasele;){
                                  x=fgetc(fp);
                                  if(x==' ' || x=='\n') i++;
                                  if(x==EOF) break;
                               }
                               space+=fasele+1;
                               fputs(string2,temp);
                               if(x==EOF) break;
                               fputc(x,temp);
                               i++;
                            }
                            }
                        }
                  fclose(temp);
                  fclose(fp);
                  fp=fopen(path,"w");
                  temp=fopen("temp.txt","r");

                  char c;
                  c=fgetc(temp);
                  while(c!=EOF){
                    fputc(c,fp);
                    c=fgetc(temp);
                  }
                  fclose(fp);
                  fclose(temp);
                  remove("temp.txt");
                }

            }else
            if(all==0 && at==1){
                if(t==0) printf("not found str1\n");
                else if(atn>t) printf("not found str1 at this pos\n");
                else
                {
                  FILE *fp,*temp;
                  fp=fopen(path,"r");
                  temp=fopen("temp.txt","w");

                  int i=0;
                  int space=0;
                        while(1){
                            char c;
                            c=fgetc(fp);
                            if(c==EOF){
                               break;
                            }
                            fputc(c,temp);

                            if(c==' ' || c=='\n') space++;

                            if(space==v[atn-1]-1){
                               char x;
                               for(int i=0;i<=fasele;){
                                  x=fgetc(fp);
                                  if(x==' ' || x=='\n') i++;
                                  if(x==EOF) break;
                               }
                               space+=fasele+1;
                               fputs(string2,temp);
                               if(x==EOF) break;
                               fputc(x,temp);

                            }

                        }
                  fclose(temp);
                  fclose(fp);
                  fp=fopen(path,"w");
                  temp=fopen("temp.txt","r");

                  char c;
                  c=fgetc(temp);
                  while(c!=EOF){
                    fputc(c,fp);
                    c=fgetc(temp);
                  }
                  fclose(fp);
                  fclose(temp);
                  remove("temp.txt");
                }

            }else
            if(all==0 && at==0){
                if(t==0) printf("not found str1\n");
                else
                {
                  FILE *fp,*temp;
                  fp=fopen(path,"r");
                  temp=fopen("temp.txt","w");

                  int i=0;
                  int space=0;
                        while(1){
                            char c;
                            c=fgetc(fp);
                            if(c==EOF){
                               break;
                            }
                            fputc(c,temp);

                            if(c==' ' || c=='\n') space++;

                            if(space==v[0]-1){
                               char x;
                               for(int i=0;i<=fasele;){
                                  x=fgetc(fp);
                                  if(x==' ' || x=='\n') i++;
                                  if(x==EOF) break;
                               }
                               space+=fasele+1;
                               fputs(string2,temp);
                               if(x==EOF) break;
                               fputc(x,temp);

                            }

                        }
                  fclose(temp);
                  fclose(fp);
                  fp=fopen(path,"w");
                  temp=fopen("temp.txt","r");

                  char c;
                  c=fgetc(temp);
                  while(c!=EOF){
                    fputc(c,fp);
                    c=fgetc(temp);
                  }
                  fclose(fp);
                  fclose(temp);
                  remove("temp.txt");
                }
            }




    }else
    if(strcmp(command,"grep")==0){

          getchar();
          getchar();
          char opt;
          char option='0';
          opt=getchar();
          if(opt=='c'){
                option='c';
                for(int i=0;i<7;i++) getchar();
          }else
          if(opt=='i'){
                option='i';
                for(int i=0;i<7;i++) getchar();
          }
          else{
                for(int i=0;i<4;i++) getchar();
          }


          char string[200];
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

            }

            for(int i=0;i<8;i++) getchar();

            struct GREP {
                 char file[50];
                 char sentence[1000];
            } ;

            struct GREP g[20];
            int i=0;
                   while(1){
                       char path[200];
                       char c;
                       char s;
                       if((c=getchar())=='"'){
                           getchar();
                           int i=0;
                           while((c=getchar())!='"'){
                              path[i]=c;
                              i++;
                           }
                           path[i]='\0';
                          s=getchar();
                       }else{
                           int i=0;
                           while(c!=' ' && c!='\n'){
                               c=getchar();
                               if(c==' ' || c=='\n') break;
                               path[i]=c;
                               i++;
                           }
                           s=c;
                           path[i]='\0';
                       }

                            FILE *fp;
                            fp=fopen(path,"r");
                            if(fp==NULL){
                                printf("file does not exist\n");
                                break;
                            }

                            char jomle[1000];
                            char x;
                            while(1){
                               x=fgetc(fp);
                               int k=0;
                               while(x!='\n' && x!=EOF){
                                   jomle[k]=x;
                                   x=fgetc(fp);
                                   k++;
                               }
                               jomle[k]='\0';
                               char *p=strstr(jomle,string);
                               if(p){
                                   strcpy(g[i].file,path);
                                   strcpy(g[i].sentence,jomle);
                                   i++;
                                }
                               if(x==EOF) break;
                            }
                            fclose(fp);
                            if(s=='\n') break;
                   }

                   if(i==0){
                      printf("not found this pattern\n");
                      continue;
                   }
                   if(option=='c'){
                       printf("%d\n",i);
                   }else
                   if(option=='i'){
                       for(int j=0;j<i;j++){
                           printf("%s\n",g[j].file);
                       }
                   }else{
                      for(int j=0;j<i;j++){
                          printf("%s : %s\n",g[j].file,g[j].sentence);
                      }
                   }

    }else
    if(strcmp(command,"compare")==0){
            getchar();
            char path1[200];
                   char c1;
                   if((c1=getchar())=='"'){
                        getchar();
                        int i=0;
                        while((c1=getchar())!='"'){
                             path1[i]=c1;
                             i++;
                        }
                        path1[i]='\0';
            }else{
                    int i=0;
                    while((c1=getchar())!=' '){
                        path1[i]=c1;
                        i++;
                    }
                    path1[i]='\0';
            }

            char path2[200];
                   char c2;
                   if((c2=getchar())=='"'){
                        getchar();
                        int i=0;
                        while((c2=getchar())!='"'){
                             path2[i]=c2;
                             i++;
                        }
                        path2[i]='\0';
            }else{
                    int i=0;
                    while((c2=getchar())!='\n'){
                        path2[i]=c2;
                        i++;
                    }
                    path2[i]='\0';
            }

            FILE *fp1,*fp2;
            fp1=fopen(path1,"r");
            fp2=fopen(path2,"r");

            if(fp1==NULL || fp2==NULL){
                printf("file does not exist\n");
                continue;
            }

            char s1,s2;
            int j=1;
        while(s1!=EOF && s2!=EOF){
            char line1[1000];
            char line2[1000];
            int i1=0,i2=0;

            s1=fgetc(fp1);
            while(s1!='\n' && s1!=EOF){
                line1[i1]=s1;
                s1=fgetc(fp1);
                i1++;
            }
            line1[i1]='\0';
            s2=fgetc(fp2);
            while(s2!='\n' && s2!=EOF){
                line2[i2]=s2;
                s2=fgetc(fp2);
                i2++;
            }
            line2[i2]='\0';

            if(strcmp(line1,line2)!=0){
                printf("========== #%d ==========\n",j);
                printf("%s\n",line1);
                printf("%s\n",line2);
            }
            j++;
        }

            if(s1==EOF && s2!=EOF){
                printf("<<<<<<<<<< %d-end >>>>>>>>>> content from file2\n",j);
                char buffer[1000];
                while(fgets(buffer,1000,fp2)!=NULL){
                    printf("%s",buffer);
                }
                printf("\n");
            }else
            if(s1!=EOF && s2==EOF){
                printf("<<<<<<<<<< #%d-end >>>>>>>>>> content from file1\n",j);
                char buffer[1000];
                while(fgets(buffer,1000,fp1)!=NULL){
                    printf("%s",buffer);
                }
                printf("\n");
            }


    }else
    if(strcmp(command,"tree")==0){

        char path[100];
        int depth;
        scanf("%d",&depth);
        if(depth<-1){
            printf("invalid depth\n");
            continue;
        }
        scanf("%s", path);

        treemain(path, 0,depth);

    }else
    if(strcmp(command,"auto-indent")==0){

            getchar();
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

            FILE *fp,*temp,*backup;

            if(fp=fopen(path,"r")){
                fclose(fp);
            }else{
                printf("file does not exists\n");
                continue;
            }

            char bpath[200];
            strcpy(bpath,path);
            bpath[0]='t';
            fp=fopen(path,"r");
            backup=fopen(bpath,"w");
            char b;
            b=fgetc(fp);
            while(b!=EOF){
                fputc(b,backup);
                b=fgetc(fp);
            }
            fclose(fp);
            fclose(backup);

            fp=fopen(path,"r");
            temp=fopen("temp.txt","w");
            int tabs=0;

            char s0=' ',s,bn='\n',tab='\t',sp=' ';

            s0=fgetc(fp);
            if(s0!='{'){
               fputc(s0,temp);
            }else{
              s=s0;
              s0=' ';
            }
            while(s!=EOF){
                if(s!='}' && s!='{'){
                   s=fgetc(fp);
                }
                if(s=='{'){
                  tabs++;
                    if(s0==' ' || s0=='{'){

                        fputc(s,temp);
                        fputc(bn,temp);
                        for(int i=0;i<tabs;i++){
                            for(int j=0;j<4;j++){
                                fputc(sp,temp);
                            }
                        }
                    }else{

                        fputc(sp,temp);
                        fputc(s,temp);
                        fputc(bn,temp);
                        for(int i=0;i<tabs;i++){
                            for(int j=0;j<4;j++){
                                fputc(sp,temp);
                            }
                        }
                    }
                  s0=s;
                  s=fgetc(fp);
                  while(s==' ' || s=='\n') s=fgetc(fp);
                  s0=s;
                  if(s!='{' && s!='}'){
                     fputc(s,temp);
                  }
                  continue;
                }

                if(s=='}'){
                    if(s0!='\n') fputc(bn,temp);
                    tabs--;
                    for(int i=0;i<tabs;i++){
                            for(int j=0;j<4;j++){
                                fputc(sp,temp);
                            }
                        }
                    fputc(s,temp);
                    s=fgetc(fp);
                    while(s==' ' || s=='\n') s=fgetc(fp);
                    if(s!='}'){
                    fputc(bn,temp);
                    }
                    for(int i=0;i<tabs;i++){
                            for(int j=0;j<4;j++){
                                fputc(sp,temp);
                            }
                    }
                    if(s!='}') fputc(s,temp);
                    continue;
                }

                fputc(s,temp);
                if(s=='\n'){
                    for(int i=0;i<tabs;i++){
                            for(int j=0;j<4;j++){
                                fputc(sp,temp);
                            }
                        }
                    while(s=='\n' || s==' ') s=fgetc(fp);
                    if(s!='{' &&s!='}') fputc(s,temp);
                }

                s0=s;
            }

            fclose(fp);
            fclose(temp);

            fp=fopen(path,"w");
            temp=fopen("temp.txt","r");
            char x;
            x=fgetc(temp);
            while(x!=EOF){
                fputc(x,fp);
                x=fgetc(temp);
            }
            fclose(fp);
            fclose(temp);
            remove("temp.txt");


    }else
    if(strcmp(command,"undo")==0){

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

            FILE *fp,*temp,*backup;

            if(fp=fopen(path,"r")){
                fclose(fp);
            }else{
                fclose(fp);
                printf("file does not exists\n");
                continue;
            }

            char bpath[200];
            strcpy(bpath,path);
            bpath[0]='t';

            fp=fopen(path,"r");
            temp=fopen("temp.txt","w");
            char c1;
            c1=fgetc(fp);
            while(c1!=EOF){
                fputc(c1,temp);
                c1=fgetc(fp);
            }
            fclose(fp);
            fclose(temp);

            backup=fopen(bpath,"r");
            fp=fopen(path,"w");
            char c2;
            c2=fgetc(backup);
            while(c2!=EOF){
                fputc(c2,fp);
                c2=fgetc(backup);
            }
            fclose(fp);
            fclose(backup);

            temp=fopen("temp.txt","r");
            backup=fopen(bpath,"w");
            char c3;
            c3=fgetc(temp);
            while(c3!=EOF){
                fputc(c3,backup);
                c3=fgetc(temp);
            }
            fclose(backup);
            fclose(temp);
            remove("temp.txt");

         }else{printf("invalid\n");}

    }else
    if(strcmp(command,"arman")==0){
           getchar();
           char first[10];
           scanf("%s",first);

           if(strcmp(first,"cat")==0){

                for(int i=0;i<8;i++) getchar();

                char path1[200];
                char c;
                if((c=getchar())=='"'){
                    getchar();
                    int i=0;
                    while((c=getchar())!='"'){
                        path1[i]=c;
                        i++;
                    }
                    path1[i]='\0';
                    getchar();
                }else{
                    int i=0;
                    while((c=getchar())!=' '){
                        path1[i]=c;
                        i++;
                    }
                    path1[i]='\0';
                }

                char khoroji[1000000];
                cat(path1,khoroji);

                for(int i=0;i<3;i++) getchar();

                char second[10];
                scanf("%s",second);

                if(strcmp(second,"insertstr")==0){

                      for(int i=0;i<8;i++) getchar();

                      char path2[200];
                      char c;
                      if((c=getchar())=='"'){
                         getchar();
                         int i=0;
                         while((c=getchar())!='"'){
                             path2[i]=c;
                             i++;
                         }
                         path2[i]='\0';
                         getchar();
                      }else{
                         int i=0;
                         while((c=getchar())!=' '){
                             path2[i]=c;
                             i++;
                         }
                         path2[i]='\0';
                      }

                      for(int i=0;i<6;i++) getchar();
                      int line,pos;
                      scanf("%d:%d",&line,&pos);

                      insertstr(path2,khoroji,line,pos);


                }
                if(strcmp(second,"find")==0){
                      for(int i=0;i<8;i++) getchar();
                      char path2[200];
                      char c;
                      if((c=getchar())=='"'){
                         getchar();
                         int i=0;
                         while((c=getchar())!='"'){
                            path2[i]=c;
                            i++;
                         }
                         path2[i]='\0';
                         c=getchar();

                      }else{
                         int i=0;
                         c=getchar();
                         while(c!=' ' && c!='\n'){
                             path2[i]=c;
                             i++;
                             c=getchar();
                         }
                         path2[i]='\0';
                      }

                      int count=0,at=0,atn=1,byword=0,all=0;


                      if(c=='\n'){

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

                      }

                      FILE *fp;
                      if(fp=fopen(path2,"r")){
                          fclose(fp);
                      }else{
                          printf("file does not exist\n");
                          fclose(fp);
                          continue;
                      }



                      int t;
                      int v[200];
                      int jai[200];

                      find(path2,khoroji,&t,v,jai);

                      if(all==1 && byword==1 && count==0 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    for(int i=0;i<t;i++){
                        printf("%d ",v[i]);
                    }
                    printf("\n");
                }
            }else
            if(all==1 && byword==0 && count==0 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    for(int i=0;i<t;i++){
                       printf("%d ",jai[i]);
                    }
                    printf("\n");
                }
            }else
            if(all==0 && byword==0 && count==1 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    printf("%d\n",t);
                }
            }else
            if(all==0 && byword==0 && count==0 && at==1){
                if(t<atn){
                    printf("not found\n");
                }else{
                    printf("%d\n",jai[atn]);
                }
            }else
            if(all==0 && byword==1 && count==0 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    printf("%d\n",v[0]);
                }
            }else
            if(all==0 && byword==0 && count==0 && at==0){

               if(t==0){
                    printf("not found\n");
                }else{
                    printf("%d\n",*(jai));
                }

                }else{printf("invalid combination of attributes\n");}


                }

           }
           if(strcmp(first,"find")==0){
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

            }else{
                char dastoor[50];
                char x;
                int i=0;
                while((x=getchar())!='='){
                    dastoor[i]=x;
                    i++;
                }
                i--;
                dastoor[i]='\0';

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

            }

            FILE *fp;
            if(fp=fopen(path,"r")){
                fclose(fp);
            }else{
                printf("file does not exist\n");
                fclose(fp);
                continue;
            }



        int t;
        int v[200];
        int jai[200];

        find(path,string,&t,v,jai);

        char khoroji[200];
        int index=0;

            if(all==1 && byword==1 && count==0 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    for(int i=0;i<t;i++){
                        index+=sprintf(&khoroji[index],"%d",v[i]);
                    }
                    printf("\n");
                }
            }else
            if(all==1 && byword==0 && count==0 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    for(int i=0;i<t;i++){
                       index+=sprintf(&khoroji[index],"%d",jai[i]);
                    }
                    printf("\n");
                }
            }else
            if(all==0 && byword==0 && count==1 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    index+=sprintf(&khoroji[index],"%d",t);
                }
            }else
            if(all==0 && byword==0 && count==0 && at==1){
                if(t<atn){
                    printf("not found\n");
                }else{
                    index+=sprintf(&khoroji[index],"%d",jai[atn]);
                }
            }else
            if(all==0 && byword==1 && count==0 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    index+=sprintf(&khoroji[index],"%d",v[0]);
                }
            }else
            if(all==0 && byword==0 && count==0 && at==0){

               if(t==0){
                    printf("not found\n");
                }else{
                    index+=sprintf(&khoroji[index],"%d",jai[0]);
                }

            }else{printf("invalid combination of attributes\n");}


                    for(int i=0;i<19;i++) getchar();

                    char path2[200];
                      char co;
                      if((co=getchar())=='"'){
                         getchar();
                         int i=0;
                         while((co=getchar())!='"'){
                             path2[i]=co;
                             i++;
                         }
                         path2[i]='\0';
                         getchar();
                      }else{
                         int i=0;
                         while((co=getchar())!=' '){
                             path2[i]=co;
                             i++;
                         }
                         path2[i]='\0';
                      }

                      for(int i=0;i<6;i++) getchar();
                      int line,pos;
                      scanf("%d:%d",&line,&pos);

                      insertstr(path2,khoroji,line,pos);

           }
           if(strcmp(first,"tree")==0){
                 getchar();
                 int depth;
                 scanf("%d",&depth);
                 getchar();

                 char path[5]="root";


                 char khoroji[10000];

                 tree(path, 0,depth,khoroji);

                for(int i=0;i<3;i++) getchar();

                char second[10];
                scanf("%s",second);

                if(strcmp(second,"insertstr")==0){

                      for(int i=0;i<8;i++) getchar();

                      char path2[200];
                      char c;
                      if((c=getchar())=='"'){
                         getchar();
                         int i=0;
                         while((c=getchar())!='"'){
                             path2[i]=c;
                             i++;
                         }
                         path2[i]='\0';
                         getchar();
                      }else{
                         int i=0;
                         while((c=getchar())!=' '){
                             path2[i]=c;
                             i++;
                         }
                         path2[i]='\0';
                      }

                      for(int i=0;i<6;i++) getchar();
                      int line,pos;
                      scanf("%d:%d",&line,&pos);

                      insertstr(path2,khoroji,line,pos);


                }
                if(strcmp(second,"find")==0){
                      for(int i=0;i<8;i++) getchar();
                      char path2[200];
                      char c;
                      if((c=getchar())=='"'){
                         getchar();
                         int i=0;
                         while((c=getchar())!='"'){
                            path2[i]=c;
                            i++;
                         }
                         path2[i]='\0';
                         c=getchar();

                      }else{
                         int i=0;
                         c=getchar();
                         while(c!=' ' && c!='\n'){
                             path2[i]=c;
                             i++;
                             c=getchar();
                         }
                         path2[i]='\0';
                      }

                      int count=0,at=0,atn=1,byword=0,all=0;


                      if(c=='\n'){

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

                      }

                      FILE *fp;
                      if(fp=fopen(path2,"r")){
                          fclose(fp);
                      }else{
                          printf("file does not exist\n");
                          fclose(fp);
                          continue;
                      }



                      int t;
                      int v[200];
                      int jai[200];

                      find(path2,khoroji,&t,v,jai);

                      if(all==1 && byword==1 && count==0 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    for(int i=0;i<t;i++){
                        printf("%d ",v[i]);
                    }
                    printf("\n");
                }
            }else
            if(all==1 && byword==0 && count==0 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    for(int i=0;i<t;i++){
                       printf("%d ",jai[i]);
                    }
                    printf("\n");
                }
            }else
            if(all==0 && byword==0 && count==1 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    printf("%d\n",t);
                }
            }else
            if(all==0 && byword==0 && count==0 && at==1){
                if(t<atn){
                    printf("not found\n");
                }else{
                    printf("%d\n",jai[atn]);
                }
            }else
            if(all==0 && byword==1 && count==0 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    printf("%d\n",v[0]);
                }
            }else
            if(all==0 && byword==0 && count==0 && at==0){

               if(t==0){
                    printf("not found\n");
                }else{
                    printf("%d\n",*(jai));
                }

                }else{printf("invalid combination of attributes\n");}


                }
           }
           if(strcmp(first,"grep")==0){
                 getchar();
                 getchar();
                 char opt;
                 char option='0';
                 opt=getchar();
                 if(opt=='c'){
                     option='c';
                     for(int i=0;i<7;i++) getchar();
                 }else
                 if(opt=='i'){
                     option='i';
                     for(int i=0;i<7;i++) getchar();
                 }
                 else{
                     for(int i=0;i<4;i++) getchar();
                }


          char string[200];
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

                  }
                  for(int i=0;i<8;i++) getchar();

                  char khoroji[100000];
                  grep(string,option,khoroji);

                  for(int i=0;i<2;i++) getchar();

                char second[10];
                scanf("%s",second);

                if(strcmp(second,"insertstr")==0){

                      for(int i=0;i<8;i++) getchar();

                      char path2[200];
                      char c;
                      if((c=getchar())=='"'){
                         getchar();
                         int i=0;
                         while((c=getchar())!='"'){
                             path2[i]=c;
                             i++;
                         }
                         path2[i]='\0';
                         getchar();
                      }else{
                         int i=0;
                         while((c=getchar())!=' '){
                             path2[i]=c;
                             i++;
                         }
                         path2[i]='\0';
                      }

                      for(int i=0;i<6;i++) getchar();
                      int line,pos;
                      scanf("%d:%d",&line,&pos);

                      insertstr(path2,khoroji,line,pos);


                }
                if(strcmp(second,"find")==0){
                      for(int i=0;i<8;i++) getchar();
                      char path2[200];
                      char c;
                      if((c=getchar())=='"'){
                         getchar();
                         int i=0;
                         while((c=getchar())!='"'){
                            path2[i]=c;
                            i++;
                         }
                         path2[i]='\0';
                         c=getchar();

                      }else{
                         int i=0;
                         c=getchar();
                         while(c!=' ' && c!='\n'){
                             path2[i]=c;
                             i++;
                             c=getchar();
                         }
                         path2[i]='\0';
                      }

                      int count=0,at=0,atn=1,byword=0,all=0;


                      if(c=='\n'){

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

                      }

                      FILE *fp;
                      if(fp=fopen(path2,"r")){
                          fclose(fp);
                      }else{
                          printf("file does not exist\n");
                          fclose(fp);
                          continue;
                      }



                      int t;
                      int v[200];
                      int jai[200];

                      find(path2,khoroji,&t,v,jai);

                      if(all==1 && byword==1 && count==0 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    for(int i=0;i<t;i++){
                        printf("%d ",v[i]);
                    }
                    printf("\n");
                }
            }else
            if(all==1 && byword==0 && count==0 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    for(int i=0;i<t;i++){
                       printf("%d ",jai[i]);
                    }
                    printf("\n");
                }
            }else
            if(all==0 && byword==0 && count==1 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    printf("%d\n",t);
                }
            }else
            if(all==0 && byword==0 && count==0 && at==1){
                if(t<atn){
                    printf("not found\n");
                }else{
                    printf("%d\n",jai[atn]);
                }
            }else
            if(all==0 && byword==1 && count==0 && at==0){
                if(t==0){
                    printf("not found\n");
                }else{
                    printf("%d\n",v[0]);
                }
            }else
            if(all==0 && byword==0 && count==0 && at==0){

               if(t==0){
                    printf("not found\n");
                }else{
                    printf("%d\n",*(jai));
                }

                }else{printf("invalid combination of attributes\n");}


                }
           }


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
