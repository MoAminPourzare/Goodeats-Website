#include "UserMenuHandler.hpp"

using namespace std;

UserMenuHandler::UserMenuHandler(Goodeats* _goodeats_) : goodeats(_goodeats_) {}

Response *UserMenuHandler::callback(Request *req){
	Response *res = new Response;
	res->setHeader("Content-Type", "text/html");
	vector<Recipe*> recipes = goodeats->get_all_recipes();
	ostringstream body;
	body
		<< "<!DOCTYPE html>" << endl
		<< "<html>" << endl
		<< "	<head><title>UserMenu</title>" << endl
		<< "	</head>" << endl
		<< "	<body style='text-align: center;'>" << endl
		<< "		<h1>**User Menu**</h1>" << endl
		<< "		<div style='background-color: red; padding: 1%; width: 500px; height: 35px; margin: auto;'>" << endl
		<< "			<form action='/' method='get'>" << endl
		<< "				<input type='submit' value='Logout' style='display:block; margin: auto; margin-bottom: 70px; padding: 5px; width: 70%;'/>" << endl
		<< "			</form>" << endl
		<< "		</div>" << endl
		<< "		<div style='background-color: lightgreen; padding: 1%; width: 500px; height: 140px; margin: auto;'>" << endl
		<< "			<form action='/ShelvesMenu' method='get'>" << endl
		<< "				<input type='submit' value='Shelves Menu' style='display:block; margin: auto; margin-bottom: 70px; padding: 5px; width: 94%;'/>" << endl
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
		<< "	</body>" << endl
		<< "</html>" << endl;
	res->setBody(body.str());
	return res;
}