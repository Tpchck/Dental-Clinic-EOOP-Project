//
// Created by Tpshck on 5/27/2024.
//

#ifndef DENTAL_CLINIC_EOOP_PROJECT_PATIENTSREGISTRY_H
#define DENTAL_CLINIC_EOOP_PROJECT_PATIENTSREGISTRY_H

#endif //DENTAL_CLINIC_EOOP_PROJECT_PATIENTSREGISTRY_H

#pragma once

#include <vector>
#include "Patient.h"

class PatientsRegistry {
private:
    vector<Patient*> patients;
public:
    void addPatient(const string& name, int age, const string& phoneNumber);
    Patient* findPatient(const string& name);
    vector<Patient*> getPatients() const;
    void printAllPatients() const;
};