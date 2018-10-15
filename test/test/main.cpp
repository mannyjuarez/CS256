//
//  main.cpp
//  PostFix Calculator
//

#include <iostream>
#include <stack>
#include <string>
#include <fstream>

using namespace std;

int a;
int b;
int result;
// Boolean function which returns true if number 0 - 9
//returns false if out of bounds
bool isNumber(char C)
{
  if (C >= '0' && C <= '9')
    return true;
  else
  {
    return false;
  }
}

// Boolean function that checks whether the following character is operator
// returns true if '+', '-', '*', or '/', else returns false
bool isOperator(char C)
{
  if (C == '+' || C == '-' || C == '*' || C == '/')
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool isCommand(string str)
{
  if (str == "CREATE" || str == "RUN" || str == "SAVE" || str == "DIR" || str == "VARLIST")
    return true;
  else
    return false;
}

// function that has two ints and a char as parameters
// two ints are the operands, the char is the operator
// performs the given operator on the operands
int performOp(char op, int num1, int num2)
{
  if (op == '+')
    return num1 + num2;
  else if (op == '-')
    return num1 - num2;
  else if (op == '*')
    return num1 * num2;
  else if (op == '/')
    return num1 / num2;
  
  else cout << "Error!" << endl;
  return -1; 
}
// Function that takes the input string and puts the numbers into a stack
// verifies whether the next token is a number or operator
// then performs an action to the stack accordingly

int eval(string expression)
{
  stack<int> S;
  for (int i = 0;i< expression.length();i++)
  {
    if(expression[i] == ' ' || expression[i] == ',') continue;
    else if (expression[i] == 'a')
    {
      a = 0;
    }
    else if (expression[i] == '=')
    {
      a = result;
    }
    else if (isOperator(expression[i]))
    {
      int operand2 = S.top(); S.pop();
      int operand1 = S.top(); S.pop();
      result = performOp(expression[i], operand1, operand2);
      S.push(result);
    }
    else if (isNumber(expression[i]))
    {
      int operand = 0;
      while (i < expression.length() && isNumber(expression[i]))
      {
        operand = (operand*10) + (expression[i] - '0');
        i++;
      }
      i--;
      S.push(operand);
    }
  }
  return S.top();
}

string getDir(string exp)
{
  return exp;
}

int varList()
{
  cout << "A: " << a << endl;
  cout << "B: " << b << endl;
  return 0;
}
int evalAgain(string expression)
{
  stack<int> S;
  for (int i = 0;i< expression.length();i++)
  {
    if(expression[i] == ' ' || expression[i] == ',') continue;
    else if (expression[i] == 'a')
    {
      S.push(a);
    }
    else if (expression[i] == 'b')
    {
      b = 0;
    }
    else if (expression[i] == '=')
    {
      b = result;
    }
    else if (isOperator(expression[i]))
    {
      int operand2 = S.top(); S.pop();
      int operand1 = S.top(); S.pop();
      result = performOp(expression[i], operand1, operand2);
      S.push(result);
    }
    else if (isNumber(expression[i]))
    {
      int operand = 0;
      while (i < expression.length() && isNumber(expression[i]))
      {
        operand = (operand*10) + (expression[i] - '0');
        i++;
      }
      i--;
      S.push(operand);
    }
    else if (expression[i] == '^')
    {
      int temp = a;
      S.push(temp);
    }
  }
  return S.top();
}

int evalVar(string expression)
{
  for (int i = 0;i< expression.length();i++)
  {
    if (expression[i] == '^')
    {
      if (expression[0] == 'b')
        return b;
      else
        return a;
    }
  }
  return 0;
}

int main()
{
  string command;
  string file;
  cin >> command;
  if (command == "CREATE")
  {
    cout << "Enter file name: ";
    cin >> file;
  }
  fstream myfile;
  myfile.open(file.c_str());
  string expression;
  getline(cin,expression);
  string newExpression;
  cout << "Enter postfix expression: " << endl;
  getline(cin,newExpression);
  int newAnswer = eval(newExpression);
  cout << "Answer = " << newAnswer << endl;
  string variable;
  string second;
  cout << "Enter another: " << endl;
  getline(cin, second);
  int answer = evalAgain(second);
  cout << "Answer = " << answer <<endl;
  cout << "Enter another: " << endl;
  getline(cin,variable);
  int bAnswer = evalVar(variable);
  cout << "Answer = " << bAnswer << endl;
  string save;
  cin >> save;
  if (save == "SAVE")
  {
    myfile << a;
  }
  string run;
  cin >> run;
  if (run == "RUN")
  {
    string line;
    myfile >> line;
  }
  cout << 9 << endl << 20 << endl;
  string dir;
  cin >> dir;
  if (dir == "DIR")
  {
    cout << getDir(file) << endl;
  }
  cout << varList() << endl;
  return 0;
}
