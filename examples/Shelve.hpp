#ifndef _SHELVE_
#define _SHELVE_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Recipe.hpp"

class Shelve {
public:
	Shelve(string _name_, int _shelves_id_);
	int get_id();
	string get_name();
	void add_recipe(Recipe *recipe);
	vector<Recipe*> get_recipes();
	void add_recipe_s(Recipe* recipe);
	bool delete_recipe_s(int recipe_id);

private:
	int id;
	string name;
	vector<Recipe*> recipes;
};

#endif