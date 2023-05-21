#include "UpdateGivingScoreHandler.hpp"

using namespace std;

UpdateGivingScoreHandler::UpdateGivingScoreHandler(Goodeats* _goodeats_) : goodeats(_goodeats_) {}

Response *UpdateGivingScoreHandler::callback(Request *req) {
	Response *res;
	string score = req->getBodyParam("score");
	string id = req->getBodyParam("id");
	string username = req->getSessionId();
	if (!goodeats->giving_score(username, score, id))
		res = Response::redirect("/BadRequest");
	else 
		res = Response::redirect("/RecipeInformation?id="+id);
	return res;
}