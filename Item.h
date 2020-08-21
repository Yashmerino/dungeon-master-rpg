#pragma once
#include <string>

class Item {
private:
    std::string name; //Item's name
    int price; //Item's price
    std::string purpose; //Item's attribute. Attack, Defense, Quest.

public:
    Item(); //Constructors

    Item(std::string name, int price, std::string purpose);

    std::string GetName(); //Getter for the name of the item

    void SetName(std::string name); //Setter for item's name

    void SetPrice(int price); //Setter for item's price

    void SetPurpose(std::string purpose); //Setter for item's purpose

    void PrintInfo(); //Function to print info about the item

};