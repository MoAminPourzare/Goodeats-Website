#include "DeleteRecipeFromShelveHandler.hpp"

using namespace std;

DeleteRecipeFromShelveHandler::DeleteRecipeFromShelveHandler(Goodeats* _goodeats_) : goodeats(_goodeats_) {}

Response *DeleteRecipeFromShelveHandler::callback(Request *req) {
	Response *res = new Response;
	res->setHeader("Content-Type", "text/html");
	string id = req->getQueryParam("id");
	ostringstream body;
	body
		<< "<!DOCTYPE html>" << endl
		<< "<html>" << endl
		<< "	<head>" << endl
		<< "		<title>DeleteRecipeFromShelve</title>" << endl
		<< "	</head>" << endl
		<< "	<body style='text-align: center;'>" << endl
		<< "		<h1>**Delete Recipe From Shelve**</h1>" << endl
		<< "		<div style='background-color: red; padding: 1%; width: 300px; height: 35px; margin: auto;'>" << endl
		<< "			<form action='/' method='get'>" << endl
		<< "				<input type='submit' value='Logout' style='display:block; margin: auto; margin-bottom: 70px; padding: 5px; width: 70%;'/>" << endl
		<< "			</form>" << endl
		<< "		</div>" << endl
		<< "		<div style='background-color: lightgreen; padding: 1%; width: 300px; height: 170px; margin: auto;'>" << endl
		<< "			<form action='/DeleteRecipeFromShelve' method='post' style='text-align: center;'>" << endl
		<< "				<input type='hidden' name='id' value='" << id << "'/>" << endl
		<< "				<p>" << endl
		<< "					<big>Enter recipe id : </big>" << endl
		<< "					<br style='margin-bottom: 25px;'>" << endl
		<< "					<input name='recipe_id' type='text' placeholder='recipe id' style='display:block; margin: auto; margin-bottom: 30px; padding: 5px; width: 60%' />" << endl
		<< "				</p>" << endl
		<< "				<button type='submit' style='display:block; padding: 7px; margin: auto; width: 30%;'>Save</button>" << endl
		<< "			</form>" << endl
		<< "		</div>" << endl
		<< "	</body>" << endl
		<< "</html>" << endl;
	res->setBody(body.str());
	return res;
}