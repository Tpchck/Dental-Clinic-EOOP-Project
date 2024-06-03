//
// Created by Tpshck on 3/25/2024.
//
#pragma once

#ifndef DENTIST_H
#define DENTIST_H

#include <vector>
#include <string>
#include "Treatment.h"
#include "DentalClinic.h"
#include "Appointment.h"

class Patient;

class Dentist {
private:
    string name;
    string specialization;
    int id;
    static int lastId;
    vector<Patient*> patients;
    vector<Treatment*> treatments;
    vector<DentalClinic*> clinics;
    vector<Appointment*> appointments;
public:
    Dentist(const string& name, const string& specialization);
    ~Dentist();
    void addClinics(DentalClinic* clinic);
    void removeClinic(DentalClinic* clinic);
    string getName() const;
    string getSpecialization() const;
    int getId() const;
    void addPatient(Patient* patient);
    void removePatient(Patient* patient);
    void addTreatment(Treatment* treatment);
    void addAppointment(Appointment* appointment);
    void removeAppointment(const Appointment* appointment);
    void printTreatments() const;
    void printClinics() const;
    void printPatients() const;
    void printAppointments() const;
    bool isAvailable(const string& date, const string& time) const;
    bool canPerformTreatment(const Treatment* treatment) const;
};

#endif // DENTIST_H




