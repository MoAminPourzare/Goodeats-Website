#include "SignupHandler.hpp"

using namespace std;

SignupHandler::SignupHandler(Goodeats* _goodeats_) : goodeats(_goodeats_) {}

Response *SignupHandler::callback(Request *req) {
	string username = req->getBodyParam("username");
	string password = req->getBodyParam("password");
	string type = req->getBodyParam("type");
	Response *res;
	if (type == ""){
		res = Response::redirect("/BadRequest");
		return res;
	}
	if (goodeats->check_duplicate_person(username)) {
		res = Response::redirect("/BadRequest");
		return res;
	}
	goodeats->add_person(username, password, type);
	if (type == CHEF)
		res = Response::redirect("/ChefMenu");
	else if (type == USER)
		res = Response::redirect("/UserMenu");
	res->setSessionId(username);
	return res;
}