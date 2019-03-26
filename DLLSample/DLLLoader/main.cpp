#include <iostream>
#include "foolibrary.h"
#include "barlibrary.h"

int main()
{
    std::cout << "--- FooLibrary" << std::endl;
    foo::IFoo* foo = foo::FooLibrary::create();
    foo->setName( "foo" );
    std::cout << "Name: " << foo->name() << std::endl;
    foo::FooLibrary::destroy( foo );

    std::cout << "--- BarLibrary" << std::endl;
    std::cout << bar::BarLibrary::cdeclMethod(1, 2) << std::endl;
    std::cout << bar::BarLibrary::stdcallMethod(2, 3) << std::endl;
    std::cout << bar::BarLibrary::defExportMethod(3, 4) << std::endl;

    return 0;
}
