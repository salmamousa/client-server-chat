#pragma once
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <string>
#include <iostream>
#define MAX_LETTERS 100
using namespace std;

class Client
{
private:
	struct sockaddr_in ServerAddress;
	int PortNumber, connect_fd;
public:
	Client(int);
	void Socket_Creation();
	void Connect();
	void Communicate();
	~Client();
};
