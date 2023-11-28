#include <iostream>
#include <string>
using namespace std;

class Lesson123 {
public:
  static int runCalculator() {
	string operation;
	float operand1, operand2, result = 0.f;

	cout << "Enter operation (+ - / *) and operands in format op a b!" << endl;
	cin >> operation >> operand1 >> operand2;

	if (operation == "+") {
	  result = operand1 + operand2;
	}
	else if (operation == "-") {
	  result = operand1 - operand2;
	}
	else if (operation == "/") {
	  result = operand1 / operand2;
	}
	else if (operation == "*") {
	  result = operand1 * operand2;
	}
	else {
	  cout << "Unknow operation: " << operation << endl;
	  return 0;
	}

	cout << "Result: " << floor(result * 10) / 10 << endl;
  }
};


int main()
{
  Lesson123::runCalculator();
}