#include "Farm.hpp"
#include "../Game/Game.hpp"

Farm::Farm(int r, int c) : SpecializedGrid<Plant>(r, c) {}

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
