#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <string>
#include <iostream>
#include "Client.h"
using namespace std;
int main(int argc, char * argv[])
{
	int PortNumber = atoi(argv[1]); //converts an ascii string to integer
	Client * client = new Client(PortNumber); //dynamically allocating an object from Server class and giving the constructor the Port Number
	client->Socket_Creation();
	return 0;
}
