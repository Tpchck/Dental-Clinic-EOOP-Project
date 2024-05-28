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
    std::vector<Dentist*> dentists;
    std::vector<Patient*> patients;
    std::vector<Treatment*> treatments;
    std::vector<Appointment*> appointments;
public:
    void addDentist(Dentist* dentist);
    void addPatient(Patient* patient);
    void addTreatment(const std::string& name, const std::string& description, double cost, const std::string& requiredSpecialization);
    Appointment* bookAppointment(const std::string& date, const std::string& time, Dentist* dentist, Patient* patient, Treatment* treatment);
    Dentist* findDentist(const std::string& name);
    Patient* findPatient(const std::string& name);
    std::vector<Dentist*> getDentists() const;
    std::vector<Patient*> getPatients() const;

    bool isDentistAvailable(const Dentist* dentist, const std::string& date, const std::string& time) const;
    bool canDentistPerformTreatment(const Dentist* dentist, const Treatment* treatment) const;

    void printAllAppointments() const;
    void printAllDentists() const;
    void printAllPatients() const;

    void removeAppointment(const std::string& date, const std::string& time, const Patient* patient);
};