#include "Zoo.h"

//Location Zoo::random()
//{
//    int row = std::rand() % 20; // random number between 0 and 20
//    int col = std::rand() % 40; // random number between 0 and 40
//    
//    return Location(row, col);
//}

void Zoo::stopAnmal(int row, int col) const
{
    Location l(row, col);
    for (const auto& animal : animals) {
        if (animal->getLocation() == l)
            animal->stop();
    }
}

void Zoo::moveAnmal(int row, int col) const
{
    Location l(row, col);
    for (const auto& animal : animals) {
        if (animal->getLocation() == l)
            if (!animal->getIsMoveing())
                animal->move();
    }
}

Zoo::Zoo()
{
    std::srand(std::time(nullptr)); // seed the random number generator with the current time
}
void Zoo::run() {
    //std::unique_ptr<Animal> animal;// = std::make_unique<Owl>("Hedwig");
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

    //animal = creatAnimal(animalType, animalName);
    //addAnimal(std::move(animal));

    //animal = std::make_unique<Lion>("simba");
    //addAnimal(std::move(animal));

    //animal = std::make_unique<Monkey>("Rafiki");
    //addAnimal(std::move(animal));
    //std::unique_ptr<Lion> lion = std::make_unique<Lion>("Simba");
    //addAnimal(std::move(lion));

    //std::unique_ptr<Monkey> monkey = std::make_unique<Monkey>("Rafiki");
    //addAnimal(std::move(monkey));
    //
    //std::unique_ptr<Owl> owl1 = std::make_unique<Owl>("Erol");
    //addAnimal(std::move(owl1));

    //std::unique_ptr<Lion> lion1 = std::make_unique<Lion>("Nala");
    //addAnimal(std::move(lion1));

    //std::unique_ptr<Monkey> monkey1 = std::make_unique<Monkey>("Tarzan");
    //addAnimal(std::move(monkey1));

    printTable(animals);

    printAnimals();
    for (auto it = animals.begin(); it != animals.end(); ++it) {
        (*it)->move();
        (*it)->step();
    }
    printTable(animals);

    printAnimals();

    removeAnimal("Hedwig");


    printAnimals();

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

//void Zoo::printDirection(const Animal& a)
//{
//    std::cout << "direction " << a.getName() << " : " << a.getDirection() << std::endl;
//}

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

