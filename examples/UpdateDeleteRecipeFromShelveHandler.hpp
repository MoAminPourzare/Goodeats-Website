#ifndef _UPDATE_DELETE_RECIPE_FROM_SHELVE_HANDLER_
#define _UPDATE_DELETE_RECIPE_FROM_SHELVE_HANDLER_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Goodeats.hpp"

class UpdateDeleteRecipeFromShelveHandler : public RequestHandler {
public:
	UpdateDeleteRecipeFromShelveHandler(Goodeats* _goodeats_);
	Response *callback(Request *);
private:
	Goodeats *goodeats;
};

#endif