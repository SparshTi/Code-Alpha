#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<string, string> users;  // Stores username -> password

void registerUser() {
    string username, password;

    cout << "\n--- Register ---\n";
    cout << "Enter username: ";
    cin >> username;

    // Check if username already exists
    if (users.find(username) != users.end()) {
        cout << "Username already taken. Try another.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    // Save to map
    users[username] = password;
    cout << "Registration successful!\n";
}

void loginUser() {
    string username, password;

    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Check if credentials match
    if (users.find(username) != users.end() && users[username] == password) {
        cout << "Login successful! Welcome, " << username << "!\n";
    } else {
        cout << "Login failed. Invalid username or password.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n=== Simple Login System ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 3);

    return 0;
}
