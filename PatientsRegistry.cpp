//
// Created by Tpshck on 5/27/2024.
//

#include "PatientsRegistry.h"
#include <algorithm>

void PatientsRegistry::addPatient(const string& name, int age, const string& phoneNumber) {
    patients.push_back(new Patient(name, age, phoneNumber));
}

Patient* PatientsRegistry::findPatient(const string& name) {
    for (Patient* patient : patients) {
        if (patient->getName() == name) {
            return patient;
        }
    }
    return nullptr;
}

vector<Patient*> PatientsRegistry::getPatients() const {
    return patients;
}