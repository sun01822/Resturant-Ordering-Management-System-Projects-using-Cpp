#include <bits/stdc++.h>
#include <ctime>
#include <fstream>
using namespace std;

void mainPage();
void inputOrder();
void inputOrderItem();
void viewSales();
bool findOrder(string s);
void choiceOption();
void displayItemOrder(vector<string> v);
time_t now = time(0);
tm *gmtm = gmtime(&now);
char *dt = asctime(gmtm);
vector<string> v;
map<string, int> mp;
int total_amount = 0;
string customer_name, address, customer_contact;

int main()
{
    while(1)
    {
        system("cls");
        mainPage();
        int op;
        cout << "______________________________________________________\n";
        cout << "Input 1, 2, or 3: ";
        cin >> op;
        if(op==1)
        {
            v.clear();
            mp.clear();
            total_amount = 0;
            inputOrder();
        }
        else if(op==2){
            viewSales();
        }
        else if(op==3)
        {
            system("cls");
            cout << "Closing Time...Have a great day!" << endl;
            system("pause");

            break;
        }
        else
        {
            cout << "\nPlease enter valid input\n";
            system("pause");
        }
    }
    return 0;
}



void mainPage()
{
    cout << "-=* Welcome to MAMA MIA RESTURANT *=-\n";
    cout << "______________________________________________________\n";
    cout << "1 - Input Order\n";
    cout << "2 - View Sales\n";
    cout << "3 - Close the Program\n";
}

