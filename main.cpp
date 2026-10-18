/******************************************************************************
# Author:           Andy Joy
# Assignment:       Assignment 3
# Date:             10/16/2026
# Description:      This program takes numerical scores from the user as input.
#                   Then it calculates the equivalent letter grade.
# Input:            num (double).
# Output:           scores (double array), grade (char array).       
# Sources:          Y. Daniel Liang. selection sort.
#******************************************************************************/
#include <iostream>
#include <iomanip>
using namespace std;

//Constants
const int MAX_CHAR = 20;

//Function prototypes
void welcome();
void readScores(double scores[], int &count);
void readDouble(string prompt, double &num);
void calcGrade(double scores[], char grade[], int count);
void printList(double scores[], char grades[], int count);
void sort(double scores[], char grade[], int count);
double median(double scores[], int count);

//Main function
int main() {
  double scores[MAX_CHAR];
  char grade[MAX_CHAR];
  int count = 0;
  
  welcome();
  readScores(scores, count);
  calcGrade(scores, grade, count);
  
  cout << "\nYour stats are as below:" << endl;
  cout << "\nThe list of scores and their grades are:" << endl;
  printList(scores, grade, count);

  cout << "The list sorted by scores in ascending order:" << endl;
  sort(scores, grade, count);
  printList(scores, grade, count);

  cout << fixed << setprecision(2);
  cout << "The median score is " << median(scores, count) << endl;
  cout << "\nThank you for using my Parallel Arrays program!!" << endl;
  return 0;
}

//Welcome function
void welcome(){
  cout << "Welcome to my Parallel Arrays program!" << endl;
  cout << "Please enter the list of scores (-1 to end input:)" << endl;
  cout << "Valid scores are between 0 and 4 inclusive." << endl;
}

//ReadScore function used to get all scores from user until user inputs "-1" or 20 values are entered.
//Also has input validation to limit scores to under 4.
void readScores(double scores[], int &count) {
  double tempVar = 0;

  while (tempVar != -1 && count < 20) {
    readDouble(">> ", tempVar);

    while (tempVar > 4) {
      cout << "Invalid score! Please try again!!" << endl;
      readDouble(">> ", tempVar);
    }

    if (tempVar != -1) {
      scores[count] = tempVar;
      ++count;
    }
  }
}

//ReadDouble function with input validation to prevent negative values, but allows for "-1".
void readDouble(string prompt, double &num) {
  cout << prompt;
  cin >> num;
  while (!cin || (num < 0 && num != -1)) {
    cout << "Invalid score! Please try again!!" << endl;
    cin.clear();
    cin.ignore(100, '\n');
    cout << prompt;
    cin >> num;
  }
  cin.ignore(10, '\n');
}

//CalcGrade function calculates and stores the equivalent letter grade for the given score.
void calcGrade(double scores[], char grade[], int count) {
  for (int i = 0; i < count; i++){
    if (scores[i] > 3.3) {
      grade[i] = 'A';
    }
    else if (scores[i] > 2.7) {
      grade[i] = 'B';
    }
    else if (scores[i] > 1.9) {
      grade[i] = 'C';
    }
    else if (scores[i] > 1.1) {
      grade[i] = 'D';
    }
    else {
      grade[i] = 'F';
    }
  }
}

//Printlist function
void printList(double scores[], char grades[], int count) {
  for (int i = 0; i < count; i++){
    cout << fixed << setprecision(1);
    cout << scores[i] << " " << grades[i] << endl;
  }
  cout << endl;
}

//Sort function, uses selection sort and shifts the corresponding letter grade in the parallel array
void sort(double scores[], char grade[], int count) {
  for (int i = 0; i < count - 1; i++) { 
    double currentMin = scores[i];
    int currentMinIndex = i;
    char currentMinGrade = grade[currentMinIndex];
    
    for (int j = i + 1; j < count; j++) {
      if (currentMin > scores[j]) {
      currentMin = scores[j];
      currentMinIndex = j;
      }
    }
   
    if (currentMinIndex != i) {
      scores[currentMinIndex] = scores[i];
      scores[i] = currentMin;

      currentMinGrade = grade[currentMinIndex];
      grade[currentMinIndex] = grade[i];
      grade[i] = currentMinGrade;
    }
  }
}


//Median function
double median(double scores[], int count) {
  double median = 0;

  if (count % 2 == 0) {
    median = (scores[count / 2 - 1]+ scores[count / 2]) / 2;
  }
  else {
    median = scores[count / 2];
  }
  return median;
}