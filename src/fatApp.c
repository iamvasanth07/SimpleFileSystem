#include"fat.h"



int main(){
    char *buf;
    buf = malloc(sizeof(char) * 100);
    int addr = 10000,offset=0,p=0,k=0;
    char *name;int i,j,size,opt,blk,blks,cnt=0,start,end,blocks;
    name = malloc(sizeof(char)*30);
    printf("Enter the Size of FAT FileSystem (in bytes):\n");
    scanf("%d",&size);
    blk = size/25;
    printf("[+]Creating File System...\n");
    createFS(blk);
    blocks = blk;
    while(p<3)
    {
        printf("....................\n....................\n....................\n");
    p++;
    }    
    printf("[+]mounting.....done..\n");
    printf("##########################################################\n");
    printf("###                        F-A-T                       ###\n");
    printf("##########################################################\n");
    do
    {
    printf(" [+]\t1.create file \n [+]\t2.read Files \n [+]\t3.Files available \n [+]\t4.FAT \n [+]\t5.Exit\n");
printf("Blocks : %d Availabe : %d\n",blocks,blk);
    scanf("%d",&opt);
    blk = getBlocks();
    switch(opt)
    {
        case 1: 
            printf("Enter the name of the file :\n");
            scanf("%s",name);
            printf("Size in Bytes : \n");
            scanf("%d",&size);
            printf("Type the contents :\n");
            scanf("%s",buf);
            if(blk >= (size/25))
                if(createFile(name,buf)){
                    printf("\nFile created successfully...\n");
	     if((size%25)==0){	   
                blk = blk - (size/25);
                blks = size/25;
        }
	     else
        {
		    blk = blk - ((size/25)+1);
            blks = (size/25)+1;
        }
	    ++cnt;
	    start = addr + offset;
	    end = start+(size/25);
        makeEntry(name,size,start,end,blks);
	    offset += (size/25);
	    updateBlocks(blk);
            }
		else
		     printf("[-]Can't open File ...\n");
            break;
	case 2:
		printf("File name : \n");
		scanf("%s",name);
		if(!readFile(name))
            printf("[-]File not Found... !\n");
		break;
    case 3:
        printFiles();
        break;
    /*case 6:
        updateBlocks(100);
        deleteFiles();
        system("rm FAT");
        offset = 0;
    */
    case 4:
        printFAT();
        break;
    case 5:
        printf("Exiting....\n");
        break;
	default:
	   printf("Invalid Option....\n"); 
    }
    }while(opt!=5);
}
