#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include "../server/server.hpp"
#include "Recipe.hpp"
#include "Person.hpp"
#include "Chef.hpp"
#include "User.hpp"
#include "Shelve.hpp"
#include "Goodeats.hpp"
#include "SignupHandler.hpp"
#include "LoginHandler.hpp"
#include "ChefMenuHandler.hpp"
#include "AddRecipeHandler.hpp"
#include "DeleteRecipeHandler.hpp"
#include "UserMenuHandler.hpp"
#include "GivingScoreHandler.hpp"
#include "RecipeInformationHandler.hpp"
#include "ChangeScoreHandler.hpp"
#include "UpdateGivingScoreHandler.hpp"
#include "GivingScoreHandler.hpp"
#include "UpdateChangeScoreHandler.hpp"
#include "ShelvesMenuHandler.hpp"
#include "AddShelveHandler.hpp"
#include "ShelveInformationHandler.hpp"
#include "AddRecipeToShelveHandler.hpp"
#include "DeleteRecipeFromShelveHandler.hpp"
#include "UpdateAddRecipeToShelveHandler.hpp"
#include "UpdateDeleteRecipeFromShelveHandler.hpp"
#include "my_server.hpp"

using namespace std;

#define ADDRESS_404 "html codes/404.html"
#define ADDRESS_HOME "html codes/home.html"
#define ADDRESS_BAD_REQUEST "html codes/BadRequest.html"
#define ADDRESS_NOT_FOUND "html codes/NotFound.html"
#define ADDRESS_SIGNUP "html codes/signup.html"
#define ADDRESS_LOGIN "html codes/login.html"
#define ADDRESS_ADD_RECIPE "html codes/AddRecipe.html"
#define ADDRESS_DELETE_RECIPE "html codes/DeleteRecipe.html"
#define ADDRESS_ADD_SHELVE "html codes/AddShelve.html"

int main(int argc, char const **argv) {
	try {
		MyServer server(argc > 1 ? atoi(argv[1]) : 5000);
		Goodeats *goodeats = new Goodeats();
		server.setNotFoundErrPage(ADDRESS_404);
		server.get("/", new ShowPage(ADDRESS_HOME));
		server.get("/BadRequest", new ShowPage(ADDRESS_BAD_REQUEST));
		server.get("/NotFound", new ShowPage(ADDRESS_NOT_FOUND));
		server.get("/Signup", new ShowPage(ADDRESS_SIGNUP));
		server.post("/Signup", new SignupHandler(goodeats));
		server.get("/Login", new ShowPage(ADDRESS_LOGIN));
		server.post("/Login", new LoginHandler(goodeats));
		server.get("/UserMenu", new UserMenuHandler(goodeats));
		server.get("/ChefMenu", new ChefMenuHandler(goodeats));
		server.get("/AddRecipe", new ShowPage(ADDRESS_ADD_RECIPE));
		server.post("/AddRecipe", new AddRecipeHandler(goodeats));
		server.get("/DeleteRecipe", new ShowPage(ADDRESS_DELETE_RECIPE));
		server.post("/DeleteRecipe", new DeleteRecipeHandler(goodeats));
		server.get("/RecipeInformation", new RecipeInformationHandler(goodeats));
		server.get("/GivingScore", new GivingScoreHandler(goodeats));
		server.post("/UpdateGivingScore", new UpdateGivingScoreHandler(goodeats));
		server.get("/ChangeScore", new ChangeScoreHandler(goodeats));
		server.post("/UpdateChangeScore", new UpdateChangeScoreHandler(goodeats));
		server.get("/AddShelve", new ShowPage(ADDRESS_ADD_SHELVE));
		server.post("/AddShelve", new AddShelveHandler(goodeats));
		server.get("/AddRecipeToShelve", new AddRecipeToShelveHandler(goodeats));
		server.post("/AddRecipeToShelve", new UpdateAddRecipeToShelveHandler(goodeats));
		server.get("/DeleteRecipeFromShelve", new DeleteRecipeFromShelveHandler(goodeats));
		server.post("/DeleteRecipeFromShelve", new UpdateDeleteRecipeFromShelveHandler(goodeats));
		server.get("/ShelvesMenu", new ShelvesMenuHandler(goodeats));
		server.get("/ShelveInformation", new ShelveInformationHandler(goodeats));
		
		server.run();
	} catch (Server::Exception e) {
		cerr << e.getMessage() << endl;
	}
	return 0;
}

