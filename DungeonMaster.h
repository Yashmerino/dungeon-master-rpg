#pragma once
#include <string>
#include <vector>
#include "Item.h"

class DungeonMaster { //Dungeon Master class
private:
    std::string name; //Vars
    char sex;
    std::string age;
    std::string weight;
    int hp;
    std::vector<Item> Inventory;

public:
    DungeonMaster(); //Constructor

    bool CheckInteger(std::string str);

    void GetInventory(); //Getter for the inventory

    void GetItem(int slot); //Getter for the item

    int GetHP(); //Getter for the HP

    std::string GetName(); //Getter for the name

    void SetInventory(int slot, Item stuff); //Setter for the inventory

    void DeleteInventory(int slot); //Deletes last item from the inventory

    void SetHP(int value); //Setter for the HP

    void SetName(); //Setter for the name

    void SetAge(); //Setter for the age

    void SetWeight(); //Setter for the weight

    void SetSex(); //Setter for the sex

    void PrintInfo(); //Printing info about the character

    int Attack(); //Attacking

    int Defense(); //Defending

    int Heal(); //Heal

};