#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

class Lesson223 {
public:
  static void run() {
	const int arraySize = 10;
	int staticArray[arraySize];
	for (int i = 0; i < arraySize; ++i) {
	  staticArray[i] = i;
	}

	cout << "Static array: ";
	for (auto it = begin(staticArray); it != end(staticArray); ++it) {
	  cout << *it << " ";
	}
	cout << endl;

	auto it = find(begin(staticArray), end(staticArray), 5);
	cout << "Found element 5 at index " << distance(begin(staticArray), it) << endl;

	it = find(begin(staticArray), end(staticArray), 11);
	if (it == end(staticArray)) {
	  cout << "Element 11 not found" << endl;
	}


  }
};

class Lesson224 {
public:

  static int* myLowerBound(int* start, int* end, int value) {
	while (start < end) {
	  int* mid = start;
	  int length = distance(start, end);
	  advance(mid, length / 2);
	  if (*mid < value) {
		start = ++mid;
	  }
	  else {
		end = mid;
	  }
	}
	return start;
  }

  static int* myUpperBound(int* start, int* end, int value) {
	while (start < end) {
	  int* mid = start;
	  int length = distance(start, end);
	  advance(mid, length / 2);
	  if (*mid <= value) {
		start = ++mid;
	  }
	  else {
		end = mid;
	  }
	}
	return start;
  }

  static void testLowerBound(int* start, int* end, int value) {
	cout << "Test(" << value << "): ";
	int* myAns = myLowerBound(start, end, value);
	int* stdAns = lower_bound(start, end, value);
	cout << (myAns < end ? to_string(*myAns) : "null") << " | " << (stdAns < end ? to_string(*stdAns) : "null") << " | " << (myAns == stdAns ? "OK" : "FALL") << endl;
  }

  static void testUpperBound(int* start, int* end, int value) {
	cout << "Test(" << value << "): ";
	int* myAns = myUpperBound(start, end, value);
	int* stdAns = upper_bound(start, end, value);
	cout << (myAns < end ? to_string(*myAns) : "null") << " | " << (stdAns < end ? to_string(*stdAns) : "null") << " | " << (myAns == stdAns ? "OK" : "FALL") << endl;
  }

  static void quickSort(int* array, int arraySize) {
	if (arraySize <= 1) {
	  return;
	}

	int pivot = array[arraySize / 2];
	int* left = array;
	int* right = array + arraySize - 1;

	while (left <= right) {
	  while (*left <= pivot) {
		++left;
	  }
	  while (*right > pivot) {
		--right;
	  }
	  if (left <= right) {
		swap(*left, *right);
		++left;
		--right;
	  }
	}

	quickSort(array, int(right - array + 1));
	quickSort(left, int(arraySize - (left - array)));

  }


  static void run() {
	const int n = 7;
	int arr[n] = { 1, 3, 4, 5, 7, 8, 9 };
	
	cout << "=== lower bound ===\n" << endl;
	testLowerBound(arr, arr + n, 0);
	testLowerBound(arr, arr + n, 1);
	testLowerBound(arr, arr + n, 6);
	testLowerBound(arr, arr + n, 7);
	testLowerBound(arr, arr + n, 9);
	testLowerBound(arr, arr + n, 10);

	cout << "=== upper bound ===\n" << endl;
	testUpperBound(arr, arr + n, 0);
	testUpperBound(arr, arr + n, 1);
	testUpperBound(arr, arr + n, 5);
	testUpperBound(arr, arr + n, 6);
	testUpperBound(arr, arr + n, 8);
	testUpperBound(arr, arr + n, 9);
	testUpperBound(arr, arr + n, 10);
  }
};

class Lesson224Sort {
public:
  
  static void hoarSort(vector<int> &arr) {

	vector<int> less;
	vector<int> up;

	size_t midIndex = (arr.size() - 1) / 2;
	int midElement = arr[midIndex];

	for (int i = 0; i < midIndex; ++i){
	  if (arr[i] <= midElement) {
		less.push_back(arr[i]);
	  }
	  else if (arr[i] > midElement) {
		up.push_back(arr[i]);
	  }
	}


	for (int i = midIndex + 1; i < arr.size(); ++i) {
	  if (arr[i] <= midElement) {
		less.push_back(arr[i]);
	  }
	  else if (arr[i] > midElement) {
		up.push_back(arr[i]);
	  }
	}


	if (less.size() == 0 || up.size() == 0) {
	  less.push_back(midElement);
	  less.insert(less.end(), up.begin(), up.end());
	  arr = less;
	  return;
	}

	hoarSort(less);
	hoarSort(up);

	less.push_back(midElement);
	less.insert(less.end(), up.begin(), up.end());
	arr = less;
  }

  static void mergeSort(int arr[], const int N) {

	if (N <= 1) {
	  return;
	}

	int middle = (N / 2);
	mergeSort(arr, middle);
	mergeSort(arr + middle, N - middle);

	const int n = N / 2;
	const int m = N;
	int* result = new int[N];
	

	int left = 0, right = n, index = 0;
	while (left < n || right < m) {
	  if (right == m || (left < n && arr[left] < arr[right])) {
		result[index] = arr[left];
		left++;
	  }
	  else {
		result[index] = arr[right];
		right++;
	  }
	  index++;
	}

	for (int i = 0; i < N; ++i) {
	  arr[i] = result[i];
	}

	delete[] result;
  }
  

};


int main()
{
  int A[] = { 11, 2, 8, 13, 15 };
  int* B = partition(A, end(A), [](int i) {return i % 2 == 0; });

  cout << "here";

} 