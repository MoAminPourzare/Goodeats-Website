#include "ShelvesMenuHandler.hpp"

using namespace std;

ShelvesMenuHandler::ShelvesMenuHandler(Goodeats* _goodeats_) : goodeats(_goodeats_) {}

Response *ShelvesMenuHandler::callback(Request *req){
	Response *res = new Response;
	res->setHeader("Content-Type", "text/html");
	Person *person = goodeats->get_enter_person(req->getSessionId());
	vector<Shelve*> shelves = person->get_shelves();
	ostringstream body;
	body
		<< "<!DOCTYPE html>" << endl
		<< "<html>" << endl
		<< "	<head><title>ShelvesMenu</title>" << endl
		<< "	</head>" << endl
		<< "	<body style='text-align: center;'>" << endl
		<< "		<h1>**Shelves Menu**</h1>" << endl
		<< "		<div style='background-color: red; padding: 1%; width: 500px; height: 35px; margin: auto;'>" << endl
		<< "			<form action='/' method='get'>" << endl
		<< "				<input type='submit' value='Logout' style='display:block; margin: auto; margin-bottom: 70px; padding: 5px; width: 70%;'/>" << endl
		<< "			</form>" << endl
		<< "		</div>" << endl
		<< "		<div style='background-color: lightgreen; padding: 1%; width: 500px; height: 170px; margin: auto;'>" << endl
		<< "			<form action='/AddShelve' method='get'>" << endl
		<< "				<input type='submit' value='Add Shelve' style='display:block; margin: auto; margin-bottom: 70px; padding: 5px; width: 94%;'/>" << endl
		<< "			</form>" << endl
		<< "			<h2>*Shelves*</h2>" << endl
		<< "		</div>" << endl;
	if (shelves.size() == 0) {
		body
		<< "		<div style='background-color: yellow; padding: 1%; width: 500px; height: 80px; margin: auto;'>" << endl
		<< "			<h2>Empty" << endl
		<< "			</h2>" << endl
		<< "		</div>" << endl;
	}
	for (int i = 0; i < shelves.size(); i++) {
		body
		<< "		<div style='background-color: yellow; padding: 1%; width: 500px; height: 165px; margin: auto;'>" << endl
		<< "			<h3 style='color: red;'>Shelve" << i + 1 << endl
		<< "			</h3>" << endl
		<< "			<h3>id : " << shelves[i]->get_id() << endl
		<< "			</h3>" << endl
		<< "			<h3>name : " << shelves[i]->get_name() << endl
		<< "			</h3>" << endl
		<< "			<form action='/ShelveInformation' method='get'>" << endl
		<< "				<input type='hidden' name='id' value='" << shelves[i]->get_id() << "'/>" << endl
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