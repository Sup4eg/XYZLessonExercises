#include <iostream>
#include <string>
using namespace std;

class Lesson123 {
public:
  static int runCalculator() {
	
	string operation;
	float operand1, operand2, result = 0.f;

	bool sholdContinue = true;
	string answer;

	while(sholdContinue)
	{
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

	  cout << "Do you want to continue ? y/n: ";
	  cin >> answer;
	  sholdContinue = answer == "y";
	}
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

class Lesson125 {

public:

  static void runBallsManager() {
	constexpr int NUM_BALLS = 20;

	int balls[NUM_BALLS];
	
	//range based for
	for (int& ball : balls) {
	  ball = 0;
	}

	bool sholdContinue = true;
	while (sholdContinue) {
	  
	  cout << "List of commands: " << endl;
	  cout << "0 - Exit" << endl;
	  cout << "1 - Add ball" << endl;
	  cout << "2 - Remove ball" << endl;
	  cout << "3 - Count balls" << endl;
	  cout << "4 - Total balls" << endl;
	  cout << "5 - Needed balls" << endl;
	  cout << ">: ";
	  string command;
	  cin >> command;

	  if (command == "1") {

	  }
	  else if (command == "2") {
	  }
	  else if (command == "3") {

		cout << "Enter article: ";
		int article = -1;
		cin >> article;

		//check that article is right
		if (article < 0 || article > NUM_BALLS - 1) {
		  cout << "Incorrect article!" << endl;
		}
		else {
		  cout << "There are " << balls[article] << " balls of article " << article << endl;
		}

	  }
	  else if (command == "4") {
	  }
	  else if (command == "5") {

		for (int i = 0; i < NUM_BALLS; ++i) {
		  if (balls[i] == 0) {
			cout << "There are no balls of article " << i << endl;
		  }
		}

	  }
	  else if (command == "0") {
		cout << "Bye!" << endl;
		sholdContinue = false;
	  }
	  else {
		cout << "Unknows commmand " << command << endl;
	  }
	
	}

  }

};

class Lesson212 {
public:
  static void runBitMaskTask() {

	int k = 3;
	const int n = 10;
	int arr[n] = { -5, 1, 1, 1, -3, -1, 4, 1, 1, 1 };
	// 1  0  0  0   0   0  0  0  0  0  0
	//    0  0  0   0   0  0  0  0  0  0
	//    0  0  0   0   0  0  0  0  0  1
	//    1  1  1   1   1  1  1  1  1  1
	int result = -10000000;

	 //do something
	 //3 -4 -2 1
	 //1 0 0 1
	 //000 001 010 011 100 101 110 111
	 //[0, 2^n)

	const int count_masks = 1 << n;

	for (int mask = 0; mask < count_masks; ++mask) {
	  int product = 1;
	  int cnt = 0;
	  for (int i = 0; i < n; ++i) {
		if (mask & (1 << i)) {
		  product *= arr[i];
		  cnt++;
		}
	  }
	  if (cnt == k) {
		result = max(result, product);
	  }
	}

	cout << "Result: " << result << endl;
  }

  //c++ usually doesn't include last elem [first, last)
  static void myReverse(int * first, int * last) {
	while (first < last) {
	  last--;
	  swap(*first, *last);
	  first++;
	}
  }

  static void runReverseArrayForStaticArray() {
	const int N = 5;
	int arr[N] = { 1, 2, 3, 4, 5 };
	myReverse(arr, arr + N);

	for (int* ptr = arr; ptr < arr + N; ++ptr) {
	  cout << *ptr << " ";
	}
  }
  static void runReverseArrayForDynamicArray() 
  {
	int n;
	cin >> n;
	int* arr = new int[n];

	for (int* ptr = arr; ptr < arr + n; ++ptr) {
	  cin >> *ptr;
	}

	myReverse(arr, arr + n);

	for (int* ptr = arr; ptr < arr + n; ++ptr) {
	  cout << *ptr << " ";
	}
	
	delete[] arr;
  }
};


int main()
{
  Lesson212::runReverseArrayForDynamicArray();
} 