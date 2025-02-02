#include <iostream>
#include <fstream>
#include <algorithm>
#include <deque>
#include <string>
#include <vector>
using namespace std;

void merging(string doc1, string doc2, string docOutput){
  vector<int> numbers1, numbers2, numbersOutput;
  // variables for storing the numbers as integers
  int numbers; 
  deque<string> numbs; // unused
  
  ifstream input(doc1); // used to read a file 
  ifstream inputs(doc2); // used to read a file
  ofstream out(docOutput); // used to display output of a file

 while (input >> numbers) { // pushes values in the first file into a variable
        numbers1.push_back(numbers);
    }

    while (inputs >> numbers) { // pushes values in the second file into a variable
        numbers2.push_back(numbers);
    }

  // used to sort the values from smallest to biggest
    numbersOutput.resize(numbers1.size() + numbers2.size());
    merge(numbers1.begin(), numbers1.end(), numbers2.begin(), numbers2.end(), numbersOutput.begin());

  // loops through the values and puhses it into the last file
    for (int numbers : numbersOutput) {
        out << numbers << endl;
    }


  // closes the files
  input.close();
  inputs.close();
  out.close();
}



int main() {
string file1, file2, file3; // variables to store the file name 
  
  std:: cout << "Enter the first file you want to read: " << endl;
  std:: cin >> file1; // where input is enetered

  std:: cout << "Enter the second file you want to read: " << endl;
  std:: cin >> file2; // where input is enetered

  std:: cout << "Enter the last file you want to read: " << endl;
  std:: cin >> file3; // where input is enetered
  
  merging(file1, file2, file3); // calling the method that puts the files 
  // together

  std:: cout << "The numbers have been stored in "<< file3 << endl;
 // the name of the file where the values are stored. 
  
    return 0;
}