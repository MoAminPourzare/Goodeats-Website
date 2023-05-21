#ifndef _SHELVES_MANU_HANDLER_
#define _SHELVES_MANU_HANDLER_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Goodeats.hpp"

class ShelvesMenuHandler : public RequestHandler {
public:
	ShelvesMenuHandler(Goodeats* _goodeats_);
	Response *callback(Request *);
private:
	Goodeats *goodeats;
};

#endif