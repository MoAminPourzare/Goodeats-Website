#ifndef _UPDATE_CHANGE_SCORE_HANDLER_
#define _UPDATE_CHANGE_SCORE_HANDLER_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Goodeats.hpp"

class UpdateChangeScoreHandler : public RequestHandler {
public:
	UpdateChangeScoreHandler(Goodeats* _goodeats_);
	Response *callback(Request *);
private:
	Goodeats *goodeats;
};

#endif