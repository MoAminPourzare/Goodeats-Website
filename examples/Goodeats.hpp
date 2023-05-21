#ifndef _GOODEATS_
#define _GOODEATS_

using namespace std;

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "Recipe.hpp"
#include "Person.hpp"
#include "Chef.hpp"
#include "User.hpp"
#include "Shelve.hpp"

#define NOT_FOUND "Not Found"
#define BAD_REQUEST "Bad Request"
#define USER "user"
#define CHEF "chef"
#define EMPTY_TEXT ""
#define OK "OK"

class Goodeats {
public:
	Goodeats();
	bool check_duplicate_person(string username);
	void add_person(string username, string password, string type);
	bool check_is_number(string command);
	bool add_recipe(string title, string ingredients, string vegetarian, string tags, string image_address, string minutes_to_ready, string enter_person);
	string delete_recipe(string id, string enter_person);
	bool delete_recipe_from_all(int id);
	bool find_person(string username, string password);
	vector<Person*> get_all_persons();
	Person *get_enter_person(string _username_);
	vector<Recipe*> get_all_recipes();
	vector<Shelve*> get_all_shelves();
	bool giving_score(string username, string score, string id);
	bool find_recipe_by_id(int id, double score, string username);
	bool change_score(string username, string score, string id);
	int check_previous_score(int id, string username);
	bool add_shelve(string name, string enter_person);
	string add_recipe_to_shelve(string recipe_id, string id);
	string delete_recipe_from_shelve(string recipe_id, string id);
	string find_type_person(string username);

private:
	vector<Person*> all_persons;
	vector<Recipe*> all_recipes;
	vector<Shelve*> all_shelves;
	int recipes_id;
	int shelves_id;
};

#endif