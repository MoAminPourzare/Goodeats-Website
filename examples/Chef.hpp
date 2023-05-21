#ifndef _CHEF_
#define _CHEF_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Recipe.hpp"
#include "Person.hpp"

class Chef : public Person {
public:
	Chef(string _username_, string _password_, string _type_);
	void add_one_recipe(Recipe *recipe);
	bool delete_one_recipe(int _id_);
	vector<Recipe*> get_recipes();

private:
	vector<Recipe*> my_recipes;
};

#endif