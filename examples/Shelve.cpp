#include "Shelve.hpp"

using namespace std;

Shelve::Shelve(string _name_, int _shelves_id_) {
	name = _name_;
	id = _shelves_id_;
}
int Shelve::get_id() {
	return id;
}
string Shelve::get_name() { return name; }
vector<Recipe*> Shelve::get_recipes(){
	return recipes;
}
void Shelve::add_recipe_s(Recipe* recipe){
	recipes.push_back(recipe);
}
bool Shelve::delete_recipe_s(int recipe_id){
	bool check = false;
	for (int i = 0; i < recipes.size(); ++i)
		if (recipes[i]->get_id() == recipe_id){
			recipes.erase(recipes.begin() + i);
			check = true;
		}
	if (check == false)
		return false;
	return true;
}