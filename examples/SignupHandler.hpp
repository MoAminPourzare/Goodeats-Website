#ifndef _SIGNUP_HANDLER_
#define _SIGNUP_HANDLER_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Goodeats.hpp"

class SignupHandler : public RequestHandler {
public:
	SignupHandler(Goodeats* _goodeats_);
	Response *callback(Request *);
private:
	Goodeats *goodeats;
};

#endif