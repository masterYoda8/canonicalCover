#include <iostream>
#include "utils.h"

std::vector<functionalDependency> functionalDependencies;

int main(void){
    readInputFile(functionalDependencies);
    //leftReduction(functionalDependencies);
    //rightReduction(functionalDependencies);
    //removeDuplicates(functionalDependencies);
    //removeEmpty(functionalDependencies);
    writeOutputFile(functionalDependencies);
    return 0;
}

