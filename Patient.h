//
// Created by Tpshck on 3/25/2024.
//
#pragma ocne

#include <string>
#include <vector>
#include "MedicalRecord.h"

#ifndef DENTAL_CLINIC_EOOP_PROJECT_PATIENT_H
#define DENTAL_CLINIC_EOOP_PROJECT_PATIENT_H
#endif //DENTAL_CLINIC_EOOP_PROJECT_PATIENT_H


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
    int getAge() const;
    string getPhoneNumber() const;

    void setName(const string &newName);
    void setAge(int newAge);
    void setPhoneNumber(const string &newPhoneNumber);

    void addMedicalRecord(const MedicalRecord& record);
    void printMedicalRecord() const;
};