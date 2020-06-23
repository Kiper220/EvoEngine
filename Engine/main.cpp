#include <iostream>
#include <dirent.h>
#include <FSEntity.h>

int main(int argv, char **args) {
    GLOBALDIR_INIT()
    DIR* dir = opendir(RTL::GetGlobalPath(RTL::GetMinimizedPath("./Engine/../Game/Maps")));
    struct dirent* ent = readdir(dir);
    std::cout << ent->d_name;
}