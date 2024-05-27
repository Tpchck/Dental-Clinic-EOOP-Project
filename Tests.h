//
// Created by Tpshck on 5/27/2024.
//

#pragma once

#include "DentalClinic.h"
#include "System.h"

#ifndef DENTAL_CLINIC_EOOP_PROJECT_TESTS_H
#define DENTAL_CLINIC_EOOP_PROJECT_TESTS_H

#endif //DENTAL_CLINIC_EOOP_PROJECT_TESTS_H



class Tests {
public:
    void testAddDentists(DentalClinic& clinic);
    void testAddPatients(DentalClinic& clinic);
    void testAddTreatments(DentalClinic& clinic);
    void testBookAppointment(DentalClinic& clinic);
    void testDentistAvailability(DentalClinic& clinic);
    void testAddMedicalRecord(DentalClinic& clinic);
    void testDeleteAppointment(DentalClinic& clinic);
    void testEditAppointment(DentalClinic& clinic);
    void testAddDentistWithEmptyName(DentalClinic &clinic);
    void testAddPatientWithEmptyName(DentalClinic &clinic);
    void testAddTreatmentWithEmptyName(DentalClinic &clinic);
    void testBookAppointmentWithNonexistentDentist(DentalClinic &clinic);
    void testAddMedicalRecordForNonexistentPatient(DentalClinic &clinic);
    void testDeleteNonexistentAppointment(DentalClinic &clinic);
};