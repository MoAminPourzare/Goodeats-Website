CC=g++
STD=-std=c++11 -Wall -pedantic
CF=$(STD)
BUILD_DIR=build
TEMPLATE_DIR=.template

all: $(BUILD_DIR) goodeats.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/template_parser.o: utils/template_parser.cpp utils/template_parser.hpp utils/request.cpp utils/request.hpp utils/utilities.hpp utils/utilities.cpp
	$(CC) $(CF) -c utils/template_parser.cpp -o $(BUILD_DIR)/template_parser.o

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp utils/template_parser.hpp utils/template_parser.cpp
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o

$(BUILD_DIR)/my_server.o: examples/my_server.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/my_server.cpp -o $(BUILD_DIR)/my_server.o

$(BUILD_DIR)/Recipe.o: examples/Recipe.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/Recipe.cpp -o $(BUILD_DIR)/Recipe.o

$(BUILD_DIR)/Person.o: examples/Person.cpp examples/Shelve.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/Person.cpp -o $(BUILD_DIR)/Person.o

$(BUILD_DIR)/Chef.o: examples/Chef.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/Chef.cpp -o $(BUILD_DIR)/Chef.o

$(BUILD_DIR)/User.o: examples/User.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/User.cpp -o $(BUILD_DIR)/User.o

$(BUILD_DIR)/Shelve.o: examples/Shelve.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/Shelve.cpp -o $(BUILD_DIR)/Shelve.o

$(BUILD_DIR)/Goodeats.o: examples/Goodeats.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/Goodeats.cpp -o $(BUILD_DIR)/Goodeats.o

$(BUILD_DIR)/SignupHandler.o: examples/SignupHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/SignupHandler.cpp -o $(BUILD_DIR)/SignupHandler.o

$(BUILD_DIR)/LoginHandler.o: examples/LoginHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/LoginHandler.cpp -o $(BUILD_DIR)/LoginHandler.o

$(BUILD_DIR)/ChefMenuHandler.o: examples/ChefMenuHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/ChefMenuHandler.cpp -o $(BUILD_DIR)/ChefMenuHandler.o

$(BUILD_DIR)/AddRecipeHandler.o: examples/AddRecipeHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/AddRecipeHandler.cpp -o $(BUILD_DIR)/AddRecipeHandler.o

$(BUILD_DIR)/DeleteRecipeHandler.o: examples/DeleteRecipeHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/DeleteRecipeHandler.cpp -o $(BUILD_DIR)/DeleteRecipeHandler.o

$(BUILD_DIR)/UserMenuHandler.o: examples/UserMenuHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/UserMenuHandler.cpp -o $(BUILD_DIR)/UserMenuHandler.o

$(BUILD_DIR)/RecipeInformationHandler.o: examples/RecipeInformationHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/RecipeInformationHandler.cpp -o $(BUILD_DIR)/RecipeInformationHandler.o

$(BUILD_DIR)/GivingScoreHandler.o: examples/GivingScoreHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/GivingScoreHandler.cpp -o $(BUILD_DIR)/GivingScoreHandler.o

$(BUILD_DIR)/UpdateGivingScoreHandler.o: examples/UpdateGivingScoreHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/UpdateGivingScoreHandler.cpp -o $(BUILD_DIR)/UpdateGivingScoreHandler.o

$(BUILD_DIR)/ChangeScoreHandler.o: examples/ChangeScoreHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/ChangeScoreHandler.cpp -o $(BUILD_DIR)/ChangeScoreHandler.o

$(BUILD_DIR)/UpdateChangeScoreHandler.o: examples/UpdateChangeScoreHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/UpdateChangeScoreHandler.cpp -o $(BUILD_DIR)/UpdateChangeScoreHandler.o

$(BUILD_DIR)/ShelvesMenuHandler.o: examples/ShelvesMenuHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/ShelvesMenuHandler.cpp -o $(BUILD_DIR)/ShelvesMenuHandler.o

$(BUILD_DIR)/AddShelveHandler.o: examples/AddShelveHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/AddShelveHandler.cpp -o $(BUILD_DIR)/AddShelveHandler.o

$(BUILD_DIR)/ShelveInformationHandler.o: examples/ShelveInformationHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/ShelveInformationHandler.cpp -o $(BUILD_DIR)/ShelveInformationHandler.o

