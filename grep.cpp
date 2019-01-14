#include <stdio.h>
#include <dirent.h>

DIR *dir;
struct dirent *ent;


int main()
{
    freopen("README.md","w",stdout);
    if ((dir = opendir("c:\\Users\\Sandy\\Desktop\\code\\uva")) != NULL)
    {
      /* print all the files and directories within directory */
        printf("# UVA\n");
        while ((ent = readdir(dir)) != NULL)
        {
            if (ent->d_name[0] == 'u' && ent->d_name[1] == 'v' && ent->d_name[2] == 'a')
            {
                if (strlen(ent->d_name) - 3 == 3)
                {
                    printf("* [x] %s - \n",ent->d_name );
                } 
            }
           
        }
        dir = opendir("c:\\Users\\Sandy\\Desktop\\code\\uva");
        while ((ent = readdir(dir)) != NULL)
        {
            if (ent->d_name[0] == 'u' && ent->d_name[1] == 'v' && ent->d_name[2] == 'a')
            {
                if (strlen(ent->d_name) - 3 == 4)
                {
                    printf("* [x] %s - \n",ent->d_name );
                } 
            }
           
        }
        dir = opendir("c:\\Users\\Sandy\\Desktop\\code\\uva");
        while ((ent = readdir(dir)) != NULL)
        {
            if (ent->d_name[0] == 'u' && ent->d_name[1] == 'v' && ent->d_name[2] == 'a')
            {
                if (strlen(ent->d_name) - 3 == 5)
                {
                    printf("* [x] %s - \n",ent->d_name );
                } 
            }
           
        }
        closedir(dir);
    }
    return 0;
}