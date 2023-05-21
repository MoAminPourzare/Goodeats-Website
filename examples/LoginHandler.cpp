#include "LoginHandler.hpp"

using namespace std;

LoginHandler::LoginHandler(Goodeats* _goodeats_) : goodeats(_goodeats_) {}

Response *LoginHandler::callback(Request *req){
	Response *res;
	string username = req->getBodyParam("username");
	string password = req->getBodyParam("password");
	if (username == EMPTY_TEXT || password == EMPTY_TEXT){
		res = Response::redirect("/BadRequest");
		return res;
	}
	else if (!goodeats->find_person(username, password)){
		res = Response::redirect("/BadRequest");
		return res;
	}
	string type = goodeats->find_type_person(username);
	if (type == CHEF)
		res = Response::redirect("/ChefMenu");
	else if (type == USER)
		res = Response::redirect("/UserMenu");
	res->setSessionId(username);
	return res;
}