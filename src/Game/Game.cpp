#include "Game.hpp"
#include <iostream>
// #include <string.h>
#include "../Mayor/Mayor.hpp"
#include "../Player/Player.hpp"
#include "../Breeder/Breeder.hpp"
#include "../Farmer/Farmer.hpp"
#include "../Command/CommandException.hpp"

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

    try
    {
        this->handleLoadConfig();
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
        cout << "Terdapat masalah dalam load config!!" << endl;
        cout << "Silahhkan periksa kembali file config Anda dan silahkan untuk memulai Game kembali dari awal" << endl;
        return;
    }

    this->initializeGame();

    bool isGameOver = false;

    cout << "Selamat Bermain!!" << endl
         << endl;

    Game::setCurrentPlayer(0);
    while (!isGameOver)
    {
        for (unsigned int i = 0; i < players.size(); i++)
        {
            cout << "Sekarang giliran pemain " << Game::getCurrentPlayer()->getName() << " untuk bermain!!" << endl;

            commandHandler.printCommand(Game::getCurrentPlayer());

            bool isNext = false;

            while (!isNext)
            {
                try
                {
                    auto winnner = checkWinner();

                    if (winnner != nullptr)
                    {
                        displayWinner(winnner);
                        isGameOver = true;
                        break;
                    }
                    string input;
                    cout << endl
                         << "> ";
                    cin >> input;
                    if (input == "NEXT")
                    {
                        if (*(Game::getCurrentPlayer()) == *(players[i]))
                        {
                            i++;
                        }
                        handleNext(i);
                        break;
                    }
                    else
                    {
                        this->commandHandler.handleCommand(input);
                    }
                }
                catch (const NoCommandException &e)
                {
                    cout << e.what() << endl
                         << endl;
                    commandHandler.printCommand(Game::getCurrentPlayer());
                }
                catch (const exception &e)
                {
                    cout << e.what() << endl
                         << endl;
                }
            }
            if (isGameOver)
            {
                break;
            }
        }
    }

    cout << "Terima kasih karena telah bermain game kami, silahkan datang kembali di lain waktu." << endl;
}

void Game::displayWinner(shared_ptr<Player> &player)
{
    cout << setfill('*') << setw(50) << "" << endl;
    cout << setfill(' ') << setw(25) << right << "CONGRATULATIONS!" << endl;
    cout << setfill(' ') << setw(27) << right << player->getName() << endl;
    cout << setfill(' ') << setw(25) << right << "YOU WON!" << endl;
    cout << setfill('*') << setw(50) << "" << endl;
}

void Game::setPlayers(vector<shared_ptr<Player>> &tempplayers)
{
    players = tempplayers;
}

void Game::handleLoadConfig()
{
    cout << "LOAD CONFIG..." << endl;
    cout << "LOAD CONFIG..." << endl;
    cout << "LOAD CONFIG..." << endl
         << endl;

    this->loadHandler.loadAnimalConfig("./config/animal.txt");
    this->loadHandler.loadPlantConfig("./config/plant.txt");
    this->loadHandler.loadMainConfig("./config/misc.txt");
    this->loadHandler.loadProductConfig("./config/product.txt");
    this->loadHandler.loadRecipeConfig("./config/recipe.txt");
    store.setUnlimitedAnimalSell();
    store.setUnlimitedPlantSell();

    cout << "Finish Load Config" << endl;
}

void Game::handleNext(int index)
{
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

void Game::handleSave()
{
    string filepath = "";
    cout << "Masukkan lokasi berkas state: ";
    cin >> filepath;

    const char* folderpath = filepath.substr(0, filepath.find_last_of("/\\")).c_str();
    DIR* dir = opendir(folderpath);
    if (dir) {
        closedir(dir);
    } 
    else {
        cerr << "Error: Lokasi berkas tidak valid." << endl;
        return;
    }

    ofstream outFile(filepath);
    if (!outFile.is_open())
    {
        cerr << "Error: Gagal membuka file untuk menambahkan data." << endl;
        return;
    }

    auto players = Game::getPlayers();
    outFile << players.size() << endl;

    for (const auto &player : players)
    {
        if (auto breeder = dynamic_pointer_cast<Breeder>(player))
        {
            breeder->saveFile(filepath);
        }
        else if (auto farmer = dynamic_pointer_cast<Farmer>(player))
        {
            farmer->saveFile(filepath);
        }
        else if (auto mayor = dynamic_pointer_cast<Mayor>(player))
        {
            mayor->saveFile(filepath);
        }
    }

    Game::getStore().saveFile(filepath);

    cout << "State berhasil disimpan ke " << filepath << endl;
    outFile.close();
}

void Game::initializeGame()
{
    bool isAnswerValid = false;
    while (!isAnswerValid)
    {

        string answerState = "";
        cout << "Apakah Anda ingin memulai dengan membaca state? (Y/N) ";
        cin >> answerState;

        if (answerState == "Y")
        {
            this->handleLoadState();
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

            cout << "Finish Preparing The Game!!" << endl;
            isAnswerValid = true;
        }
        else
        {
            cout << "Masukan salah silahkan ulangi kembali!!" << endl;
        }
    }
}

void Game::handleLoadState()
{
    string filename = "";

    bool filenameValid = false;
    while (!filenameValid)
    {
        try
        {
            cout << "Masukan nama file (ketik q untuk keluar): ";
            cin >> filename;
            string fileAddr = "./config/" + filename;
            this->loadHandler.loadStateConfig(fileAddr);

            if (filename == "q")
            {
                cout << "Keluar dari permainan!!" << endl;
                return;
            }

            filenameValid = true;
        }
        catch (const exception &e)
        {
            cout << "Terdapat masalah saat pembacaan file state!!" << endl;
            cout << e.what() << endl;
        }
    }
    cout << endl
         << "LOAD STATE..." << endl;
    cout << "LOAD STATE..." << endl;
    cout << "LOAD STATE..." << endl
         << endl;

    cout << "Finish Load State!!" << endl
         << endl;
}

// cout << "Players in the game:" << endl;
    // for (auto player : players)
    // {
    //     cout << player->getName() << endl;

    //     cout << player->getInventory() << endl;

    //     shared_ptr<Breeder> breeder = dynamic_pointer_cast<Breeder>(player);
    //     if (breeder != nullptr)
    //     {
    //         cout << breeder->getRanch() << endl;
    //         continue;
    //     }

    //     shared_ptr<Farmer> farmer = dynamic_pointer_cast<Farmer>(player);
    //     if (farmer != nullptr)
    //     {
    //         cout << farmer->getFarm() << endl;
    //     }
    // }

    // cout << "Items in the store:" << endl;
    // cout << store << endl;