#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "Owl.h"
#include "Lion.h"
#include "Monkey.h"

class Zoo
{

    std::vector<std::unique_ptr<Animal>> animals;

    static Location random();
    void printTable(const std::vector<std::unique_ptr<Animal>>& animals);
    void addAnimal(std::unique_ptr<Animal> animal);
    void removeAnimal(int index);
    void removeAnimal(const std::string& name);
    void printAnimals() const;
   // void printDirection(const Animal& a);

public:
	Zoo();

    void run();



};