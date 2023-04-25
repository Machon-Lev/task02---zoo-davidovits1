#include "Zoo.h"

Location Zoo::random()
{
    int row = std::rand() % 20; // random number between 0 and 20
    int col = std::rand() % 40; // random number between 0 and 40
    
    return Location(row, col);
}

Zoo::Zoo()
{
    std::srand(std::time(nullptr)); // seed the random number generator with the current time
}
void Zoo::run() {
    Location l = random();
    std::unique_ptr<Owl> owl = std::make_unique<Owl>("Hedwig", l);
    addAnimal(std::move(owl));
    
    l = random();

    std::unique_ptr<Owl> owl1 = std::make_unique<Owl>("erol", l);
    

    addAnimal(std::move(owl1));
    printTable(animals);

    printAnimals();
    for (auto it = animals.begin(); it != animals.end(); ++it) {
        (*it)->move();
    }
    printTable(animals);

    printAnimals();

    removeAnimal("Hedwig");


    printAnimals();


    //Owl owl("erol", Location(1, 3));
    //addAnimal(owl);


    //std::cout << "\nRemoving second animal (index 1):\n";
    //removeAnimal(1);

    //// Print all animals again
    //std::cout << "\nAll animals in the zoo after removing one:\n";
    //printAllAnimals();
    //addAnimal()
    //addAnimal(std::make_unique<Owl>("Errol"));
    //printAnimals();
    //removeAnimal(0);
    //printAnimals();

}

void Zoo::addAnimal(std::unique_ptr<Animal> animal)
{
    animals.push_back(std::move(animal)); 
}

void Zoo::removeAnimal(int index)
{
    animals.erase(animals.begin() + index);
}

void Zoo::removeAnimal(const std::string& name)
{
    for (auto it = animals.begin(); it != animals.end(); ++it) {
        if ((*it)->getName() == name) {
            animals.erase(it);
            return;
        }
    }

}

void Zoo::printTable(const std::vector<std::unique_ptr<Animal>>& animals)
{
    const int ROWS = 20;
    const int COLS = 40;

    char table[ROWS][COLS];

    // Initialize table with spaces
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            table[i][j] = ' ';
        }
    }

    // Fill table with animal locations
    for (const auto& animal : animals) {
        //int row = animal->getLocation().getRow();
        //int col = animal->getLocation().getCol();
        Location l = animal->getLocation();
        table[l.row][l.col] = animal->getInitial();
    }

    // Print table
    std::cout << std::setw(3) << " ";
    for (int j = 0; j < COLS; j++) {
        std::cout << std::setw(2) << j << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < ROWS; i++) {
        std::cout << std::setw(2) << i << " ";
        for (int j = 0; j < COLS; j++) {
            std::cout << " " << table[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

