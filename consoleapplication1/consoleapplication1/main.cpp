//
//  main.cpp
//  consoleapplication1
//
//  Created by Manny Juarez on 5/2/16.
//  Copyright © 2016 Manny Juarez. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
  
  vector<int> array1(5);
  
  cout << "Please enter a value: " << endl;
  for (int i = 0; i < 5; i++)
  {
     cin >> array1[i];
  }
  
  cout << "You entered: " << endl;
  for (int i = 0; i < 5; i++)
  {
    cout << array1[i] << endl;
  }
    return 0;
}
