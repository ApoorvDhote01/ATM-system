#include<conio.h>
#include<iostream>
#include<string>

using namespace std;

class atm
{
private:
    long int account_No ;
    string name;
    int PIN  ;
    double balance;
    string Mobile_no;

public:

    void setData(long int account_No_a , string name_a , int pin_a , double balance_a , string mobile_no_a ) 
    {
        account_No = account_No_a;
        name = name_a;
        PIN = pin_a;
        balance = balance_a;
        mobile_no = mobile_no_a;
    } 

    long int getAccountNo()
    {
        return account_No;
    }
    string getName()
    {
        return name;
    }
    int getPIN()
    {
        return PIN;
    }
    double getBalance(){
        return balance;
    }
    string getMobileno(){
        return mobile_no;
    }

    void setMobile(string mob_prev , string mob_new)
    {
        if ( mobile_no == mob_prev)
        {
            mobile_no = mob_new;

            cout << endl << " Sucessfully Updated Mobile No." ;
            getch();
        }
        else
        {
            cout << endl << " Incorrect !! Please enter correct Old mobile No.";
            getch();
        }
    }
    void Cashwithdraw(amount_a)
    {
        if(amount_a > 0 && amount_a < balance)
        {

            balance -= amount_a;

            cout<<endl << "Please Collect your cash !" ;

            cout << endl << "Available Balance : " << balance;
            getch();
        }
        else
        {
            cout << endl << " Invalid amount entered Or Insufficient Balance !";
            getch();
        }
    }
};    
int main()
{

    int choice, enterPIN;
    long int enterAccountNo;

    system ("cls");

    atm user1;
    user1.setData(12345678, "Apoorv", 1987 , 75000 , "9131404094");

    do
    {
        system("cls");
        cout << endl << "*****Welcome To ATM*****" << endl;
        cout << endl << "Enter Your Account_No ";
        cin>>enterAccountNo;
        cout<<endl << " Enter PIN " ;
        cin >>enterPIN;


        if((enterAccountNo == user1.getAccountNo()) && (enterPIN == user1.getPIN()))
        {
            do
            {
                int amount = 0;
                string oldMobileNo , newMobileNo;
                system ("cls");
                cout<< endl << "***** Welcome to ATM *****"<< endl;
                cout << endl << " Select Options ";
                cout << endl << "1. Check Balance ";
                cout << endl << "2. Cash Withdraw ";
                cout << endl << "3. ShowUser Details ";
                cout << endl << "4. Update Mobile No. ";
                cout << endl << "5. Exit "<< endl;
                cin>>choice;

                switch(choice)
                {
                case 1:
                cout << endl << "Your Bank Balance is : "<< user1.getBalance() ;
                getch();
                break;

                case 2:
                cout << endl << "Enter the amount :";
                cin>>amount ;
                user1.Cashwithdraw(amount);
                break;

                case 3:
                cout << endl << " The User Details are :-";
                cout << endl << "-> Account No. :" << user1.getAccountNo();
                cout << endl << "-> Name :" << user1.getName();
                cout << endl << "-> Balance : "<< user1.getBalance();
                cout << endl << "-> Mobile No. :"<< user1.getMobileno();

                getch();
                break;

                case 4:
                cout << endl <<" Enter the old Mobile No. : ";
                cin>> oldMobileNo;
                cout << endl <<" Enetr the New Mobile No. :";
                cin>> newMobileNo;

                user1.setMobile(oldMobileNo , newMobileNo);
                break;

                case 5:
                exit(0);

                default :
                cout << endl << " Entered Invalid Input ! ";
                }
            }while(1);
            
        }
        else
        {
            cout << endl << " User Details are Invalid !!! ";
            getch();
        }
      

    }
    return (0);
}