void inputOrder()
{
    system("cls");
    cout << "-=* Welcome to MAMA MIA RESTURANT *=-\n";
    cout << "______________________________________________________" << endl;
    cout << "ULAM MENU" << endl;
    cout << "______________________________________________________" << endl;

    cout << "\t" << "SLOG MEALS" << endl;
    cout << "\t\tS1" << setw(30) << "Tocilog" << setw(20) << "80.00" << endl;
    cout << "\t\tS2" << setw(30) << "Tapsilog" << setw(20) << "80.00" << endl;
    cout << "\t\tS3" << setw(30) << "Porksilog" << setw(20) << "80.00" << endl;
    cout << "\t\tS4" << setw(30) << "Chicksilog" << setw(20) << "80.00" << endl;

    cout << "\tPORK" << endl;
    cout << "\t\tP1" << setw(30) << "Lechon Kawali" << setw(20) << "60.00" << endl;
    cout << "\t\tP2" << setw(30) << "Sisig with Egg" << setw(20) << "60.00" << endl;
    cout << "\t\tP3" << setw(30) << "Tokwat Baboy" << setw(20) << "60.00" << endl;
    cout << "\t\tP4" << setw(30) << "Fried Liempo" << setw(20) << "75.00" << endl;
    cout << "\t\tP5" << setw(30) << "Dinakdakan" << setw(20) << "100.00" << endl;
    cout << "\t\tP6" << setw(30) << "BBQ" << setw(20) << "100.00" << endl;
    cout << "\t\tP7" << setw(30) << "Bistek" << setw(20) << "150.00" << endl;
    cout << "\t\tP8" << setw(30) << "Sweet and Sour Pork" << setw(20) << "150.00" << endl;

    cout << "\t" << "CHICKEN" << endl;
    cout << "\t\tC1" << setw(30) << "Fried Chicken" << setw(20) << "80.00" << endl;
    cout << "\t\tC2" << setw(30) << "Fillet" << setw(20) << "80.00" << endl;
    cout << "\t\tC3" << setw(30) << "Bistek" << setw(20) << "100.00" << endl;
    cout << "\t\tC4" << setw(30) << "Cordon Bleu" << setw(20) << "120.00" << endl;
    cout << "\t\tC5" << setw(30) << "Honey Glazed" << setw(20) << "120.00" << endl;
    cout << "\t\tC6" << setw(30) << "Buffalo Wings" << setw(20) << "150.00" << endl;

    cout << "\t" << "VEGETABLES" << endl;
    cout << "\t\tV1" << setw(30) << "Fresh Lumpia" << setw(20) << "80.00" << endl;
    cout << "\t\tV2" << setw(30) << "Fried Lumpia" << setw(20) << "80.00" << endl;
    cout << "\t\tV3" << setw(30) << "Chopsuey" << setw(20) << "100.00" << endl;
    cout << "\t\tV4" << setw(30) << "Ensalada" << setw(20) << "120.00" << endl;

    cout << "\t" << "DRINKS" << endl;
    cout << "\t\tD1" << setw(30) << "Gulaman" << setw(20) << "50.00" << endl;
    cout << "\t\tD2" << setw(30) << "Lemonade" << setw(20) << "50.00" << endl;
    cout << "\t\tD3" << setw(30) << "Buko Juice" << setw(20) << "50.00" << endl;
    cout << "\t\tD4" << setw(30) << "Coke 1.5 L" << setw(20) << "70.00" << endl;
    cout << "\t\tD5" << setw(30) << "Sprite 1.5 L" << setw(20) << "70.00" << endl;
    cin.ignore();
    cout << "\nCustomer Name: ";
    getline(cin, customer_name);
    cout << "Customer Address: ";
    getline(cin, address);
    cout << "Customer Contact Number: ";
    getline(cin, customer_contact);
    cout << "CUSTOMER ORDER\n";
    inputOrderItem();
    sort(v.begin(), v.end());
    displayItemOrder(v);
    while(1)
    {
        int choice;
        choiceOption();
        cin >> choice;
        if(choice==1)
        {
            cout << "=======================================================\n";
            cout << "TOTAL AMOUNT DUE: " << total_amount << endl;
            cout << "DATE AND TIME OF ORDER: " << dt << endl;
            fstream Myfile("F:\\Project\\Billing System on Payment\\text.txt", std::ios_base::app);
            Myfile << "======================================================\n\n";
            Myfile << "CUSTOMER NAME: " << customer_name << endl;
            Myfile << "CUSTOMER ADDRESS: " << address << endl;
            Myfile << "CUSTOMER CONTACT NUMBER: " << customer_contact << endl;
            Myfile << "\n----------------------------------------------------\n";
            for(auto i: mp)
            {
                if(i.first=="S1")
                {
                    Myfile << "\t" << i.second << " * " << "80" << setw(20) << "Tocilog" << endl;
                }
                else if(i.first=="S2")
                {
                    Myfile << "\t" << i.second << " * " << "80" << setw(20) << "Tocilog" << endl;

                }
                else if(i.first=="S3")
                {
                    Myfile << "\t" << i.second << " * " << "80" << setw(20) << "Porksilog" << endl;
                }
                else if(i.first=="S4")
                {
                    Myfile << "\t" << i.second << " * " << "80" << setw(20) << "Chicksilog" << endl;
                }
                else if(i.first=="P1")
                {
                    Myfile << "\t" << i.second << " * " << "60" << setw(20)  << "Lechon Kawali"<< endl;
                }
                else if(i.first=="P2")
                {
                    Myfile << "\t" << i.second << " * " << "60" << setw(20) << "Sisig with Egg" << endl;
                }
                else if(i.first=="P3")
                {
                    Myfile << "\t" << i.second << " * " << "60" << setw(20) << "Tokwat Baboy" << endl;
                }
                else if(i.first=="P4")
                {
                    Myfile << "\t" << i.second << " * " << "75" << setw(20) << "Fried Liempo" << endl;
                }
                else if(i.first=="P5")
                {
                    Myfile << "\t" << i.second << " * " << "100" << setw(20) << "Dinakdakan" << endl;
                }
                else if(i.first=="P6")
                {
                    Myfile << "\t" << i.second << " * " << "100" << setw(20) << "BBQ" << endl;
                }

                else if(i.first=="P7")
                {
                    Myfile << "\t" << i.second << " * " << "150" << setw(20) << "Bistek" << endl;
                }

                else if(i.first=="P8")
                {
                    Myfile << "\t" << i.second << " * " << "150" << setw(20) << "Sweet and Sour Pork" << endl;
                }

                else if(i.first=="C1")
                {
                    Myfile << "\t" << i.second << " * " << "80" << setw(20) << "Fried Chicken" << endl;
                }
                else if(i.first=="C2")
                {
                    Myfile << "\t" << i.second << " * " << "80" << setw(20) << "Fillet" << endl;
                }
                else if(i.first=="C3")
                {
                    Myfile << "\t" << i.second << " * " << "100" << setw(20) << "Bistek" << endl;
                }
                else if(i.first=="C4")
                {
                    Myfile << "\t" << i.second << " * " << "120" << setw(20) << "Cordon Bleu" << endl;
                }

                else if(i.first=="C5")
                {
                    Myfile << "\t" << i.second << " * " << "120" << setw(20) << "Honey Glazed" << endl;
                }

                else if(i.first=="C6")
                {
                    Myfile << "\t" << i.second << " * " << "150" << setw(20) << "Buffalo Wings" << endl;
                }

                else if(i.first=="V1")
                {
                    Myfile << "\t" << i.second << " * " << "80" << setw(20) << "Fresh Lumpia" << endl;
                }
                else if(i.first=="V2")
                {
                    Myfile << "\t" << i.second << " * " << "80" << setw(20) << "Fried Lumpia" << endl;
                }
                else if(i.first=="V3")
                {
                    Myfile << "\t" << i.second << " * " << "100" << setw(20) << "Chopsuey" << endl;
                }
                else if(i.first=="V4")
                {
                    Myfile << "\t" << i.second << " * " << "120" << setw(20) << "Ensalada" << endl;
                }

                else if(i.first=="D1")
                {
                    Myfile << "\t" << i.second << " * " << "50" << setw(20) << "Gulaman" << endl;
                }
                else if(i.first=="D2")
                {
                    Myfile << "\t" << i.second << " * " << "50" << setw(20) << "Lemonade" << endl;
                }
                else if(i.first=="D3")
                {
                    Myfile << "\t" << i.second << " * " << "50" << setw(20) << "Buko Juice" << endl;
                }
                else if(i.first=="D4")
                {
                    Myfile << "\t" << i.second << " * " << "70" << setw(20) << "Coke 1.5 L" << endl;
                }
                else if(i.first=="D5")
                {
                    Myfile << "\t" << i.second << " * " << "70" << setw(20) << "Sprite 1.5 L" << endl;
                }
            }
            Myfile << "TOTAL AMOUNT DUE: " << total_amount << endl;
            Myfile << dt << endl;
            Myfile.close();
            cin.ignore();
            break;
        }
        else if(choice==2)
        {
            total_amount=0;
            v.clear();
            mp.clear();
            inputOrderItem();
            displayItemOrder(v);
        }
        else if(choice==3)
        {
            cout << "ORDER HAS BEEN CANCELLED" << endl;
            cin.ignore();
            break;
        }
    }
    system("pause");
    mainPage();
}

