#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <array>

class Method {
public:
  Method(int);
  ~Method();
  int getName();
  void changeName(int);
private:
  int newName;
  char newGrade;
};
