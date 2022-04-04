#include <iostream>
#include <serverTcp.hpp>

using namespace socketlib;

int main()
{
	ServerTcp s("127.0.0.1", 1234);

	try {
		s.init();
	}
	catch (const socket_error& er) {
		std::cout << er.what() << er.error_code << std::endl;
	}
	system("pause");
}