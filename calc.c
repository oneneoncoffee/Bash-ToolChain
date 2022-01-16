#include <iostream>

using namespace std;

int main () { 
int a, b, sum;
float c,d, result;
char operation; 
cout << "[Adding mode default]" << "Enter a sum: "; 
cin >> a;
cout << "Enter 2nd sum:";
cin >> b;
sum = a + b; 
cout << "total number:" << sum << "\n" << endl;
cout << "[User input mode] " << "Other valid mathematical operators ( + - * / )" << endl;
cout << "\n Enter sums:";
cin >> c >> operation >> d;
switch(operation) {
case '+': 
	result = c + d;
	break;
case '-': 
	result = c - d;
	break;
case '*': 
	result = c / d;
	break;
case '/': 
	result = c / d;
	break;
default:
	cout << "Error: Invalid operation." << endl;
        return -1;
}
cout << "total number:" << result << endl;

return 0; 
}


