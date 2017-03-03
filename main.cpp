// 6c
//  main.cpp


#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


struct stdRecord
{
	string firstName;
	string lastName;
	double score;
};


void sortByScore(stdRecord myArray[], int numOfRecords)
{    //using the internal sort function for sorting sscore
	sort(myArray, myArray + numOfRecords, [](stdRecord const &a, stdRecord const &b){ return a.score < b.score; });
}


void sortByName(stdRecord myArray[], int numOfRecords) {
	//using the internal sort function for sorting names
	sort(myArray, myArray + numOfRecords, [](stdRecord const &a, stdRecord const &b){
		if (a.lastName == b.lastName)
			return a.firstName < b.firstName;
		else
			return a.lastName< b.lastName; });
}

int main()
{
	char choice;
	int numStudents = 0;
	stdRecord records[100];




	//int scores[100];
	string filename;
	ifstream fin;
	ofstream fout;

	while (true){
		cout << endl << endl;
		cout << "**************Menu*******************" << endl;
		cout << " Press K to Manually reset and re-enter the information" << endl;
		cout << " Press W to Write into a file  " << endl;
		cout << " Press R to Read from a file a new value of numStudents" << endl;
		cout << " Press D to Display the number of students and the list of all the scores currently stored in the array" << endl;
		cout << " Press M to Modify one of the scores by re-entering the score from the keyboard" << endl;
		cout << " Press Q to quit the program" << endl;
		cout << " Press S for Sorting the data" << endl;
		cout << " Press N for Sorting the data" << endl;
		cout << "***********************************\n\n" << endl;
		cout << "Choice: ";
		cin >> choice;
		switch (choice){
		case 'k':
		case 'K': cout << "Enter the number of students in the class: ";
			cin >> numStudents;
			if (numStudents<0 || numStudents>100)
			{
				cout << "INVALID OUTPUT!" << endl;
				break;
			}
			for (int i = 0; i<numStudents; i++) {
				cout << endl;
				cin.ignore();
				cout << "Enter the first name of the student: ";
				getline(cin, records[i].firstName);
				cout << "Enter the last name of the student: ";
				getline(cin, records[i].lastName);
				cout << "Enter the score of the student: ";
				cin >> records[i].score;
			}
			break;

		case 'w':
		case 'W': cout << "Enter the filename: ";
			cin >> filename;    //Accepting filename
			cout << endl;
			cout << "Using file name: " << filename << endl;
			fout.open(filename); //Opening file for writing
			fout << numStudents << endl; //Printing number of students to file as first line
			for (int i = 0; i<numStudents; i++) {
				fout << records[i].firstName << "\n";
				fout << records[i].lastName << "\n";
				fout << records[i].score << "\n";//Printing scores for use to file
			}
			fout.close();  //Saving and closing the file
			break;

			{   case 'r':
			case 'R':
				cout << "Enter the filename: ";
				cin >> filename;  //Accepting filename
				cout << endl;
				fin.open(filename);  //Opening the file for reading
				fin >> numStudents; //Accepting the first line as number of students
				if (numStudents<0 || numStudents>100)
				{
					cout << "INVALID OUTPUT!" << endl;
					break;
				}
				fin.ignore();
				cout << numStudents;
				for (int i = 0; i<numStudents; i++) {
					fin >> records[i].firstName;
					fin >> records[i].lastName;
					fin >> records[i].score;

				}
				fin.close();
				break;
			case 'd':
			case 'D': cout << "\n\n********* Displayed Scores ***********" << endl;
				for (int i = 0; i<numStudents; i++)
				{
					cout << records[i].firstName << endl;
					cout << records[i].lastName << endl;
					cout << records[i].score << endl;
				}

				cout << endl;
				int sum = 0;
				int low = records[0].score;
				int high = records[0].score;
				for (int j = 0; j<numStudents; j++)
				{
					if (records[j].score<low)
						low = records[j].score;
					if (records[j].score>high)
						high = records[j].score;
					sum = sum + records[j].score;

				}

				int average = sum / numStudents;
				cout << "The average score is: " << average << endl;
				cout << endl;
				cout << "Highest score is: " << endl;
				for (int j = 0; j<numStudents; j++)
				{
					if (records[j].score == high)
						cout << records[j].firstName << " " << records[j].lastName << " " << records[j].score << endl;


				}
				cout << endl;
				cout << "Lowest score is: " << endl;
				for (int j = 0; j<numStudents; j++)
				{
					if (records[j].score == low)
						cout << records[j].firstName << " " << records[j].lastName << " " << records[j].score << endl;


				}
				break;
			}
			{
			case 'M':
			case 'm': cout << "Enter the first name of student whoes score you wish to modify: ";
				string name;
				cin.clear();
				cin.ignore();
				getline(cin, name);
				cout << endl;
				int record_num = -1;
				for (int j = 0; j<numStudents; j++)
				{
					if (name.compare(records[j].firstName) == 0){
						record_num = j;
						break;
					}
				}
				if (record_num == -1)
				{
					cout << "Record not found!!!";
					break;
				}
				else{
					cout << "Enter the new details by clicking enter" << endl;
					//  cin.ignore();
					cout << "Enter the first name of the student: ";
					getline(cin, records[record_num].firstName);
					cout << endl;
					cout << "Enter the last name of the student: ";
					getline(cin, records[record_num].lastName);
					cout << endl;
					cout << "Enter the score of the student: ";
					cin >> records[record_num].score;
					cout << endl;
				}

				break;

			}
			{
			case 'q':
			case 'Q': cout << "Would you like to save the data in a file: ";
				char ch;
				cin >> ch;
				cout << endl;
				if (ch == 'Y' || ch == 'y'){
					cout << "Enter the filename: ";
					cin >> filename;    //Accepting filename
					cout << endl;
					cout << "Using file name: " << filename << endl;
					fout.open(filename); //Opening file for writing
					fout << numStudents << endl; //Printing number of students to file as first line
					for (int i = 0; i<numStudents; i++) {
						fout << records[i].firstName << "\n";
						fout << records[i].lastName << "\n";
						fout << records[i].score << "\n";//Printing scores for use to file
					}
					fout.close();
					cout << endl;
				}
				cout << "****************Thank you****************";
				return 0;
				break;
			}
		case 'S':
		case 's':   sortByScore(records, numStudents);

			break;
		case 'N':
		case 'n': sortByName(records, numStudents);
			break;

		}


	}

}
