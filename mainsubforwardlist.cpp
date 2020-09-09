#include <iostream>
#include "subforwardlist.h"

int main()
{
    subforwardlist a;

    for(int i = 0; i < 77; i++)
        a.push_back(i);

    //a.erase_where(1);//на 0, 1 не работает
    
    for(int i = 0; i < 4; i++)
        std::cout << a.size() << std::endl;
}
