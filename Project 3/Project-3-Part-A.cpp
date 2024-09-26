/*
Author: Mohammad Islam
Course: CSCI 137
Instructor: Genady Maryash
Assingment: Project 3

Project 3: Profemon
*/

#include <iostream>
using namespace std;

class Skill {
    private:
        string name;
        string description;
        int uses;
        int specialty;
    public:
        Skill() {
            name = "Undefined";
            description = "Undefined";
            uses = -1;
            specialty = -1;
        }
        Skill(string name, string description, int specialty, int uses) {
            this -> name = name;
            this -> description = description;
            this -> specialty = specialty;
            this -> uses = uses;
        }

        string getName() {return name;}
        string getDescription() {return description;}
        int getTotalUses() {return uses;}
        int getSpecialty() {return specialty;}

        void setName(string name) {
            this -> name = name;
        }
        void setDescription(string description) {
            this -> description = description;
        }
        void setTotalUses(int uses) {
            this -> uses = uses;
        }
        bool setSpecialty(int specialty) {
            if (specialty == 0 or 1 or 2) {
                this -> specialty = specialty;
                return true;
            }
            
            return false;
        }
};

enum Specialty {ML, SOFTWARE, HARDWARE};

class Profemon {
    private:
    string name;
    int level;
    int need_xp;
    int current_xp;
    int max_health_lvl;
    Specialty special_name;
    Skill learned[3];
    public:
        Profemon() {
            name = "Undefined";
        }
        Profemon(string name, double max_health, Specialty specialty) {
            this -> name = name;
            max_health_lvl = max_health;
            special_name = specialty;
            current_xp = 0;
            need_xp = 50;
            level = 0;
        }

        string getName() {return name;}
        Specialty getSpecialty() {return special_name;}
        int getLevel() {return level;}
        int getMaxHealth() {return max_health_lvl;}

        void setName(string name) {
            this -> name = name;
        }

        void levelUp(int exp) {
            current_xp = exp;
            int ML_xp = 50;
            int SOFTWARE_xp = 50;
            int HARDWARRE_xp = 50;
            switch(special_name) {
                case ML:
                    while (current_xp >= ML_xp)
                    {
                        level++;
                        current_xp = current_xp - ML_xp;
                        ML_xp = ML_xp + 10;
                    }
                    break;
                case SOFTWARE:
                    while (current_xp >= SOFTWARE_xp) {
                        level++;
                        current_xp = current_xp - SOFTWARE_xp;
                        SOFTWARE_xp = SOFTWARE_xp + 15;
                    }
                    break;
                case HARDWARE:
                    while(current_xp >= HARDWARRE_xp) {
                        level++;
                        current_xp -= HARDWARRE_xp;
                        HARDWARRE_xp += 20;
                    }
                    break;
                default: break;
            }
        }

        bool learnSkill(int slot, Skill skill) {
            if (slot > 2 or slot < 0 or skill.getSpecialty() != special_name) {
                return false;
            }
            learned[slot] = skill;
            return true;
        }
        void printProfemon(bool print_skills) {
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
                if (print_skills) {
                    for (int i = 0; i < 3; i++) {
                        if (learned[i].getName() != "Undefined") {
                            std::cout << "    " << learned[i].getName() << " [" << learned[i].getTotalUses() << "] : " << learned[i].getDescription() << "\n";
                        }
                    }
                }
            }
        }
};

