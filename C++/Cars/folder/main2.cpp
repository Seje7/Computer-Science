#include <iostream>
#include "Pricing.h"

// PART 2 MAIN CLASS
int main() {
  int fenceLength , fenceWidth; 
  const double sodCost = 0.47;
  const double fenceCost = 22.50; 

  // Display header for output
  std:: cout << "\t\t\t\t\t\tParkton LandScaping" << "\n";
  std:: cout << "Enter length: "; // length of fence input
  std:: cin >> fenceLength;
  std:: cout << "Enter width: "; // width for the fence input
  std:: cin >> fenceWidth;
  Pricing sod(fenceLength, fenceWidth); // instantiate the Pricing class

  std:: cout << "\t\t\t\t\t\tLandScaping Cost" << "\n";
  // prints and calculates the sod and fencing cost 
  std::cout << "Price of Sod: $" << sod.getSodCost(sodCost) << "\n";
  std::cout << "Price of Fencing: $" << sod.getFenceCost(fenceCost); 
}
  