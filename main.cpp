#include <iostream>
#include <dlfcn.h>
#include <cassert>

int main()
{
    //open the native AOT DotNet binary from LD_LIBRARY_PATH
    void *dotnet_handle;
    dotnet_handle = dlopen("Dotnet_library.so",RTLD_LAZY| RTLD_DEEPBIND);

    if(!dotnet_handle)
    {
        std::cout<<"Error: "<<dlerror();
    }
    else
    {
        //Load static function with identical symbol name
        typedef int(*ptr_absolute)(int);
        ptr_absolute absolute =  (ptr_absolute)dlsym(dotnet_handle, "absolute");

        std::cout<<"DotNet Math.Abs(-100) = "<<absolute(-100)<<std::endl;
        std::cout<<"Std::abs(-100) = "<<std::abs(-100)<<std::endl;
        dlclose(dotnet_handle);
    }
    return 0;
}