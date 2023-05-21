#ifndef _CHEF_MENU_HANDLER_
#define _CHEF_MENU_HANDLER_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Goodeats.hpp"


class ChefMenuHandler : public RequestHandler {
public:
	ChefMenuHandler(Goodeats* _goodeats_);
 	Response *callback(Request *);
private:
	Goodeats *goodeats;
};

#endif