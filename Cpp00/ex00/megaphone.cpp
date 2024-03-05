#include <iostream>

int main(int argc,char **argv)
{
    if(argc>=2)
    {
        int i = 1;
        int j;
        while(argv[i])
        {
            j = 0;
            while(argv[i][j])
            {
                std::cout << (char)std::toupper(argv[i][j]);
                j++;
            }
            i++;
        }
        std::cout << std::endl;
    }
    else
        std::cout <<"* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< std::endl;
}