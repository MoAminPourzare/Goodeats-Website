#ifndef _UPDATE_GIVING_SCORE_HANDLER_
#define _UPDATE_GIVING_SCORE_HANDLER_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Goodeats.hpp"

class UpdateGivingScoreHandler : public RequestHandler {
public:
	UpdateGivingScoreHandler(Goodeats* _goodeats_);
	Response *callback(Request *);
private:
	Goodeats *goodeats;
};

#endif