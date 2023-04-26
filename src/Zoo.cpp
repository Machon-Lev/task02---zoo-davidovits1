#include "Zoo.h"


void Zoo::stopAnimal(int row, int col) const
{
    Location l(row, col);
    for (const auto& animal : animals) {
        if (animal->getLocation() == l)
        {
            animal->stop();
        }
    }
}

void Zoo::moveAnimal(int row, int col) const
{
    Location l(row, col);
    for (const auto& animal : animals) {
        if (animal->getLocation() == l) {
            animal->move();
        }
           // if (!animal->getIsMoveing())
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
    std::string input = "start";
    int row, col;
    std::string animalType, animalName;
    while (input != "exit")
    {
        printTable();
        printAnimals();
        printCommandNames();

        std::cin >> input;

        if (input == "stop") {
            std::cout << "Enter a row and column number\n";
            std::cin >> row;
            std::cin >> col;
            stopAnimal(row, col);
        }
        else if (input == "move") {
            std::cout << "Enter a row and column number\n";
            std::cin >> row;
            std::cin >> col;
            moveAnimal(row, col);
        }
        else if (input == "create") {
            std::cout << "Enter the type of animal\n";
            std::cin >> animalType;
            std::cout << "Enter the name of animal\n";
            std::cin >> animalName;
            animals.emplace_back(createAnimal(animalType, animalName));
        }
        else if (input == "del") {
            std::cout << "Enter a row and column number\n";
            std::cin >> row;
            std::cin >> col;
            removeAnimal(row, col);
        }
        else if (input == "delAll") {
            std::cout << "Enter the type of animal\n";
            std::cin >> animalType;
            deleteAnimalsOfType(animalType);
        }
        else if (input == "help") {
            printMenu();
        }
        else if (input == "exit") {
            break;
        }
        else if (input == ".") {
           
        }
        else {
            std::cout << "Invalid command\n";
        }
        stepAllAnimals();

    }


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

void Zoo::printMenu()
{
    std::cout << "Possible commands: " << std::endl;
    std::cout << "STOP - make the animal stop. The command will receive as a parameter the number of the animal (as it appears in the list)." << std::endl;
    std::cout << "MOVE - make the animal move. The command will receive as a parameter the number of the animal (as it appears in the list)." << std::endl;
    std::cout << "CREATE - creating another animal The command will receive as parameters the type of animal and a name for it. The location of the animal will be drawn random." << std::endl;
    std::cout << "DEL - delete an animal from the list. Receives as a parameter the number of the animal (as it appears in the list)." << std::endl;
    std::cout << "DEL_ALL - deletion of all animals of a certain type." << std::endl;
    std::cout << "HELP - printing help text that explains what the possible commands are, what their parameters are and what they do." << std::endl;
    std::cout << "EXIT - exit from the program." << std::endl;
    std::cout << "DOT - This command will be used to make the program advance to the next line, without changing anything." << std::endl;
}

void Zoo::printCommandNames()
{
    std::string f = "\033[1;31m";
    std::string e = "\033[0m";
    std::cout << f + "Available commands:" + e << std::endl;
    std::cout << f + "stop <animal_number>" + e << std::endl;
    std::cout << f + "move <animal_number>" + e << std::endl;
    std::cout << f + "create <animal_type> <animal_name>" + e << std::endl;
    std::cout << f + "del <animal_number>" + e << std::endl;
    std::cout << f + "delAll <animal_type>" + e << std::endl;
    std::cout << f + "help" + e << std::endl;
    std::cout << f + "exit" + e << std::endl;
    std::cout << f + ". <continu>" + e << std::endl;
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

