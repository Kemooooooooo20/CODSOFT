#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cctype>
#include<limits>

using namespace std;

int *random_value(int diff_level);
void welcome();
int check(int min,int falg);

//ptr[0] random number
//ptr[1] flag
int main()
{   
    int user_input;
    int diffculity;
    int state;
    int *ptr;


    //program core to compare the value by the gussed value
    
    while(true)
    {
    welcome();
    //to make sure that the value the user enters is from 1 to 4
    diffculity = check(1,4);
    cout<<"guess a number"<<endl;
    //this line to make a seed
    srand(time(0));
    //to get a random value
    ptr = random_value(diffculity);
    //to make sure that user inputs an integer    
    user_input = check(0,ptr[1]);
    while (user_input != ptr[0])
    {
        for(int k=9; k>0; k--)
        {
            if(user_input != ptr[0] && user_input < ptr[1])
            cout<<"you have "<<k<<" lives"<<endl;

            if (user_input <= ptr[1] && user_input > ptr[0])
            {
                cout<<"make it lower!"<<endl;
                while (!(cin >> user_input)) 
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please try again with valid input: "<< endl;
                }
            }
            
            else if (user_input <= ptr[1] && user_input < ptr[0] )
            {
                cout<<"make it higher!"<<endl;
            while (!(cin >> user_input)) 
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input! Please try again with valid input: "<< endl;
                }
            }
            else if(user_input > ptr[1])
            {
                
                while (!(cin >> user_input)) 
                {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "not a valid number please make sure that you entered an intger and in the range of the diffculty level\n" ;
                    break;
                }
                cout << "not a valid number please make sure that you entered an intger and in the range of the diffculty level\n" ;
                k++;
            }
            else
                break;
        }
        if(user_input != ptr[0])
            cout<<"you lose!"<<endl;
    break;
    }
    
    if(user_input == ptr[0])
    {
        cout << "thats true!" << endl;
    }    
        else
        {
            cout << "the random num was : "<<ptr[0] << endl;
        }
    cout <<"press 1 to quit and press 2 to retry"<<endl;
    state = check(1,2); 
    if (state == 1)
        break;
    else 
        continue;
    
    }
    return 0;
}



int *random_value(int diff_level)
{   
    static int a[2];
    static int flag;
    static int random_num ;
    if (diff_level == 1)
    {
       random_num = (rand() % 10) + 1;
       flag = 10;
    }
    else if (diff_level == 2)
    {
        random_num = (rand() % 100) + 1;
        flag = 100;
    }
    else if (diff_level == 3)
    {
        random_num = (rand() % 1000) + 1;
        flag = 1000;
    }
    else if (diff_level == 4)
    {
        random_num = (rand() % 10000) + 1;
        flag = 10000;
    }
        a[0] = random_num;
        a[1] = flag;
        return a;
}
void welcome()
{
    cout << "guess game !"<<endl;
    cout << "first you hve 10 lives to guess the number or you will lose!"<<endl;
    cout << "choose a level"<<endl <<"1.easy *NOTE* the numbers will be from 1 to 10"<<endl; 
    cout << "2.medium *NOTE* the numbers will be from 1 to 100"<<endl;
    cout << "3.hard *NOTE* the numbers will be from 1 to 1000"<<endl;
    cout << "4.extreme *NOTE* the numbers will be from 1 to 10000"<<endl<<"please note that your choice is the first char you input(incase you entered a number followed by a char!"<<endl;
}

int check(int min,int flag)
{
    while (true)
    {
        static int user_input;
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

/*int other_check(int num)
{
    while (!(cin >> num)) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please try again with valid input: "<< endl;
        }
    }
*/





/*

    bool validator(string input, int min_limit, int max_limit){
    for(int i=0; i<input.length(); ++i){
        if((int) input[i] < 48 || (int) input[i] > 57){
            "Your input cannot contain characters.. Try again!\n";
            return false;
        }
    }
    int num = stoi(input);
    if(num < min_limit || num >max_limit){
        "Your input is not within the allowed range.. Try again!\n";
        return false;
    }

    return true;
}*/