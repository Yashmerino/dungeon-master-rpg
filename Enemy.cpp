#include "Enemy.h"

    Enemy::Enemy() : hp(100) { //Constructor

    }

    int Enemy::GetHP() { //Getter for the HP
        return hp;
    }

    void Enemy::SetHP(int hp) { //Setter for the HP
        this->hp = hp;
    }

    int Enemy::Attack() { //Attacking
        return rand() % 70;
    }

    int Enemy::Defense() { //Defending
        return rand() % 30;
    }