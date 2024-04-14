#include "Farm.hpp"
#include "../Game/Game.hpp"

Farm::Farm(int r, int c, Plant defaultValue) : SpecializedGrid<Plant>(r, c) {}

Farm::Farm() : SpecializedGrid<Plant>(Game::getMainConfig().farmSize[0], Game::getMainConfig().farmSize[1])
{
}

Farm::~Farm() {}

void Farm::displayStorage(bool printInfo)
{
    SpecializedGrid::displayStorage("Ladang");
    if (printInfo)
    {
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                if (this->buffer[i][j] != nullptr)
                {
                    if (this->buffer[i][j]->getPlantId() != -1)
                    {
                        cout << "- " << this->buffer[i][j]->getCode() << ": " << this->buffer[i][j]->getName() << endl;
                    }
                }
            }
        }
    }
}

// bool Farm::checkPlantReadyToHarvest()
// {
//     for (int i = 0; i < this->row; i++)
//     {
//         for (int j = 0; j < this->col; j++)
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

// map<string, int> Farm::countPlant()
// {
//     map<string, int> plantCount;
//     for (int i = 0; i < this->row; i++)
//     {
//         for (int j = 0; j < this->col; j++)
//         {
//             if (this->buffer[i][j] != nullptr)
//             {
//                 if (this->buffer[i][j]->checkReadyToHarvest())
//                 {
//                     string plantName = this->buffer[i][j]->getName();
//                     if (plantCount.find(plantName) == plantCount.end())
//                     {
//                         plantCount[plantName] = 1;
//                     }
//                     else
//                     {
//                         plantCount[plantName]++;
//                     }
//                 }
//             }
//         }
//     }
//     return plantCount;
// }

void Farm::addPlantAge()
{
    for (int i = 0; i < this->row; i++)
    {
        for (int j = 0; j < this->col; j++)
        {
            if (this->buffer[i][j] != nullptr)
            {

                if (!this->buffer[i][j]->checkReadyToHarvest())
                {
                    ++(*(this->buffer.at(i).at(j)));
                }
            }
        }
    }
}
