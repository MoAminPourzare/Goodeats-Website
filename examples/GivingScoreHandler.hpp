#ifndef _GIVING_SCORE_HANDLER_
#define _GIVING_SCORE_HANDLER_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Goodeats.hpp"

class GivingScoreHandler : public RequestHandler {
public:
	GivingScoreHandler(Goodeats* _goodeats_);
	Response *callback(Request *);
private:
	Goodeats *goodeats;
};

#endif