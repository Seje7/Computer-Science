#include <iostream>
#include <math.h>

using namespace std;

// where the method are called
int Area(double b, double c);
void displayTitle ();
void getData (double& length, double& width);
int calcTotalCans(int totalCans);
double calcCost(int cans);
void convert12Format (int& hour, int& minute, char& aM_pM);
void displayMsg(int& paintCans);
bool isALeapYear(int year); 
int getMonthValue(int month, int year);
int getYearValue(int year); 
int getDaysOfTheWeek(int day, int month, int year);
std::string dayOfWeek(int date); 
std::string monthOfTheYear(int monthOfYear); 
void displayResults(int& area, int& cans, double& cost, std::string date, std::string monthLetters,
int& day, int& year); 

int main() {


  // this variable store values for the painting company receipt
  // some variables are not used
int  paintCans, area;
  double width, length, cost;
  int hour, minute, day, month, year, cans, date, monthOfYear;
  std::string dayFormat, monthFormat; 
  char time, vave; 

  // use of while loop to keep the program going
  while (true) {
    displayTitle (); // to display the brginning of the receipt 
    getData(length, width);
    if (length == 0){
      std:: cout << "PROGRAM HAS BEEN TERMINATED";
      break; 
      
    }
    convert12Format (hour, minute, time);
    std:: cout << "Enter the transaction date: ";
    std:: cin >> day >> month >> year;
    
    area = Area(length, width);
    paintCans = calcTotalCans(area);
    cost = calcCost(paintCans);

     
    date = getDaysOfTheWeek(day, month, year);
    dayFormat =  dayOfWeek(date);
    monthOfYear = getMonthValue( month, year);
    monthFormat = monthOfTheYear(monthOfYear);
    std:: cout << "____________________________________________\n";
    displayResults(area, paintCans, cost, dayFormat, monthFormat , day , year );

    displayMsg(paintCans); 
    std:: cout << "Thank you for shopping with us\n";
    std:: cout << "___________________________________________\n";
    std:: cout << "____________________________________________\n";
    //int calcTotalCans(area
  }
  
}
// function to calculate the area
int Area(double b, double c) {
  const double height = 3.00;
  double area;
  if (height == b && height == c) {
    area =  5 * pow(height, 2);
    return area;
  } else {
    area = (b * c) + (2 * (height * c)) + (2 * (height * b));
    return area;
  }
}
// function to print the beginning of receipt
void displayTitle (){
  std:: cout << "            RAINBOW PAINTING COMPANY" << std :: endl;
  std:: cout << "                  PAINT COSTING" << std :: endl; 
  std:: cout << "-------------------------------------------------\n";
}
// function to get measurement of room
void getData (double& length, double& width){
  std:: cout << "Enter the length in meters, enter 0 to stop......... ";
  std:: cin >> length; 
  if (length == 0){
    std:: cout << " PROGRAM HAS BEEN TERMINATED\n";
  } else {
    std:: cout << "Enter the width in meters......... ";
  std:: cin >> width; 
  }
}
// to calculate number of paint cans needed
int calcTotalCans(int totalCans){
  double oneSquareMeter = 20.00;
  double numberOfCans;
  numberOfCans = (totalCans / oneSquareMeter);  
  return ceil(numberOfCans);
  
}
// to calculate the cost of painting the room
double calcCost(int cans){
  double price, pricePerCan = 15.50;
  price = cans * pricePerCan;
  return price; 
}
// to change time to a number format
 void convert12Format(int& hour, int& minute, char& aM_pM) {
   std:: cout << "Enter time of transaction in 12 hour notation: \n";
    std:: cout << "Hour: ";
  std:: cin >> hour;
    if (hour == 0) { // midnight
        hour = 12;
        aM_pM = 'A';
    } else if (hour == 12) { // noon
        aM_pM = 'P';
    } else if (hour > 12) { // afternoon
        hour -= 12;
        aM_pM = 'P';
    } else { // morning
        aM_pM = 'A';
    }
    std:: cout << "Minute: ";
   std:: cin >> minute;
   if (minute == 00 || minute <= 59){
     std:: cout << hour << ":" << minute << " " << aM_pM<< "M" << std:: endl;
  }

}
// function to print out the customers gift
void displayMsg (int& paintCans) {
  if(paintCans > 0 && paintCans <= 3) {
    std:: cout <<  "Gift: Free paint brush"<< std:: endl;
  }else if (paintCans >= 4 && paintCans <= 7) {
    std:: cout <<  "Gift: free paint tray"<< std:: endl;
  }else {
    std:: cout <<  "Gift: $10 gift card." << std:: endl;
  }
  
}
// to check if year is a leap year or not
bool isALeapYear(int year){
   if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else if (year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}
// to get the month that the transaction was made
int getMonthValue(int month, int year) {
     int monthValue = 0;
    switch (month) {
        case 1: // January
            monthValue = 1;
            break;
        case 2: // February
            monthValue = isALeapYear(year) ? 4 : 2;
            break;
        case 3: // March
            monthValue = 3;
            break;
        case 4: // April
            monthValue = 4;
            break;
        case 5: // May
            monthValue = 5;
            break;
        case 6: // June
            monthValue = 6;
            break;
        case 7: // July
            monthValue = 7;
            break;
        case 8: // August
            monthValue = 8;
            break;
        case 9: // September
            monthValue = 9;
            break;
        case 10: // October
            monthValue = 10;
            break;
        case 11: // November
            monthValue = 11;
            break;
        case 12: // December
            monthValue = 12;
            break;
        default:
            // Invalid month
            break;
    }
    return monthValue;
}
// to get the year of the transaction
int getYearValue(int year) {
  int century = year / 100;
    int yearInCentury = year % 100;
    int value = (yearInCentury / 4) + yearInCentury;

   // Date.toUtcString
    if (century % 4 == 0) {
        value += 6;
    } else if (century % 4 == 1) {
        value += 4;
    } else if (century % 4 == 2) {
        value += 2;
    }
    
    return value % 7;
}
// to get the day of the week 
int getDaysOfTheWeek(int day, int month, int year){
    if (month < 1 || month > 12 || day < 1 || day > 31 || year < 0) {
        return -1; // invalid inputs
    }
    int y = year - (14 - month) / 12;
    int x = y + y/4 - y/100 + y/400;
    int m = month + 12 * ((14 - month) / 12) - 2;
    int d = (day + x + (31*m)/12) % 7;
   return d;
}
      // to change day of the week to string
std::string dayOfWeek(int date) {
    // Check if inputs are valid
    // Convert to string
    switch(date) {
        case 0:
            return "Sunday";
        case 1:
            return "Monday";
        case 2:
            return "Tuesday";
        case 3:
            return "Wednesday";
        case 4:
            return "Thursday";
        case 5:
            return "Friday";
        case 6:
            return "Saturday";
        default:
            return "Invalid Date";
    }
}
// to change month to string
std::string monthOfTheYear(int monthOfYear) {
    // Check if inputs are valid
    // Convert to string
        switch(monthOfYear) {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "";
    }
}
//This will return a string in the format you described together with the other values
void displayResults(int& area, int& cans, double& cost, std::string date, std::string monthLetters,
int& day, int& year ) {
  std:: cout << "Area = " << area << " meter squared" << endl; 
  std:: cout << "Cans = " << cans << endl;
  std:: cout << "Cost = $ " << cost << endl;
  std:: cout << "Date/Time =   " << date <<", " << monthLetters << " " << day << " " << year 
   <<  endl;
  
 //  
  
}