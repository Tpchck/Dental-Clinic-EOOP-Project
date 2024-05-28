//
// Created by Tpshck on 3/25/2024.
//
#pragma once

#ifndef DENTIST_H
#define DENTIST_H
#endif // DENTIST_H

using namespace std;

#include <vector>
#include "Treatment.h"
#include "DentalClinic.h"

class Patient;
class DentalClinic;

class Dentist {
private:
    string name;
    string specialization;
    int id;
    static int lastId;
    vector<Patient*> patients;
    vector<Treatment*> treatments;
    DentalClinic* clinic;
public:
    Dentist(const string& name, const string& specialization, DentalClinic* clinic);    string getName() const;
    void setName(const string& name);
    string getSpecialization() const;
    void setSpecialization(const string& specialization);
    int getId() const;
    void addPatient(Patient* patient);
    void addTreatment(Treatment* treatment);
    void setClinic(DentalClinic* clinic);
    DentalClinic* getClinic() const;
};

