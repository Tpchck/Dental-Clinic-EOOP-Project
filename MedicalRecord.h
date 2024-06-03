//
// Created by Tpshck on 4/7/2024.
//

#pragma once

#include <string>

#ifndef MEDICALRECORD_H
#define MEDICALRECORD_H

using namespace std;

class Appointment;

class MedicalRecord {
private:
    string date;
    string time;
    string dentistName;
    string patientName;
    string treatmentName;

public:
    MedicalRecord(const Appointment* appointment);
    string getDate() const;
    string getTime() const;
    string getDentistName() const;
    string getPatientName() const;
    string getTreatmentName() const;
};

#endif // MEDICALRECORD_H