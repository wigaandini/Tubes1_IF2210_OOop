#include "Game.hpp"
#include <iostream>
// #include <string.h>
#include "../Mayor/Mayor.hpp"
#include "../Player/Player.hpp"
#include "../Breeder/Breeder.hpp"
#include "../Farmer/Farmer.hpp"

map<string, AnimalConfig> Game::animalConfig;
map<string, PlantConfig> Game::plantConfig;
map<string, RecipeConfig> Game::recipe;
map<string, ProductConfig> Game::productConfig;
MainConfig Game::mainConfig;
vector<shared_ptr<Player>> Game::players;
shared_ptr<Player> Game::currentPlayer = nullptr;
Store Game::store;

Game::Game()
{
}

Game::~Game()
{
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
shared_ptr<Player> &Game::getCurrentPlayer()
{
    return currentPlayer;
}

Store &Game::getStore()
{
    return store;
}

vector<shared_ptr<Player>> &Game::getPlayers()
{
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

void Game::setCurrentPlayer(int index)
{
    currentPlayer = (players[index]);
}

void Game::start()
{
    cout << "WELCOME TO THE GAME" << endl
         << endl;

    handleLoadConfig();

    cout << "LOAD CONFIG..." << endl;
    cout << "LOAD CONFIG..." << endl;
    cout << "LOAD CONFIG..." << endl
         << endl;

    cout << "Finish Load Config" << endl;

    bool isAnswerValid = false;
    while (!isAnswerValid)
    {

        string answerState = "";
        cout << "Apakah Anda ingin memulai dengan membaca state? (Y/N) ";
        cin >> answerState;

        if (answerState == "Y")
        {

            this->configHandler.loadStateConfig("../config/state.txt");
            isAnswerValid = true;
        }
        else if (answerState == "N")
        {
            auto petani1 = make_shared<Farmer>("Petani1", 40, 50);
            auto peternak1 = make_shared<Breeder>("Peternak1", 40, 50);
            auto walikota = make_shared<Mayor>("Walikota", 40, 50);

            players.push_back(petani1);
            players.push_back(peternak1);
            players.push_back(walikota);

            isAnswerValid = true;
        }
        else
        {
            cout << "Masukan salah silahkan ulangi kembali!!" << endl;
        }
    }

    cout << "Players in the game:" << endl;
    for (auto player : players)
    {
        cout << player->getName() << endl;

        cout << player->getInventory() << endl;

        shared_ptr<Breeder> breeder = dynamic_pointer_cast<Breeder>(player);
        if (breeder != nullptr)
        {
            cout << breeder->getRanch() << endl;
            continue;
        }

        shared_ptr<Farmer> farmer = dynamic_pointer_cast<Farmer>(player);
        if (farmer != nullptr)
        {
            cout << farmer->getFarm() << endl;
        }
    }

    cout << "Items in the store:" << endl;
    cout << store << endl;
    bool isGameOver = false;

    cout << "Selamat Bermain!!" << endl << endl;

    Game::setCurrentPlayer(0);
    while (!isGameOver)
    {
        for (unsigned int i = 0; i < players.size(); i++)
        {
            cout << "Sekarang giliran pemain " << Game::getCurrentPlayer()->getName() << " untuk bermain!!" << endl;
            
            commandHandler.printCommand(Game::getCurrentPlayer());

            string input;
            cout << "> ";
            cin >> input;
            if (input == "NEXT")
            {
                if (Game::getCurrentPlayer()->getName() == players[i]->getName())
                {
                    i++;
                }
                handleNext(i);
                // break;
            }
            else if (this->commandHandler.checkCommand(input))
            {
                this->commandHandler.handleCommand(input);
            }
            else
            {
                cout << "Tidak ada command tersebut!!" << endl << endl;
            }
        }

        auto winnner = checkWinner();

        if (winnner != nullptr)
        {
            cout << "Selamat pemain " << winnner->getName() << " telah memenangkan permainan!!" << endl;
            isGameOver = true;
        }
    }
}

void Game::setPlayers(vector<shared_ptr<Player>> &tempplayers)
{
    players = tempplayers;
}

void Game::handleLoadConfig()
{
    try
    {

        this->configHandler.loadAnimalConfig("../config/animal.txt");
        this->configHandler.loadPlantConfig("../config/plant.txt");
        this->configHandler.loadMainConfig("../config/misc.txt");
        this->configHandler.loadProductConfig("../config/product.txt");
        this->configHandler.loadRecipeConfig("../config/recipe.txt");
        store.setUnlimitedAnimalSell();
        store.setUnlimitedPlantSell();
    }
    catch (exception &e)
    {
        cout << "Terdapat masalah dalam load config!!" << endl;
    }
}

void Game::handleNext(int index)
{
    // cout << index << endl;
    setCurrentPlayer(index);
    for (auto &player : players)
    {
        shared_ptr<Farmer> farmer = dynamic_pointer_cast<Farmer>(player);
        if (farmer != nullptr)
        {

            farmer->getFarm().addPlantAge();
        }
    }
}

shared_ptr<Player> Game::checkWinner()
{
    for (auto &player : players)
    {
        if (player->getGulden() >= mainConfig.guldenForWin && player->getWeight() >= mainConfig.weightPlayerToWin)
        {
            return player;
        }
    }

    return nullptr;
}