void viewSales()
{
    system("cls");
    string mytext;
    fstream MyReadFile("F:\\Project\\Billing System on Payment\\text.txt");
    int count=0;
    while(getline(MyReadFile, mytext))
    {
        cout << mytext << endl;
        count++;
    }
    if(count==0)
        cout << "No saved record for orders" << endl;
    else
        cout << "\n\n\nALL RECORDS HAS BEEN DISPLAYED" << endl;
    MyReadFile.close();
    system("pause");
}

bool findOrder(string s)
{
    if(s=="s1"||s=="S1")
        return true;
    else if(s=="s2"||s=="S2")
        return true;
    else if(s=="s3"||s=="S3")
        return true;
    else if(s=="s4"||s=="S4")
        return true;
    else if(s=="p1"||s=="P1")
        return true;
    else if(s=="p2"||s=="P2")
        return true;
    else if(s=="p3"||s=="P3")
        return true;
    else if(s=="p4"||s=="P4")
        return true;
    else if(s=="p5"||s=="P5")
        return true;
    else if(s=="p6"||s=="P6")
        return true;
    else if(s=="p7"||s=="P7")
        return true;
    else if(s=="p8"||s=="P8")
        return true;
    else if(s=="c1"||s=="C1")
        return true;
    else if(s=="c2"||s=="C2")
        return true;
    else if(s=="c3"||s=="C3")
        return true;
    else if(s=="c4"||s=="C4")
        return true;
    else if(s=="c5"||s=="C5")
        return true;
    else if(s=="c6"||s=="C6")
        return true;
    else if(s=="v1"||s=="V1")
        return true;
    else if(s=="v2"||s=="V2")
        return true;
    else if(s=="v3"||s=="V3")
        return true;
    else if(s=="v4"||s=="V4")
        return true;
    else if(s=="d1"||s=="D1")
        return true;
    else if(s=="d2"||s=="D2")
        return true;
    else if(s=="d3"||s=="D3")
        return true;
    else if(s=="d4"||s=="D4")
        return true;
    else if(s=="d5"||s=="D5")
        return true;
    else
        return false;
}