$(BUILD_DIR)/AddRecipeToShelveHandler.o: examples/AddRecipeToShelveHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/AddRecipeToShelveHandler.cpp -o $(BUILD_DIR)/AddRecipeToShelveHandler.o

$(BUILD_DIR)/DeleteRecipeFromShelveHandler.o: examples/DeleteRecipeFromShelveHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/DeleteRecipeFromShelveHandler.cpp -o $(BUILD_DIR)/DeleteRecipeFromShelveHandler.o

$(BUILD_DIR)/UpdateAddRecipeToShelveHandler.o: examples/UpdateAddRecipeToShelveHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/UpdateAddRecipeToShelveHandler.cpp -o $(BUILD_DIR)/UpdateAddRecipeToShelveHandler.o

$(BUILD_DIR)/UpdateDeleteRecipeFromShelveHandler.o: examples/UpdateDeleteRecipeFromShelveHandler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/UpdateDeleteRecipeFromShelveHandler.cpp -o $(BUILD_DIR)/UpdateDeleteRecipeFromShelveHandler.o

$(BUILD_DIR)/main.o: examples/main.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c examples/main.cpp -o $(BUILD_DIR)/main.o

goodeats.out: $(BUILD_DIR)/my_server.o $(BUILD_DIR)/main.o $(BUILD_DIR)/Recipe.o $(BUILD_DIR)/Person.o $(BUILD_DIR)/Chef.o $(BUILD_DIR)/User.o $(BUILD_DIR)/Shelve.o $(BUILD_DIR)/Goodeats.o $(BUILD_DIR)/SignupHandler.o $(BUILD_DIR)/LoginHandler.o $(BUILD_DIR)/ChefMenuHandler.o $(BUILD_DIR)/AddRecipeHandler.o $(BUILD_DIR)/DeleteRecipeHandler.o $(BUILD_DIR)/UserMenuHandler.o $(BUILD_DIR)/RecipeInformationHandler.o $(BUILD_DIR)/GivingScoreHandler.o $(BUILD_DIR)/UpdateGivingScoreHandler.o $(BUILD_DIR)/ChangeScoreHandler.o $(BUILD_DIR)/UpdateChangeScoreHandler.o $(BUILD_DIR)/ShelvesMenuHandler.o $(BUILD_DIR)/AddShelveHandler.o $(BUILD_DIR)/ShelveInformationHandler.o $(BUILD_DIR)/AddRecipeToShelveHandler.o $(BUILD_DIR)/DeleteRecipeFromShelveHandler.o $(BUILD_DIR)/UpdateAddRecipeToShelveHandler.o $(BUILD_DIR)/UpdateDeleteRecipeFromShelveHandler.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o
	$(CC) $(CF) $(BUILD_DIR)/my_server.o $(BUILD_DIR)/main.o $(BUILD_DIR)/Recipe.o $(BUILD_DIR)/Person.o $(BUILD_DIR)/Chef.o $(BUILD_DIR)/User.o $(BUILD_DIR)/Shelve.o $(BUILD_DIR)/Goodeats.o $(BUILD_DIR)/SignupHandler.o $(BUILD_DIR)/LoginHandler.o $(BUILD_DIR)/ChefMenuHandler.o $(BUILD_DIR)/AddRecipeHandler.o $(BUILD_DIR)/DeleteRecipeHandler.o $(BUILD_DIR)/UserMenuHandler.o $(BUILD_DIR)/RecipeInformationHandler.o $(BUILD_DIR)/GivingScoreHandler.o $(BUILD_DIR)/UpdateGivingScoreHandler.o $(BUILD_DIR)/ChangeScoreHandler.o $(BUILD_DIR)/UpdateChangeScoreHandler.o $(BUILD_DIR)/ShelvesMenuHandler.o $(BUILD_DIR)/AddShelveHandler.o $(BUILD_DIR)/ShelveInformationHandler.o $(BUILD_DIR)/AddRecipeToShelveHandler.o $(BUILD_DIR)/DeleteRecipeFromShelveHandler.o $(BUILD_DIR)/UpdateAddRecipeToShelveHandler.o $(BUILD_DIR)/UpdateDeleteRecipeFromShelveHandler.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o  -o goodeats.out

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(TEMPLATE_DIR) *.o *.out &> /dev/null
