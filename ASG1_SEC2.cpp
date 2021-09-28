// This program is written in the C++ language.

// Input: The program will read the 
// the first line of an input file may contain 25 10,
// where 25 indicates number of students and 10 is the number of scores for all students.
// 
// After that, name of student followed by scores from a text file

// Ex. SPWKLZWHCIE GAPCEXAS  99 100 91 68 72 100 93 74 77 96
// Where,
// SPWKLZWHCIE GAPCEXAS is the student’s name and
// 99 100 91 68 72 100 93 74 77 96 are the exam scores.
// 
// A 2-D (25* 10)array will store the scores of all students and 
// 1-D array will store the name of students
// Another 1-D array will store the average score according to the exam 
// 
// Then, the grade was counted according to diffrence of the average score and student's score
// 
// Output: The program will generate the text file having the date of student's name, and a grade equivalent to the average score with it's grade


#include<iostream>
#include<string>
#include<fstream>
#include <sstream>
#include <iomanip>
#include"ASG1_header.h"

using namespace std;

// Types defination fpr the array having 25 students and 10 columns for storing the scores of the students
typedef unsigned int Student[25][10];
int main()
{
  // Opening a file for reading the data
  ifstream in_file;
  in_file.open("grades_Section2.txt", ios::in);

  // Opening a file for writing the data
  ofstream out_file;
  out_file.open("grades_Section2_output.txt", ios::out);

  if(in_file.is_open()) // Check that whether the file is open or not
  {
    string str;

    // Reading the first line of a file which has no.of students and exams saperated by a space. Like, "25 10"
    // Hence, getting it's value, string will be converted into an array with an integer value like [25, 10]
    getline (in_file, str);  
    string arr[2];
    str_to_array(arr, str); // Converting string to array 

    // Getting the value of no. of students and exams
    unsigned int no_of_students = stoi(arr[0]);
    unsigned int sub = stoi(arr[1]);

    // Creating an array that contains all the names of students and scores(2- dimentional array)
    string students_name[no_of_students];
    Student students_score;

    // Getting the string line 
    // Storing the name and scores of exam in 'student_name' and 'students_score' respectivaly
    for (unsigned int student = 0; getline (in_file,str); student++)
      set_stutdent_data(students_name, students_score, str, student);

    in_file.close();  // Closing the file

    // Getting the average score of each exam and storing it in an array
    float avg_score[sub];
    get_avg_score(students_score, avg_score, sub, no_of_students);
	
    // Write all the resultant data into a file
    cout<< left<< setw(40)<<"Student name"<<"Marks/ grade\n"<< endl;
    out_file<< left<< setw(40)<<"Student name"<<"Marks/ grade\n"<< endl;
    out_file<< "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
  
    for(unsigned int row=0; row<no_of_students; row++)
    {      
      cout<< left<< setw(23)<< students_name[row]<<" ";
      out_file<< left<< setw(23)<< students_name[row]<<" "; // Writing student name

      for(unsigned int col=0; col<sub; col++)
      {
          float diff = 0;
          diff = students_score[row][col] - avg_score[col]; // Counting the diffrence of marks of student with the average score of the same exam for counting the grade

          string grade = get_sub_grade(diff); // Getting the grade of a student according to diffrence of score
          cout<< left<< setw(4)<<students_score[row][col]<< "/ "<< grade<< left<< setw(7)<<"  |"; 
          out_file<< left<< setw(3)<<students_score[row][col]<< "/ "<< grade<< left<< setw(7)<<"  |"; // Writing the data to a file
      }

      cout<< endl;
      out_file<< endl<< "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
    }
  }

  // Closing the file
  out_file.close();

  return 0;
}