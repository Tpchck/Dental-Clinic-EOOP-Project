//
// Created by Tpshck on 5/27/2024.
//

#include "PatientsRegistry.h"
#include <algorithm>
#include <iostream>

void PatientsRegistry::addPatient(const string& name, int age, const string& phoneNumber) {
    patients.push_back(new Patient(name, age, phoneNumber));
}

Patient* PatientsRegistry::findPatient(const string& name) {
    for (Patient* patient : patients) {
        if (patient->getName() == name) {
            return patient;
        }
    }
    cout << "Error: Patient with name " << name << " not found." << endl;
    return nullptr;
}

vector<Patient*> PatientsRegistry::getPatients() const {
    return patients;
}

void PatientsRegistry::printAllPatients() const {
    cout << "-----------------------------------------------------------" << endl;
    if (patients.empty()) {
        cout << "No patients available." << endl;
        return;
    }
    cout << "Registered Patients:" << endl;
    for (const Patient *patient: patients) {
        cout << "Name: " << patient->getName() << ", "
             << "Age: " << patient->getAge() << ", "
             << "Phone Number: " << patient->getPhoneNumber() << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
}