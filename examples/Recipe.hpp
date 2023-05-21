#ifndef _RECIPE_
#define _RECIPE_

#include "../server/server.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <sstream>
#include <fstream>

using namespace std;

#define COMMA ','

class Recipe {
public:
	Recipe(string _title_, string _vegetarian_, string _ingredients_,
		int _minutes_to_ready_, string _tags_, string _image_address_, int _recipes_id_);
	int get_id();
	string get_title();
	vector<string> get_tags();
	string get_vegetarian();
	double get_average_rating();
	int get_minutes_to_ready();
	string get_connected_ingredients();
	string get_connected_tags();
	bool rate_recipe(double _score_, string _username_);
	double average_recipe_rating();
	void calculate_average_rating();
	bool existence_previous_score(string _username_);
	void save_new_score(double new_score, string _username_);
	const vector<string> separate_arguments(string line, char divider);

private:
	int id;
	string title;
	string vegetarian;
	string connected_ingredients;
	string connected_tags;
	vector<string> ingredients;
	int minutes_to_ready;
	vector<string> tags;
	struct Rating{
		double score;
		string username;
	}rating;
	vector<Rating> ratings;
	double average_rating;
	string image_address;
};

#endif