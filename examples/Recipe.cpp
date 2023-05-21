#include "Recipe.hpp"

using namespace std;

Recipe::Recipe(string _title_, string _vegetarian_, string _ingredients_,
	int _minutes_to_ready_, string _tags_, string _image_address_, int _recipes_id_) {
	connected_ingredients = _ingredients_;
	connected_tags = _tags_;
	vector<string> separate_ingredients = separate_arguments(_ingredients_, COMMA);
	vector<string> separate_tags = separate_arguments(_tags_, COMMA);
	title = _title_;
	vegetarian = _vegetarian_;
	ingredients = separate_ingredients;
	minutes_to_ready = _minutes_to_ready_;
	tags = separate_tags;
	image_address = _image_address_;
	id = _recipes_id_;
	average_rating = 0;
}
int Recipe::get_id() { return id; }
string Recipe::get_title() { return title; }
vector<string> Recipe::get_tags() { return tags; }
string Recipe::get_vegetarian() { return vegetarian; }
double Recipe::get_average_rating() { return average_rating; }
int Recipe::get_minutes_to_ready() { return minutes_to_ready; }
string Recipe::get_connected_ingredients() { return connected_ingredients; }
string Recipe::get_connected_tags() { return connected_tags; }
double Recipe::average_recipe_rating() {
	double sum = 0;
	for (int i = 0; i < ratings.size(); i++)
		sum += ratings[i].score;
	return sum;
}
void Recipe::calculate_average_rating() {
	average_rating = ceil((average_recipe_rating() / ratings.size()) * 10) / 10;
}
bool Recipe::rate_recipe(double _score_, string _username_) {
	for (int i = 0; i < ratings.size(); i++)
		if (ratings[i].username == _username_)
			return false;
	rating.score = _score_;
	rating.username = _username_;
	ratings.push_back(rating);
	calculate_average_rating();
	return true;
}
double Recipe::average_recipe_rating();
void Recipe::calculate_average_rating();
bool Recipe::existence_previous_score(string _username_) {
	for (int i = 0; i < ratings.size(); i++)
		if (ratings[i].username == _username_)
			return true;
	return false;
}
void Recipe::save_new_score(double new_score, string _username_) {
	for (int i = 0; i < ratings.size(); i++)
		if (ratings[i].username == _username_)
			ratings[i].score = new_score;
	calculate_average_rating();
}
const vector<string> Recipe::separate_arguments(string line, char divider) {
	vector<string> dividedLine;
	string argument;
	istringstream arguments(line);
	while (getline(arguments, argument, divider)) {
	if (argument == "") continue;
		dividedLine.push_back(argument);
	}
	return dividedLine;
}