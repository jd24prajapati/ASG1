# Assignment 1
This program is written in the C++ language.
<br>
>Input file for both problems are **grades_Section1.txt** and **grades_Section2.txt** respectively

# Problem 1

Input: The program will read the data of student's name, no. of exams and scores of the exams from a text file.
<br>
Ex. SPWKLZWHCIE GAPCEXAS 11 100 88 95 94 98 100 90 71 100 92 98<br>
>Where,
  SPWKLZWHCIE GAPCEXAS is the student’s name, 11 is the number of exam scores, and
  100 88 95 94 98 100 90 71 100 92 98 are the exam scores.
<!-- 
Which will be converted to an array saperated by a space which look like
["SPWKLZWHCIE", "GAPCEXAS", "11", "100", "88", "95", "94", "98", "100", "90", "71", "100", "92", "98"]

Another function will check that whether the element of the array is a string or a number and will be distribute accordingly.
The first integer value will be consider as a no. of exams and remaining will be the scores of the exam.

The average and a grade will be calculated based on the scores and will be save to a file namely, **grades_Section1_output.txt** -->

Output: The program will generate the text file namely, **grades_Section1_output.txt** having the date of student's name, no.of exams, scores and a grade equivalent to the average score

Solution to the above problem is in **ASG1_SEC1.cpp**, which imports **ASG1_header.h** header file.

# Problem 2

Input: Now, suppose the input file is modified. The number of students and number of scores are data items; the first line of the input file contains only the
number of students and number of scores. For example, the first line of an input file may contain 25 10, where 25 indicates number of students and 10 is the number of scores for all students.
 

Ex. SPWKLZWHCIE GAPCEXAS  99 100 91 68 72 100 93 74 77 96
>Where,
SPWKLZWHCIE GAPCEXAS is the student’s name and
99 100 91 68 72 100 93 74 77 96 are the exam scores.
<!-- 

A 2-D (25* 10)array will store the scores of all students and 
1-D array will store the name of students
Another 1-D array will store the average score according to the exam 
 
Then, the grade was counted according to diffrence of the average score and student's score-->
 
Output: The program will generate the text file namely, **grades_Section2_output.txt** having the date of student's name, and a score along with equivalent grade to score.

Solution to the above problem is in **ASG1_SEC2.cpp**, which imports **ASG1_header.h** header file.




