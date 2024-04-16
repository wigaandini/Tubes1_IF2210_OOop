<h1 align="center"> Tugas Besar 1 </h1>
<h2 align="center"> IF2210 Pemrograman Berorientasi Objek </h2>


## Table of Contents
1. [General Information](#general-information)
2. [Features](#features)
3. [Requirements Program](#required_program)
4. [How to Run The Program](#how-to-run-the-program)
5. [Project Status](#project-status)
6. [Project Structure](#project-structure)
7. [Contributors](#contributors)


## General Information
This program is a simple simulation designed to help Roro manage her kingdom. Bondowoso, her husband, wants to create this game to ensure that Roro has the necessary skills to govern their kingdom effectively. Despite Bondowoso's limited understanding of object-oriented programming concepts, we will assist him in creating this game using the C++ programming language. The game will simulate various aspects of kingdom management, taking into account the characteristics of the society within the kingdom. Its goal is to teach players how to manage resources, make policy decisions, and prioritize the happiness and well-being of the kingdom's populace.


## Features
Features (command) that used in this program are:
| No. | Command              | Description                                                      |
|-----|----------------------|------------------------------------------------------------------|
| 1   | CETAK_PENYIMPANAN    | Player can display their storage                                |
| 2   | MAKAN                | Player can eat food from their storage                          |
| 3   | SIMPAN               | Player can save the current state of the program                |
| 4   | JUAL                 | Player can sell the items from their storage                    |
| 5   | BELI                 | Player can buy items from the store and then keep it in storage |
| 6   | PERMAINAN_SLOT       | Player can play a slot game                                     |
| 7   | TANAM                | Player (only farmer) can plant the plants they own              |
| 8   | CETAK_LADANG         | Player (only farmer) can display their farm                     |
| 9   | TERNAK               | Player (only breeder) can cattle their animals                  |
| 10  | CETAK_PETERNAKAN     | Player (only breeder) can display their ranch                   |
| 11  | KASIH_MAKAN          | Player (only breeder) can feed their livestock (animals)        |
| 12  | PANEN                | Player (farmer and breeder) can harvest their products          |
| 13  | TAMBAH_PEMAIN        | Player (only mayor) can add a new player                        |
| 14  | PUNGUT_PAJAK         | Player (only mayor) can tax the residents (farmers and breeders)|
| 15  | BANGUN_BANGUNAN      | Player (only mayor) can build a building using materials        |
| 16  | NEXT                 | Switch the player's turn                                        |


## Requirements Program
|   NO   |  Required Program                    |                                         Reference Link                                         |
| :----: | :----------------------------------: | :--------------------------------------------------------------------------------------------: |
|   1    |  C++ Compiler                        | [On Windows](https://www.freecodecamp.org/news/how-to-install-c-and-cpp-compiler-on-windows/) <br> [On Linux](https://www.codespeedy.com/how-to-install-cpp-on-linux/) |
|   2    |  UNIX based terminal, if use OS Windows can use Windows Subsystem for Linux (WSL)    | [WSL](https://learn.microsoft.com/en-us/windows/wsl/install)        
|   3    |  Ubuntu 22.04.3 LTS                  | [Ubuntu](https://ubuntu.com/download/desktop)                                                 |


## How to Run The Program
1. Clone this repository by typing `git clone https://github.com/wigaandini/Tubes1_IF2210_OOop` in the terminal.
2. Change the directory using `cd Tubes1_IF2210_OOop`.
3. Compile and run the program by typing `make run`.
4. Note: Ensure to always prefix the file path with ./ when use command "SIMPAN" and when use load state.


## Project Status
This project has been completed and can be executed.


## Project Structure
```bash

│
├── README.md
├── bin/                        # Executable compiled program
│
├── config/                     # Configuration files
│   ├── animal.txt
│   ├── misc.txt
│   ├── plant.txt
│   ├── product.txt
│   └── recipe.txt  
│
├── doc/                        # Document files
│   ├── IF2110_TB1_SMH.pdf
│
├── src/                        # Source code files
│   ├── Breeder/                
│   │   ├── Breeder.cpp
│   │   └── Breeder.hpp
│   │
│   ├── Command/                
│   │   ├── Command.cpp
│   │   ├── Command.hpp
│   │   └── CommandException.hpp
│   │
│   ├── configClass/
│   │   ├── AnimalConfig.cpp
│   │   ├── AnimalConfig.hpp
│   │   ├── MainConfig.cpp
│   │   ├── MainConfig.hpp
│   │   ├── PlantConfig.cpp
│   │   ├── PlantConfig.hpp
│   │   ├── ProductConfig.cpp
│   │   ├── ProductConfig.hpp
│   │   ├── RecipeConfig.cpp
│   │   └── RecipeConfig.hpp
│   │
│   ├── Farm/
│   │   ├── Farm.cpp
│   │   └── Farm.hpp
│   │
│   ├── Farmer/
│   │   ├── Farmer.cpp
│   │   └── Farmer.hpp
│   │
│   ├── Game/
│   │   ├── Game.cpp
│   │   └── Game.hpp
│   │
│   ├── Grid/
│   │   ├── Grid.hpp
|   |   ├── Grid.tpp
│   │   └── GridException.hpp
|   |   
│   │
│   ├── Harvester/
│   │   ├── Harvester.hpp
│   │   └── Harvester.cpp
│   │
│   ├── Inventory/
│   │   ├── Inventory.cpp
│   │   └── Inventory.hpp
│   │
│   ├── Item/
│   │   ├── Animal.cpp
│   │   ├── Animal.hpp
│   │   ├── AnimalException.hpp
│   │   ├── Building.cpp
│   │   ├── Building.hpp
│   │   ├── Carnivore.cpp
│   │   ├── Carnivore.hpp
│   │   ├── Herbivore.cpp
│   │   ├── Herbivore.hpp
│   │   ├── Item.cpp
│   │   ├── Item.hpp
│   │   ├── Omnivore.cpp
│   │   ├── Omnivore.hpp
│   │   ├── Plant.cpp
│   │   ├── Plant.hpp
│   │   ├── Product.cpp
│   │   └── Product.hpp
│   │
│   ├── loadhandler/
│   │   ├── LoadException.hpp
│   │   ├── LoadHandler.cpp
│   │   └── LoadHandler.hpp
│   │
│   ├── Mayor/
│   │   ├── Mayor.cpp
│   │   ├── Mayor.hpp
│   │   └── MayorException.hpp
│   │
│   ├── PColor/
│   │   ├── pcolor.cpp
│   │   └── pcolor.hpp
│   │
│   ├── Player/
│   │   ├── Player.cpp
│   │   ├── Player.hpp
│   │   └── PlayerException.hpp
│   │
│   ├── Ranch/
│   │   ├── Ranch.cpp
│   │   └── Ranch.hpp
│   │
│   ├── Resident/
│   │   ├── Resident.cpp
|   |   ├── Resident.tpp
│   │   └── Resident.hpp
│   │
│   ├── Slot/
│   │   ├── Slot.cpp
│   │   ├── Slot.hpp
│   │
│   ├── Store/
│   │   ├── Store.cpp
│   │   ├── Store.hpp
│   │   └── StoreException.hpp
│   │
│   ├── SpecializedGrid/
│   │   ├── SpecializedGrid.hpp
|   |   └── SpecializedGrid.tpp
│   │
│   ├── Utils/
│   │   ├── Utils.cpp
│   │   └── Utils.hpp
│   │
│   └── main.cpp                # Main program
│
└── makefile                    # Makefile for building the project                                      
        
```


## Contributors
### **Kelompok OOop**
|   NIM    |                  Nama                  |
| :------: | :------------------------------------: |
| 13522053 |       Erdianti Wiga Putri Andini       |
| 13522055 |                Benardo                 |
| 13522113 |        William Glory Henderson         |
| 13522115 |            Derwin Rustanly             |
| 13522117 |          Mesach Harmasendro            |
| 10023575 |       Renny Melanda Febriyanti         |
