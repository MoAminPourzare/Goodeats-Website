#ifndef _USER_
#define _USER_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Person.hpp"

class User : public Person {
public:
	User(string _username_, string _password_, string _type_);
	vector<Shelve*> get_shelves();
	bool add_one_shelve(Shelve* shelve);
	
private:
	vector<Shelve*> my_shelves;
};

#endif