#include <iostream>
#include <string>

using namespace std;

class DungeonMaster { //Dungeon Master class
private:
    string name = "noname"; //Vars
    char sex = ' ';
    int age = 0;
    int weight = 0;

public:
    void SetName() { //Setter for the name
        string nick;
        cin >> nick;
        name = nick;
    }

    void SetAge() { //Setter for the age
        int value;
        cin >> value;
        age = value;
    }

    void SetWeight() { //Setter for the weight
        int value;
        cin >> value;
        weight = value;
    }

    void SetSex() { //Setter for the sex
        cin >> sex;
        while (sex != 'f' && sex != 'm' && sex != 'M' && sex != 'F') {
            cout << "Error. Only F or M: ";
            cin >> sex;
        }
    }

    void PrintInfo() { //Function to print info about the character
        cout << endl;
        cout << "Your character's name is: " << name << ".\nIt is " << age << " years old." << "\nIt weighs " << weight << " kg." << "\nIt's sex is: " << (char)toupper(sex) << endl;
    }

};

int main()
{
    DungeonMaster hero; //Creatting hero
    cout << "Welcome to the Dungeon Master RPG.\nCreate your character.\nType a name for it: ";
    hero.SetName(); //Setting it's name

    cout << "It's age: ";
    hero.SetAge(); //Setting it's age

    cout << "It's weight: ";
    hero.SetWeight(); //Setting it's weight

    cout << "It's sex (only F or M): ";
    hero.SetSex(); //Setting it's sex

    hero.PrintInfo(); //Printing info about the character
    
    cin.get();
    return 0;
}
