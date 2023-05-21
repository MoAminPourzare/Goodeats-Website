#include "UpdateChangeScoreHandler.hpp"

using namespace std;

UpdateChangeScoreHandler::UpdateChangeScoreHandler(Goodeats* _goodeats_) : goodeats(_goodeats_) {}

Response *UpdateChangeScoreHandler::callback(Request *req) {
	Response *res;
	string new_score = req->getBodyParam("score");
	string id = req->getBodyParam("id");
	string username = req->getSessionId();
	if (!goodeats->change_score(username, new_score, id))
		res = Response::redirect("/BadRequest");
	else
		res = Response::redirect("/RecipeInformation?id="+id);
	return res;
}