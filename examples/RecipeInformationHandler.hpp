#ifndef _RECIPE_INFORMATION_HANDLER_
#define _RECIPE_INFORMATION_HANDLER_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Goodeats.hpp"

class RecipeInformationHandler : public RequestHandler {
public:
	RecipeInformationHandler(Goodeats* _goodeats_);
	Response *callback(Request *);
private:
	Goodeats *goodeats;
};

#endif