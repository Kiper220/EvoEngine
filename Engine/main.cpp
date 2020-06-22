#include <iostream>
#include <sys/stat.h>
#include <Directory.h>

using namespace std;
using namespace RTL;


int main(){
    struct stat st;
    stat("./EvoEngine", &st);
    std::cout << st.st_size;
}
