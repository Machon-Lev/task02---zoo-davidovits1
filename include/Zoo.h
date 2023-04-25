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


    void printGrid() {
        const int numRows = 20;
        const int numCols = 40;
        // print column numbers
        std::cout << " ";
        for (int col = 0; col < numCols; col++) {
            std::cout << " " << col;
        }
        std::cout << std::endl;

        // print grid rows with row numbers
        for (int row = 0; row < numRows; row++) {
            std::cout << row << " ";
            for (int col = 0; col < numCols; col++) {
                std::cout << ".";
            }
            std::cout << std::endl;
        }
    }

    void printTable() {
        const int numRows = 20;
        const int numCols = 40;
        int maxRowDigits = std::to_string(numRows).size();
        int maxColDigits = std::to_string(numCols).size();

        for (int row = 1; row <= numRows; ++row) {
            std::cout << std::setw(maxRowDigits) << row << " | ";
            for (int col = 1; col <= numCols; ++col) {
                std::cout << std::setw(maxColDigits) << col << " ";
            }
            std::cout << std::endl;
        }
    }




};