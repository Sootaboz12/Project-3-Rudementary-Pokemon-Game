/*
Author: Mohammad Islam
Course: CSCI 137
Instructor: Genady Maryash
Assingment: Project 3

Project 3: Profemon
*/

#pragma once
#include "skill.hpp"

enum Specialty {ML, SOFTWARE, HARDWARE};

class Profemon {
    private:
        std::string name;
        int level;
        int need_xp;
        int current_xp;
        int max_health_lvl;
        Specialty special_name;
        Skill learned[3];
    public:
        Profemon();
        Profemon(std::string name, double max_health, Specialty specialty);
        std::string getName();
        Specialty getSpecialty();
        int getLevel();
        int getMaxHealth();
        void setName(std::string name);
        void levelUp(int exp);
        bool learnSkill(int slot, Skill skill);
        void printProfemon(bool print_skills);
};

