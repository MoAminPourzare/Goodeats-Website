#ifndef _SHELVE_INFORMATION_HANDLER_
#define _SHELVE_INFORMATION_HANDLER_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Goodeats.hpp"

class ShelveInformationHandler : public RequestHandler {
public:
	ShelveInformationHandler(Goodeats* _goodeats_);
	Response *callback(Request *);
private:
	Goodeats *goodeats;
};

#endif