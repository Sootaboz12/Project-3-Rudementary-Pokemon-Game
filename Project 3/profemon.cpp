/*
Author: Mohammad Islam
Course: CSCI 137
Instructor: Genady Maryash
Assingment: Project 3

Project 3: Profemon
*/

#include <iostream>
#include "profemon.hpp"

Profemon::Profemon() {
    name = "Undefined";
}

Profemon::Profemon(std::string name, double max_health, Specialty specialty) {
    this -> name = name;
    max_health_lvl = max_health;
    special_name = specialty;
    current_xp = 0;
    need_xp = 50;
    level = 0;
}

std::string Profemon::getName() {
    return name;
}

Specialty Profemon::getSpecialty() {
    return special_name;
}

int Profemon::getLevel() {
    return level;
}

int Profemon::getMaxHealth() {
    return max_health_lvl;
}

void Profemon::setName(std::string name) {
    this -> name = name;
}

void Profemon::levelUp(int exp) {
    current_xp = current_xp + exp;
    switch(special_name) {
        case ML:
            while (current_xp >= need_xp)
            {
                level++;
                current_xp = current_xp - need_xp;
                need_xp = need_xp + 10;
            }
            break;
        case SOFTWARE:
            while (current_xp >= need_xp) {
                level++;
                current_xp = current_xp - need_xp;
                need_xp = need_xp + 15;
            }
            break;
        case HARDWARE:
            while(current_xp >= need_xp) {
                level++;
                current_xp -= need_xp;
                need_xp += 20;
            }
            break;
        default: break;
    }
}

bool Profemon::learnSkill(int slot, Skill skill) {
    if (slot > 2 or slot < 0 or skill.getSpecialty() != special_name) {
        return false;
    }
    learned[slot] = skill;
    return true;
}

void Profemon::printProfemon(bool print_skills) {
    switch (getSpecialty()) {
        case 0:
            std::cout << name << " [ML] | lvl " << level << " | exp " << current_xp << "/" << need_xp << " | hp " << max_health_lvl << "\n";
            break;
        case 1:
            std::cout << name << " [SOFTWARE] | lvl " << level << " | exp " << current_xp << "/" << need_xp << " | hp " << max_health_lvl << "\n";
            break;
        case 2:
            std::cout << name << " [HARDWARE] | lvl " << level << " | exp " << current_xp << "/" << need_xp << " | hp " << max_health_lvl << "\n";
            break;
        default:
            break;
    }
    if (print_skills) {
        for (int i = 0; i < 3; i++) {
            if (learned[i].getName() != "Undefined") {
                std::cout << "    " << learned[i].getName() << " [" << learned[i].getTotalUses() << "] : " << learned[i].getDescription() << "\n";
            }
        }
    }
}