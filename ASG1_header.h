#include <sstream>
using namespace std;

typedef unsigned int Student[25][10];

// is_number
// 
// Purpose: To check that given number is a number or not   
// Parameter(s): 
//    <1> string s: A word which might be a number in a form of a string    
// Precondition(s): N/A
// Returns: It returns 1 if string contains all the numbers. Like '99', '100'.
//          0 otherwise
// Side effect: If argument is a number with a space(like, ' 92') is passed, it will not 
// consider it as a number and returns 0 becase ' '(space) is not an integer.

bool is_number(string s)
{
    for(int i = 0; i < s.length(); i++)
        if(isalpha(s[i]))
            return false;
    return true;
}


// get_result
// 
// Purpose: To calculate the sum of scores and number of exams along with a name and all scores 
// Parameter(s): 
//    <1> string arr[]: Array that contains all the information of a student including name, exams and scores
//                      Like, ["SPWKLZWHCIE", "GAPCEXAS", "11", "100", "88", "95", "94", "98", "100", "90", "71", "100", "92", '98']
//    <2> int len: Length of an array
//    <3> string name: Empty string 'name' for getting the name of student from an array
//    <4> int sub: To store the total no. of exams of a student
//    <5> int sum: To store the sum of a student
//    <6> string scores: To store the the scores of all the exams
// Precondition(s): N/A
// Returns: Arguments are passed by refference. So it will change the value however, it won't return anything
// Side effect: N/A
 

void get_result(string arr[], unsigned int len, string &name, unsigned int &sub, unsigned int &sum, string &scores)
{
	for(unsigned int i=0; i<len; i++)
	{
		string word = arr[i];
		if (is_number(word))
		{
			if(sub == 0)
				sub = stoi(word);

			else
            {
				sum += stoi(word);
                scores = scores + word + " ";
            }
		}

		else
			name = name + ' ' + word;
    }
}


// str_to_array
// 
// Purpose: To convert the given string into an array seprated by a space(' ')
// Parameter(s): 
//    <1> string arr[]: An array to store the values as an element seprated by a space
//    <2> string str: A line(string) from a file for conversion
// Precondition(s): N/A
// Returns: Array are by default passing by a reffrence. Hence, array will be updated without returning anything 
//          
// Side effect: If there are more than 2 spaces in a string, function will consider remaining spaces as an elemet of an array
// 

void str_to_array(string arr[], string str)
{   
    string word = "";
    unsigned int index = 0;

    for(unsigned int i=0; i< str.size(); i++)
    {
        char ch = str[i];
        if (ch == ' ')
        {   
            if(word.length() != 0)
            {
                arr[index++] = word;
                word = "";
            }
        }
        else
            word = word + ch;
    }
    arr[index] = word;
}

// count
// 
// Purpose: To count the number of spaces in a string for getting 
//          the size of an array to store the word os a astring as an elements
// Parameter(s): 
//    <1> string str: String for scanning 
//    <2> char ch: A character, by whom the functiion is goint to count the len(space in this case) 
// Precondition(s): 
// Returns: The count of a space ina  string 
//          
// Side effect: N/A
// 

int count(string str, char ch)
{
	unsigned int len = 0;
    for(auto ch1: str)
        if(ch1 == ch)
            len++;
	
	return len;
}


// get_grade
// 
// Purpose: To getting a grade of a student according to average score of exams
// Parameter(s): 
//    <1> float per: Average score of exams of a student
// Precondition(s): N/A
// Returns: The grade of a student according to the average score 
//          
// Side effect: N/A
// 

string get_grade(float per)
{
    if(per>= 90.00 && per<=100.00)
        return "A";

    else if(per>= 91.67 && per<=95.00)
        return "A-";

    else if(per>= 88.30 && per<=91.67)
        return "B+";

    else if(per>= 85.00 && per<=88.30)
        return "B";

    else if(per>= 81.67 && per<=85.00)
        return "B-";

    else if(per>= 78.33 && per<=81.67)
        return "C+";

    else if(per>= 75.00 && per<=78.33)
        return "C";

    else if(per>= 71.67 && per<=75.00)
        return "C-";

    else if(per>= 68.33 && per<=71.67)
        return "D+";

    else if(per>= 65.00 && per<=68.33)
        return "D";

    else if(per>= 61.67 && per<=65.00)
        return "D-";

    else if(per>= 00.00 && per<=61.67)
        return "F";

    else
        return "Grade doesn't exist";
}

// set_stutdent_data
// 
// Purpose: 
// Parameter(s): 
//    <1> string student_name[]: Array for storing a name of a student
//    <2> students_score[25][10]: 2-D array for storing the scores of a students
//    <3> string str: A string that contains studen't name and it's scores of all exams
//    <4> int row: No. of index
// Precondition(s): 
// Returns: Doesn't return anything. However, it will store the scores of all exams of all students 
//          
// Side effect: N/A 
// 

void set_stutdent_data(string student_name[], Student students_score, string str, int row)
{
    string word = "";

    string name;
    unsigned int col_index = 0;
    unsigned int len = count(str, ' ');    
    string arr[len];
    str_to_array(arr, str);

    for(unsigned int i=0; i< len; i++)
    {
        word = arr[i];
        if(is_number(word))
            students_score[row][col_index++] = stoi(word);

        else
            name = name + word + " ";
    }
    student_name[row] = name;
}

// get_sub_grade
// 
// Purpose: To get a grade of a subject according to the score of the subject
// Parameter(s): 
//    <1> float diff: A diffrence of average score and student score of particular exam
// Precondition(s): N/A
// Returns: A grade of exam
//          
// Side effect: N/A
// 

string get_sub_grade(float diff)
{
    if(diff<=5 && diff>= -5)
        return "C";

    else if(diff<=-5 && diff>= -15)
        return "D";
    
    else if(diff<= -15)
        return "F";
    
    else if(diff>= 5 && diff<= 15)
        return "B";
    
    else if(diff>= 15)
        return "A";

    else
        return "Grade doesn't exist";
}


// get_avg_score
// 
// Purpose: To get the average score of perticular exam
// Parameter(s): 
//    <1> students_score[25][10]: An array with all the scores of all exam to calculate the average score of exam  
//    <2> avg_score[]: To store the average score of an exam
//    <3> int sub: No. of exams
//    <4> int no_of_students: no. of students in exam
// Precondition(s): N/A
// Returns: Doesn't return anything. However, it will store the average score to an array
//          
// Side effect: N/A
// 

void get_avg_score(Student students_score, float avg_score[], int sub, int no_of_students)
{
    int score_index = 0;

    for(unsigned int col=0; col< sub; col++)
    {
      unsigned int sum = 0;
      for(unsigned int row=0; row< no_of_students; row++)
        sum += students_score[row][col];

      float avg_marks = float(sum)/no_of_students;
      avg_score[score_index++] = avg_marks;
    }

}