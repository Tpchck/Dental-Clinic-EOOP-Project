//
// Created by Tpshck on 3/25/2024.
//
#pragma once

#ifndef PATIENT_H
#define PATIENT_H
#endif // PATIENT_H

#include <string>
#include <vector>
#include "MedicalRecord.h"



using namespace std;

class Patient {
private:
    int id;
    string name;
    int age;
    string phoneNumber;
    vector<MedicalRecord> medicalRecords;
    static int lastId;
public:
    Patient(const string& name, int age, const string& phoneNumber);
    int getId() const;
    string getName() const;
    void setName(const string& name);
    int getAge() const;
    void setAge(int age);
    string getPhoneNumber() const;
    void setPhoneNumber(const string& phoneNumber);
    vector<MedicalRecord> getMedicalRecords() const;
    void addMedicalRecord(const MedicalRecord& medicalRecord);
};

