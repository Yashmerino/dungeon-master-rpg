#pragma once
#include <string>

class Enemy {
private:
    int hp;

public:
    Enemy(); //Constructor

    int GetHP(); //Getter for the HP

    void SetHP(int value); //Setter for the HP

    int Attack(); //Attacking

    int Defense(); //Defending

};