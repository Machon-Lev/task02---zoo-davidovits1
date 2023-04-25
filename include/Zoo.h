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
    //std::vector<std::unique_ptr<Animal>> animals;
    //std::vector<Animal> animals;
    std::vector<std::unique_ptr<Animal>> animals;
    static Location random();
    void printTable(const std::vector<std::unique_ptr<Animal>>& animals);



public:
	Zoo();

    void run();

    void addAnimal(std::unique_ptr<Animal> animal); 
    void removeAnimal(int index);  
    void removeAnimal(const std::string& name);
    void printAnimals() const {
        std::cout << "The zoo contains:" << std::endl;
        for (const auto& animal : animals) {
            std::cout << animal->getInitial() << " - ";
            animal->printDetails();
        }
    }





};