# Compiler & linker
C             = g++

# Directory
SOURCE_FOLDER = src
OUTPUT_FOLDER = bin

run: build
	$(OUTPUT_FOLDER)/main.exe

build:
	$(C) $(SOURCE_FOLDER)/Breeder/Breeder.cpp -o $(OUTPUT_FOLDER)/Breeder.o
	$(C) $(SOURCE_FOLDER)/Command/Command.cpp -o $(OUTPUT_FOLDER)/Command.o
	$(C) $(SOURCE_FOLDER)/configClass/AnimalConfig.cpp -o $(OUTPUT_FOLDER)/AnimalConfig.o
	$(C) $(SOURCE_FOLDER)/configClass/MainConfig.cpp -o $(OUTPUT_FOLDER)/MainConfig.o
	$(C) $(SOURCE_FOLDER)/configClass/PlantConfig.cpp -o $(OUTPUT_FOLDER)/PlantConfig.o
	$(C) $(SOURCE_FOLDER)/configClass/ProductConfig.cpp -o $(OUTPUT_FOLDER)/ProductConfig.o
	$(C) $(SOURCE_FOLDER)/configClass/RecipeConfig.cpp -o $(OUTPUT_FOLDER)/RecipeConfig.o
	$(C) $(SOURCE_FOLDER)/Customer/Customer.cpp -o $(OUTPUT_FOLDER)/Customer.o
	$(C) $(SOURCE_FOLDER)/Farm/Farm.cpp -o $(OUTPUT_FOLDER)/Farm.o
	$(C) $(SOURCE_FOLDER)/Game/Game.cpp -o $(OUTPUT_FOLDER)/Game.o
	$(C) $(SOURCE_FOLDER)/Grid/Grid.cpp -o $(OUTPUT_FOLDER)/Grid.o
	$(C) $(SOURCE_FOLDER)/Inventory/Inventory.cpp -o $(OUTPUT_FOLDER)/Inventory.o
	$(C) $(SOURCE_FOLDER)/Item/Item.cpp -o $(OUTPUT_FOLDER)/Item.o
	$(C) $(SOURCE_FOLDER)/Item/Animal.cpp -o $(OUTPUT_FOLDER)/Animal.o
	$(C) $(SOURCE_FOLDER)/Item/Building.cpp -o $(OUTPUT_FOLDER)/Building.o
	$(C) $(SOURCE_FOLDER)/Item/Carnivore.cpp -o $(OUTPUT_FOLDER)/Carnivore.o
	$(C) $(SOURCE_FOLDER)/Item/Herbivore.cpp -o $(OUTPUT_FOLDER)/Herbivore.o
	$(C) $(SOURCE_FOLDER)/Item/Omnivore.cpp -o $(OUTPUT_FOLDER)/Omnivore.o
	$(C) $(SOURCE_FOLDER)/Item/Product.cpp -o $(OUTPUT_FOLDER)/Product.o
	$(C) $(SOURCE_FOLDER)/Item/Plant.cpp -o $(OUTPUT_FOLDER)/Plant.o
	$(C) $(SOURCE_FOLDER)/loadconfig/LoadConfig.cpp -o $(OUTPUT_FOLDER)/LoadConfig.o
	$(C) $(SOURCE_FOLDER)/Mayor/Mayor.cpp -o $(OUTPUT_FOLDER)/Mayor.o
	$(C) $(SOURCE_FOLDER)/Player/Player.cpp -o $(OUTPUT_FOLDER)/Player.o
	$(C) $(SOURCE_FOLDER)/Ranch/Ranch.cpp -o $(OUTPUT_FOLDER)/Ranch.o
	$(C) $(SOURCE_FOLDER)/Resident/Resident.cpp -o $(OUTPUT_FOLDER)/Resident.o
	$(C) $(SOURCE_FOLDER)/Store/Store.cpp -o $(OUTPUT_FOLDER)/Store.o
	
clean:
	rm $(OUTPUT_FOLDER)/*.o
	rm $(OUTPUT_FOLDER)/*.exe

uff:
	g++ -o bin/main \
	src/Breeder/Breeder.cpp \
	src/Command/Command.cpp \
	src/configClass/*.cpp \
	src/Customer/Customer.cpp \
	src/Farm/Farm.cpp \
	src/Game/Game.cpp \
	src/Grid/Grid.cpp \
	src/Inventory/Inventory.cpp \
	src/Item/*.cpp \
	src/loadconfig/LoadConfig.cpp \
	src/Mayor/Mayor.cpp \
	src/Player/Player.cpp \
	src/Ranch/Ranch.cpp \
	src/Resident/Resident.cpp \
	src/Store/Store.cpp
	/bin/main