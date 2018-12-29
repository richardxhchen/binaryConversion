//============================================================================
// Name        : BinaryConvert.cpp
// Author      : Rich
// Version     : 1.0
// Description : Binary Conversion (Decimal to Binary) Tool in C++, Ansi-style
//============================================================================

#include<iostream>
#include <exception>
#include<string>
using namespace std;

int deciToBinary(int N) {
  string binaryNum;
  int curr = N;

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
  return stoi(binaryNum);
}

int main() {
  int convert;
  cout<<"What number would you like to convert to binary? "<<endl;
  string x;
  cin>>x;
  try{
    convert = stoi(x);
  } catch(exception& e) {
    cout<<"Unable to Convert " << x << " into Binary\n" <<endl;
    return 1;
  }

  cout<<deciToBinary(convert)<<" is the binary form"<<endl;
  return 0;
}
