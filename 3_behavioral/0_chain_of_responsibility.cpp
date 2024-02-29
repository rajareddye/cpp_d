/*
Chain of Responsibility :
which allows an object to send a request to other objects without knowing who is going to handle it. 
This pattern is frequently used in the chain of multiple objects, where each object either handles the request or passes it on to the next 
object in the chain if it is unable to handle that request. This pattern encourages loose coupling between sender and receiver, 
providing freedom in how the request is handled.

*/
#include <iostream>
#include <string>

// Handler Interface
class AuthenticationHandler {
public:
	virtual void setNextHandler(AuthenticationHandler* handler) = 0;
	virtual void handleRequest(const std::string& request) = 0;
};

// Concrete Handlers
class UsernamePasswordHandler : public AuthenticationHandler {
private:
	AuthenticationHandler* nextHandler;

public:
	void
	setNextHandler(AuthenticationHandler* handler) override
	{
		nextHandler = handler;
	}

	void handleRequest(const std::string& request) override
	{
		if (request == "username_password") {
			std::cout << "Authenticated using username and ""password."	<< std::endl;
		}
		else if (nextHandler != nullptr) {
			nextHandler->handleRequest(request);
		}
		else {
			std::cout << "Invalid authentication method."<< std::endl;
		}
	}
};

class OAuthHandler : public AuthenticationHandler {
private:
	AuthenticationHandler* nextHandler;

public:
	void
	setNextHandler(AuthenticationHandler* handler) override
	{
		nextHandler = handler;
	}

	void handleRequest(const std::string& request) override
	{
		if (request == "oauth_token") {
			std::cout << "Authenticated using OAuth token." << std::endl;
		}
		else if (nextHandler != nullptr) {
			nextHandler->handleRequest(request);
		}
		else {
			std::cout << "Invalid authentication method." << std::endl;
		}
	}
};

// Client
int main()
{
	AuthenticationHandler* usernamePasswordHandler = new UsernamePasswordHandler();
	AuthenticationHandler* oauthHandler = new OAuthHandler();

	// Set up the chain
	usernamePasswordHandler->setNextHandler(oauthHandler);

	// Handling authentication requests
	usernamePasswordHandler->handleRequest("oauth_token");
	usernamePasswordHandler->handleRequest( "username_password");
	usernamePasswordHandler->handleRequest( "invalid_method");

	delete usernamePasswordHandler;
	delete oauthHandler;

	return 0;
}
