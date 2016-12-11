#include "api.h"
#include<math.h>



int main(int argc,char *argv[])
{
    char c;
    FILE * fp;
    int needed_block,file_size,buffcount;
    data_block *buff;
    buff = (data_block *) malloc(sizeof(data_block));

    fp = fopen ("bigfile.txt", "r");
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    needed_block = ceil(file_size*1.0/(BS))
    
    if(sb->no_free_inodes < needed_block){
        printf("E: not enough memory");
        return 0;
    }

    fseek(fp, 0, SEEK_SET);
    
    

    while(c=fgetc(fp)!=EOF){
        buff->data[buffcount]=c; 
        buffcount++;
        if(buffcount==BS){
            buffcount=0;

        }
    }
    free(buff);

    return 0;
}
