# Dental Clinic EOOP Project

This project is a dental clinic management system developed as part of an Object-Oriented Programming course. It includes the following features:

## Features

1. **Manage Dentists**: Add new dentists with their specialization.
2. **Manage Patients**: Add new patients with their contact information.
3. **Manage Treatments**: Add new types of treatments with their description, cost, and required specialization.
4. **Manage Appointments**: Create new appointments specifying the date, time, dentist, patient, and treatment.
5. **Check Dentist Availability**: Check if a dentist is available at a certain date and time.
6. **Manage Patient Medical Records**: Add new medical records for patients.

## Test Scenarios

### Possible Scenarios

1. **Test Dentist Addition**: Test if a new dentist can be added successfully. Verify that the dentist's details are correctly stored and can be retrieved.
2. **Test Patient Addition**: Test if a new patient can be added successfully. Verify that the patient's details are correctly stored and can be retrieved.
3. **Test Treatment Addition**: Test if a new treatment can be added successfully. Verify that the treatment's details are correctly stored and can be retrieved.
4. **Test Appointment Booking**: Test if an appointment can be booked successfully. Verify that the appointment's details are correctly stored and can be retrieved.
5. **Test Dentist Availability**: Test if the system correctly determines whether a dentist is available at a certain date and time.
6. **Test Medical Record Addition**: Test if a new medical record can be added for a patient successfully. Verify that the medical record's details are correctly stored and can be retrieved.
7. **Test Appointment Deletion**: Test if an existing appointment can be deleted successfully. Verify that the appointment's details are removed from the system.
8. **Test Appointment Editing**: Test if the date and time of an existing appointment can be edited successfully. Verify that the changes are saved correctly.
9. **Test Dentist Specialization Matching**: Test if the system correctly prevents booking an appointment for a treatment that does not match the dentist's specialization.
10. **Test Dentist Time Slot Availability**: Test if the system correctly prevents booking an appointment for a time when the dentist is not available.
11. **Test Treatment Cost Calculation**: Test if the system correctly calculates the total cost of a treatment.
12. **Test Patient Medical Record Retrieval**: Test if the system correctly retrieves a patient's medical record.

### Impossible Scenarios

1. Add a dentist with an empty name or specialization.
2. Add a patient with an empty name or contact information.
3. Add a treatment with an empty name, description, or required specialization.
4. Book an appointment without specifying a dentist, patient, or treatment.
5. Add a medical record for a non-existent patient.

*This document was translated and orthographic errors were formatted using GitHub Copilot.*