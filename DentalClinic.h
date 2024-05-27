//
// Created by Tpshck on 3/25/2024.
//
#pragma once

#ifndef DENTAL_CLINIC_H
#define DENTAL_CLINIC_H
#endif //DENTAL_CLINIC_H

#include <vector>
#include "Dentist.h"
#include "Treatment.h"
#include "Appointment.h"

class DentalClinic {
private:
    vector<Dentist*> dentists;
    vector<Patient*> patients;
    vector<Treatment*> treatments;
    vector<Appointment*> appointments;
public:
    void addDentist(const string& name, const string& specialization);
    void addPatient(const string& name, int age, const string& phoneNumber);
    void addTreatment(const string& name, const string& description, double cost, const string& requiredSpecialization);
    Appointment* bookAppointment(const string& date, const string& time, Dentist* dentist, Patient* patient, Treatment* treatment);
    Dentist* findDentist(const string& name);
    Patient* findPatient(const string& name);
    vector<Dentist*> getDentists() const;
    vector<Patient*> getPatients() const;

    bool isDentistAvailable(const Dentist* dentist, const string& date, const string& time) const;
    bool canDentistPerformTreatment(const Dentist* dentist, const Treatment* treatment) const;

    void printAllAppointments() const;
    void printAllDentists() const;
    void printAllPatients() const;

    void removeAppointment(const string& date, const string& time, const Patient* patient);
};