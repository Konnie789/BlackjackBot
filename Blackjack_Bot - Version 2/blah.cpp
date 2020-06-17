#include <iostream>
using namespace std;

int main(){
  string blah = "12345678987654321";
  int blah2;
  for(int i = 0; i < blah.size(); i++){
    blah2 = static_cast<int>(blah[i]) - 48;
    cout << blah2 << endl;
  }
  return 0;
}