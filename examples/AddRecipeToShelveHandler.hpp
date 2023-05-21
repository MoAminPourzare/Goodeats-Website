#ifndef _ADD_RECIPE_TO_SHELVE_HANDLER_
#define _ADD_RECIPE_TO_SHELVE_HANDLER_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Goodeats.hpp"

class AddRecipeToShelveHandler : public RequestHandler {
public:
	AddRecipeToShelveHandler(Goodeats* _goodeats_);
	Response *callback(Request *);
private:
	Goodeats *goodeats;
};

#endif