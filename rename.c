#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
    
// 将 main.c 放入文件夹同一级目录
// 结果所有图片被命名为 1.jpg, 2.jpg ... n.jpg
int main(void)
{
    // 初始文件夹序号
    int beg = 73;
    char oldName[100];
    char newName[100];
    char tempStr[25];
    DIR * dir;
    struct dirent * ptr;

    // 文件夹名字
    dir = opendir("./res");
    while((ptr = readdir(dir)) != NULL)
    {
        memset(oldName, '\0', sizeof(oldName));
        memset(newName, '\0', sizeof(newName));
        if(!(strcmp(ptr->d_name, ".")) || !(strcmp(ptr->d_name, ".."))) {
            continue;
        }
        sprintf(oldName, "./%s/%s","res", ptr->d_name);
        itoa((beg++), tempStr, 10);
        strcat(tempStr,".docx");
        sprintf(newName, "./%s/%s", "from", tempStr);
        printf("oldname:%s\n", oldName);
        printf("newname:%s\n", newName);
        rename(oldName, newName);
    }
    closedir(dir);
    return 0;
}