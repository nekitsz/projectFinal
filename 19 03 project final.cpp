



#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Student {
	string first_name;
	string last_name;
	float average_grade;
};

Student students[100];
int student_count = 0;


void save_to_file() {
	ofstream file("student-list.txt");
	if (!file) {
		cout << "error openning file";
		return;
	}

	file << "list of students: ";
	for (int i = 0; i < student_count;i++) {
		file << students[i].first_name << " "
			<< students[i].last_name << " "
			<< students[i].average_grade << endl;
	}
}

void add_student() {
	if (student_count >= 100) {
		cout << "u can't add more than 100 students. \n";
		return;
	}
	cout << "enter name of a student: ";
	cin >> students[student_count].first_name;
	cout << "enter last name of a student: ";
	cin >> students[student_count].last_name;
	cout << "enter an average grade of a student: ";
	cin >> students[student_count].average_grade;

	if (students[student_count].average_grade > 12) {
		cout << "grade can't be higher than 12 :(";
		return;
	}
	student_count++;
	
	save_to_file();
}


void delete_student() {
	
	if (student_count == 0) {
		cout << "no students to delete";
		return;
	}
	string last_name;
	cout << "enter the last name of a student to delete: ";
	cin >> last_name;

	for (int i = 0; i < student_count;i++) {
		if (students[i].last_name == last_name) {
			for (int j = i; j < student_count - 1;j++) {
				students[j] = students[j + 1];
			}
			student_count--;
			cout << "student deleted \n";
			save_to_file();
			return;
		}
	}
	cout << "student wasn't found \n";
}

void edit_student() {
	string last_name;
	cout << "enter a last name of a student u want to change: ";
	cin >> last_name;

	for (int i = 0; i < student_count; i++) {
		if (students[i].last_name == last_name) {
			cout << "enter a new name of a student: ";
			cin >> students[i].first_name;
			cout << "enter a new average grade of a student: ";
			cin >> students[i].average_grade;
			cout << "info changed \n";
			save_to_file();
			return;
		}
	}
	cout << "student wasn't found \n";
}

void show_all_students() {
	if (student_count == 0) {
		cout << "there are 0 students \n";
		return;
	}
	for (int i = 0; i < student_count;i++) {
		cout << "\n name: " << students[i].first_name << "\n last name: " << students[i].last_name << "\n average grade: " << students[i].average_grade << endl;
	}
}

void find_student() {
	string last_name;
	cout << "enter a last name of a student: ";
	cin >> last_name;

	for (int i = 0; i < student_count;i++) {
		if (students[i].last_name == last_name) {
			cout << "\nfound: " << students[i].first_name << " " << students[i].last_name <<" ," << " average grade: " << students[i].average_grade << endl;
			return;
		}
	}
	cout << "student wasn't found \n";
}

void show_best_students() {
	bool found = false;
	for (int i = 0; i < student_count;i++) {
		if (students[i].average_grade > 10) {
			cout << students[i].first_name << "  " << students[i].last_name <<"  " << " average grade: " << students[i].average_grade << endl;
			found = true;
		}
	}

	if (!found) {
		cout << "there are no best students :( \n";
	}
}

int main() {
	int choice;
	do {
		cout << "\n\nMenu\n\n\n";
		cout << "1. add student\n";
		cout << "2. delete student\n";
		cout << "3. edit student\n";
		cout << "4. show all students\n";
		cout << "5. find student\n";
		cout << "6. show best students\n";
		cout << "7. exit\n";
		cout << "enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1: add_student();break;
		case 2: delete_student();break;
		case 3: edit_student();break;
		case 4: show_all_students();break;
		case 5: find_student();break;
		case 6: show_best_students();break;
		case 7: cout << "press any button to fisnih the program \n";break;
		default:cout << "wrong choice. please try again \n";
		}
	} while (choice != 7);

	return 0;
}