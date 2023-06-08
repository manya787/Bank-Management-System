#include <iostream>
#include <windows.h>
#include <cmath> // FOR MATHEMATICAL OPERATIONS
#include <string.h>
#include <fstream>
#include <iomanip> // FOR SET PRECISION
using namespace std;

int ac = 371450; // Initial account number for the customer
int cust = 0;    // Initial no. of customers

//                       -------------------------           //
//                          PARENT CLASS - BANK
//                       -------------------------           //
class Bank
{
public:
    int pin;
    int acc_no;
    string cust_name;
    float cust_mobile;
    int curr_bal;
    string last_trans;

    //      ---------------------     //
    //           SUB CLASS
    //      ----------------------    //

    class last_date // LAST TRANSACTION DATE
    {
    public:
        int date;
        int month;
        int year;
    } d;

    //         --------------------
    //              SUB CLASS
    //         --------------------
    class Date_of_birth
    {
    public:
        int date, month, year;
    } dob;
};

//               ------------------------------
//                  DERIVED CLASS - ACCOUNTS
//               ------------------------------

class Account : public Bank // PUBLICALLY DERIVED FROM BANK
{
public:
    void add_new();            //          ------>     TO ADD NEW CUSTOMERS               <-----        //
    void dispaly();            //          ------>     TO DISPALY CUSTOMER DETAILS        <-----        //
    void deposit();            //          ------>     TO DEPOSIT MONEY IN ACCOUNR        <-----        //
    void withdraw();           //          ------>    TO WITHDRAW MONEY FROM ACCOUNT      <-----        //
    void change_pin();         //          ------>      TO CHANGE THE PIN                 <-----        //
    void change_mobile();      //          ------>      TO CHANGE THE MOBILE NO.          <-----        //
    void transfer(Account &a); //          ------>  TO TRANSFER MONEY IN ANOTHER ACCOUNT  <-----        //
};

//                 --------------------------------           //
//                    TO MAKE THE INTRODUCTION
//                 --------------------------------           //
void intro()
{
    system("clear"); // TO CLEAR THE OUTPUT CONSOLE  //

    system("color 0a"); // TO CHANGE BACKGROUNG COLOR  //

    Sleep(2000);

    string top = "\n\tTOPIC : BANK MANAGEMENT SYSTEM ";

    for (int i = 0; i < top.length(); i++)
    {
        Sleep(100);
        cout << top[i];
    }

    cout << "\n\t-------------------------------\n"<< endl;
    Sleep(1000);

    system("pause"); // TO PAUSE THE RUNNING PROGRAM  //
    system("cls");
}

int a;
void transactions(); // TO PRINT ALL THE TRANSACTIONS THROUGH BANK
void view_account(); // TO PRINT DATA OF ALL ACCOUNT HOLDERS / CUSTOMERS

