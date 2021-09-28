// This program is written in the C++ language.

// Input: The program will read the data of student's name, no. of exams and scores of the exams 
// from a text file
// Ex. SPWKLZWHCIE GAPCEXAS 11 100 88 95 94 98 100 90 71 100 92 98
// Where,
// SPWKLZWHCIE GAPCEXAS is the student’s name, 11 is the number of exam scores, and
// 100 88 95 94 98 100 90 71 100 92 98 are the exam scores.
// 
// Which will be converted to an array saperated by a space which look like
// ["SPWKLZWHCIE", "GAPCEXAS", "11", "100", "88", "95", "94", "98", "100", "90", "71", "100", "92", "98"]

// Another function will check that whether the element of the array is a string or a number and will be distribute accordingly.
// The first integer value will be consider as a no. of exams and remaining will be the scores of the exam.

// The average and a grade will be calculated based on the scores and will be save to a file namely, 'grades_Section1_output.txt'

// Output: The program will generate the text file having the date of student's name, no.of exams, scores and a grade equivalent to the average score


#include<iostream>
#include<fstream>
#include <iomanip>
#include"ASG1_header.h"
using namespace std;

int main()
{
    // Opening a file for reading the data
    ifstream in_file;
    in_file.open("grades_Section1.txt", ios::in);

    // Opening a file for writing the data
    ofstream outfile;
    outfile.open("grades_Section1_output.txt", ios::out);

    if(in_file.is_open())// Check that whether the file is open or not
    {
        // Setting the header for the output file
        outfile<< left<< setw(25)<< "Student name"<< left<< setw(15)<< "No. of exams"<< left<< setw(40)<< "Exam scores"<< fixed<< setprecision(2)<< left<< setw(20)<< "Avg. score"<< left<< setw(18)<< "Grade"<< endl;
        outfile<< "------------------------------------------------------------------------------------------------------------"<< endl;
        cout<<  left<< setw(30)<<"Name"<< left<< setw(20)<< "Percentage"<< "Grade"<< endl<< endl;
        cout<< "-----------------------------------------------------------"<< endl;
        string str;

        // Read the content of a file line by line
        while(getline (in_file,str))
        {            
            // String will be convered into an array of the size of 'no. of spaces'+ 1 
            // Getting the required size of an array 
            unsigned int len = 0;
            len = count(str, ' ') + 1;
            
            // 'str_to_array' will return an array with the words saperated by a space in a string
            // Like, "SPWKLZWHCIE GAPCEXAS 11 100 88 95 94 98 100 90 71 100 92 98
            // To, ["SPWKLZWHCIE", "GAPCEXAS", "11", "100", "88", "95", "94", "98", "100", "90", "71", "100", "92", '98']
            string arr[len];
            str_to_array(arr, str);

            // Getting the no. of exams as subjects, name and scores along with it's sum  
            string name= "";
            unsigned int sub=0, sum=0;
            string scores = "";
            get_result(arr, len, name, sub, sum, scores);

            // Getting the grade and average score of a student
            float per = (float)sum/ (float)sub;
            string grade = get_grade(per);

            // Writing and displying the resultant content  
            cout<< left<< setw(30)<<  name<< fixed<< setprecision(2)<< left<< setw(20)<<  per<< grade<< endl;
            cout<< "---------------------------------------------------------"<< endl;
            outfile<< left<< setw(25)<< name<< left<< setw(15) << sub<< left<< setw(40)<< scores<< left<< setw(20)<< per<< grade<< endl;
            outfile<< "---------------------------------------------------------------------------------------------------------"<< endl;
        }   
    }
    in_file.close();
    outfile.close();

    return 0;
}