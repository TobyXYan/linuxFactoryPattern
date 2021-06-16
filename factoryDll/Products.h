#ifndef _PRODUCTS_H_
#define _PRODUCTS_H_

#include "IProduct.h"

class ProductA:public IProduct
{
  public:
    void ShowName();
};


class ProductB:public IProduct
{
  public:
    void ShowName();
};
#endif
