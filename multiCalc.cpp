// Copyright (c) 2022 Nicolas Riscalas All rights reserved.
//
// Created by: Nicolas Riscalas
// Created on:April 25 2022
// This program figures out the area of a triangle

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstring>

using std::cin;
using std::cout;
using std::stof;
using std::stoi;
using std::string;

float energy(float mass) {
    int c = 3 * pow(10, 8);
    float energy = mass * c;
    return energy;
}

float area(float side[3]) {
    float s = (side[0] + side[1] + side[2]) / 2;
    float area = sqrt(s * (s - side[0]) * (s - side[1]) * (s - side[2]));
    return area;
}

float perimeter(float side[3]) {
    float perimeter = side[0] + side[1] + side[2];
    return perimeter;
}

int main() {
    // try again loop
    while (true) {
        string garbage, calc;
        float sideU[3], answer, massU;
        try {
            cout << "What would you like to calculate "\
                    "(E = Energy/A = Area of Triangle/P "\
                    "= Perimeter of Triangle: ";
            getline(cin, calc, '\n');
            transform(calc.begin(), calc.end(), calc.begin(), ::toupper);
            if (calc == "E" || calc == "ENERGY") {
                cout << "What is the mass of the object: ";
                cin >> massU;
                answer = energy(massU);
                cout << "The energy of this object is " << answer << "\n";
            } else if (calc == "A" || calc == "AREA") {
                cout << "Enter the sides of the triangle: ";
                for (int i = 0; i < 3; ++i) {
                    cin >> sideU[i];
                }
                answer = area(sideU);
                cout << "The area of the triangle is " <<\
                        std::fixed << std::setprecision(2) << answer << "\n";
            } else if (calc == "P" || calc == "PERIMETER") {
                cout << "Enter the sides of the triangle: ";
                for (int i = 0; i < 3; ++i) {
                    cin >> sideU[i];
                }
                answer = perimeter(sideU);
                cout << "The perimeter of the triangle is " << answer << "\n";
            } else {
                cout << "You have to input a valid answer";
            }
        } catch (...) {
            cout << "You have to input valid values\n";
        }
        cin.get();
        cout << "\nIf you would like to calculate again just press <enter>: ";
        if (cin.get() == '\n') {
            continue;
        } else if (cin.get() != '\n') {
            cin >> garbage;
            continue;
        }
    }
}
