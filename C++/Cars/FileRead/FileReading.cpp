#include <iostream>
#include <fstream>
#include <deque>
#include <string>
using namespace std;

void SwitchTheFiles(string file,string file1){
  deque<string>  letters1;  string letters,lettering; 
  
     ifstream input(file);  // used to read a file
   ofstream input1(file1); // used to display output file
  
    while (input >> lettering){ // loops until file is empty
    // checks if the word is 3 lettesr and if the first word is an
    // alphabet
         if (lettering.length() == 3 && isalpha(lettering[0])){
    if (isupper(lettering[0])){ // checks if the first word is uppercase
     lettering = "C++";  
    }else { // if the first letter is lowercase
      lettering = "c--"; 
    }    
  }
        std:: cout << lettering << " "; // space
      letters1.push_back(lettering); // pushes values in the first file into a variable
       input1 << lettering << " "; // puts the word into the new file
  }
 
   
   
  
   // closes the files
  input.close();
  input1.close();
}  

int main() {
  string file, file1; // variable that stores the file
  
  
  std::cout << "Enter the file you want to read: ";
  std::cin >> file; // the original file to be read

  std::cout << "Enter the new file: ";
  std::cin >> file1; // the new file 
  std:: cout << endl; 

  SwitchTheFiles(file,file1);

  return 0; 
}