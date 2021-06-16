#include "include/Factories.h"
#include "include/Products.h"
int main(){

  FactoryA facA;
  //Below case will succeed though .so is built with -fvisibility=hidden, as CreateProduct is labelled as default visibility
  IProduct* product = facA.CreateProduct();
  product->ShowName();

  //Below case will fail, as .so is built with -fvisibility=hidden and CreateOne is not labelled with defult visibility
  //product = facA.CreateOne();
  //product->ShowName();
}


/*** Note ***/
//