int main()
{

    intro();
    system("color 9");
    Account customer[10]; // ARRAY OF OBJECTS CREATED  //

    string str3 = "\t\t\t| NATIONAL BANK OF INDIA |\n";
    cout << "\t\t\t--------------------------\n";
    for (int i = 0; i < str3.length(); i++)
    {
        Sleep(100);
        cout << str3[i];
    }
    cout << "\t\t\t--------------------------\n";

    //              -----------------------         //
    //                      MENU
    //              -----------------------         //

    while (1)
    {

        cout << "\n\t\tPlease select the following services you want to use : \n"
             << endl;
        cout << "  1. Add new Customer \n";
        cout << "  2. Transfer money to another account\n";
        cout << "  3. Modify mobile number of customer\n";
        cout << "  4. Change Mpin\n";
        cout << "  5. Deposit Money\n";
        cout << "  6. Withdraw money\n";
        cout << "  7. View all the content of customers\n";
        cout << "  8. To view all transactions in the Bank" << endl;
        cout << "  9. To view all Account holders details \n";
        cout << "  10. Quit..\n";
        cin >> a;
        while (a > 10 || a < 1)
        {
            cout << "Invalid choice!!!!!!\n";
            cout << "Enter your choice : ";
            cin >> a;
        }

        int acc_choise;
        switch (a)
        {
        case 1:

            customer[cust].add_new();

            cust++;
            system("pause");
            Sleep(2000);
            system("cls");

            break;

        case 2:
        {
            int acc_1;
            int acc_2;

            cout << "\nEnter your account no. : ";
            cin >> acc_1;
            cout << "\nEnter the account no. in which you want to transfer the money : ";
            cin >> acc_2;
            for (int i = 0; i < cust; i++)
            {
                if (customer[i].acc_no == acc_1)
                {
                    for (int j = 0; j < cust; j++)
                    {
                        if (customer[j].acc_no == acc_2)
                        {
                            customer[i].transfer(customer[j]);
                        }
                    }
                }
            }
        }

            system("pause");
            Sleep(2000);
            system("cls");
            break;
        case 3:

            cout << "\nEnter the account no. in which you want to change mobile no. : ";
            cin >> acc_choise;
            for (int i = 0; i < cust; i++)
            {
                if (customer[i].acc_no == acc_choise)
                {
                    customer[i].change_mobile();
                    break;
                }
                if (i == cust)
                {
                    cout << "\nNO RECORD FOUND !! " << endl;
                }
            }
            system("pause");
            Sleep(2000);
            system("cls");

            break;
        case 4:

            cout << "Enter the account no. in which you want to change the Mpin : ";
            cin >> acc_choise;
            for (int i = 0; i < cust; i++)
            {
                if (customer[i].acc_no == acc_choise)
                {
                    customer[i].change_pin();
                    break;
                }
                if (i == cust)
                {
                    cout << "\nNO RECORD FOUND !! " << endl;
                }
            }
            system("pause");
            Sleep(2000);
            system("cls");
            break;
        case 5:

            cout << "Enter the account no. from which you want to deposit : ";
            cin >> acc_choise;
            for (int i = 0; i < cust; i++)
            {
                if (customer[i].acc_no == acc_choise)
                {
                    customer[i].deposit();
                    break;
                }
                if (i == cust)
                {
                    cout << "\nNO RECORD FOUND !! " << endl;
                }
            }
            system("pause");
            Sleep(2000);
            system("cls");
            break;

        case 6:

            cout << "Enter the account no. in which you want to withdraw : ";
            cin >> acc_choise;
            for (int i = 0; i < cust; i++)
            {
                if (customer[i].acc_no == acc_choise)
                {
                    customer[i].withdraw();
                    break;
                }
                if (i == cust)
                {
                    cout << "\nNO RECORD FOUND !! " << endl;
                }
            }
            system("pause");
            Sleep(2000);
            system("cls");
            break;

        case 7:

            cout << "Enter the account no. whose details you want to view : ";
            cin >> acc_choise;
            for (int i = 0; i < cust; i++)
            {
                if (customer[i].acc_no == acc_choise)
                {
                    customer[i].dispaly();
                    break;
                }
                if (i == cust)
                {
                    cout << "\nNO RECORD FOUND !! " << endl;
                }
            }
            system("pause");
            Sleep(2000);
            system("cls");
            break;

        case 8:
            transactions();
            system("pause");
            system("cls");
            break;

        case 9:
            view_account();
            system("pause");
            system("cls");
            break;
        }
        if (a == 10)
        {
            break;
        }
    }

    cout << "\n\n     =======>  Thank you for using our program   <======= " << endl;
    cout << "     =======>         Have a nice day            <=======  " << endl;

    return 0;
}

//       X----------X--------X------------X----------X          //
//                       MAIN PROGRAM ENDS
//       X----------X---------X-----------X----------X          //

