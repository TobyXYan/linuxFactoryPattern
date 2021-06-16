#ifndef _I_FACTORY_H_
#define _I_FACTORY_H_


#include "IProduct.h"

struct IFactory
{
  virtual IProduct* CreateOne() = 0;
  virtual IProduct* CreateProduct() = 0;
};
#endif
