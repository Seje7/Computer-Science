#include <iostream>
#include <cmath>

class Geometry {
private: int side, length, width; 

public: 
 Geometry(int length, int width){ // rectangle constructor
   checkNum(length);  
   checkNum(width);
   this->length = length; 
     this->width = width;
 }
 Geometry(int side){ // cube constructor
   checkNum(side);
   this->side = side; 
 }
  Geometry(){ // default constructor
    this->side = 0;
    this->length = 0;
    this->width = 0 ;
  }

void setLength(int number){ // Accessor and mutator functions 
  this->length = checkNum(number);
}
void setWidth(int number){ // Accessor and mutator functions 
  this->width = checkNum(number);
 
}
void setSide(int number){ // Accessor and mutator functions 
  this->side = checkNum(number); 
}

int getLength(){ // Accessor and mutator functions 
  return this->length; 
}
int getWidth(){ // Accessor and mutator functions 
  return this->width;
}
int getSide(){ // Accessor and mutator functions 
  return this->side;
}

int getArea(){ // Calculates the area 
 return getLength() * getWidth();
}

int getPerimeter(){ // Calculates tyhe perimeter
  return 2 * (getLength() + getWidth());
}

int getSurfaceArea(){ // Calulates the surface area
  return pow(getSide(), 3);
}

private: // checks is the number is greater than zero
int checkNum(int number){
  if (number < 0){
    std::cout << "Number is less than zero ";
    exit(0);
  }
  return number; 
  
}
};