#include "UpdateAddRecipeToShelveHandler.hpp"

using namespace std;

UpdateAddRecipeToShelveHandler::UpdateAddRecipeToShelveHandler(Goodeats* _goodeats_) : goodeats(_goodeats_) {}

Response *UpdateAddRecipeToShelveHandler::callback(Request *req) {
	Response *res;
	string recipe_id = req->getBodyParam("recipe_id");
	string id = req->getBodyParam("id");
	string username = req->getSessionId();
	string check_error = goodeats->add_recipe_to_shelve(recipe_id, id);
	if (check_error == NOT_FOUND)
		res = Response::redirect("/NotFound");
	else if (check_error == BAD_REQUEST)
		res = Response::redirect("/BadRequest");
	else
		res = Response::redirect("/ShelveInformation?id="+id);
	return res;
}