#pragma once
#include <string>

class NPC {
private:
    std::string name;
    int age;
    int weight;
    char sex;
    std::string story;

public:
    NPC(); //Constructors

    NPC(std::string name, char sex, int age, int weight);

    void SetStory(std::string story); //Setter for the story

    void SetName(std::string name); //Setter for the name

    void SetAge(int age); //Setter for the age

    void SetWeight(int weight); //Setter for the weight

    void SetSex(char sex); //Setter for the sex

    void PrintInfo(); //Function to print info about the NPC

};