#include "Enemy.h"

    Enemy::Enemy() : hp(100) { //Constructor

    }

    int Enemy::GetHP() { //Getter for the HP
        return hp;
    }

    void Enemy::SetHP(int value) { //Setter for the HP
        hp = value;
    }

    int Enemy::Attack() { //Attacking
        return rand() % 70;
    }

    int Enemy::Defense() { //Defending
        return rand() % 30;
    }