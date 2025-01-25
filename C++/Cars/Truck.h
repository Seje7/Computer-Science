#include <iostream>
using namespace std;
#include "Vehicle.h"

class Truck : public Vehicle {
private:               // PRIVATE MEMBER VARIABLES
  double loadCapacity; // IN TONS
  int towingCapacity;  // IN POUNDS

public:
  Truck(string manufacturerName, int numOfCynlinders,
        const Person ownerOfCynlinder, int towingCapacity, double loadCapacity);
  Truck(); // DEFUALT CONSTRUCTOR

  // MEMBER FUNCTIONS
  double getTheLoadCapacity() const;
  int getTheTowingCapacity() const;
}