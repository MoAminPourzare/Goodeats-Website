#include "DeleteRecipeHandler.hpp"

using namespace std;

DeleteRecipeHandler::DeleteRecipeHandler(Goodeats* _goodeats_) : goodeats(_goodeats_) {}

Response *DeleteRecipeHandler::callback(Request *req){
	Response *res;
	string enter_person = req->getSessionId();
	string id = req->getBodyParam("delete_id");
	string check_error = goodeats->delete_recipe(id, enter_person);
	if (id == EMPTY_TEXT)
		res = Response::redirect("/BadRequest");
	if (check_error == NOT_FOUND)
		res = Response::redirect("/NotFound");
	else if (check_error == BAD_REQUEST)
		res = Response::redirect("/BadRequest");
	else
		for (int i = 0; i < goodeats->get_all_persons().size(); ++i)
			if (req->getSessionId() == goodeats->get_all_persons()[i]->get_username())
				res = Response::redirect("/ChefMenu");
	return res;
}