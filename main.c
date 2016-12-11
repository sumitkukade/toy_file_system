#include "api.h"

int main(int argc, char *argv[])
{
  if(argc != 2){
    printf("E: please provide fs_name with ./a.out or too many arguments \n");
    return 0;
  }

  fd = createDisk(argv[1]); //create a disk image with file name
  sb_object = (sb *)malloc(sizeof(sb));
  db_bmap_object = (db_bmap *)malloc(sizeof(db_bmap));
  inode_bmap_object = (inode_bmap *)malloc(sizeof(inode_bmap));
  inode_table_object = (inode_table *)malloc(sizeof(inode_table));

  sb_object = get_super_block();
  db_bmap_object = get_db_bmap();
  inode_bmap_object = get_inode_bmap();
  inode_table_object = get_inode_table();
  initiate_file_system(fd,argv[1]);

  printf("%d\n", get_inode("..",0,2));
  update();

  return 0;
}

