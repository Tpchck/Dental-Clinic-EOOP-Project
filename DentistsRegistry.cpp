//
// Created by Tpshck on 5/27/2024.
//

#pragma once

#include "DentistsRegistry.h"
#include <iostream>

void DentistsRegistry::addDentist(const string& name, const string& specialization) {
    dentists.push_back(new Dentist(name, specialization));
}

Dentist* DentistsRegistry::findDentist(const string& name) {
    for (Dentist* dentist : dentists) {
        if (dentist->getName() == name) {
            return dentist;
        }
    }
    cout << "Error: Dentist with name " << name << " not found." << endl;
    return nullptr;
}

vector<Dentist*> DentistsRegistry::getDentists() const {
    return dentists;
}

void DentistsRegistry::printAllDentists() const {
    cout << "-----------------------------------------------------------" << endl;
    if (dentists.empty()) {
        cout << "No dentists available." << endl;
        return;
    }
    cout << "Available Dentists:" << endl;
    for (const Dentist *dentist: dentists) {
        cout << "Name: " << dentist->getName() << ", "
             << "Specialization: " << dentist->getSpecialization() << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
}