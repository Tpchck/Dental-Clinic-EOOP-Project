//
// Created by Tpshck on 5/27/2024.
//

#pragma once

#include "DentistsRegistry.h"

void DentistsRegistry::addDentist(const string& name, const string& specialization) {
    dentists.push_back(new Dentist(name, specialization));
}

Dentist* DentistsRegistry::findDentist(const string& name) {
    for (Dentist* dentist : dentists) {
        if (dentist->getName() == name) {
            return dentist;
        }
    }
    return nullptr;
}

vector<Dentist*> DentistsRegistry::getDentists() const {
    return dentists;
}