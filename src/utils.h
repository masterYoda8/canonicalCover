#ifndef UTILS_H 
#define UTILS_H 

#include "string.h"
#include <vector>

typedef struct {
    std::vector<std::string> left;  
    std::vector<std::string> right;
} functionalDependency;

void readInputFile(std::vector<functionalDependency> &);
void writeOutputFile(std::vector<functionalDependency> &);
void eraseUnnecessaryCharacters(std::string &);
void addFunctionalDependency(std::string, std::vector<functionalDependency> &); 
void addToVector(std::string, std::vector<std::string> &);
void leftReduction(std::vector<functionalDependency> &);
void rightReduction(std::vector<functionalDependency> &);
void removeDuplicates(std::vector<functionalDependency> &);
void removeEmpty(std::vector<functionalDependency> &);

#endif

