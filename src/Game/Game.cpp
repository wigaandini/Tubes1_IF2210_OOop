#include "Game.hpp"
#include <string.h>
#include "../Mayor/Mayor.hpp"

map<string, AnimalConfig> Game::animalConfig;
map<string, PlantConfig> Game::plantConfig;
map<string, RecipeConfig> Game::recipe;
map<string, ProductConfig> Game::productConfig;
MainConfig Game::mainConfig;
vector<Player> Game::players;
Player &Game::currentPlayer = *(new Mayor());
Store Game::store;

Game::Game()
{
    Mayor mayor;

    players.push_back(mayor);

}

map<string, AnimalConfig> &Game::getAnimalConfig()
{
    return animalConfig;
}

map<string, PlantConfig> &Game::getPlantConfig()
{
    return plantConfig;
}

map<string, RecipeConfig> &Game::getRecipe()
{
    return recipe;
}

MainConfig &Game::getMainConfig(){
    return mainConfig;
}


map<string, ProductConfig> &Game::getProductConfig()
{
    return productConfig;
}
Player &Game::getCurrentPlayer(){
    return currentPlayer;
}


Store &Game::getStore()
{
    return store;
}

void Game::setAnimalConfig(const map<string, AnimalConfig> &config)
{
    animalConfig = config;
}

void Game::setPlantConfig(const map<string, PlantConfig> &config)
{
    plantConfig = config;
}

void Game::setRecipe(const map<string, RecipeConfig> &config)
{
    recipe = config;
}

void Game::setProductConfig(const map<string, ProductConfig> &config)
{
    productConfig = config;
}

void Game::setMainConfig(const MainConfig &config)
{
    mainConfig = config;
}

void Game::setCurrentPlayer(int index){
    currentPlayer = players[index];
}

void Game::mainLoop()
{
    cout << "WELCOME TO THE GAME" << endl
         << endl;

    // this->configHandler.loadAnimalConfig("animal.txt");
    // this->configHandler.loadPlantConfig("plant.txt");
    // this->configHandler.loadMainConfig("misc.txt");
    // this->configHandler.loadProductConfig("product.txt");
    // this->configHandler.loadRecipeConfig("recipe.txt");

    cout << "LOAD CONFIG..." << endl;
    cout << "LOAD CONFIG..." << endl;
    cout << "LOAD CONFIG..." << endl
         << endl;

    cout << "Finish Load Config" << endl;

    bool isGameOver = false;

    Game::setCurrentPlayer(0);
    while (!isGameOver)
    {
        string input;
        cout << "> ";
        cin >> input;
        if (this->commandHandler.checkCommand(input)){
            this->commandHandler.handleCommand(input);
        }
    }
}