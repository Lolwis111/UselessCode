#include <fstream>
#include <string>
#include <cstddef>
#include <algorithm>
#include <iostream>

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        return 1;
    }

    const int mapsize = 26 + 26 + 10;

    std::ifstream file;
    file.open(argv[1], std::ifstream::in);

    std::string data;

    char* map = new char[mapsize + 1];

    int i = 1;
    for(char c = 'A'; c <= 'Z'; c++)
        map[i++] = c;
    for(char c = 'a'; c <= 'z'; c++)
        map[i++] = c;
    for(char c = '0'; c <= '9'; c++)
        map[i++] = c;

    std::string line;
    while(std::getline(file, line)) data += line + '\n';

    for(auto i = 0; i < data.size();)
    {
        char c = data[i];
        if(c == '\n')
        {
            std::cout << "\\nA";
            i++;   
        }
        else
        {
            int counter = 1;
            while(++counter < mapsize && ++i < data.size() && data[i] == c);
            std::cout << c << map[counter - 1];
        }

        // std::cout << c << ": " << (int)counter << '\n';
    }

    delete[] map;

    file.close();
}