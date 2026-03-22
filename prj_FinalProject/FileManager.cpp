#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

void FileManager::saveToCSV(const vector<Developer>& list, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Loi: Khong the mo file " << filename << " de ghi.\n";
        return;
    }

    // Ghi tiêu đề cột (Header)
    file << "DevID,Name,BirthYear,Languages,Salary\n";

    // Ghi dữ liệu từ vector
    for (const auto& dev : list) {
        file << dev.getDevID() << ","
             << dev.getName() << ","
             << dev.getBirthYear() << ","
             << dev.getLanguages() << ","
             << dev.getSalary() << "\n";
    }
    file.close();
}

void FileManager::loadFromCSV(vector<Developer>& list, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        // Nếu file chưa tồn tại (chạy lần đầu), cứ bỏ qua để tạo list trống
        return; 
    }

    list.clear();
    string line;
    
    // Đọc bỏ dòng Header
    getline(file, line);

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string id, name, lang, temp;
        int birthYear = 0;
        double salary = 0.0;

        // Cắt từng trường phân cách bởi dấu phẩy
        getline(ss, id, ',');
        getline(ss, name, ',');
        
        getline(ss, temp, ',');
        if (!temp.empty()) birthYear = stoi(temp);

        getline(ss, lang, ',');
        
        getline(ss, temp, ',');
        if (!temp.empty()) salary = stod(temp);

        // Đẩy vào vector
        Developer dev(id, name, birthYear, lang, salary);
        list.push_back(dev);
    }
    file.close();
}
