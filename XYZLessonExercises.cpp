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

  static void runGuessingGame() {
	//set seed here
	srand(time(0));
	
	string name;
	int number;
	int guessingNumber = 1 + (rand() % 100);
	int count = 0;
	
	cout << "Enter your name, please: ";
	getline(cin, name);

	cout << "I'm gguessing a number from 1 to 100" << endl;

	while (true) {
	  cout << "Choose the number, please: ";
	  cin >> number;
	  count += 1;

	  if (number == guessingNumber) {
		cout << "Yes, you have guessed correctly!!! \n Well done " << name << "!!!" << endl;
		break;
	  }
	  else if (number < guessingNumber) {
		cout << "Try the number that is bigger" << endl;
	  }
	  else {
		cout << "Try the number that is less" << endl;
	  }
	}

	if (count > 8) {
	  cout << "You may do it fuster!!! =)" << endl;
	}
	else {
	  cout << "Well done, you have done it very fast";
	}
	
  }
};


int main()
{
}