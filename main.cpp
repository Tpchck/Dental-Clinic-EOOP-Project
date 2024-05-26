//
// Created by Tpshck on 3/25/2024.
//

#include "Appointment.h"
#include "DentalClinic.h"
#include "System.h"

using namespace std;

int main() {

    DentalClinic clinic;

    // Test Dentist Addition
    clinic.addDentist("Dr. Smith", "Dentist-Therapist");
    clinic.addDentist("Dr. Bruno", "Dentist-Surgeon");
    clinic.addDentist("Dr. Leopold", "Orthodontist");

    // Test Patient Addition
    clinic.addPatient("John Doe", 30, "123-456-7890");
    clinic.addPatient("Alex Margo", 24, "510-229-1488");
    clinic.addPatient("Jane Doe", 30, "1234567890");

    // Test Treatment Addition
    clinic.addTreatment("Teeth Whitening",
                        "Lightens teeth and helps to remove stains and discoloration",
                        250.00, "Dentist-Therapist");
    clinic.addTreatment("Dental Crowns",
                        "Caps placed on top of damaged teeth to restore shape, size, strength, and appearance",
                        500.00, "Dentist-Surgeon");
    clinic.addTreatment("Braces", "Used to straighten teeth and correct bite issues", 3000.00,
                        "Orthodontist");
    clinic.addTreatment("Root Canal Treatment", "Procedure to repair and save a tooth that is badly decayed or becomes infected.", 200.0, "Orthodontist");

    //Print all Treatments
    printAllTreatments(clinic.getTreatments());

    // Test Appointment Booking
    Appointment* successAppointment1 = clinic.bookAppointment("2024-04-01", "11:00", clinic.findDentist("Dr. Bruno"), clinic.findPatient("Alex Margo"), clinic.findTreatment("Dental Crowns"));
    cout << "Appointment booked successfully with id: " << successAppointment1->getId() << endl;
    printAllAppointments(clinic.getAppointments());

    // Test Dentist Availability
    bool isAvailable = clinic.isDentistAvailable(clinic.findDentist("Dr. Bruno"), "2024-04-01", "12:00");
    cout << "Is Dr. Bruno available at 2024-04-01 12:00? " << (isAvailable ? "Yes" : "No") << endl;

    // Test Medical Record Addition
    clinic.addPatientMedicalRecord(clinic.findPatient("John Doe")->getId(), {"Cavities", "Filling", "2024-01-10", "Dr Bruno"});
    cout << "Medical record added successfully for patient: " << clinic.findPatient("John Doe")->getName() << endl;

    // Test Appointment Deletion
    clinic.deleteAppointment(successAppointment1->getId());

    // Test Appointment Editing
    Appointment* failedAppointment = clinic.bookAppointment("2024-04-02", "12:00", clinic.findDentist("Dr. Bruno"), clinic.findPatient("Jane Doe"), clinic.findTreatment("Root Canal Treatment"));

    if (failedAppointment != nullptr) {
        failedAppointment->editDate("2024-04-03");
        clinic.deleteAppointment(failedAppointment->getId());
    } else {
        cout << "Failed to create new appointment." << endl;
    }

    // Print all appointments
    printAllAppointments(clinic.getAppointments());

    return 0;
}