int main(){
    Skill oop("OOP", "a programming paradigm based on the concept of objects, which can contain data and code", SOFTWARE, 30);
    Skill dynamic_array("Vector", "a c++ dynamic array library", SOFTWARE, 30);
    Skill pointer("Pointer", "a pointer stores a memory address", SOFTWARE, 10);
    // ligorio
    Skill sorting("Sorting", "algorithms to sort things in order", SOFTWARE, 30);
    Skill polymorphism("Polymorphism", "the same entity (function or object) behaves differently in different scenarios", SOFTWARE, 20);
    Skill searching("Searching", "algorithms to efficiently search items in data structures", SOFTWARE, 30);
    // shostak skills
    Skill report("Report", "report a student for cheating", SOFTWARE, 30);
    Skill tree("Tree", "an abstract data type that represents a hierarchical tree structure with a set of connected nodes", SOFTWARE, 25);
    Skill hashtable("HashTable", "an abstract data type that maps keys to values", SOFTWARE, 30);
    // shankar skills
    Skill nickname("Nickname", "assign a nickname to the students", HARDWARE, 20);
    Skill mips("MIPS", "an assembly level programming language", HARDWARE, 10);
    Skill multiplexer("Multiplexer", "a device that selects between several analog or digital input signals and forwards the selected input to a single output line", HARDWARE, 30);
    // schweitzer skills
    Skill flashbag("Flashbag", "creates and throws rgb backpack to blind enemies", HARDWARE, 5);
    Skill induction("Induction", "a method of mathematical proof typically used to establish a given statement for all possible cases", HARDWARE, 15);
    Skill recurrence("Recurrence", "n equation that defines a sequence based on a rule that gives the next term as a function of the previous term(s)", HARDWARE, 15);
    // zamfirescu
    Skill flipflop("Flip-Flop", "circuits that can store state(on/off) information", HARDWARE, 20);
    Skill number_system("Number System", "a technique to represent numbers", HARDWARE, 20);
    Skill kmap("Karnaugh Map", "a table that simplify the expressions to Boolean functions", HARDWARE, 5);
    // raja skills
    Skill supervised("Supervised Learning", "a ML training method that uses labeled datasets and algorithms classify data or predict outcomes accurately", ML, 25);
    Skill unsupervised("Unsupervised Learning", "a ML training method that can discover hidden patterns or data groupings without the need for human intervention", ML, 30);
    Skill reinforcement("Reinforcement Learning", "a ML training method based on rewarding desired behaviors and/or punishing undesired ones", ML, 15);
    // levitan skills
    Skill ngrams("Ngrams", "a contiguous sequence of n items from a given sample of text or speech", ML, 10);
    Skill tokenizing("Tokenizing", "breaks the raw text into words, sentences called tokens", ML, 30);
    Skill lemmatizing("Lemmatizing", "the process of grouping together different inflected forms of the same word", ML, 20);
    // epstein skill
    Skill perceptron("Perceptron", "a ML algorithm that can decide whether an input belongs to some specific class", ML, 20);
    Skill neuralnetwork("Neural Network", "a series of perceptrons that have an input, output, and hidden layer", ML, 30);
    Skill autoencoder("Autoencoder", "a ML technique that involves the use of a generator which generates fake information and a discriminator which can discern whether the information is fake or not", ML, 30);

    Profemon maryash("Maryash", 13500, SOFTWARE);
    cout << maryash.learnSkill(0, oop) << endl;                 // prints 1
    /*
        Maryash [SOFTWARE] | lvl 0 | exp 0/50 | hp 13500
            OOP [30] : a programming paradigm based on the concept of objects, which can contain data and code
    */
    maryash.printProfemon(true);

    Profemon ligorio("Ligorio", 23500, SOFTWARE);
    cout << ligorio.learnSkill(2, perceptron) << endl;          // prints 0

    Profemon shostak("Shostak", 33500, SOFTWARE);
    shostak.levelUp(200);
    cout << shostak.getLevel() << endl;                         // prints 3
    
    Profemon shankar("Shankar", 26000, HARDWARE);
    Profemon schweitzer("Schweitzer", 15000, HARDWARE);
    Profemon zamfirescu("Zamfirescu", 16000, HARDWARE);
    Profemon raja("Raja", 35000, ML);
    Profemon levitan("Levitan", 49362, ML);
    Profemon epstein("Epstein", 49377, ML);

    // . . . test your functions here
}