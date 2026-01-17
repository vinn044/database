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



    cout << "Welcome to the database! Are you a new or returning member? ";
    cout << "Type 'new' for new member or 'returning' for returning member: ";

    string memberType;
    string filename = "userstorage.txt"; // my desired file name
    ofstream myFile(filename, ios::app); // open file in append mode for data persistence

    
    
    cin >> memberType;
    if (memberType == "returning") {

        // returning member login
        cout << "Enter username: ";
        cin >> username;
        
        
        


        cout << "Enter password: ";
        cin >> password;

        // Check if the username and password match the stored data
        ifstream checkFile(filename);
        string line;
        bool found = false;
        while (getline(checkFile, line)) {
            if (line.find("Username: " + username) != string::npos && line.find("Password: " + password) != string::npos) {
                found = true;
                break;
            }
        }
        checkFile.close();

        if (found) {
            cout << "Welcome back, " + username + "!" << endl;
            cout << "Select an option below: " << endl;
            cout << "1. View Profile" << endl;
            cout << "2. Update Profile" << endl;
            cout << "3. Delete Profile" << endl;
            cout << "4. Exit" << endl;
            int option;
            cin >> option;
            
            if (option == 1) {
                // View Profile
                cout << "Viewing Profile..." << endl;
            } else if (option == 2) {
                // Update Profile
                cout << "Updating Profile..." << endl;
            } else if (option == 3) {
                // Delete Profile
                cout << "Deleting Profile..." << endl;
            } else if (option == 4) {
                // Exit
                cout << "Exiting..." << endl;
            }

        } else {
            cout << "Invalid username or password." << endl;
        }
        
    } else if (memberType == "new") {


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

        myFile << "ID: " << id << "," << "Name: " << name << "," << "Age: " << age << "," << "Username: " << username << "," << "Password: " << password << "\n";


    myFile.close(); // close the file after writing
    cout << "Welcome" + name + "! You are now a member of the database" << endl;



    return 0;

    }
}