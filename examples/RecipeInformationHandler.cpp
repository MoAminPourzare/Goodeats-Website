#include "RecipeInformationHandler.hpp"

using namespace std;

RecipeInformationHandler::RecipeInformationHandler(Goodeats* _goodeats_) : goodeats(_goodeats_) {}

Response *RecipeInformationHandler::callback(Request *req){
	Response *res = new Response;
	res->setHeader("Content-Type", "text/html");
	vector<Recipe*> recipes = goodeats->get_all_recipes();
	int id = stoi(req->getQueryParam("id"));
	Recipe* recipe;
	for (int i = 0; i < recipes.size(); ++i)
		if (recipes[i]->get_id() == id)
			recipe = recipes[i];
	ostringstream body;
	body
		<< "<!DOCTYPE html>" << endl
		<< "<html>" << endl
		<< "	<head><title>RecipeInformation</title>" << endl
		<< "	</head>" << endl
		<< "	<body style='text-align: center;'>" << endl
		<< "		<h1>**Recipe Information**</h1>" << endl
		<< "		<div style='background-color: red; padding: 1%; width: 500px; height: 35px; margin: auto;'>" << endl
		<< "			<form action='/' method='get'>" << endl
		<< "				<input type='submit' value='Logout' style='display:block; margin: auto; margin-bottom: 70px; padding: 5px; width: 70%;'/>" << endl
		<< "			</form>" << endl
		<< "		</div>" << endl
		<< "		<div style='background-color: yellow; padding: 1%; width: 500px; height: 350px; margin: auto;'>" << endl
		<< "			<h3>id : " << recipe->get_id() << endl
		<< "			</h3>" << endl
		<< "			<h3>title : " << recipe->get_title() << endl
		<< "			</h3>" << endl
		<< "			<h3>vegetarian : " << recipe->get_vegetarian() << endl
		<< "			</h3>" << endl
		<< "			<h3>minutes to ready : " << recipe->get_minutes_to_ready() << endl
		<< "			</h3>" << endl
		<< "			<h3>ingredients : " << recipe->get_connected_ingredients() << endl
		<< "			</h3>" << endl
		<< "			<h3>tags : " << recipe->get_connected_tags() << endl
		<< "			</h3>" << endl
		<< "			<h3>rating : " << recipe->get_average_rating() << endl
		<< "			</h3>" << endl
		<< "		</div>" << endl
		<< "		<div style='background-color: yellow; padding: 1%; width: 500px; height: 120px; margin: auto;'>" << endl
		<< "			<form action='/GivingScore' method='get' style='text-align: center;'>" << endl
		<< "				<input type='hidden' name='id' value='" << id << "'/>" << endl
		<< "				<button type='submit' style='display:block; width: 100%; padding: 7px; margin-bottom: 15px;'>Giving Score</button>" << endl
		<< "			</form>" << endl
		<< "			<form action='/ChangeScore' method='get' style='text-align: center;'>" << endl
		<< "				<input type='hidden' name='id' value='" << id << "'/>" << endl
		<< "				<button type='submit' style='display:block; width: 100%; padding: 7px;'>Change Score</button>" << endl
		<< "			</form>" << endl
		<< "		</div>" << endl
		<< "	</body>" << endl		
		<< "</html>" << endl;
	res->setBody(body.str());
	return res;
}