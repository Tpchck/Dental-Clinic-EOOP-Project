//
// Created by Tpshck on 3/25/2024.
//
#pragma once
#include "DentalClinic.h"


#ifndef PATIENT_H
#define PATIENT_H
#endif // PATIENT_H

#include <vector>
#include "Treatment.h"
#include "MedicalRecord.h"

class Dentist;
class DentalClinic;
class Appointment;

class Patient {
private:
    int id;
    string name;
    int age;
    string phoneNumber;
    vector<MedicalRecord> medicalRecords;
    static int lastId;
    vector<Dentist*> dentists;
    vector<Treatment*> treatments;
    DentalClinic* clinic;

public:
    Patient(const string& name, int age, const string& phoneNumber, DentalClinic* clinic);
    int getId() const;
    string getName() const;
    void setName(const string& name);
    int getAge() const;
    void setAge(int age);
    string getPhoneNumber() const;
    void setPhoneNumber(const string& phoneNumber);
    vector<MedicalRecord> getMedicalRecords() const;
    void addMedicalRecord(const MedicalRecord& medicalRecord);
    void addDentist(Dentist* dentist);
    void addTreatment(Treatment* treatment);
    void setClinic(DentalClinic* clinic);
    DentalClinic* getClinic() const;
};

