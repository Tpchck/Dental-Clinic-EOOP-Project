//
// Created by Tpshck on 4/4/2024.
//

#include "System.h"
#include <iostream>

using namespace std;

void printAllTreatments(const vector<Treatment*>& treatments) {
    cout << "-----------------------------------------------------------" << endl;
    if (treatments.empty()) {
        cout << "No treatments available." << endl;
        return;
    }
    cout << "Available Treatments:" << endl;
    for (const Treatment *treatment: treatments) {
        cout << "Name: " << treatment->getName() << ", "
             << "Description: " << treatment->getDescription() << ", "
             << "Cost: $" << treatment->getCost() << endl;
    }
    cout << "-----------------------------------------------------------" << endl;
}

