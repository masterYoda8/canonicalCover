#include <iostream>
#include <fstream>
#include <string>
#include "utils.h"
#include <vector>


void readInputFile(std::vector<functionalDependency> &functionalDependencies) {
    std::string line;
    std::ifstream inputFile("input.txt");
    if (inputFile.is_open()) {
        while (getline(inputFile, line)) {
            addFunctionalDependency(line, functionalDependencies);
        }
        inputFile.close();
    }
    else {
        std::cout << "Unable to open file" << std::endl;
    }
}

void writeOutputFile(std::vector<functionalDependency> &fds) {
    std::ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        for (int i = 0; i < fds.size(); i++) {
            outputFile << "{ ";
            for (int j = 0; j < fds[i].left.size(); j++) {
                outputFile << fds[i].left[j];
                if (j != fds[i].left.size() - 1) {
                    outputFile << ", ";
                }
            }
            outputFile << " } ";
            outputFile << "-> { ";
            for (int j = 0; j < fds[i].right.size(); j++) {
                outputFile << fds[i].right[j];
                if (j != fds[i].right.size() - 1) {
                    outputFile << ", ";
                }
            }
            outputFile << " }";
            outputFile << std::endl;
        }
        outputFile.close();
    }
    else {
        std::cout << "Unable to create output file" << std::endl;
    }
}

void addFunctionalDependency(std::string line, std::vector<functionalDependency> &functionalDependencies) {
    eraseUnnecessaryCharacters(line);
    std::string left = line.substr(0, line.find("->"));
    std::string right = line.substr(left.length() + 2);
    functionalDependency *d = new functionalDependency;
    addToVector(left, d->left); 
    addToVector(right, d->right);
    functionalDependencies.push_back(*d);
}

void eraseUnnecessaryCharacters(std::string &str) {
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
    str.erase(std::remove(str.begin(), str.end(), '{'), str.end());
    str.erase(std::remove(str.begin(), str.end(), '}'), str.end());
}

void addToVector(std::string str, std::vector<std::string> &vec) {
    std::string delimiter = ",";
    size_t pos = 0;
    std::string token;
    while ((pos = str.find(delimiter)) != std::string::npos) {
        token = str.substr(0, pos);
        vec.push_back(token);
        str.erase(0, pos + delimiter.length());
    }
    vec.push_back(str);
}

