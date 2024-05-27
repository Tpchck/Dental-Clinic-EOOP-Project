//
// Created by Tpshck on 3/25/2024.
//

#pragma once

#include <string>

#ifndef DENTAL_CLINIC_EOOP_PROJECT_TREATMENT_H
#define DENTAL_CLINIC_EOOP_PROJECT_TREATMENT_H

#endif //DENTAL_CLINIC_EOOP_PROJECT_TREATMENT_H

using namespace std;

class Treatment {
private:
    string name;
    string description;
    double cost;
    string requiredSpecialization;
public:
    Treatment(const string& name, const string& description, double cost, const string& requiredSpecialization);
    string getName() const;
    void setName(const string& name);
    string getDescription() const;
    void setDescription(const string& description);
    double getCost() const;
    void setCost(double cost);
    string getRequiredSpecialization() const;
    void setRequiredSpecialization(const string& requiredSpecialization);
};
