#include "AddRecipeHandler.hpp"

using namespace std;

AddRecipeHandler::AddRecipeHandler(Goodeats* _goodeats_) : goodeats(_goodeats_) {}

Response *AddRecipeHandler::callback(Request *req){
	Response *res;
	string enter_person = req->getSessionId();
	string title = req->getBodyParam("title");
	string ingredients = req->getBodyParam("ingredients");
	string vegetarian = req->getBodyParam("_vegetarian_");
	string tags = req->getBodyParam("tags");
	string image_address = req->getBodyParam("image_address");
	string minutes_to_ready = req->getBodyParam("minutes_to_ready");
	if (title == EMPTY_TEXT || ingredients == EMPTY_TEXT || vegetarian == EMPTY_TEXT ||
		 tags == EMPTY_TEXT || image_address == EMPTY_TEXT || minutes_to_ready == EMPTY_TEXT)
		res = Response::redirect("/BadRequest");
	if (!goodeats->add_recipe(title, ingredients, vegetarian, tags, image_address, minutes_to_ready, enter_person))
		res = Response::redirect("/BadRequest");
	else
		res = Response::redirect("/ChefMenu");
	return res;
}