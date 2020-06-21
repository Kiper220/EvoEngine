#include <iostream>
#include <sys/stat.h>
#include <Directory.h>

using namespace std;
using namespace RTL;


int main(){
    Directory dir(".");
    std::cout << "All Objects Count: " << EntitiesCount(dir)
    << "\nAll File Count: " << FileCount(dir)
    << "\nAll Directories Count: " << DirectoriesCount(dir);
}
