#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cctype>
#include<limits>
#include<math.h>

using namespace std;

double GPA_calc(double grade[], double CH[]);
bool validator(string input, int min_limit, int max_limit);
string num_to_alpha(int n);

class student
{
    public:
    string student_name;
    string OVER_all_grade;
    double marks[10];
    double GPA;
    double CHS[10];
};

int main ()
{
student students[100];
string student_Name, Grade, Marks, GPa, Chs;
double  GPA_num,GPA_num__2 ;
int marks_num,count=1;
string mode,again;
bool mode_case,again_case;
int mode_num;

while (true)
{
cout << "**************Welcome in grading system app!************** \n**************\nplease mote that the max number of allowed students is 100! \n**************\nPlease chose a mode \n1.Add student \n2.Sort steudents based on their GPA \n3.Calculate student GPA \n0.Exit\n";
while(true)
{
cin >> mode;
mode_case = validator(mode, 0, 5);
if (mode_case == true)
{
    mode_num = stoi(mode);
    break;
}
else
    continue;
}


switch (mode_num)
{
case 0:                 /* exit*/
    break;

case 1:                 /*ADD A student*/
    cout<<"**************welcome in add stydent section!************** \n";
    for(int k=0; k<100; k++)
    {
        cout<<"enter student name\n";
        cin >> students[k].student_name;
        cout<<"enter student grades \nchoose the number of courses\n";
        cin >> marks_num;
        for(int i=0; i<marks_num; i++)
        {
            cout << "enter the "<< num_to_alpha(i+1)<<" grade\n";
            cin >> students[k].marks[i];
        }
        cout<<"enter the credit hour for each course\n";
        for(int i=0; i<marks_num; i++)
        {
            cout << "enter the "<< num_to_alpha(i+1)<<" credit hours\n";
            cin >> students[k].CHS[i];
        }
        cout<<"do you want to add another student?\nif yes press 1 if no press 0 \n";
        cin >> again;
        again_case = validator(again,0,1);
        if (again_case == true && again == "1")
        {
            count++;
            continue;
        }
        else
        {
        for (int u=0; u<100; u++)
        {
                GPA_num = GPA_calc(students[u].marks, students[u].CHS);
                students[k].GPA = GPA_num;
        }
        }
        break;
    }
    break;

case 2: /* Sort based on GPA */
    cout << "**************Welcome in sorting mode**************\n";
    
    for (int i = 0; i < 100; i++) {
        students[i].GPA = GPA_calc(students[i].marks, students[i].CHS);
        for (int j = 0; j < 100 - i - 1; j++) {
            if (students[j].GPA < students[j + 1].GPA) {
                // Swap GPA
                double tempGPA = students[j].GPA;
                students[j].GPA = students[j + 1].GPA;
                students[j + 1].GPA = tempGPA;

                // Swap student names
                string tempName = students[j].student_name;
                students[j].student_name = students[j + 1].student_name;
                students[j + 1].student_name = tempName;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        cout << students[i].student_name << "   " << students[i].GPA << endl;
    }
    
    cout << "do you want to try again?\nif yes press 1 if no press 0 \n";
    cin >> again;
    again_case = validator(again, 0, 1);
    if (again_case == true && again == "1")
        continue;
    else
        break;

    break;



case 3:   /*calc student GPA*/

while(true)
{   cout << "**************welcome in sorting mode**************\n";
    bool studentFound = false; // Add a flag to track if the student is found
    cout << "enter student name\n";
    cin >> student_Name;
    for (int i = 0; i < 100; i++) 
    {
        if(student_Name == students[i].student_name) {
            GPA_num__2 = GPA_calc(students[i].marks, students[i].CHS);
            cout << students[i].student_name << " has a gpa of "<< GPA_num__2<<endl;
            studentFound = true; // Set the flag to true when student is found
            break; // Exit the loop when student is found
        }
    }
        if (!studentFound) {
            cout << "Student not found\n";
        }

        cout<<"***************do you want to try again??**************\n**************if yes press 1 if no press 0 **************\n";
        cin >> again;
        again_case = validator(again,0,1);
        if (again_case == true && again == "1")
        continue;
        else
        break;
}


    break;

}
cout << "**************do you want another process?************** \n**************if yes press 1 for no press 0 **************\n";
cin >> again;
again_case = validator(again,0,1);
if (again_case == true && again == "1")
continue;
else
break;
}
return 0;
}

double GPA_calc(double grade[], double CH[])
{
     double GPA = 0.0;
     double g_GPA = 0.0;
     double C_H = 0.0;
     //int i,length = sizeof(grade)/sizeof(grade[0]);
    for(int i=0; i<10; i++)
    {
        g_GPA = g_GPA + ((double) grade[i] * (double)CH[i]);
        C_H +=CH[i];
    }
    GPA = (double) g_GPA / C_H ;
    return GPA;
    
}

bool validator(string input, int min_limit, int max_limit){
    for(int i=0; i<input.length(); ++i){
        if( (int) input[i] < 45 || (int) input[i] > 57 ){
            cout<<"Your input cannot contain characters.. Try again!\n";
            return false;
        }
    }
    double num = stold(input);
    if(num < min_limit || num >max_limit){
        cout<<"Your input is not within the allowed range.. Try again!\n";
        return false;
    }

  return true;
}
string num_to_alpha(int n)
{
    string out;
    if (n == 1)
    {
        out = "first";
    }
    else if (n == 2)
    {
        out = "second";
    }

    else if (n == 3)
    {
        out = "third";
    }
    
    else if (n == 4)
    {
        out = "fourth";
    }
    
    else if (n == 5)
    {
        out = "fifth";
    }
    
    else if (n == 6)
    {
        out = "sixth";
    }
    
    else if (n == 7)
    {
        out = "seventh";
    }

    else if (n == 8)
    {
        out = "eights";
    }
    else if (n == 9)
    {
        out = "ninth";
    }
    return out;
}
