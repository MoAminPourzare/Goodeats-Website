#include "ShelveInformationHandler.hpp"

using namespace std;

ShelveInformationHandler::ShelveInformationHandler(Goodeats* _goodeats_) : goodeats(_goodeats_) {}

Response *ShelveInformationHandler::callback(Request *req){
	Response *res = new Response;
	res->setHeader("Content-Type", "text/html");
	vector<Shelve*> shelves = goodeats->get_all_shelves();
	int id = stoi(req->getQueryParam("id"));
	Shelve* shelve;
	for (int i = 0; i < shelves.size(); ++i)
		if (shelves[i]->get_id() == id)
			shelve = shelves[i];
	vector<Recipe*> recipes = shelve->get_recipes();
	ostringstream body;
	body
		<< "<!DOCTYPE html>" << endl
		<< "<html>" << endl
		<< "	<head><title>ShelveInformation</title>" << endl
		<< "	</head>" << endl
		<< "	<body style='text-align: center;'>" << endl
		<< "		<h1>**Shelve Information**</h1>" << endl
		<< "		<div style='background-color: red; padding: 1%; width: 500px; height: 35px; margin: auto;'>" << endl
		<< "			<form action='/' method='get'>" << endl
		<< "				<input type='submit' value='Logout' style='display:block; margin: auto; margin-bottom: 70px; padding: 5px; width: 70%;'/>" << endl
		<< "			</form>" << endl
		<< "		</div>" << endl
		<< "		<div style='background-color: lightgreen; padding: 1%; width: 500px; height: 200px; margin: auto;'>" << endl
		<< "			<form action='/AddRecipeToShelve' method='get'>" << endl
		<< "				<input type='hidden' name='id' value='" << shelve->get_id() << "'/>" << endl
		<< "				<input type='submit' value='Add Recipe To Shelve' style='display:block; margin: auto; margin-bottom: 20px; padding: 5px; width: 94%;'/>" << endl
		<< "			</form>" << endl
		<< "			<form action='/DeleteRecipeFromShelve' method='get'>" << endl
		<< "				<input type='hidden' name='id' value='" << shelve->get_id() << "'/>" << endl
		<< "				<input type='submit' value='Delete Recipe From Shelve' style='display:block; margin: auto; margin-bottom: 70px; padding: 5px; width: 94%;'/>" << endl
		<< "			</form>" << endl
		<< "			<h2>*Recipes*</h2>" << endl
		<< "		</div>" << endl;
	if (recipes.size() == 0) {
		body
		<< "		<div style='background-color: yellow; padding: 1%; width: 500px; height: 80px; margin: auto;'>" << endl
		<< "			<h2>Empty" << endl
		<< "			</h2>" << endl
		<< "		</div>" << endl;
	}
	for (int i = 0; i < recipes.size(); i++) {
		body
		<< "		<div style='background-color: yellow; padding: 1%; width: 500px; height: 250px; margin: auto;'>" << endl
		<< "			<h3 style='color: red;'>Resipe" << i + 1 << endl
		<< "			</h3>" << endl
		<< "			<h3>id :" << recipes[i]->get_id() << endl
		<< "			</h3>" << endl
		<< "			<h3>title :" << recipes[i]->get_title() << endl
		<< "			</h3>" << endl
		<< "			<h3>vegetarian :" << recipes[i]->get_vegetarian() << endl
		<< "			</h3>" << endl
		<< "			<h3>minutes to ready :" << recipes[i]->get_minutes_to_ready() << endl
		<< "			</h3>" << endl
		<< "			<form action='/RecipeInformation' method='get'>" << endl
		<< "				<input type='hidden' name='id' value='" << recipes[i]->get_id() << "'/>" << endl
		<< "				<input type='submit' value='More information' style='display:block; margin: auto; margin-bottom: 70px; padding: 5px; width: 94%;'/>" << endl
		<< "			</form>" << endl
		<< "		</div>" << endl;
	}
	body
		<< "		</div>" << endl
		<< "	</body>" << endl		
		<< "</html>" << endl;
	res->setBody(body.str());
	return res;
}