#include <iostream>
using namespace std;

#include "stack.h" // Your implementation of vector

// main function
int main()
{
	stack<int, 3> stackInt;

	stackInt.push(1);
	stackInt.push(2);

	stackInt.print();

	stackInt.pop();
	stackInt.pop();

	stackInt.push(3);

	cout << "Top element is: " << stackInt.peek() << endl;
	cout << "Stack size is " << stackInt.size() << endl;

	//stackInt.pop();

	if (stackInt.isEmpty())
		cout << "Stack Is Empty\n";
	else
		cout << "Stack Is Not Empty\n";


    stack<double, 3> stackDouble;

	stackDouble.push(2.5);
	stackDouble.push(3.1);

	stackDouble.print();

	stackDouble.pop();
	stackDouble.pop();
	

	stackDouble.push(4.6);

 	// Prints the top of the stack
 	cout << "Top element is: " << stackDouble.peek() << endl;

	// Returns the number of elements present in the stack
	cout << "Stack size is " << stackDouble.size() << endl;

	stackDouble.pop();

	// check if stack is empty or not
	if (stackDouble.isEmpty())
		cout << "Stack Is Empty\n";
	else
		cout << "Stack Is Not Empty\n";

    stack<string, 3> stackString;

	stackString.push("Abb");
	stackString.push("Baa");
	// Test empty Sting
	stackString.push("");

	stackString.print();

	stackString.pop();
	stackString.pop();

	stackString.push("Caa");

 	// Prints the top of the stack
 	cout << "Top element is: " << stackString.peek() << endl;

	// Returns the number of elements present in the stack
	cout << "Stack size is " << stackString.size() << endl;

	stackString.pop();

	// check if stack is empty or not
	if (stackString.isEmpty())
		cout << "Stack Is Empty\n";
	else
		cout << "Stack Is Not Empty\n";

	return 0;
}

