// Week 3 cpp: 
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
	//Assignment Operators
	int x = 4;
	int y = 7;

	//arithmetic operatops
	int total = x + y;
	int difference = x - y;
	int product = x * y;
	int quotient = x / y;
	int modulo = x % y;

	// Compound assignment
	int a = 0;
		a += 5;

		//Increase/ decrease 
		a++; 
		a += 1;
		a = a + 1;

		a--;

		// incrament order
		int m = 3;
		int n = ++m;
		//m = 4, n = 4

		int j = 3;
		int k = j++;
		// j =3 , k=4

		// Relational and Comparison operator

		// == equal to
		cout << (5 == 5) << "\n";// true
		cout << (3 == 2) << "\n"; //false
	
		//!= not equal to
		cout << (5 !=5) << "\n";// false
		cout << (3 !=2) << "\n";// true

		// less than or equal or greater than
		cout << (1 < 2) << "\n";  // true
		cout << (5 <= 5) << "\n";
		cout << (8 > 5) << "\n";

		bool bT = true;
		bool bF = false;

		// && AND operator
		cout << (true && true) << "\n"; //true
		cout << (true && false) << "\n"; //false
		cout << (false && false) << "\n"; //false

		// || OR operator
		cout << (true || true) << "\n"; //true
		cout << (true || false) << "\n"; //true
		cout << (false || false) << "\n"; //false

		// ! NOT Operator
		cout << !true << "\n"; //false
		cout << !false << "\n"; // true

		// order of operation 
		// arithmetics:
		//1 - scaling (* / %)
		//2 - addition ( + -)
		int iStep1 = 5 + 7 % 2;
		int iStep2 = 5 + 1;
		int iStep3 = 6;

		//Logical
		//0 - nEGATION (!)
		//1- Conjunction (&&)
		//2- Disjunction (||)
		bool bStep1 = true && false || false|| true && true || false && true || true && false && !true && true;
		bool bStep2 = false || false || true || false || false;
		bool bStep3 = true;
		
		int i1 = 12; //binary 1100
		int i2 = 10; //binary 1010
					 // 0110 -- decimal 6 

		int i3 = i1 ^ i2;

		cout << i3 << endl;

		int c1 = 3;
		int c2 = 2;
		bool results;
		c1 == c2 ? printf("equal") : printf("not equal");
		cout << endl;

		if (c1 > c2)
		{ 
			cout << "c1 is greater \n";
		
		}

		int guess = 3;
		int number = 5;
		
		if (guess > number)
		{
			cout << "number is smaller \n";
		}
		else if (guess < number)
		{
			cout << "number is larger \n";

		}
		else
		{
			cout << "You guessed the number ! \n";
		}

	cout << "========================";
	cout << "\n";
	string animal;
		cin >> animal;
		if (animal == "cow")

		{
			printf("moo");
		}
		if (animal == "dog")
		{
			printf("bork");
	     }
	
	cout << "\n";
	cout << "========================";
	cout << "\n";

	


	







	

			
		




	cout << "end of code";
	return 0;
}