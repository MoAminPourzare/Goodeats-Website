#ifndef _LOGIN_HANDLER_
#define _LOGIN_HANDLER_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Goodeats.hpp"

class LoginHandler : public RequestHandler {
public:
	LoginHandler(Goodeats* _goodeats_);
	Response *callback(Request *);
private:
	Goodeats *goodeats;
};

#endif