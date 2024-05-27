//
// Created by Tpshck on 5/27/2024.
//

#ifndef DENTAL_CLINIC_EOOP_PROJECT_DENTISTSREGISTRY_H
#define DENTAL_CLINIC_EOOP_PROJECT_DENTISTSREGISTRY_H

#endif //DENTAL_CLINIC_EOOP_PROJECT_DENTISTSREGISTRY_H

#pragma once

#include <vector>
#include "Dentist.h"

class DentistsRegistry {
private:
    vector<Dentist*> dentists;
public:
    void addDentist(const string& name, const string& specialization);
    Dentist* findDentist(const string& name);
    vector<Dentist*> getDentists() const;
};
