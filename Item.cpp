#include "Item.h"
#include <iostream>

    Item::Item() : name("Unknown"), price(0), purpose("Unknown") { //Constructors

    }

    Item::Item(std::string name, int price, std::string purpose) : name(name), price(price), purpose(purpose) {
    }

    std::string Item::GetName() { //Getter for the name of the item
        return name;
    }

    void Item::SetName(std::string name) { //Setter for item's name
        this->name = name;
    }
    void Item::SetPrice(int price) { //Setter for item's price
        this->price = price;
    }
    void Item::SetPurpose(std::string purpose) { //Setter for item's purpose
        this->purpose = purpose;
    }

    void Item::PrintInfo() { //Function to print info about the item
        std::cout << std::endl;
        std::cout << "Item's name is: " << name << ".\nIt costs " << price << " gold." << "\nIt's purpose is " << purpose << "." << std::endl;
    }
