#include "api.h"
/* Function to read a data from a file. If file_size not exceeds 4096 bytes then read only direct block */
int read_file(char *filePath)
{
  char buff[4096];
  int file_inode_index = get_inode(filePath, 0, strlen(filePath));
  inode file_inode = inode_table_object->inode_index[file_inode_index];
  int file_size = file_inode.size;

  my_read(buff, 4096, file_inode.direct_block_offset);
  printf("File Data = \n %s", buff);

  if(file_size >  4096){
    file_size -= 4096;
    _read_file_from_indirect_block(file_size, file_inode);
  }
  return 0;
}
/* Function to read from a file from single indirect block */
int _read_file_from_indirect_block(int file_size, inode file_inode)
{
  int i;
  char buff[4096];
  si_block *si_block_object;
  data_block * data_block_object;
  si_block *si_block_index;
  my_read(si_block_object, BS, file_inode.single_indirect_block_offset);
  int remain_block = ceil((float) file_size / BS);
  while(remain_block > 0){
    if(remain_block < BS / sizeof(int *))
      for(i = 0;i < remain_block;i++ ){
	my_read(data_block_object, BS, si_block_index->db_index[i]);
	printf("%s", data_block_object->data);
      }
    else{
      for(i = 0;i < (BS / sizeof(int *)) - 1;i++ ){
	my_read(data_block_object, BS, si_block_index->db_index[i]);
	printf("%s", data_block_object->data);
      }
      remain_block -= (BS / sizeof(int *)) - 1;
      my_read(si_block_object, BS, si_block_index->db_index[(BS / sizeof(int *)) - 1]);
    }
  }
  return 0;
}
