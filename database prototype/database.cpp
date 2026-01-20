#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
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
    string filename = "userstorage.txt";
    
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

                // Extract user details from the line
                size_t idPos = line.find("ID: ");
                size_t namePos = line.find("Name: ");
                size_t agePos = line.find("Age: ");

                // Extract ID
                if (idPos != string::npos) {
                    id = stoi(line.substr(idPos + 4));
                }
                // Extract Name
                if (namePos != string::npos) {
                    size_t nameStart = namePos + 6;
                    size_t nameEnd = line.find(",", nameStart);
                    name = line.substr(nameStart, nameEnd - nameStart);
                }
                // Extract Age
                if (agePos != string::npos) {
                    size_t ageStart = agePos + 5;
                    size_t ageEnd = line.find(",", ageStart);
                    if (ageEnd == string::npos) ageEnd = line.length();
                    age = stoi(line.substr(ageStart, ageEnd - ageStart));
                }

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
                cout << "Here is your profile information:" << endl;
                cout << "ID: " << id << endl;
                cout << "Name: " << name << endl;
                cout << "Age: " << age << endl;
                cout << "Username: " << username << endl;
                cout << "Password: " << password << endl;

            } else if (option == 2) {
                // Update Profile

                cout << "What changes would you like to make to your account?: " << endl;
                cout << "1. Change Username" << endl;
                cout << "2. Change Password" << endl;
                int updateOption;
                cin >> updateOption;
                if (updateOption == 1) {
                    cout << "Enter new username: ";
                    cin >> username;
                    cout << "Username updated successfully!" << endl;
                } else if (updateOption == 2) {
                    cout << "Enter new password: ";
                    cin >> password;
                    cout << "Password updated successfully!" << endl;
                }
                
                // Rewrite the file with updated user info
                ifstream inputFile(filename);
                ofstream tempFile("temp.txt");
                string fileLine;
                while (getline(inputFile, fileLine)) {
                    if (fileLine.find("ID: " + to_string(id)) != string::npos) {
                        tempFile << "ID: " << id << "," << "Name: " << name << "," << "Age: " << age << "," << "Username: " << username << "," << "Password: " << password << "\n";
                    } else {
                        tempFile << fileLine << "\n";
                    }
                }
                inputFile.close();
                tempFile.close();
                remove(filename.c_str());
                rename("temp.txt", filename.c_str());
            
            } else if (option == 3) {
                // Delete Profile
                cout << "Are you sure you want to delete your profile? (yes/no): ";
                string confirm;
                cin >> confirm;

                if (confirm == "yes") {
                    // Rewrite the file without the deleted user info
                    ifstream inputFile(filename);
                    ofstream tempFile("temp.txt");
                    string fileLine;
                    while (getline(inputFile, fileLine)) {
                        if (fileLine.find("ID: " + to_string(id)) == string::npos) {
                            tempFile << fileLine << "\n";
                        }
                    }
                    inputFile.close();
                    tempFile.close();
                    remove(filename.c_str());
                    rename("temp.txt", filename.c_str());
                    cout << "Profile deleted successfully." << endl;
                } else {
                    cout << "Profile deletion canceled." << endl;
                }

            
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

    ofstream myFile(filename, ios::app);
    myFile << "ID: " << id << "," << "Name: " << name << "," << "Age: " << age << "," << "Username: " << username << "," << "Password: " << password << "\n";
    myFile.close();
    cout << "Welcome" + name + "! You are now a member of the database" << endl;



    return 0;

    }
}