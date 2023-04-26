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
    void stopAnmal(int row, int col) const;
    void moveAnmal(int row, int col) const;
    void creatAnimal(const Animal& a, const std::string& name);

    void printTable(const std::vector<std::unique_ptr<Animal>>& animals);
    void addAnimal(std::unique_ptr<Animal> animal);
    void removeAnimal(int index);
    void removeAnimal(const std::string& name);
    void printAnimals() const;
   // void printDirection(const Animal& a);
    std::unique_ptr<Animal> createAnimal(const std::string& kind, const std::string& name);


public:
	Zoo();

    void run();



};