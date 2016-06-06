#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct tree
{
  char word[1024];
  int flag;
  int times;
  struct tree *left;
}tree_node;

int main(int argc,char* argv[])
{
  // FILE *fp;
  char c;
  char buf[1024];
  int bWord=0;
  //int MAX=MAXINT;
 
  buf[0]='\0';
  
  while((c=fgetc(stdin))!=EOF){
    if((c>='A'&&c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')||c=='\''||c=='-'){
      if(c<='Z'&&c>='A'){
	c=c-('A'-'a');
      }
      int n=strlen(buf);
      buf[n++]=c;
      if(bWord==0&&(c=='\''||c=='-')){
	buf[n--]='\0';
      }  
      buf[n]='\0';     
      bWord=1;
    }
    else  if((c<='A'&&c>='Z')||(c<='a'&&c>='z')||(c<='0'&&c>='9')||c!='\''||c!='-'){
      int n=strlen(buf);
      bWord=0;
      if(buf[n-1]=='-'||buf[n-1]=='\''){
	buf[n-1]='\0';
      }
      printf("%s\n",buf);
      buf[0]='\0';
    }
  }
  return 0;
}

