#ifndef _PERSON_
#define _PERSON_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Shelve.hpp"

class Person {
public:
	Person(string _username_, string _password_, string _type_);
	string get_username();
	string get_password();
	string get_type();
	virtual void add_one_recipe(Recipe *recipe){}
	virtual string get_first_recipe() { return "oooops"; }
	virtual vector<Recipe*> get_recipes() { 
		vector<Recipe*> recipes;
		return recipes;
	}
	virtual bool delete_one_recipe(int _id_){ return true; }
	virtual vector<Shelve*> get_shelves() {
		vector<Shelve*> shelves;
		return shelves;
	}
	virtual bool add_one_shelve(Shelve* shelve){ return true; }

protected:
	string username;
	string password;
	string type;
};

#endif