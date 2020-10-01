#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    char x;
    ifstream f("host.txt", ios::ate);
    streampos size = f.tellg();
    for (int var = 1; var <= size; var++)
    {
        f.seekg(-var, ios::end);
        f.get(x);
        printf("%c", x);
    }
    return 0;
}
