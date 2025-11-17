#include <iostream>
#include <fstream>
#include "src/hello.hpp"
using namespace std;

void moreMemory(int* &number, int &size) {
  int *temp = new int[size];
  for (int i = 0; i < size; i++) {
    *(temp + i) = *(number + i);
  }
  delete[] number;
  size = size * 2;
  number = new int[size];
  for (int i = 0; i < size / 2; i++) {
    *(number + i) = *(temp + i);
  }
  delete[] temp;
}

float median(int* &numbers, int size) {
  if (size % 2 != 0) {
    return *(numbers + size/2);
  }
  float lowermed = *(numbers + size/2);
  float uppermed = *((numbers + size/2) + 1) ;

  return ((uppermed + lowermed)/2);
}

void printNumbers(int* &numbers, int numberSize) {
  for (int i = 0; i < numberSize; i++) {
    cout << *(numbers + i) << endl;
  }
}

int main() {
  ifstream f;
  string line = "";
  string data;
  int size = 10;
  int *numbers = new int[size];
  int numberSize = 0;

  std::cout << "Please enter the file name" << std::endl;
  cin >> line;

  f.open("../data/" + line);

  if (f.is_open())
  {
    while (getline(f, data))
    {
      //cout << data << endl;
    }
  }
  else
  {
    cout << "Sorry, the file could not be openend." << endl;
  }

  string number = "";

  for (int i = 0; i < data.length(); i++) {
    if (numberSize == size) {
      moreMemory(numbers, size);
    }
    if (data[i] != ',') {
      number += data[i];
    }
    else {
      *(numbers + numberSize) = stoi(number);
      numberSize++;
      number = "";
    }
    if (i == data.length() - 1) {
      *(numbers + numberSize) = stoi(number);
      numberSize++;
      number = "";
    }
  }

  //printNumbers(numbers, numberSize);
  cout  << "The median of the dataset is: " << median(numbers, numberSize) << endl;

  delete[] numbers;

  f.close();

  return 0;
}
