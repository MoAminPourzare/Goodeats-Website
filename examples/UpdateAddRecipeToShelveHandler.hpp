#ifndef _UPDATE_ADD_RECIPE_TO_SHELVE_HANDLER__
#define _UPDATE_ADD_RECIPE_TO_SHELVE_HANDLER__

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Goodeats.hpp"

class UpdateAddRecipeToShelveHandler : public RequestHandler {
public:
	UpdateAddRecipeToShelveHandler(Goodeats* _goodeats_);
	Response *callback(Request *);
private:
	Goodeats *goodeats;
};

#endif