#ifndef _ADD_SHELVE_HANDLER_
#define _ADD_SHELVE_HANDLER_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Goodeats.hpp"

class AddShelveHandler : public RequestHandler {
public:
	AddShelveHandler(Goodeats* _goodeats_);
	Response *callback(Request *);
private:
	Goodeats *goodeats;
};

#endif