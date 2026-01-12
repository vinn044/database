#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    int id;
    string name;
    int age;
    string username;
    string password;



    cout << "Welcome to the database! Are you a new or returning member?";
    cout << "Type 'new' for new member or 'returning' for returning member: ";

    string memberType;
    cin >> memberType;
    if (memberType == "returning") {
        // returning member login
        cout << "Enter username: ";
        cin >> username;

        cout << "Enter password: ";
        cin >> password;

        cout << "Welcome back, " + username + "!" << endl;
        return 0;
    } else (memberType == "new") {
        



    // asking user for credentials then storing
    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Age: ";
    cin >> age;

    cout << "username: ";
    cin >> username;

    cout << "password: ";
    cin >> password;

    cout << "Welcome" + name + "! You are now a member of the database" << endl;



    return 0;

    }
}