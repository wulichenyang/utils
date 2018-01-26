#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
    
// 将 main.c 放入文件夹同一级目录
// 结果所有图片被命名为 1.jpg, 2.jpg ... n.jpg
int main(int argc, char* argv[])
{
    try {
        if (argc != 5)
        {
            throw "Invalid number of arguments";
        }

        // 初始文件夹序号
        int beg = atoi(argv[1]);
        char oldName[100];
        char newName[100];
        char tempStr[25];
        char *from = argv[2];
        char *to = argv[3];
        char *suffix = argv[4];

        DIR * dir;
        struct dirent * ptr;

        // source dir
        dir = opendir(from);
        // create target dir
        mkdir(to);

        while((ptr = readdir(dir)) != NULL)
        {
            memset(oldName, '\0', sizeof(oldName));
            memset(newName, '\0', sizeof(newName));

            if(!(strcmp(ptr->d_name, ".")) || !(strcmp(ptr->d_name, ".."))) {
                continue;
            }
            // old file
            sprintf(oldName, "./%s/%s",from, ptr->d_name);
            itoa((beg++), tempStr, 10);

            // suffix
            strcat(tempStr, ".");
            strcat(tempStr, suffix);

            // new file 
            sprintf(newName, "./%s/%s", to, tempStr);
            printf("oldname:%s\n", oldName);
            printf("newname:%s\n", newName);
            rename(oldName, newName);
        }
        closedir(dir);

    } catch(char *err) {
        printf("%s\n", err);
    }

    return 0;
}