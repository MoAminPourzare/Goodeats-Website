#include "AddShelveHandler.hpp"

using namespace std;

AddShelveHandler::AddShelveHandler(Goodeats* _goodeats_) : goodeats(_goodeats_) {}

Response *AddShelveHandler::callback(Request *req){
	Response *res;
	string enter_person = req->getSessionId();
	string name = req->getBodyParam("name");
	if (name == EMPTY_TEXT)
		res = Response::redirect("/BadRequest");
	if (!goodeats->add_shelve(name, enter_person))
		res = Response::redirect("/BadRequest");
	else
		res = Response::redirect("/ShelvesMenu");
	return res;
}