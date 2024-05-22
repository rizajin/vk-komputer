#include <framework.h>

#include <iostream>

int main()
{
    KomputeFramework fw;
    if (fw.Init())
    {
        std::cout << "Success" << std::endl;
    }

    return 0;
}
