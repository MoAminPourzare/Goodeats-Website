#include "UpdateDeleteRecipeFromShelveHandler.hpp"

using namespace std;

UpdateDeleteRecipeFromShelveHandler::UpdateDeleteRecipeFromShelveHandler(Goodeats* _goodeats_) : goodeats(_goodeats_) {}

Response *UpdateDeleteRecipeFromShelveHandler::callback(Request *req) {
	Response *res;
	string recipe_id = req->getBodyParam("recipe_id");
	string id = req->getBodyParam("id");
	string username = req->getSessionId();
	string check_error = goodeats->delete_recipe_from_shelve(recipe_id, id);
	if (check_error == BAD_REQUEST)
		res = Response::redirect("/BadRequest");
	else if (check_error == NOT_FOUND)
		res = Response::redirect("/NotFound");
	else
		res = Response::redirect("/ShelveInformation?id="+id);
	return res;
}