#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Owl.h"

class Zoo
{

    std::vector<std::unique_ptr<Animal>> animals;

    static Location random();
    void printTable(const std::vector<std::unique_ptr<Animal>>& animals);
    void addAnimal(std::unique_ptr<Animal> animal);
    void removeAnimal(int index);
    void removeAnimal(const std::string& name);
    void printAnimals() const;

public:
	Zoo();

    void run();



};