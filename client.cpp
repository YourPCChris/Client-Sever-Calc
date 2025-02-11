/*
 * Christopher Bennett
 * Client Side
*/


#include <ctime> 
#include <iostream> 
#include <string> 
#include <boost/asio.hpp> 
#include <unistd.h> 
 
 
using namespace std; 
using boost::asio::ip::tcp; 


#define addCode   1;
#define subCode   2;
#define divCode   3;
#define multCode  4;
#define notValid  5;

int takeOp(int op)
{
	op = toupper(op);

	switch (op)
	{
		case 'A':
			return addCode;
			break;	
		case 'S':
			return subCode;
			break;
		case 'D':
			return divCode;
			break;
		case 'M':
			return multCode;
			break;
		default:
			return notValid;
			break;
	}
}

int takeNums()
{
        tcp::iostream stream;

	string one, two;
	float num1, num2;

	stream >> one;
	cout << "Hello" << "\n";
	cout << one << "\n";
	if (one == "one"){
		cout << "Enter First Number: " << "\n";
		cin >> num1;
		stream << num1 << endl;
	}

	return 0;
}
	


int main(int argc, char* argv[])
{
	int code = 0;
	string firstNumRequest, secNumRequest, iterationRequest;
	char op;

	try
	{
		tcp::iostream stream("localhost", "5678");
		if (!stream){
			cout << "unable to connect: " << stream.error().message() << "\n";
			return EXIT_FAILURE;
		}

		while (true)
		{
			cout << "What operation do you want to preform?(a/s/d/m)" << "\n";
			cin >> op;
			code = takeOp(op);
			stream << code  << endl;

			float num1, num2, ans;
			int goAgain;
			stream >> firstNumRequest;

			if (firstNumRequest == "one"){
				cout << firstNumRequest << " first num \n";
				cin >> num1;
				stream << num1 << endl;
			}
			stream >> secNumRequest;
			if (secNumRequest == "two"){
				cout << secNumRequest <<" Second num \n";
				cin >> num2;
				stream << num2 << endl;
				stream << "ans" << endl;
				stream >> ans;
			}
			cout << "Sever says:\t\t" << ans << "\n";

			cout << "Do you want to do more caluclations?(0/1)" <<"\n";
			cin >> goAgain;

			if (goAgain != 0) exit(0);
			
			
			if(!stream) break;
		}
	}
	catch (exception& e)
	{
		cout << "Error" << "\n";
	}
}


