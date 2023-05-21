#include "Goodeats.hpp"

using namespace std;

Goodeats::Goodeats(){
	recipes_id = 1;
	shelves_id = 1;
}
bool Goodeats::find_person(string username, string password) {
	for (int i = 0; i < all_persons.size(); i++) {
		if (username == all_persons[i]->get_username() && password == all_persons[i]->get_password())
			return true;
	}
	return false;
}

string Goodeats::delete_recipe(string id, string enter_person) {
	if (!check_is_number(id))
		return BAD_REQUEST;
	int id_number = stoi(id);
	if (!delete_recipe_from_all(id_number))
		return NOT_FOUND;
	for (int i = 0; i < all_persons.size(); ++i)
		if(enter_person == all_persons[i]->get_username())
			if (!all_persons[i]->delete_one_recipe(id_number))
				return NOT_FOUND;
	return OK;
}
bool Goodeats::delete_recipe_from_all(int id) {
	for (int i = 0; i < all_recipes.size(); i++)
		if (all_recipes[i]->get_id() == id) {
			all_recipes.erase(all_recipes.begin() + i);
			return true;
		}
	return false;
}
bool Goodeats::check_duplicate_person(string username) {
	for (int i = 0; i < all_persons.size(); i++)
		if (username == all_persons[i]->get_username())
			return true;
	return false;
}
void Goodeats::add_person(string username, string password, string type){
	if (type == CHEF)
		all_persons.push_back(new Chef(username, password, type));
	else if (type == USER)
		all_persons.push_back(new User(username, password, type));
}
bool Goodeats::add_recipe(string title, string ingredients, string vegetarian, string tags, string image_address, string minutes_to_ready, string enter_person){
	if (!check_is_number(minutes_to_ready))
		return false;
	Recipe *recipe = new Recipe(title, vegetarian, ingredients, stoi(minutes_to_ready), tags, image_address, recipes_id);
	all_recipes.push_back(recipe);
	for (int i = 0; i < all_persons.size(); ++i)
		if(enter_person == all_persons[i]->get_username())
			all_persons[i]->add_one_recipe(recipe);
	recipes_id++;
	return true;
}
bool Goodeats::check_is_number(string entry) {
	for (int i = 0; i < entry.size(); i++)
		if (entry[i] - '0' > 9 || entry[i] - '0' < 0) 
			return false;
	return true;
}
vector<Person*> Goodeats::get_all_persons(){
	return all_persons;
}
Person *Goodeats::get_enter_person(string _username_){
	for (int i = 0; i < all_persons.size(); ++i)
		if (all_persons[i]->get_username() == _username_)
			return all_persons[i];
}
vector<Recipe*> Goodeats::get_all_recipes(){
	return all_recipes;
}
vector<Shelve*> Goodeats::get_all_shelves(){
	return all_shelves;
}
bool Goodeats::giving_score(string username, string score, string id){
	if (username == EMPTY_TEXT || id == EMPTY_TEXT || score == EMPTY_TEXT){
		return false;
	}
	if (!check_is_number(score)){
		return false;
	}
	double score_number = stod(score);
	if (score_number < 1 || score_number > 5){
		return false;
	}
	find_recipe_by_id(stoi(id), score_number, username);
	return true;
}
bool Goodeats::find_recipe_by_id(int id, double score, string username) {
	for (int i = 0; i < all_recipes.size(); i++)
		if (all_recipes[i]->get_id() == id) {
			if (!all_recipes[i]->rate_recipe(score, username))
				return false;
		}
	return true;
}
bool Goodeats::change_score(string username, string score, string id) {
	if (!check_is_number(score)){
		return false;
	}
	double new_score = stod(score);
	if (username == EMPTY_TEXT || id == EMPTY_TEXT || score == EMPTY_TEXT){
		return false;
	}
	if (new_score < 1 || new_score > 5)
		return false;
	int recipe = check_previous_score(stoi(id), username);
	if (recipe == -1)
		return false;
	all_recipes[recipe]->save_new_score(new_score, username);
	return true;
}
int Goodeats::check_previous_score(int id, string username) {
	bool check_existence;
	int i = 0;
	for (i = 0; i < all_recipes.size(); i++)
		if (all_recipes[i]->get_id() == id) {
			check_existence = all_recipes[i]->existence_previous_score(username);
			break;
		}
	if (check_existence == true)
		return i;
	else
		return -1;
}
bool Goodeats::add_shelve(string name, string enter_person) {
	Shelve *shelve = new Shelve(name, shelves_id);
	all_shelves.push_back(shelve);
	for (int i = 0; i < all_persons.size(); ++i)
		if(enter_person == all_persons[i]->get_username())
			if (!all_persons[i]->add_one_shelve(shelve))
				return false;
	shelves_id++;
	return true;
}
string Goodeats::add_recipe_to_shelve(string recipe_id, string id){
	if (!check_is_number(recipe_id))
		return BAD_REQUEST;
	Recipe *recipe = NULL;
	for (int i = 0; i < all_recipes.size(); i++)
		if (all_recipes[i]->get_id() == stoi(recipe_id))
			recipe = all_recipes[i];
	if (recipe == NULL)
		return NOT_FOUND;
	for (int i = 0; i < all_shelves.size(); ++i)
		if (all_shelves[i]->get_id() == stoi(id))
			all_shelves[i]->add_recipe_s(recipe);
	return OK;
}
string Goodeats::delete_recipe_from_shelve(string recipe_id, string id){
	if (!check_is_number(recipe_id))
		return BAD_REQUEST;
	Recipe *recipe = NULL;
	for (int i = 0; i < all_recipes.size(); i++)
		if (all_recipes[i]->get_id() == stoi(recipe_id))
			recipe = all_recipes[i];
	if (recipe == NULL)
		return NOT_FOUND;
	for (int i = 0; i < all_shelves.size(); ++i)
		if (all_shelves[i]->get_id() == stoi(id))
			if (!all_shelves[i]->delete_recipe_s(stoi(recipe_id)))
				return NOT_FOUND;
	return OK;
}
string Goodeats::find_type_person(string username){
	for (int i = 0; i < all_persons.size(); ++i)
		if (all_persons[i]->get_username() == username)
			return all_persons[i]->get_type();
}