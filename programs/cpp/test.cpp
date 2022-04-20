#include "paths.h"

Method::Method(int x){
  std::cout << x << std::endl;
  newName = x;
}

Method::~Method(){
}

int Method::getName(){
  return newName;
}

void Method::changeName(int x){
  this->newName = x;
}
