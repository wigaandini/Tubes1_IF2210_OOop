#include "Ranch.hpp"
#include "../Game/Game.hpp"

Ranch::Ranch(int r, int c) : SpecializedGrid<Animal>(r, c) {}

Ranch::~Ranch() {}

Ranch::Ranch() : SpecializedGrid<Animal>(Game::getMainConfig().ranchSize[0], Game::getMainConfig().ranchSize[1])
{
}

void Ranch::displayStorage(bool printInfo)
{

    SpecializedGrid::displayStorage("Peternakan");
    if (printInfo)
    {
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                if (this->buffer[i][j] != nullptr)
                {
                    if (this->buffer[i][j]->getAnimalId() != -1)
                    {
                        if (i < 10)
                        {
                            cout << "- " << char('A' + j) << '0' << i + 1 << ": " << this->buffer[i][j]->getName() << endl;
                        }
                        else
                        {
                            cout << "- " << char('A' + j) << i + 1 << ": " << this->buffer[i][j]->getName() << endl;
                        }
                    }
                }
            }
        }
    }
}

// bool Ranch::checkAnimalReadyToHarvest()
// {
//     for (int i = 0; i < this->getRow(); i++)
//     {
//         for (int j = 0; j < this->getCol(); j++)
//         {
//             if (this->buffer[i][j] != nullptr)
//             {
//                 if (this->buffer[i][j]->checkReadyToHarvest())
//                 {
//                     return true;
//                 }
//             }
//         }
//     }
//     return false;
// }

// map<string, int> Ranch::countAnimal()
// {
//     map<string, int> animalCount;
//     for (int i = 0; i < this->getRow(); i++)
//     {
//         for (int j = 0; j < this->getCol(); j++)
//         {
//             if (this->buffer[i][j] != nullptr)
//             {
//                 if (this->buffer[i][j]->checkReadyToHarvest())
//                 {
//                     string animalName = this->buffer[i][j]->getName();
//                     if (animalCount.find(animalName) == animalCount.end())
//                     {
//                         animalCount[animalName] = 1;
//                     }
//                     else
//                     {
//                         animalCount[animalName]++;
//                     }
//                 }
//             }
//         }
//     }

//     return animalCount;
// }

int Ranch::countAnimalType()
{
    map<string, int> animalCount = countItemsReadyToHarvest();
    return animalCount.size();
}