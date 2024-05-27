//
// Created by Tpshck on 3/25/2024.
//

#include "Tests.h"

int main() {
    DentalClinic clinic;
    Tests tests;

    // Successful Execute tests
    tests.testAddDentists(clinic);
    tests.testAddPatients(clinic);
    tests.testAddTreatments(clinic);
    printAllTreatments(clinic.getTreatments());
    tests.testBookAppointment(clinic);
    printAllAppointments(clinic.getAppointments());
    tests.testDentistAvailability(clinic);
    tests.testAddMedicalRecord(clinic);
    tests.testEditAppointment(clinic);
    printAllAppointments(clinic.getAppointments());
    tests.testDeleteAppointment(clinic);
    printAllAppointments(clinic.getAppointments());

    // Unsuccessful Execute tests
    tests.testAddDentistWithEmptyName(clinic);
    tests.testAddPatientWithEmptyName(clinic);
    tests.testAddTreatmentWithEmptyName(clinic);
    tests.testBookAppointmentWithNonexistentDentist(clinic);
    tests.testAddMedicalRecordForNonexistentPatient(clinic);
    tests.testDeleteNonexistentAppointment(clinic);

    return 0;
}
