#include "Game.hpp"
#include <string.h>
#include "../Mayor/Mayor.hpp"
#include "../Player/Player.hpp"
#include "../Breeder/Breeder.hpp"
#include "../Farmer/Farmer.hpp"

map<string, AnimalConfig> Game::animalConfig;
map<string, PlantConfig> Game::plantConfig;
map<string, RecipeConfig> Game::recipe;
map<string, ProductConfig> Game::productConfig;
MainConfig Game::mainConfig;
vector<shared_ptr<Player>> Game::players ;
Player &Game::currentPlayer = *(new Mayor());
Store Game::store;

Game::Game()
{
    players.push_back(make_shared<Mayor>());

}

Game::~Game(){
    
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

MainConfig &Game::getMainConfig()
{
    return mainConfig;
}

map<string, ProductConfig> &Game::getProductConfig()
{
    return productConfig;
}
Player &Game::getCurrentPlayer()
{
    return currentPlayer;
}

Store &Game::getStore()
{
    return store;
}

vector<shared_ptr<Player>> &Game::getPlayers(){
    return players;
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
    currentPlayer = *(players[index]);
}

void Game::mainLoop()
{
    cout << "WELCOME TO THE GAME" << endl
         << endl;

    this->configHandler.loadAnimalConfig("../config/animal.txt");
    cout << "1" << endl;
    this->configHandler.loadPlantConfig("../config/plant.txt");
    cout << "1" << endl;
    this->configHandler.loadMainConfig("../config/misc.txt");
    cout << "1" << endl;
    this->configHandler.loadProductConfig("../config/product.txt");
    cout << "1" << endl;
    this->configHandler.loadRecipeConfig("../config/recipe.txt");
    cout << "5" << endl;

    cout << "10" << endl;

    // cout << mainConfig.ranchSize[0] << mainConfig.ranchSize[1];
    // cout << "dad";
    this->configHandler.loadStateConfig("../config/state.txt");
    // cout << "1" << endl;

    cout << "LOAD CONFIG..." << endl;
    cout << "LOAD CONFIG..." << endl;
    cout << "LOAD CONFIG..." << endl
         << endl;

    cout << "Finish Load Config" << endl;

    std::cout << "Players in the game:" << std::endl;
    for (auto player : players)
    {
        std::cout << player->getName() << std::endl;

        std::cout << player->getInventory() << std::endl;


        shared_ptr<Breeder> breeder = dynamic_pointer_cast<Breeder>(player);
        if (breeder != nullptr) {
            // The player is a Breeder, so we can safely call getRanch
            cout << breeder->getRanch() << endl;
            continue; // Move to the next player
        }

        // Try to cast player to Farmer
        shared_ptr<Farmer> farmer = dynamic_pointer_cast<Farmer>(player);
        if (farmer != nullptr) {
            // The player is a Farmer, so we can safely call getFarm
            cout << farmer->getFarm() << endl;
        }
    }

    std::cout << "Items in the store:" << std::endl;
    for (const auto& pair : this->store.getItems()) {
        std::cout << "Category: " << pair.first << std::endl;
        for (const auto& item : pair.second) {
            std::cout << " - " << item->getName() << std::endl;
        }
    }
    // bool isGameOver = false;

    // Game::setCurrentPlayer(0);
    // while (!isGameOver)
    // {
    //     string input;
    //     cout << "> ";
    //     cin >> input;
    //     if (this->commandHandler.checkCommand(input))
    //     {
    //         this->commandHandler.handleCommand(input);
    //     }

    //     Game::setCurrentPlayer(1);
    // }
}

void Game::setPlayers(vector<shared_ptr<Player>> &tempplayers)
{
    players = tempplayers;
}

