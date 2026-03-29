#include <iostream>
#include "DeveloperManager.h"
#include "ProjectManager.h"
#include "FileManager.h"

using namespace std;

void menu() {
    cout << "\n===== MENU =====\n";
    cout << "1. Add Developer\n";
    cout << "2. Remove Developer\n";
    cout << "3. Search Developer\n";
    cout << "4. Update Salary\n";
    cout << "5. Sort Developer\n";
    cout << "6. Assign Project\n";
    cout << "7. Total Experience\n";
    cout << "8. Group Projects\n";
    cout << "9. Display Developers\n";
    cout << "0. Exit\n";
}

int main() {
    DeveloperManager dm;
    ProjectManager pm;
    FileManager fm;

    fm.loadDevelopers(dm.getList());
    fm.loadProjects(pm.getList());

    int choice;

    do {
        menu();
        cout << "Choose: ";
        cin >> choice;

        try {
            switch(choice) {
            case 1: dm.addDev();          break;
            case 2: dm.removeDev(pm);     break;
            case 3: dm.searchDev();       break;
            case 4: dm.updateSalary();    break;
            case 5: dm.sortDev();         break;
            case 6: pm.assignProject(dm); break;
            case 7: pm.totalExperience(); break;
            case 8: pm.groupProject();    break;
            case 9: dm.displayAll();      break;
            }
        }
        catch(exception &e) {
            cout << "Error: " << e.what() << endl;
        }

    } while(choice != 0);

    fm.saveDevelopers(dm.getList());
    fm.saveProjects(pm.getList());

    return 0;
}