#include <iostream>
#include <dirent.h>
#include <Directory.h>

int main(int argv, char **args) {
    GLOBALDIR_INIT()
    RTL::Directory dir("./");
    dir.OpenDir();
    (RTL::Directory*)dir["RedText"];
}