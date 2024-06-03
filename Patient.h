//
// Created by Tpshck on 3/25/2024.
//
#pragma once
#ifndef PATIENT_H

#define PATIENT_H

#include <vector>
#include "DentalClinic.h"
#include "Treatment.h"
#include "MedicalRecord.h"
#include "Appointment.h"

class Dentist;

class Patient {
private:
    int id;
    string name;
    int age;
    string phoneNumber;
    static int lastId;
    vector<MedicalRecord> medicalRecords;
    vector<Dentist*> dentists;
    vector<Treatment*> treatments;
    vector<DentalClinic*> clinics;
    vector<Appointment*> appointments;

public:
    Patient(const string& name, int age, const string& phoneNumber);
    ~Patient();
    void addClinics(DentalClinic* clinic);
    void removeClinic(DentalClinic* clinic);
    int getId() const;
    string getName() const;
    int getAge() const;
    string getPhoneNumber() const;
    void addDentist(Dentist* dentist);
    void removeDentist(Dentist* dentist);
    void addTreatment(Treatment* treatment);
    void addAppointment(Appointment* appointment);
    void removeAppointment(const Appointment* appointment);
    void addMedicalRecord(MedicalRecord* record);
    vector<Appointment*> getAppointments() const;
    void printAppointments() const;
    void printTreatments() const;
    void printClinics() const;
    void printDentists() const;
};

#endif // PATIENT_H
