#include "Geometry.h"

class Pricing : public Geometry {
public: 
 // constructors from the geometry class
  Pricing(int num1, int num2) : Geometry(num1, num2) {
    // Call the constructor of the base class with the given arguments
  
}
Pricing (int num3) : Geometry(num3){
  // Call the constructor of the base class with the given arguments
}

double getSodCost(double price){
  // calculates the total cost of the sod
  return getArea() * price; 
}
double getFenceCost(double price){ 
  // calculates the total cost of fencing
  return getPerimeter() * price; 
}
};