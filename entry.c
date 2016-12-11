#include "api.h"
char *strrev(char *str)
{
  char *p1, *p2;

  if (! str || ! *str)
    return str;
  for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
    {
      *p1 ^= *p2;
      *p2 ^= *p1;
      *p1 ^= *p2;
    }
  return str;
}

int make_entry(char *file_path)
{
  int file_inode_index;
  int i, j;
  int dir_inode_index;
  inode *dir_inode;
  dir *dir_object;
  char dir_path[strlen(file_path)];
  char tmp_path[strlen(file_path)];
  char file_name[strlen(file_path)];

  tmp_path = strrev(file_path);
  for(i = 0;tmp_path[i] != '/';i++ )
    file_name[i] = tmp_path = [i];
  file_name = strrev(file_name);

  i = 0;
  while(tmp[i] != '/')
    i++;
  i++;
  j = 0;
  while(tmp[i] != '\0'){
    dir_path[j] = tmp[i];
    j++;
    i++;
  }
  dir_path = strrev(dir_path);
  file_inode_index = writefile();
  dir_inode_index = get_inode(dir_path, 0, strlen(dir_path));
  dir_inode = inode_table_object->inode_index[dir_inode_index];
  if(dir_inode->file_type != 1){;
    printf("E:Not a valid path. Parent is not directoty\n");
    return -1;
  }
  my_read(dir_object, BS, dir_inode->direct_block_offset);
  dir_object->child[dir_inode.size].inode_index = file_inode_index;
  strcpy(dir_object->child[dir_inode.size].file_name, file_name);
  my_write(dir_object, sizeof(*dir_object), sb_object->next_free_data_block_offset);

  return 0;
  
}
