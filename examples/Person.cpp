#include "Person.hpp"

using namespace std;

Person::Person(string _username_, string _password_, string _type_){
	username = _username_;
	password = _password_;
	type = _type_;
}
string Person::get_username(){
	return username;
}
string Person::get_password(){
	return password;
}
string Person::get_type(){
	return type;
}