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

//class zoo
class Zoo
{
    std::vector<std::unique_ptr<Animal>> animals;

    /// <summary>
    /// stop animal to move by location
    /// </summary>
    /// <param name="row">row of location</param>
    /// <param name="col">col of location</param>
    void stopAnimal(int row, int col) const;

    /// <summary>
    /// returns animal to move by location 
    /// </summary>
    /// <param name="row">row of location</param>
    /// <param name="col">col of location</param>
    void moveAnimal(int row, int col) const;

    //steps of all the animals (those not at a stop)
    void stepAllAnimals();

    //print map of zoo
    void printTable();

    //remove animal by location
    void removeAnimal(const int row, const int col);

    //remove all animals by type 
    void deleteAnimalsOfType(const std::string& type);

    //remove animal by location
    void removeAnimal(const std::string& name);

    //prints details about all the animals in a zoo
    void printAnimals() const;

    //prints the menu and explains each command
    void printHelpMenu();

    //print all commands
    void printCommandNames();

    //creat new animal by type and name
    std::unique_ptr<Animal> createAnimal(const std::string& type, const std::string& name);

    //initializes the zoo with multiple animals
    void initZoo();


public:
    //Default constructor
	Zoo();

    //Zoo management
    void run();
};
