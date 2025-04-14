#include <iostream>
#include "Person.h"
using namespace std;

// Create a base class called Vehicle that has the manufacturer's name (type string), number of cylinders in the engine (type int), and owner (type Person, given below).

class Vehicle{
private: // PRIVATE MEMBER VARIABLES
string manufacturerName;
int numOfCynlinders;
Person ownerOfCynlinder; 

public:
// CONSTRUCTORS
Vehicle (string manufacturerName, int numOfCynlinders, const Person ownerOfCynlinder);
Vehicle (); // DEFAULT CONSTRUCTOR

// MEMBER FUNCTIONS
string getmanufacturer() const;
int getCynlinders() const;
Person getTheOwner() const; 
}