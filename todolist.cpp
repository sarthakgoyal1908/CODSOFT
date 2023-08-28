#include <iostream>
#include <vector>
using namespace std;
// Function to display the menu options
void displayMenu() {
    cout << "===== To-Do List Manager =====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Complete" << endl;
    cout << "4. Delete Task" << endl;
    cout << "5. Exit" << endl;
    cout << "==============================" << endl;
}
int main() {
    vector<pair<string, bool>> tasks; 
    int choice;
    string task;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter a new task: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, task);
                tasks.push_back(make_pair(task, false)); // Initialize the task as incomplete
                cout << "Task added successfully." << endl;
                break;

            case 2:
                if (tasks.empty()) {
                    cout << "No tasks to display." << endl;
                } else {
                    cout << "Tasks:" << endl;
                    for (int i = 0; i < tasks.size(); i++) {
                        cout << i + 1 << ". ";
                        if (tasks[i].second) {
                            cout << "[Complete] ";
                        } else {
                            cout << "[Incomplete] ";
                        }
                        cout << tasks[i].first << endl;
                    }
                }
                break;

            case 3:
                if (tasks.empty()) {
                    cout << "No tasks to mark as complete." << endl;
                } else {
                    int taskIndex;
                    cout << "Enter the task number to mark as complete: ";
                    cin >> taskIndex;

                    if (taskIndex >= 1 && taskIndex <= tasks.size()) {
                        tasks[taskIndex - 1].second = true;
                        cout << "Task marked as complete." << endl;
                    } else {
                        cout << "Invalid task number." << endl;
                    }
                }
                break;

            case 4:
                if (tasks.empty()) {
                    cout << "No tasks to delete." << endl;
                } else {
                    int taskIndex;
                    cout << "Enter the task number to delete: ";
                    cin >> taskIndex;

                    if (taskIndex >= 1 && taskIndex <= tasks.size()) {
                        tasks.erase(tasks.begin() + taskIndex - 1);
                        cout << "Task deleted successfully." << endl;
                    } else {
                        cout << "Invalid task number." << endl;
                    }
                }
                break;

            case 5:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
