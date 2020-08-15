#include <iostream>
#include <string>

using namespace std;

class DungeonMaster {
private:
    string name = "noname";
    char sex = ' ';
    int age = 0;
    int weight = 0;

public:
    void SetName() {
        string nick;
        cin >> nick;
        name = nick;
    }

    void SetAge() {
        int value;
        cin >> value;
        age = value;
    }

    void SetWeight() {
        int value;
        cin >> value;
        weight = value;
    }

    void SetSex() {
        cin >> sex;
        while (sex != 'f' && sex != 'm' && sex != 'M' && sex != 'F') {
            cout << "Error. Only F or M: ";
            cin >> sex;
        }
    }

    void PrintInfo() {
        cout << endl;
        cout << "Your character's name is: " << name << ".\nIt is " << age << " years old." << "\nIt weighs " << weight << " kg." << "\nIt's sex is: " << (char)toupper(sex) << endl;
    }

};

int main()
{
    DungeonMaster hero;
    cout << "Welcome to the Dungeon Master RPG.\nCreate your character.\nType a name for it: ";
    hero.SetName();

    cout << "It's age: ";
    hero.SetAge();

    cout << "It's weight: ";
    hero.SetWeight();

    cout << "It's sex (only F or M): ";
    hero.SetSex();

    hero.PrintInfo();
    
    cin.get();
    return 0;
}
