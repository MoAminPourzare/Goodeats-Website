#ifndef _USER_MANU_HANDLER_
#define _USER_MANU_HANDLER_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Goodeats.hpp"

class UserMenuHandler : public RequestHandler {
public:
	UserMenuHandler(Goodeats* _goodeats_);
	Response *callback(Request *);
private:
	Goodeats *goodeats;
};

#endif