void Account ::add_new()
{
    ofstream out2;
    out2.open("trans.bin", ios::app);
    ofstream out;
    out.open("accounts.bin", ios::app);
    cin.ignore();
    cout << "\nEnter the name of the customer :";
    getline(cin, cust_name);
    cout << "\nEnter the date (DD/MM/YYYY) : ";
    cin >> d.date >> d.month >> d.year;

    while (1)
    {
        cout << "\nEnter the mobile you want to register in your account : ";
        cin >> cust_mobile;
        if (cust_mobile < 6000000000)
        {
            cout << "\nInvalid number entered !!! ";
        }
        else
            break;
    }
    cout << "\nEnter your date of birth (DD/MM/YYYY): ";
    cin >> dob.date >> dob.month >> dob.year;
    while (1)
    {
        cout << "\nPlease enter the amount you want deposit (min. 5000) : ";
        cin >> curr_bal;
        last_trans = "credit";
        if (curr_bal < 5000)
        {
            cout << "\nPlease deposit amount greater than 5000" << endl;
        }
        else
            break;
    }

    cout << "\n\n\tCongratulations Account opened successfully !! " << endl;
    cout << "\tNow you can use other services like withdrawl , deposit , loan etc... " << endl;
    cout << "\n\tAccount no. : " << ac << endl;
    acc_no = ac;
    cout << "\n\tNOTE : Your First two digits of your Mpin are first two digits of your Account no." << endl
         << "\t       and last two digits are the month of your date of birth" << endl;
    pin = ((ac / 10000) * 100) + dob.month;
    out << "\n\nName : " << cust_name << "\nAccount no. : " << acc_no << "\nMobile no. : " << setprecision(15) << cust_mobile << "\nD.O.B : " << dob.date << "-" << dob.month << "-" << dob.year;
    out.close();
    out2 << d.date << "-" << d.month << "-" << d.year << "    " << acc_no << "      " << curr_bal << "      "
         << "credit    " << curr_bal << endl;
    out2.close();

    cust++;

    ac++;
}

//   ------------------------------------------------------------//

void Account ::dispaly()
{
    int p;

    int run = 2;
    while (run)
    {
        cout << "\nEnter the Mpin : ";
        cin >> p;
        if (p == pin)
        {

            cout << "    ========>  Details  <==========    " << endl;
            cout << "Name                  : " << cust_name << endl;
            cout << "Account no.           : " << acc_no << endl;
            cout << "D.O.B                 : " << dob.date << "-" << dob.month << "-" << dob.year << endl;
            cout << "Registered Mob.no.    : " << setprecision(15) << cust_mobile << endl;
            cout << "Current Balance (Rs)  : " << curr_bal << endl;
            cout << "Last transaction type : " << last_trans << endl;
            cout << "Last transaction date : " << d.date << "-" << d.month << "-" << d.year << endl;
            break;
        }
        else
            cout << "\nInvalid pin\n";
        run--;
        cout << run << " Chances left" << endl;
    }
}

// -------------------------------------------------------------  //

void Account ::deposit()
{
    ofstream out;
    out.open("trans.bin", ios::app);
    int depo;
    int p;
    int warn = 3;
    int run = 0;

    while (warn)
    {
        cout << "\nPlease enter your 4 digit Mpin : ";
        cin >> p;
        if (p == pin)
        {
            cout << "\nEnter the date (DD/MM/YYYY) : ";
            cin >> d.date >> d.month >> d.year;
            cout << "\nEnter the amount you want to deposit. : ";
            cin >> depo;
            curr_bal = curr_bal + depo;
            Sleep(1000);
            cout << "\n\nRs " << depo << " credited in your account !!" << endl;
            cout << "Current balance is : Rs " << curr_bal << endl;
            last_trans = "credit";
            out << d.date << "-" << d.month << "-" << d.year << "    " << acc_no << "      " << depo << "      "
        << "credit    " << curr_bal << endl;
    out.close();
            break;
        }
        else
            cout << "Incorret Mpin !! " << endl;
        warn--;
        cout << "Only " << warn << " chances left " << endl;
    }
    if (warn == 0)
        cout << "\nAccount freezed !!! " << endl;

}

//   -----------------------------------------------------    //

void Account ::withdraw()
{
    ofstream out;
    out.open("trans.bin", ios::app);
    int w;
    int p;
    int warn = 3;

    while (warn)
    {
        cout << "\nPlease enter your 4 digit Mpin : ";
        cin >> p;
        if (p == pin)
        {
            cout << "\nEnter the date (DD/MM/YYYY) : ";
            cin >> d.date >> d.month >> d.year;

            while (1)
            {

                cout << "\nEnter the amount you want to Withdraw. :  ";
                cin >> w;
                if (w < curr_bal)
                {
                    curr_bal = curr_bal - w;
                    Sleep(1000);
                    cout << "\n\nRs " << w << " Debited from your account !!" << endl;
                    cout << "Current balance is : Rs " << curr_bal << endl;
                    last_trans = "debit";
                    out << d.date << "-" << d.month << "-" << d.year << "    " << acc_no << "      " << w << "      "
        << "debit    " << curr_bal << endl;

                    break;
                }

                else
                {
                    cout << "\nInsufficient balance !! " << endl;
                }
            }
            break;
        }
        else
            cout << "\nIncorret Mpin !! " << endl;
        warn--;
        cout << "Only " << warn << " chances left " << endl;
    }
    if (warn == 0)
    {

        cout << "\nAccount Freezed !!" << endl;
    }
    if (curr_bal < 5000)
    {
        cout << "Rs 500 debited as for not maintaining minimum balance " << endl;
        curr_bal = curr_bal - 500;
        cout << "Updated Current balance : " << curr_bal << endl;
        out << d.date << "-" << d.month << "-" << d.year << "    " << acc_no << "      " << "500"<< "      "
        << "debit    " << curr_bal << endl;
    out.close();
    }
    out.close();

}

