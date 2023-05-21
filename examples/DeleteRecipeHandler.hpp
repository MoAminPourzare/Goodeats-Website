#ifndef _DELETE_RECIPE_HANDLER_
#define _DELETE_RECIPE_HANDLER_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Goodeats.hpp"

#define NOT_FOUND "Not Found"
#define BAD_REQUEST "Bad Request"

class DeleteRecipeHandler : public RequestHandler {
public:
	DeleteRecipeHandler(Goodeats* _goodeats_);
	Response *callback(Request *);
private:
	Goodeats *goodeats;
};

#endif