#include "GivingScoreHandler.hpp"

using namespace std;

GivingScoreHandler::GivingScoreHandler(Goodeats* _goodeats_) : goodeats(_goodeats_) {}

Response *GivingScoreHandler::callback(Request *req) {
	Response *res = new Response;
	res->setHeader("Content-Type", "text/html");
	string id = req->getQueryParam("id");
	ostringstream body;
	body
		<< "<!DOCTYPE html>" << endl
		<< "<html>" << endl
		<< "	<head>" << endl
		<< "		<title>GivingScore</title>" << endl
		<< "	</head>" << endl
		<< "	<body style='text-align: center;'>" << endl
		<< "		<h1>**Giving Score**</h1>" << endl
		<< "		<div style='background-color: red; padding: 1%; width: 300px; height: 35px; margin: auto;'>" << endl
		<< "			<form action='/' method='get'>" << endl
		<< "				<input type='submit' value='Logout' style='display:block; margin: auto; margin-bottom: 70px; padding: 5px; width: 70%;'/>" << endl
		<< "			</form>" << endl
		<< "		</div>" << endl
		<< "		<div style='background-color: lightgreen; padding: 1%; width: 300px; height: 170px; margin: auto;'>" << endl
		<< "			<form action='/UpdateGivingScore' method='post' style='text-align: center;'>" << endl
		<< "				<input type='hidden' name='id' value='" << id << "'/>" << endl
		<< "				<p>" << endl
		<< "					<big>Enter score : </big>" << endl
		<< "					<br style='margin-bottom: 25px;'>" << endl
		<< "					<input name='score' type='text' placeholder='score' style='display:block; margin: auto; margin-bottom: 30px; padding: 5px; width: 60%' />" << endl
		<< "				</p>" << endl
		<< "				<button type='submit' style='display:block; padding: 7px; margin: auto; width: 30%;'>Save</button>" << endl
		<< "			</form>" << endl
		<< "		</div>" << endl
		<< "	</body>" << endl
		<< "</html>" << endl;
	res->setBody(body.str());
	return res;
}