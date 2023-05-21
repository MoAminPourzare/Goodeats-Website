#ifndef _DELETE_RECIPE_FROM_SHELVE_HANDLER__
#define _DELETE_RECIPE_FROM_SHELVE_HANDLER__

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Goodeats.hpp"

class DeleteRecipeFromShelveHandler : public RequestHandler {
public:
	DeleteRecipeFromShelveHandler(Goodeats* _goodeats_);
	Response *callback(Request *);
private:
	Goodeats *goodeats;
};

#endif