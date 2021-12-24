#include "Client.h"

Client::Client(int PortNumber)
{
	this->PortNumber = PortNumber;
}

void Client::Socket_Creation()
{
	connect_fd = socket(AF_INET, SOCK_STREAM, 0); //Socket function will return a small integer containing a  socket discriptor 
	if (connect_fd < 0)
	{
		cout << "Socket Creation has failed.. The system will exit now" << endl;
		exit(1);
	}

	else
	{
		cout << "Socket was created successfully" << endl;
		ServerAddress.sin_family = AF_INET;
		ServerAddress.sin_addr.s_addr = INADDR_ANY; 
		ServerAddress.sin_port = htons(PortNumber);
		Connect();
	}
}

void Client::Connect()
{
	connect(connect_fd, (struct sockaddr *)&ServerAddress, sizeof(ServerAddress));
	cout << "you are successfully connected to the server" << endl;
	Communicate();
}

void Client::Communicate()
{
	char hello[] = "Hello From Client";
        send(connect_fd, hello, sizeof(hello), 0);
	char hello2[MAX_LETTERS];
	recv(connect_fd, hello2, sizeof(hello2), 0);
        cout<< "From Server : "<<hello2<<endl;
	for (;;)
	{
		char msg[MAX_LETTERS];
		cin.getline(msg, MAX_LETTERS, '\n');
		send(connect_fd, msg, sizeof(msg), 0);
                string check(msg);
                if(check=="exit")
                {
                   exit(1);
                }
                char msg2[MAX_LETTERS];
		recv(connect_fd, msg2, sizeof(msg2), 0);
		cout << "From Server : "<<msg2 << endl;
	}

}

Client::~Client()
{

}
