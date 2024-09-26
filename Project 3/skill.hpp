/*
Author: Mohammad Islam
Course: CSCI 137
Instructor: Genady Maryash
Assingment: Project 3

Project 3: Profemon
*/

#pragma once
#include <string>

class Skill {
    private:
        std::string name;
        std::string description;
        int uses;
        int specialty;
    public:
        Skill();
        Skill(std::string name, std::string description, int specialty, int uses);
        std::string getName();
        std::string getDescription();
        int getTotalUses();
        int getSpecialty();
        void setName(std::string name);
        void setDescription(std::string description);
        void setTotalUses(int uses);
        bool setSpecialty(int specialty);
};