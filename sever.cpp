/*
 * Christopher Bennett
 * Sever Side 
*/


#include <ctime>
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <unistd.h>

using namespace std;
using boost::asio::ip::tcp;
	
#define addCode   1
#define subCode   2
#define divCode   3
#define multCode  4
#define notValid  5


//Functions

bool checkCode(int c)
{
	switch (c)
	{
		case addCode:
			return true;
			break;
		case subCode:
			return true;
			break;
		case divCode:
			return true;
			break;
		case multCode:
			return true;
			break;
		case notValid:
			return false;
			break;
	}

	return false;
}

int takeNums(int c)
{
	int num1, num2;
	tcp::iostream stream;
	cout << "Taking numbers" << "\n";

	stream << "one" << endl;
	stream >> num1;
	stream << "two" << endl;
	stream >> num2;

	switch (c)
	{
		case addCode:
			return (num1 + num2);
			break;
		case subCode:
			return (num1 - num2);
			break;
		case divCode:
			return (num1 / num2);
			break;
		case multCode:
			return (num1 * num2);
			break;
	}

	return -1;
}	


int main()
{
	char again;

	boost::asio::io_context io_context;
	tcp::endpoint endpoint(tcp::v4(), 5678); //setting port
	tcp::acceptor acceptor(io_context, endpoint);
	tcp::iostream stream;
	boost::system::error_code ec;
	cout << "Waiting for client to connect\n";
	acceptor.accept(stream.socket(), ec);
	cout<< "Client Connected\n";


	if (!ec){
		while (true)
		{
			int code;
			stream >> code;
			cout << code << "\n";

			if (checkCode(code)){
				cout << "Code Accepted" << "\n";
			}else cout << "Invalid Code" << "\n";

			takeNums(code);

			if (!stream) break;
		}			
	}
}

