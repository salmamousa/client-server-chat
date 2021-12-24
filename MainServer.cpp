#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <sstream>
#include <fstream>
#include<string>
#include <string.h>
#include <pthread.h>
#include "Server.h"
using namespace std;

int main(int argc, char * argv[])
{
	int PortNumber = atoi(argv[1]); //converts an ascii string to integer
	//Server * server = new Server(PortNumber); //dynamically allocating an object from Server class and giving the constructor the Port Number
        Server server(PortNumber);
        server.Socket_Creation();
	return 0;
}
