#include"fat.h"


void createFS(int blk)
{
  FILE *fp = fopen("BLOCKS","w");
  FILE *fd = fopen("FAT","w");
  fprintf(fp,"%d",blk);
  fprintf(fd,"Files\t\tSize\t\tStart\t\tEnd\t\tBlocks\n");
  fclose(fp);
  fclose(fd);
}


void printFAT()
{  
  char c;
  FILE *fp = fopen("FAT","r");
  printf("######################################################################\n");
  printf("###                         FILE ALLOCATION TABLE                  ###\n");
  printf("######################################################################\n");
  c = getc(fp);
  while(c != EOF)
  {
    printf("%c",c);
    c = getc(fp);
  }
  printf("######################################################################\n");
  fclose(fp);
}

void printFiles()
{
  FILE *fp = fopen("FAT","r");
  int i=0;
  char name[30];
  while(!feof(fp))
  {
    fscanf(fp,"%s",name);
    if((i%5)==0){
      printf("%s\n",name);
     
    }
    ++i;
  }
  fclose(fp);
}

/*
void deleteFiles()
{
  FILE *fp = fopen("FAT","r");
  int i=0;
  char name[30];
  while(!feof(fp))
  {
    fscanf(fp,"%s",name);
    if((i%5)==0){
      system("rm name");
    }
    i++;
  }
  fclose(fp);
}
*/
bool createFile(char *name,char *buf)
{
    FILE *fd;
    //char *buf;
    //buf = malloc(sizeof(char) * 100);
    fd = fopen(name,"w+");
    if(fd != NULL)
    {
        //printf("Type the contents :\n");
        //scanf("%[^\n]s",&buf);
        fprintf(fd,"%s\n",buf);
        fclose(fd);
        return true;
    }
    else
        return false;
}

void makeEntry(char *name,int size,int start,int end,int blk)
{
  FILE *fp;
  fp = fopen("FAT","a");
  fprintf(fp,"%s\t\t%d\t\t%p\t\t%p\t\t%d\n",name,size,start,end,blk);
  fclose(fp);

}

int getBlocks()
{
  FILE *fp = fopen("BLOCKS","r");
  int blk;
  fscanf(fp,"%d",&blk);
  fclose(fp);
  return blk;
}

void updateBlocks(int blk)
{
  FILE *fp = fopen("BLOCKS","w");
  fprintf(fp,"%d",blk);
  fclose(fp);
}

bool readFile(char *name)
{
  char c[100];
  FILE *fp = fopen(name,"r");
  if(fp != NULL) {
  fscanf(fp,"%s",c);
  while(!feof(fp))
  {
    printf("%s",c);
    fscanf(fp,"%s",c);
  }
  printf("\n");
  return true;
  }
  else
    return false;
  fclose(fp);
}
