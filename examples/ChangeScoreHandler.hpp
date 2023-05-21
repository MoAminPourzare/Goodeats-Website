#ifndef _CHANGE_SCORE_HANDLER_
#define _CHANGE_SCORE_HANDLER_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Goodeats.hpp"

class ChangeScoreHandler : public RequestHandler {
public:
	ChangeScoreHandler(Goodeats* _goodeats_);
	Response *callback(Request *);
private:
	Goodeats *goodeats;
};

#endif