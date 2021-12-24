#pragma once
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
#define NumberOfThreads 3
#define MAX_LETTERS 100
using namespace std;

class Server
{
private:
        
	static int Client_IDs[NumberOfThreads];
	struct sockaddr_in m_ServerAddress, m_ClientAddress;
	int socket_fd, PortNumber,connect_fd;
	//static int Connect_fd_clone;
	//int * Connect_fd_Arr = new int[NumberOfThreads];
        //static int Connect_fd_Arr[NumberOfThreads];
public:
	Server(int);
	void Socket_Creation();
	void Listen();
	void Accept_Connection();
	static void * Communicate(void *);
	~Server();

};
