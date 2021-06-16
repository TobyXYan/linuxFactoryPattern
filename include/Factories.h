#ifndef _FACTORIES_H_
#define _FACTORIES_H_

#include "IFactory.h"

//#ifdef _FACTORY_DLL_
//#define _FACTORY_DLL_ __attribute__ ((dllexport))
//#else
//#define _FACTORY_DLL_ __attribute__ ((dllimport))
//#endif

//Different with windows C++, here we use this way to expose methods
//And we have to use -fvisibility=hidden with CFLAGS in Makefile to make sure 
//unexpected methods still keep unexposed
#define _FACTORY_DLL_ __attribute__ ((visibility("default")))

class FactoryA:public IFactory
{
  public:
    _FACTORY_DLL_ FactoryA();
    IProduct* CreateOne();
    _FACTORY_DLL_ IProduct* CreateProduct();
};


class FactoryB:public IFactory
{
  public:
    _FACTORY_DLL_ IProduct* CreateOne();
    _FACTORY_DLL_ IProduct* CreateProduct();
};
#endif