//    ------------------------------------------------------     //

void Account ::change_pin()
{
    int p;
    int np;
    int n = 3;
    while (n)
    {
        cout << "\nPlease enter your old Mpin : ";
        cin >> p;
        if (p == pin)
        {
            cout << "\nEnter your new Mpin : ";
            cin >> np;
            cout << "\nRe-enter your new Mpin : ";
            cin >> np;
            pin = np;
            cout << "\nMpin changed successfully !! " << endl;
            break;
        }
        else
        {
            cout << "\nInvalid Mpin " << endl;

            n--;
        }
    }
}

//    ----------------------------------------------------------    //

void Account ::transfer(Account &obj)
{
    ofstream out;
    out.open("trans.bin", ios::app);
    int run = 2;
    int p;
    int amount;
    while (run)
    {

        cout << "\nEnter your 4 digit Mpin : ";
        cin >> p;
        if (p == pin)
        {
            cout << "\nEnter the date (DD/MM/YYYY) : ";
            cin >> d.date >> d.month >> d.year;
            obj.d.date = d.date;
            obj.d.month = d.month;
            obj.d.year = d.year;

            while (1)
            {
                cout << "\nEnter the amount you want to transfer. : ";
                cin >> amount;
                if (amount < curr_bal)
                {
                    curr_bal = curr_bal - amount;
                    obj.curr_bal = obj.curr_bal + amount;
                    cout << "\nMoney transfered successfully !!" << endl;
                    last_trans = "debit";
                    obj.last_trans = "credit";
                    if (curr_bal < 5000)
                    {
                        cout << "Rs 500 is debited from tour account for not maintaining minimum balance" << endl;
                        curr_bal = curr_bal - 500;
                    }
                    break;
                }
                else
                {
                    cout << "\nInsufficient Balance !! " << endl;
                }
            }
            break;
        }
        else
        {
            cout << "\nInvalid pin !!" << endl;
            cout << run << " chances left " << endl;
            run--;
        }
    }
    out << d.date << "-" << d.month << "-" << d.year << "    " << acc_no << "      " << amount << "      "
        << "debit    " << curr_bal << endl;
    out << d.date << "-" << d.month << "-" << d.year << "    " << obj.acc_no << "      " << amount << "      "
        << "credit    " << obj.curr_bal << endl;
}

//     ----------------------------------------------------    //

void Account ::change_mobile()
{
    float mob;
    int p;
    int n = 2;
    while (n)
    {
        cout << "\nEnter your 4 digit Mpin : ";
        cin >> p;
        if (p == pin)
        {
            cout << "\nEnter your new mobile number : ";
            cin >> mob;
            cust_mobile = mob;
            cout << "\nMobile number updated sucessfully !! : ";
            break;
        }
        else
            cout << "\nInvalid mpin !!" << endl;
        n--;
    }
}

//      ------------------------------------------------------   //

void transactions()
{
    cout << "         NATIONAL BANK OF INDIA          " << endl;
    cout << "        ------------------------         " << endl;
    cout << "   Date  ||  Acc. no. ||  Amount || T-Type || Balance  " << endl;
    ifstream in;
    in.open("trans.bin", ios::in);
    string b;
    while (!in.eof())
    {
        getline(in, b);
        cout << b << endl;
    }
    in.close();
}


//       ---------------------------------------------------------- //

void view_account()
{
    cout << "         NATIONAL BANK OF INDIA          " << endl;
    cout << "        ------------------------         " << endl;
    ifstream in;
    in.open("accounts.bin", ios::in);
    string b;
    while (!in.eof())
    {
        getline(in, b);
        cout << b << endl;
    }
    in.close();
}
//   X---------------X----------------------X------------------------X--------------------      /
