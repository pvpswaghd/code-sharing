#include "paths.h"

void fillVector(std::vector<Method>& myVec){
  int numberofVector;
  std::cout << "Input the number of vectors you wanna insert: ";
  std::cin >> numberofVector;

  for (int i = 0; i < numberofVector; i++){
    Method newVector(i);
    myVec.push_back(newVector);
  }
}

void printVector(std::vector<Method>& myVec){
  for (int i = 0; i < myVec.size(); i++){
    std::cout << "this is: " << myVec[i].getName() << std::endl;
  }
}

int main(){
  std::vector<Method> myVec;
  fillVector(myVec);
  std::string changes;
  while(changes!="q"){
    std::cout << "Which name do you want to change? ";
    std::cin >> changes;
    if(changes=="q") break;
    else if (changes == "p") printVector(myVec);
    else{
      int newX;
      std::cout << changes << " changes to ? ";
      std::cin >> newX;
      //search index : c++11 lambda
      for (int i = 0; i < myVec.size(); i++){
        if(stoi(changes) != i){
          continue;
        }
        else{
          std::cout << myVec[i].getName();
          myVec[i].changeName(newX);
          std::cout << myVec[i].getName();
          break;
        }
      }
    }
  }
  return 0;
}
