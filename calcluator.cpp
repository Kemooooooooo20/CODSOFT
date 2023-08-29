#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cctype>
#include<limits>
#include<math.h>

using namespace std;


bool validator(string input, int min_limit, int max_limit);
double add(double first_input,double second_input);
double subtract(double first_input,double second_input);
double mult(double first_input,double second_input);
double devide(double first_input,double second_input);
double power(double first_input,double second_input);
double check(double min,double flag);

int main()
{
    static double result;
    int i=0;
while(true)
{
    bool user_input01_case, user_input02_case, state_case;
    string user_input, second_user_input, operation, state;
    double user_input_num, second_user_input_num, prev_result[10]; int state_num;
    


cout<<"enter your operation separetied with spaces\n";
while (true)
{
   // cout<<"enter first number\n";
    cin>>user_input;
    user_input01_case = validator(user_input,-900000000,900000000);
    if(user_input01_case)
    {
    user_input_num = stod(user_input);
    break;
    }
    else
    continue;
}


while(true)
{
    //cout<<"choose the operation \n ";
    cin>>operation;
    if (operation == "+")
    {
    break;
    }
    else if (operation == "-")
    {

    break;
    }
    else if (operation == "*")
    {

    break;}
    else if (operation == "/")
    {
    break;
    }
    else if (operation == "^")
    {
    break;
    }
    else
    {
        cout<<"wrong input please try again\n";
        continue;
    }
}

while (true)
{
    //cout<<"enter second number\n";
    cin>>second_user_input;
    user_input02_case = validator(second_user_input,-900000000,900000000);
    if(user_input02_case){
    second_user_input_num = stod(second_user_input);
    break;
    }
    else
    continue;
}

    if (operation == "+")
    {
    result = add(user_input_num, second_user_input_num);
    cout << "ans = "<<result<<endl;
    }

    else if (operation == "-")
    {
    result = subtract(user_input_num, second_user_input_num);
    cout << "ans = "<<result<<endl;
    }

    else if (operation == "*")
    {
    result = mult(user_input_num, second_user_input_num);
    cout << "ans = "<<result<<endl;
    }

    else if (operation == "/")
    {
    result = devide(user_input_num, second_user_input_num);
    if (second_user_input_num != 0)
        cout << "ans = "<<result<<endl;
    }

    else if (operation == "^")
    {
        result = power(user_input_num, second_user_input_num);
        cout << "ans = "<<result<<endl;
    }

    prev_result[i] = result;
    cout << "the prev result was "<<prev_result[i-1]<<endl;
    i++;

while (true)
{
cout <<"if you want another process press 1, for quit press 2\n";
cin >> state;
state_case = validator(state, 1,2);
if(state_case)
break;
}
state_num = stoi(state);
if(state_num == 1)
{
    continue;
}
else
break;
}
return 0 ;
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

double add(double first_input,double second_input)
{
    double result = first_input + second_input;
    return result;
}

double subtract(double first_input,double second_input)
{
    double result = first_input - second_input;
    return result;
}

double mult(double first_input,double second_input)
{
    double result = first_input * second_input;
    return result;
}

double devide(double first_input,double second_input)
{
    if (second_input == 0)
        cout<<"syntax error!\n";
    else
    {
    double result = first_input / second_input;
    return result;
    }
}

double power(double first_input,double second_input)
{
    double result = pow(first_input,second_input);
    return result;
}

double check(double min,double flag)
{
    while (true)
    {
        static double user_input;
        scanf("%d",&user_input);
        if (user_input>=min && user_input<=flag)
        {
            // process with your input then use break to end the while loop
            return user_input;
            break;
        }
        else
        {
            cout<<"Wrong input! try Again."<<endl;
            continue;
        }
    }
}