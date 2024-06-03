//
// Created by Tpshck on 4/7/2024.
//

#include "Dentist.h"
#include "Appointment.h"
#include "MedicalRecord.h"

MedicalRecord::MedicalRecord(const Appointment* appointment)
        : date(appointment->getDate()), time(appointment->getTime()),
          dentistName(appointment->getDentist()->getName()), patientName(appointment->getPatient()->getName()),
          treatmentName(appointment->getTreatment()->getName()) {}

string MedicalRecord::getDate() const {
    return date;
}

string MedicalRecord::getTime() const {
    return time;
}

string MedicalRecord::getDentistName() const {
    return dentistName;
}

string MedicalRecord::getPatientName() const {
    return patientName;
}

string MedicalRecord::getTreatmentName() const {
    return treatmentName;
}
