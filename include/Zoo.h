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

    /*static Location random();*/
    void stopAnimal(int row, int col) const;
    void moveAnimal(int row, int col) const;
    void stepAllAnimals();
    void printTable();
    void addAnimal(std::unique_ptr<Animal> animal);
    void removeAnimal(const int row, const int col);
    void deleteAnimalsOfType(const std::string& type);
    void removeAnimal(const std::string& name);
    void printAnimals() const;
    std::unique_ptr<Animal> createAnimal(const std::string& kind, const std::string& name);
    void initZoo();


public:
	Zoo();

    void run();



};