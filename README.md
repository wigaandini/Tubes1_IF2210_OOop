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


## Requirements Program
|   NO   |  Required Program                    |                                         Reference Link                                         |
| :----: | :----------------------------------: | :--------------------------------------------------------------------------------------------: |
|   1    |  C++ Compiler                        | [On Windows](https://www.freecodecamp.org/news/how-to-install-c-and-cpp-compiler-on-windows/), [On Linux](https://www.codespeedy.com/how-to-install-cpp-on-linux/) |
|   2    |  Windows Subsystem for Linux (WSL)   | [WSL](https://learn.microsoft.com/en-us/windows/wsl/install)                                  |
|   3    |  Ubuntu 22.04.3 LTS                  | [Ubuntu](https://ubuntu.com/download/desktop)                                                 |


## How to Run The Program
1. Clone this repository by typing `git clone https://github.com/wigaandini/Tubes1_IF2210_OOop` in the terminal.
2. Change the directory using `cd Tubes1_IF2210_OOop`.
3. Compile and run the program by typing `make run`.


## Project Status
This project has been completed and can be executed.


## Project Structure
```bash

project-root/
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
│   │   └── GridException.hpp
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
│   │   ├── pcolor.c
│   │   └── pcolor.h
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
│   │   └── Resident.hpp
│   │
│   ├── Store/
│   │   ├── Store.cpp
│   │   ├── Store.hpp
│   │   └── StoreException.hpp
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