#include "Chef.hpp"

using namespace std;

Chef::Chef(string _username_, string _password_, string _type_)
	: Person(_username_, _password_, _type_) {}
void Chef::add_one_recipe(Recipe *recipe){
	my_recipes.push_back(recipe);
}
bool Chef::delete_one_recipe(int _id_){
	for (int i = 0; i < my_recipes.size(); ++i)
		if (my_recipes[i]->get_id() == _id_){
			delete my_recipes[i];
			my_recipes.erase(my_recipes.begin() + i);
			return true;
		}
	return false;
}
vector<Recipe*> Chef::get_recipes(){
	return my_recipes;
}