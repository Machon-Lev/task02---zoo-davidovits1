#include "Zoo.h"

Zoo::Zoo()
{

}
void Zoo::run() {
    std::unique_ptr<Owl> owl = std::make_unique<Owl>("Hedwig", Location(2, 3));
    addAnimal(std::move(owl));
    std::unique_ptr<Owl> owl1 = std::make_unique<Owl>("erol", Location(1, 3));
    addAnimal(std::move(owl1));
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

