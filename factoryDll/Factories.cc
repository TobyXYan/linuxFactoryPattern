
#include "Factories.h"
#include "Products.h"


FactoryA::FactoryA(){
}

IProduct* FactoryA::CreateProduct(){
  IProduct* product = new ProductA();
  return product;
}



IProduct* FactoryB::CreateProduct(){
  IProduct* product = new ProductB();
  return product;
}



IProduct* FactoryA::CreateOne(){
  IProduct* product = new ProductA();
  return product;
}



IProduct* FactoryB::CreateOne(){
  IProduct* product = new ProductB();
  return product;
}
