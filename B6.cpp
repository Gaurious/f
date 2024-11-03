#include<bits/stdc++.h>
using namespace std;



class overloading{
public:
  int area(int side) {
    return (side * side);
  }
};


int main() {


  overloading obj1;
  int square;
  square = obj1.area(5);
  cout << "Area of square: " << square;

  return 0;
}