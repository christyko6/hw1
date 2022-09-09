/* Write your test code for the ULListStr in this file */

#include <iostream>
#include "ulliststr.h"
using namespace std;


int main(int argc, char* argv[])
{
ULListStr dat;
//test push_back() with empty list
dat.push_back("0");
//should return 0
cout << "Testing push_back on an empty list (should be 0): " << dat.get(0) << endl;
//testing push_back() with a full list
for(int i = 1;i<=10;i++){
  dat.push_back(to_string(i));
}
cout << "Testing push_back & back on a full list (should be 10): " << dat.back()<< endl;

//making dat empty for next test
for(int i = 0;i<=10;i++){
  //testing pop_back
  dat.pop_back();
}
cout << "Testing pop_back on the list just created (size, should be 0): " << dat.size()<< endl;

//test push_front() with empty list
dat.push_front("0");
cout << "Testing push_front on an empty list (should be 0): " << dat.front()<< endl;
// //test push_front() with a full list
for(int i = 1;i<=10;i++){
  dat.push_front(to_string(i));
}
cout << "Testing push_front & front on a full list (should be 10): " << dat.front()<< endl;

//making dat empty for next test
for(int i = 0;i<=10;i++){
  //testing pop_front
  dat.pop_front();
}
cout << "Testing pop_front on the list just created (size, should be 0): " << dat.size()<< endl;

//testing getValAtLoc
// ULListStr dat2;
dat.push_back("7");
dat.push_back("9");
cout << "Testing getValAtLoc & push_back (should be 7 9): "<< dat.get(0) << " " <<dat.get(1) <<endl;
dat.push_front("8");
cout << "Testing getValAtLoc & push_front (should be 8): "<<dat.get(0) <<endl;
cout << "Testing size (should be 3): "<<dat.size() << endl;  // prints 3 since there are 3 strings stored
  return 0;
}
