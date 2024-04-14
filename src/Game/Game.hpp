#ifndef _GAME_HPP_
#define _GAME_HPP_


#include "../loadhandler/LoadHandler.hpp"
#include "../Command/Command.hpp"
#include "../Player/Player.hpp"
#include <memory>

using namespace std;

class Game
{
private:
    static map<string, AnimalConfig> animalConfig;
    static map<string, PlantConfig> plantConfig;
    static map<string, RecipeConfig> recipe;
    static map<string, ProductConfig> productConfig;
    static MainConfig mainConfig;
    static vector<shared_ptr<Player>> players;
    static shared_ptr<Player> currentPlayer;
    LoadHandler loadHandler;
    Command commandHandler;

    static Store store;

public:
    Game();
    ~Game();
    static map<string, AnimalConfig> &getAnimalConfig();
    static map<string, PlantConfig> &getPlantConfig();
    static map<string, RecipeConfig> &getRecipe();
    static map<string, ProductConfig> &getProductConfig();
    static MainConfig &getMainConfig();
    static vector<shared_ptr<Player>>& getPlayers();
    static shared_ptr<Player>& getCurrentPlayer();
    static Store &getStore();
    static void setAnimalConfig(const map<string, AnimalConfig> &);
    static void setPlantConfig(const map<string, PlantConfig> &);
    static void setRecipe(const map<string, RecipeConfig> &);
    static void setProductConfig(const map<string, ProductConfig> &);
    static void setMainConfig(const MainConfig &);
    static void setPlayers(vector<shared_ptr<Player>> &);
    static void setCurrentPlayer(int);
    void start();
    static void handleSave();
    void handleLoadState();
    void initializeGame();
    void handleLoadConfig();
    static void handleNext(int);
    void displayWinner(shared_ptr<Player>&);
    static shared_ptr<Player> checkWinner();
};

#endif
