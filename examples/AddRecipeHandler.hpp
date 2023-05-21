#ifndef _ADD_RECIPE_HANDLER_
#define _ADD_RECIPE_HANDLER_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Goodeats.hpp"

class AddRecipeHandler : public RequestHandler {
public:
	AddRecipeHandler(Goodeats* _goodeats_);
	Response *callback(Request *);
private:
	Goodeats *goodeats;
};

#endif