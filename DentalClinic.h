//
// Created by Tpshck on 3/25/2024.
//
#pragma once

#ifndef DENTAL_CLINIC_H
#define DENTAL_CLINIC_H
#endif //DENTAL_CLINIC_H

#include <vector>
#include "Treatment.h"

class Dentist;
class Patient;
class Appointment;


class DentalClinic {
private:
    string name;
    vector<Dentist*> dentists;
    vector<Patient*> patients;
    vector<Treatment*> treatments;
    vector<Appointment*> appointments;
public:
    DentalClinic(const string& name);
    void addDentist(Dentist* dentist);
    void addPatient(Patient* patient);
    Appointment* bookAppointment(const string& date, const string& time, Dentist* dentist, Patient* patient, Treatment* treatment);
    Dentist* findDentist(const string& name);
    Patient* findPatient(const string& name);
    vector<Dentist*> getDentists() const;
    vector<Patient*> getPatients() const;

    string getName() const;

    void printAllAppointments() const;
    void printAllDentists() const;
    void printAllPatients() const;

    Treatment* findTreatment(const string& name);

    vector<Appointment*> getAppointments() const;
    vector<Treatment*> getTreatments() const;

    void removeAppointment(const string& date, const string& time, const Patient* patient);
};