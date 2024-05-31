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
    vector<DentalClinic*> clinics;
public:
    Dentist(const string& name, const string& specialization);
    void addClinics(DentalClinic* clinic);
    string getName() const;
    string getSpecialization() const;
    int getId() const;
    void addPatient(Patient* patient);
    void addTreatment(Treatment* treatment);
    vector<DentalClinic*> getClinics() const;
    vector<Treatment*> getTreatments() const;
    void printTreatments() const;
    void printClinics() const;
    bool isAvailable(const string& date, const string& time) const;
    bool canPerformTreatment(const Treatment* treatment) const;
    void printPatients() const;
};

