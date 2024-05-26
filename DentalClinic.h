//
// Created by Tpshck on 3/25/2024.
//
#pragma once

#include <iostream>
#include <vector>
#include "Dentist.h"
#include "Treatment.h"

class Patient;
class Appointment;
#ifndef DENTAL_CLINIC_EOOP_PROJECT_DENTALCLINIC_H
#define DENTAL_CLINIC_EOOP_PROJECT_DENTALCLINIC_H
#endif //DENTAL_CLINIC_EOOP_PROJECT_DENTALCLINIC_H

using namespace std;


class DentalClinic {
private:
    vector<Dentist *> dentists;
    vector<Patient *> patients;
    vector<Treatment *> treatments;
    vector<Appointment *> appointments;

    string normalizeName(const string& name) const;

public:
    ~DentalClinic();

    void deleteAppointment(int appointmentId);
    void addDentist(const string &name, const string &specialization);
    void addPatient(const string &name, int age, const string &contactInfo);
    void addTreatment(const string &name, const string &description, double cost, const string &requiredSpecialization);
    Appointment* bookAppointment(const string &date, const string &time, const Dentist* dentist, const Patient* patient, const Treatment* treatment);
    bool isDentistAvailable(const Dentist* dentist, const string& date, const string& time);
    const vector<Treatment*>& getTreatments() const;
    void addPatientMedicalRecord(int patientId, const vector<string>& medicalRecordDetails);
    const Dentist* findDentist(const string &name) const;
    const Patient* findPatient(const string &name) const;
    const Treatment* findTreatment(const string &name) const;
    const vector<Appointment*>& getAppointments() const;
};