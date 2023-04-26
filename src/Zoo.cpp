#include "Zoo.h"


void Zoo::stopAnimal(int row, int col) const
{
    Location l(row, col);
    for (const auto& animal : animals) {
        if (animal->getLocation() == l)
            animal->stop();
    }
}

void Zoo::moveAnimal(int row, int col) const
{
    Location l(row, col);
    for (const auto& animal : animals) {
        if (animal->getLocation() == l)
            if (!animal->getIsMoveing())
                animal->move();
    }
}

void Zoo::stepAllAnimals()
{
    for (const auto& animal : animals) {
        animal->step();
    }
}

Zoo::Zoo()
{
    std::srand(std::time(nullptr)); // seed the random number generator with the current time
}
void Zoo::run() {

    initZoo();

    printTable();

    printAnimals();

    for (int i = 0; i < 5; i++)
    {
        stepAllAnimals();
        printTable();
        printAnimals();
    }
 
    deleteAnimalsOfType("Owl");

    printTable();

    printAnimals();

}

void Zoo::addAnimal(std::unique_ptr<Animal> animal)
{
    animals.push_back(std::move(animal)); 
}

void Zoo::removeAnimal(const int row, const int col)
{
    Location l(row, col);
    for (auto it = animals.begin(); it != animals.end(); ++it) {
        if ((*it)->getLocation() == l) {
            animals.erase(it);
            return;
        }
    }
}

void Zoo::deleteAnimalsOfType(const std::string& type)
{
    animals.erase(std::remove_if(animals.begin(), animals.end(), [type](const std::unique_ptr<Animal>& animal) {
        return animal->getType() == type;
    }), animals.end());
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

void Zoo::printAnimals() const
{
    std::cout << "The zoo contains:" << std::endl;
    for (const auto& animal : animals) {
        animal->printDetails();
        std::cout << std::endl;
    }
}

std::unique_ptr<Animal> Zoo::createAnimal(const std::string& kind, const std::string& name)
{
    std::unique_ptr<Animal> animal;
    if (kind == "Owl") {
        animal = std::make_unique<Owl>(name);
    }
    else if (kind == "Monkey") {
        animal = std::make_unique<Monkey>(name);
    }
    else if (kind == "Lion") {
        animal = std::make_unique<Lion>(name);
    }
    else {
        return nullptr;
    }
    return animal;
}

void Zoo::initZoo()
{
    std::string animalType;
    std::string animalName;

    animalType = "Owl";
    animalName = "Hedwig";
    animals.emplace_back(createAnimal(animalType, animalName));

    animalType = "Lion";
    animalName = "Simba";
    animals.emplace_back(createAnimal(animalType, animalName));

    animalType = "Monkey";
    animalName = "Rafiki";
    animals.emplace_back(createAnimal(animalType, animalName));

    animalType = "Owl";
    animalName = "Erol";
    animals.emplace_back(createAnimal(animalType, animalName));

    animalType = "Lion";
    animalName = "Nala";
    animals.emplace_back(createAnimal(animalType, animalName));

    animalType = "Monkey";
    animalName = "Tarzan";
    animals.emplace_back(createAnimal(animalType, animalName));

}



void Zoo::printTable()
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

