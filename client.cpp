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


int main(int argc, char* argv[])
{
	int code = 0;
	string one;
	string two;
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
			
			if(!stream) break;
		}
	}
	catch (exception& e)
	{
		cout << "Error" << "\n";
	}
}


