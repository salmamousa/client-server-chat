#include "Server.h"
int Server:: Client_IDs[NumberOfThreads];
//int Server::Connect_fd_clone;
//Server *Server::ServerObj;
//int Server:: Connect_fd_Arr[NumberOfThreads];
/*struct Thread_Args
{ 
  int connect_fd_clone;
  int counter;
};*/
Server::Server(int PortNumber)
{
	this->PortNumber = PortNumber;
}

void Server::Socket_Creation()
{
	socket_fd = socket(AF_INET, SOCK_STREAM, 0);// creates a new end point for communication and returns a small integer that represents the socket discriptor
	if (socket_fd < 0)
	{
		cout << "socket creation has failed...The system will exit now" << endl;
		exit(1);
	}
	else
	{
		m_ServerAddress.sin_family = AF_INET; // assigning the address family
		m_ServerAddress.sin_addr.s_addr = INADDR_ANY; // to make the server listen to any address available 
		m_ServerAddress.sin_port = htons(PortNumber);
	}
	Listen();
}

void Server::Listen()
{
	int check=bind(socket_fd, (sockaddr *)& m_ServerAddress, sizeof(m_ServerAddress));
	if (check < 0)
	{
		cout << " Binding failed.. The system will exit now " << endl;
		exit(1);
	}

	else
	{
		cout << "The server is listening for a connection.. please wait" << endl;
		listen(socket_fd, 4); //The maximum number of pending connection requests to be queued
		Accept_Connection();
	}
}
void Server::Accept_Connection()
{
        int counter=0;
	pthread_t threads[NumberOfThreads]; //Creating an array of objects from threads 
	for (int i = 0; i < NumberOfThreads; i++)
	{
		connect_fd = accept(socket_fd, (struct sockaddr *) & m_ClientAddress, (socklen_t*)& m_ClientAddress); //accepting connections from clients
		if (connect_fd < 0)
		{
			cout << "Connection to the server has failed.. The system will exit now" << endl;
			exit(1);
		}

		else
		{
			cout << "Connection was accepted..You are now connected to the server" << endl;
			pthread_create(&threads[i], NULL, Communicate, (void *)&connect_fd);//creating the threads and assigning them to the function which we want to be executed
        }//else
	}//for loop
    for(int i=0; i< NumberOfThreads; i++)
    {
        pthread_join(threads[i],NULL);
            /*cout<<iter<<endl;
            if (iter == 0)
	    {
	    cout << "thread is joined successfully " << endl;
	    }
	    else
            {
	    cout << "there has been an error while joining thread" << endl;
	    }*/
    }
	
 }//function

void * Server::Communicate(void * connect_fd)
{
        int connect_fd_clone=  *((int*) connect_fd); // casts the address returned by accept function to integer
        int counter=0;
        counter=(connect_fd_clone - 3);
        cout << "Thread Number: " << pthread_self() << endl; // prints the id of the thread which is currently executed
	char hello2[MAX_LETTERS];
	char hello[] = "Hello From Server";
	send(connect_fd_clone, hello, sizeof(hello), 0);
	recv(connect_fd_clone, hello2, sizeof(hello2), 0);
	cout <<"From Client "<< counter<<" : "<< hello2<<endl;
	char msg[MAX_LETTERS], msg2[MAX_LETTERS];
        while(true)
	{
              recv(connect_fd_clone, msg, sizeof(msg),0);
              cout <<"From Client "<< counter<<" : "<< msg << endl;
               string tester(msg);
               if (tester == "exit")
		{ 
	          cout <<"Closing the connection with Client " <<counter << endl;
		  break;
		}
              
                cin.getline(msg2, MAX_LETTERS, '\n');
	        send(connect_fd_clone, msg2, sizeof(msg2), 0);
         }
}
      
Server:: ~Server()
{

}
