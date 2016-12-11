#include "fs.h"
int createDisk(char *file_name);
int initiate_file_system();
int my_write(void *buff, int n,int offset);
int my_read(void *buff, int n,int offset);
int init_inode_table();
int init_db_bmap();
int init_inode_bmap();
int init_superblock();
int initiate_file_system();
sb *get_super_block();
db_bmap *get_db_bmap();
inode_bmap *get_inode_bmap();
inode_table *get_inode_table();
int init_root_dir();
inode_bmap *get_inode_bmap();
