#include "User.hpp"

using namespace std;

User::User(string _username_, string _password_, string _type_)
	: Person(_username_, _password_, _type_) {}
vector<Shelve*> User::get_shelves(){
	return my_shelves;
}
bool User::add_one_shelve(Shelve* shelve){
	for (int i = 0; i < my_shelves.size(); ++i)
		if (shelve->get_name() == my_shelves[i]->get_name())
			return false;
	my_shelves.push_back(shelve);
	return true;
}