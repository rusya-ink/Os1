#include <stdio.h>
#include <dirent.h>

#define TMP "/home/rusya/tmp"

struct file{
    char *name;
    int i_node;
};
int main(){
    DIR *dirp = opendir(TMP);
    if(dirp == NULL) {
        puts("-1");
        return -1;    
    }
    struct dirent * dp;
    int i=0;
    while((dp = readdir(dirp))!=NULL){
        i++;
    }
    int n=i;
    struct file files[n];

    dirp = opendir(TMP);
    if(dirp == NULL) {
        puts("-1");
        return -1;    
    }
    i=0;
    while((dp = readdir(dirp))!=NULL){
        files[i].name=dp->d_name;
        files[i].i_node = dp->d_ino;
        i++;
    }
    int used=0;
    int used_files[n];
    for(int i=0; i<n; i++){
        used_files[i]=0;
    }
    while(used<n){
        int cur_inode=-1;
        for(int i=0; i<n; i++){
            if(used_files[i]==0){
                cur_inode=files[i].i_node;
            }
        }
        if(cur_inode!=-1){
            for(int i=0; i<n; i++){
                if(files[i].i_node==cur_inode){
                    printf("%s ", files[i].name);
                    used++;
                    used_files[i]=1;
                }
            }
            printf("%d\n", cur_inode);
        }
    }
    
    
    return 0;
}
