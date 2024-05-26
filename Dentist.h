//
// Created by Tpshck on 3/25/2024.
//
#pragma once
#include <string>


#ifndef DENTAL_CLINIC_EOOP_PROJECT_DANTIST_H
#define DENTAL_CLINIC_EOOP_PROJECT_DANTIST_H
#endif //DENTAL_CLINIC_EOOP_PROJECT_DANTIST_H

using namespace std;

class Dentist {
private:
    string name;
    string specialization;

public:
    Dentist(const string& name, const string& specialization);

    string getName() const;
    string getSpecialization() const;

    void setName(const string &newName);
    void setSpecialization(const string &newSpecialization);
};