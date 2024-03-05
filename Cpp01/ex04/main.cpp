#include <iostream>
#include <fstream>

void replace(std::string filename,std::string str1,std::string str2,std::string value)
{
   
    std::ofstream outputFile(filename + ".replace");
    size_t index = value.find(str1);
    while(index != std::string::npos)
    {
        value.erase(index,str1.length());
        value.insert(index,str2);
        index = value.find(str1);
    }  
    outputFile << value;
    outputFile.close();
}
int main(int ac,char **av)
{
    if(ac != 4)
    {
        std::cout << "Only 4 Arguments !!!" << std::endl;
        return 0;
    }
    std::string value;
    char c;
    std::string filename = av[1];
    std::string str1 = av[2];
    std::string str2 = av[3];
    if(str1 == str2)
    {
        std::cout << "Same input" << std::endl;
        return 0;
    }
    std::ifstream inputFile(filename);
    if(!inputFile)
        {
            std::cout << "File open error" << std::endl;
            return 0;
        }
    while(!inputFile.eof() && inputFile >> std::noskipws >> c)
    {
        value.append(1,c);
    }
    inputFile.close();
    replace(filename,str1,str2,value);
    return(0);

}