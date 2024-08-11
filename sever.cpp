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

float calcAns(int c, float num1, float num2)
{
	float ans;
	switch (c)
	{
		case addCode:
			ans = (num1 + num2);
			cout << "Pre Answer is:\t" << (ans) << "\n";
			break;
		case subCode:
			ans = (num1 - num2);
			cout << "Pre Answer is:\t" << (ans) << "\n";
			break;
		case divCode:
			cout << "Division" << "\n";
			cout << "Answer without ans var:\t" << (ans = num1 / num2) << "\n";
			cout << "Pre Answer is:\t" << (ans)  << "\n";
			break;
		case multCode:
			ans = (num1 * num2);
			cout << "Pre Answer is:\t" << (ans) << "\n";
			break;
		default:
			ans = -1.112;
			break;
	}

	return ans;
}


int main()
{
	bool goAgain;

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

			float num1, num2;
			string ansRequest;

			stream << "one" << endl;
			stream >> num1;
			cout << num1 << "\n";
			stream << "two" << endl;
			stream >> num2;
			cout << num2 << "\n";

			float ans = calcAns(code, num1, num2);
			cout << "The answer is: " << ans << "\n";
			stream >> ansRequest;
			//cout << "Ans Request: \t" << ansRequest << "\n";
			stream << ans << endl;

			
			if (!stream) break;
		}			
	}
}