void inputOrderItem()
{
    int input;
    cout << "\tHow many ULAM CODES do you need to input?: ";
    cin >> input;
    cin.ignore();
    int count = 0;
    for(int i=0; ; i++)
    {
        if(count==input)
            break;
        cout << "ULAM CODE: ";
        string temp;
        getline(cin, temp);
        if(findOrder(temp))
        {
            v.push_back(temp);
            count++;
        }
        else
            cout << "INVALID INPUT.";
    }
}

void choiceOption()
{
    cout << "\tIS THE ORDER IS CORRECT?" << endl;
    cout << "\t\t1 - YES" << endl;
    cout << "\t\t2 - NO, Input Again" << endl;
    cout << "\t\t3 - Cancel Order" << endl;
    cout << "\t\tInput 1,2,3: ";
}

void displayItemOrder(vector<string> v)
{
    cout << "=================================================\n";
    cout << "CUSTOMER NAME: " << customer_name << endl;
    cout << "CUSTOMER ADDRESS: " << address << endl;
    cout << "CUSTOMER CONTACT NUMBER: " << customer_contact << endl;
    cout << "\nSUMMARY OF ORDER" << endl;
    for(int i=0; i<v.size(); i++)
    {
        if(v[i]=="s1"||v[i]=="S1")
            mp["S1"]++;
        else if(v[i]=="s2"||v[i]=="S2")
            mp["S2"]++;
        else if(v[i]=="s3"||v[i]=="S3")
            mp["S3"]++;
        else if(v[i]=="s4"||v[i]=="S4")
            mp["S3"]++;
        else if(v[i]=="p1"||v[i]=="P1")
            mp["P1"]++;
        else if(v[i]=="p2"||v[i]=="P2")
            mp["P2"]++;
        else if(v[i]=="p3"||v[i]=="P3")
            mp["P3"]++;
        else if(v[i]=="p4"||v[i]=="P4")
            mp["P4"]++;
        else if(v[i]=="p5"||v[i]=="P5")
            mp["P5"]++;
        else if(v[i]=="p6"||v[i]=="P6")
            mp["P6"]++;
        else if(v[i]=="p7"||v[i]=="P7")
            mp["P7"]++;
        else if(v[i]=="p8"||v[i]=="P8")
            mp["P8"]++;
        else if(v[i]=="c1"||v[i]=="C1")
            mp["C1"]++;
        else if(v[i]=="c2"||v[i]=="C2")
            mp["C2"]++;
        else if(v[i]=="c3"||v[i]=="C3")
            mp["C3"]++;
        else if(v[i]=="c4"||v[i]=="C4")
            mp["C4"]++;
        else if(v[i]=="c5"||v[i]=="C5")
            mp["C5"]++;
        else if(v[i]=="c6"||v[i]=="C6")
            mp["C6"]++;
        else if(v[i]=="v1"||v[i]=="V1")
            mp["V1"]++;
        else if(v[i]=="v2"||v[i]=="V2")
            mp["V2"]++;
        else if(v[i]=="v3"||v[i]=="V3")
            mp["V3"]++;
        else if(v[i]=="v4"||v[i]=="V4")
            mp["V4"]++;
        else if(v[i]=="d1"||v[i]=="D1")
            mp["D1"]++;
        else if(v[i]=="d2"||v[i]=="D2")
            mp["D2"]++;
        else if(v[i]=="d3"||v[i]=="D3")
            mp["D3"]++;
        else if(v[i]=="d4"||v[i]=="D4")
            mp["D4"]++;
        else if(v[i]=="d5"||v[i]=="D5")
            mp["D5"]++;
    }

    for(auto i: mp)
    {
        if(i.first=="S1")
        {
            cout << i.second << " * " << "80" << setw(20) << "Tocilog" << endl;
            total_amount+=(i.second*80);
        }
        else if(i.first=="S2")
        {
            cout << i.second << " * " << "80" << setw(20) << "Tocilog" << endl;
            total_amount+=(i.second*80);
        }
        else if(i.first=="S3")
        {
            cout << i.second << " * " << "80" << setw(20) << "Porksilog" << endl;
            total_amount+=(i.second*80);
        }
        else if(i.first=="S4")
        {
            cout << i.second << " * " << "80" << setw(20) << "Chicksilog" << endl;
            total_amount+=(i.second*80);
        }
        else if(i.first=="P1")
        {
            cout << i.second << " * " << "60" << setw(20)  << "Lechon Kawali"<< endl;
            total_amount+=(i.second*60);
        }
        else if(i.first=="P2")
        {
            cout << i.second << " * " << "60" << setw(20) << "Sisig with Egg" << endl;
            total_amount+=(i.second*60);
        }
        else if(i.first=="P3")
        {
            cout << i.second << " * " << "60" << setw(20) << "Tokwat Baboy" << endl;
            total_amount+=(i.second*60);
        }
        else if(i.first=="P4")
        {
            cout << i.second << " * " << "75" << setw(20) << "Fried Liempo" << endl;
            total_amount+=(i.second*75);
        }
        else if(i.first=="P5")
        {
            cout << i.second << " * " << "100" << setw(20) << "Dinakdakan" << endl;
            total_amount+=(i.second*100);
        }
        else if(i.first=="P6")
        {
            cout << i.second << " * " << "100" << setw(20) << "BBQ" << endl;
            total_amount+=(i.second*100);
        }

        else if(i.first=="P7")
        {
            cout << i.second << " * " << "150" << setw(20) << "Bistek" << endl;
            total_amount+=(i.second*150);
        }

        else if(i.first=="P8")
        {
            cout << i.second << " * " << "150" << setw(20) << "Sweet and Sour Pork" << endl;
            total_amount+=(i.second*150);
        }

        else if(i.first=="C1")
        {
            cout << i.second << " * " << "80" << setw(20) << "Fried Chicken" << endl;
            total_amount+=(i.second*80);
        }
        else if(i.first=="C2")
        {
            cout << i.second << " * " << "80" << setw(20) << "Fillet" << endl;
            total_amount+=(i.second*80);
        }
        else if(i.first=="C3")
        {
            cout << i.second << " * " << "100" << setw(20) << "Bistek" << endl;
            total_amount+=(i.second*100);
        }
        else if(i.first=="C4")
        {
            cout << i.second << " * " << "120" << setw(20) << "Cordon Bleu" << endl;
            total_amount+=(i.second*120);
        }

        else if(i.first=="C5")
        {
            cout << i.second << " * " << "120" << setw(20) << "Honey Glazed" << endl;
            total_amount+=(i.second*120);
        }

        else if(i.first=="C6")
        {
            cout << i.second << " * " << "150" << setw(20) << "Buffalo Wings" << endl;
            total_amount+=(i.second*150);
        }

        else if(i.first=="V1")
        {
            cout << i.second << " * " << "80" << setw(20) << "Fresh Lumpia" << endl;
            total_amount+=(i.second*80);
        }
        else if(i.first=="V2")
        {
            cout << i.second << " * " << "80" << setw(20) << "Fried Lumpia" << endl;
            total_amount+=(i.second*80);
        }
        else if(i.first=="V3")
        {
            cout << i.second << " * " << "100" << setw(20) << "Chopsuey" << endl;
            total_amount+=(i.second*100);
        }
        else if(i.first=="V4")
        {
            cout << i.second << " * " << "120" << setw(20) << "Ensalada" << endl;
            total_amount+=(i.second*120);
        }

        else if(i.first=="D1")
        {
            cout << i.second << " * " << "50" << setw(20) << "Gulaman" << endl;
            total_amount+=(i.second*50);
        }
        else if(i.first=="D2")
        {
            cout << i.second << " * " << "50" << setw(20) << "Lemonade" << endl;
            total_amount+=(i.second*50);
        }
        else if(i.first=="D3")
        {
            cout << i.second << " * " << "50" << setw(20) << "Buko Juice" << endl;
            total_amount+=(i.second*50);
        }
        else if(i.first=="D4")
        {
            cout << i.second << " * " << "70" << setw(20) << "Coke 1.5 L" << endl;
            total_amount+=(i.second*70);
        }
        else if(i.first=="D5")
        {
            cout << i.second << " * " << "70" << setw(20) << "Sprite 1.5 L" << endl;
            total_amount+=(i.second*70);
        }

    }
}
