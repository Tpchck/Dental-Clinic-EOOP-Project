//
// Created by Tpshck on 5/27/2024.
//

#include "Tests.h"

void Tests::testAddDentists(DentalClinic &clinic) {
    clinic.addDentist("Dr. Smith", "Dentist-Therapist");
    clinic.addDentist("Dr. Bruno", "Dentist-Surgeon");
    clinic.addDentist("Dr. Leopold", "Orthodontist");
}

void Tests::testAddPatients(DentalClinic &clinic) {
    clinic.addPatient("John Doe", 30, "123-456-7890");
    clinic.addPatient("Alex Margo", 24, "510-229-1488");
    clinic.addPatient("Jane Doe", 30, "1234567890");
}

void Tests::testAddTreatments(DentalClinic &clinic) {
    clinic.addTreatment("Teeth Whitening",
                        "Lightens teeth and helps to remove stains and discoloration",
                        250.00, "Dentist-Therapist");
    clinic.addTreatment("Dental Crowns",
                        "Caps placed on top of damaged teeth to restore shape, size, strength, and appearance",
                        500.00, "Dentist-Surgeon");
    clinic.addTreatment("Braces", "Used to straighten teeth and correct bite issues", 3000.00,
                        "Orthodontist");
    clinic.addTreatment("Root Canal Treatment",
                        "Procedure to repair and save a tooth that is badly decayed or becomes infected.", 200.0,
                        "Orthodontist");
}

void Tests::testBookAppointment(DentalClinic &clinic) {
    Appointment *testAppointment = clinic.bookAppointment("2024-04-01", "11:00", clinic.findDentist("Dr. Bruno"),
                                                              clinic.findPatient("Alex Margo"),
                                                              clinic.findTreatment("Dental Crowns"));
    cout << "Appointment booked successfully with id: " << testAppointment->getId() << endl;
}

void Tests::testDentistAvailability(DentalClinic &clinic) {
    bool isAvailable = clinic.isDentistAvailable(clinic.findDentist("Dr. Bruno"), "2024-04-01", "11:00");
    cout << "Is Dr. Bruno available at 2024-04-01 11:00? ";
    if(isAvailable){
    cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}

void Tests::testAddMedicalRecord(DentalClinic &clinic) {
    clinic.addPatientMedicalRecord(clinic.findPatient("John Doe")->getId(),
                                   {"Cavities", "Filling", "2024-01-10", "Dr Bruno"});
    cout << "Medical record added successfully for patient: " << clinic.findPatient("John Doe")->getName() << endl;
    clinic.findPatient("John Doe")->printMedicalRecord();
}

void Tests::testDeleteAppointment(DentalClinic &clinic) {
    Appointment *testAppointment = clinic.bookAppointment("2024-06-01", "11:00", clinic.findDentist("Dr. Bruno"),
                                                              clinic.findPatient("Alex Margo"),
                                                              clinic.findTreatment("Dental Crowns"));
    if (testAppointment != nullptr) {
        clinic.deleteAppointment(testAppointment->getId());
    } else {
        cout << "Failed to delete new appointment." << endl;
    }
}

void Tests::testEditAppointment(DentalClinic &clinic) {
    Appointment *testAppointment = clinic.bookAppointment("2024-04-02", "12:00", clinic.findDentist("Dr. Leopold"),
                                                            clinic.findPatient("Jane Doe"),
                                                            clinic.findTreatment("Root Canal Treatment"));
    if (testAppointment != nullptr) {
        testAppointment->editDate("2024-04-03");
    } else {
        cout << "Failed to create new appointment." << endl;
    }
}

void Tests::testAddDentistWithEmptyName(DentalClinic &clinic) {
    // Attempt to add a dentist with an empty name
    clinic.addDentist("", "Dentist-Therapist");
}

void Tests::testAddPatientWithEmptyName(DentalClinic &clinic) {
    // Attempt to add a patient with an empty name
    clinic.addPatient("", 30, "123-456-7890");
}

void Tests::testAddTreatmentWithEmptyName(DentalClinic &clinic) {
    // Attempt to add a treatment with an empty name
    clinic.addTreatment("", "Description", 250.00, "Dentist-Therapist");
}

void Tests::testBookAppointmentWithNonexistentDentist(DentalClinic &clinic) {
    // Attempt to book an appointment with a non-existent dentist
    Appointment *testAppointment = clinic.bookAppointment("2024-04-01", "11:00", clinic.findDentist("Nonexistent Dentist"),
                                                          clinic.findPatient("Alex Margo"),
                                                          clinic.findTreatment("Dental Crowns"));
}

void Tests::testAddMedicalRecordForNonexistentPatient(DentalClinic &clinic) {
    // Attempt to add a medical record for a non-existent patient
    clinic.addPatientMedicalRecord(-1, {"Cavities", "Filling", "2024-01-10", "Dr Bruno"});
}

void Tests::testDeleteNonexistentAppointment(DentalClinic &clinic) {
    // Attempt to delete a non-existent appointment
    clinic.deleteAppointment(-1);
}