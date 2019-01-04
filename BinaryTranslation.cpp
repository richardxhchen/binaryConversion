//============================================================================
// Name        : BinaryConvert.cpp
// Author      : Rich
// Version     : 2.0
// Description : Unsigned Binary Conversion (Decimal to Binary) Tool in C++, Ansi-style
//============================================================================

#include<iostream>
#include<exception>
#include<string>
#include<math.h>
using namespace std;

//Converting Number into Unsigned Binary
int deciToBinary(int N) {
  string binaryNum;
  int curr = N;
  bool neg = false;

  //for the case if the number entered is negative
  if(N < 0){
    curr = -curr;
    neg = true;
  }

  //Converting the number into a string of binary digits
  while(curr!=0) {
      int remainder = curr%2;
      if(remainder == 1) {
          binaryNum.insert(0,"1");
      } else {
          binaryNum.insert(0,"0");
      }
      curr/=2;
      if(curr == 0) {
          binaryNum.insert(0,"0");
      }
  }

  //Adds a negative if the number is negative
  if(neg == true) {
    binaryNum.insert(0,"-");
  }
  //Converts it back into an integer
  return stoi(binaryNum);
}

//Converts Binary into a Decimal
int binaryToDeci(int N) {

  //Checks if input is negative
  bool neg = false;
  if(N<0) {
    N = -N;
    neg = true;
  }

  string binary = to_string(N);
  int power = binary.length()-1;
  int count = 0;

  //Keeps track of count (the final number)
  for(int i = 0; i <= binary.length(); i++) {
    if(binary[i] == '1') {
      int raise = power - i;
      count += pow(2, raise);
    }
  }

  if(neg == true) {
    count = -count;
  }

  return count;
}


int main() {
  while(1) {
    int convert;
    string input;
    do {
      cout<<"What would you like to do? "<<endl;
      cout<<"Enter 1 to convert from decimal to binary"<<endl;
      cout<<"Enter 2 to convert from binary to decimal"<<endl;
      cout<<"Enter 3 to exit"<<endl;
      cout<<">>";
      cin>>input;

      if(input != "1" && input != "2" && input != "3") {
        cout<<"Please enter a valid input!"<<endl;
      }
    } while(input != "1" && input != "2" && input != "3");

    if(input == "1") {
      cout<<"What number would you like to convert to binary? "<<endl;
      string x;
      cin>>x;
      try{
        convert = stoi(x);
      } catch(exception& e) {
        cout<<"Unable to Convert '" << x << "' into Binary \n" <<endl;
        continue;
      }
      cout<<deciToBinary(convert)<<" is the unsigned binary form \n"<<endl;
    } else if(input == "2") {
      cout<<"What binary would you like to convert to decimal? "<<endl;
      string x;
      cin>>x;
      try{
        convert = stoi(x);
      } catch(exception& e){
        cout<< "Unable to Convert '" << x << "' into Decimal \n" <<endl;
        continue;
      }
      cout<<binaryToDeci(convert)<<" is the decimal form \n"<<endl;
    } else {
      return 0;
    }
  }
}

