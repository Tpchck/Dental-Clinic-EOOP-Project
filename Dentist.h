//
// Created by Tpshck on 3/25/2024.
//
#pragma once

#ifndef DENTISTSREGISTRY_H
#define DENTISTSREGISTRY_H
#endif // DENTISTSREGISTRY_H

#include <string>
using namespace std;

class Dentist {
private:
    string name;
    string specialization;
    int id;
    static int lastId;
public:
    Dentist(const string& name, const string& specialization);
    string getName() const;
    void setName(const string& name);
    string getSpecialization() const;
    void setSpecialization(const string& specialization);
    int getId() const;
};

