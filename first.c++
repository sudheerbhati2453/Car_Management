#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

vector<string> areas(10);
int Adj[10][10];
class Graph
{
    int V;
    int adj[10][10];

public:
    Graph(int n);
    void addEdge(int u, int v, int w);
    int shortestPath(int s, int d);
    void floyd_warshall(int adj[10][10]);
    int minDistance(int dist[], bool sptSet[])
    {

      
        int min = INT_MAX;
        int min_index;

        for (int v = 0; v < V; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;

        return min_index;
    }
};

Graph::Graph(int n)
{
    V = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }
}

void Graph::addEdge(int u, int v, int w)
{
    adj[u][v] = w;
    adj[v][u] = w;
}

int Graph::shortestPath(int src, int dest)
{
    int dist[V];

    bool sptSet[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

  
    dist[src] = 0;

   
    for (int count = 0; count < V - 1; count++)
    {

        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)

            if (!sptSet[v] && adj[u][v] && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
    }

    return dist[dest];
}

void Graph::floyd_warshall(int adj[10][10])
{
    int n = V; 

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (i == j)
            {
                adj[i][j] = 0;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX && adj[i][k] + adj[k][j] < adj[i][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == INT_MAX)
            {
                adj[i][j] = -1;
            }
        }
    }
}

Graph g(10);

class cabbooking
{
public:
    void home_page();
    void cabbooking_holidays();
};


class user : public cabbooking
{
private:
    string account_no, address, email_id, contact_no;
    string name;
    float balance;
    int age;
    // for cab drivers
    string cabname, user_id, cab_no, cabemail_id, cabcontact_no;
    int earnings, cabaddress;
    int rides;
    int maxprice;

public:
    void menu1();
    void menu();
    void add_new();
    void display();
    void modify();
    void search();
    void book_cab();
    void feed_back();
    void userHelpdesk();
    void cabmenu1();
    void cabmenu();
    void cabadd_details();
    void cabdisplay();
    void cabmodify();
    void cabsearch();
};
void user::menu()
{
    system("cls");
    int choice;
    char x;
    cout << "\n o------------------------------------------- 1. LOGIN: ---------------------------------------------------o";
    cout << "\n o------------------------------------------- 2. SIGNUP: ---------------------------------------------------o";
    cout << "\n ENTER YOUR CHOICE :";
    cin >> choice;
    switch (choice)
    {
    case 1:
        search();
        break;
    case 2:
        add_new();
        break;
    }
}
void user::add_new()
{
    system("cls");
    // making a file
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- ADD DETAILS OF NEW user MEMBER ---------------------------------------------" << endl;

    cout << "\t\t\tEnter Name: ";
    cin >> name;
    cout << "\t\t\t Enter your age:";
    cin >> age;
    cout << "\t\t\tEnter Email Id: ";
    cin >> email_id;
    cout << "\t\t\tEnter Contact No: ";
    cin >> contact_no;
    cout << "\t\t\tEnter Address PINCODE: ";
    cin >> address;

    file.open("userRecord.txt", ios::app | ios::out);
    file << " " << name << " "
         << " " << age << " "
         << " " << email_id << " " << contact_no << " " << address << "\n";
    file.close();
    cout << "\n Record Added successfully !!";
    menu1();
}

// Display the details of the user members
void user::book_cab()
{
    int f;
    areas[0] = "Sector 62";
    areas[1] = "Sector 128";
    areas[2] = "Botanical Garden";
    areas[3] = "Sector 18";
    areas[4] = "Vaishali";
    areas[5] = "Anand Vihar";
    areas[6] = "Rajiv Chowk";
    areas[7] = "Kashmere Gate";
    areas[8] = "Nehru Place";
    areas[9] = "Pari Chowk";
    g.addEdge(0, 1, 16);
    g.addEdge(0, 7, 18);
    g.addEdge(1, 2, 9);
    g.addEdge(1, 7, 25);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 8, 14);
    g.addEdge(2, 5, 14);
    g.addEdge(3, 4, 17);
    g.addEdge(3, 5, 17);
    g.addEdge(4, 5, 2);
    g.addEdge(5, 6, 11);
    g.addEdge(6, 7, 13);
    g.addEdge(6, 8, 13);
    g.addEdge(7, 8, 21);
    g.addEdge(9, 5, 38);
    g.addEdge(9, 3, 27);

    int dist, dist2;
    char confirmation;
    int pickup, drop;
    int cab_type;
    cout << "\nYou can book a cab between following areas:- ";
    for (int i = 0; i < areas.size(); i++)
    {
        cout << "\n"
             << i + 1 << ". " << areas[i];
    }
    cout << "\nEnter your choice of pickup location : ";
    cin >> pickup;
    cout << "\nEnter your choice of drop location : ";
    cin >> drop;
    cout << "\nYou can book a cab of following types:- ";
    cout << "\n 1. Mini-Non-Ac \n 2. Mini-Ac \n 3. Sedan \n 4. Luxury";
    cout << "\nEnter your choice of cab type : [1/2/3/4]:";
    cin >> cab_type;

  
    g.floyd_warshall(Adj);

    dist = g.shortestPath(pickup - 1, drop - 1);

    cout << "\nShortest path between " << areas[pickup - 1] << " and " << areas[drop - 1] << " is of " << dist << " kms.";
    int fare = (7 + cab_type * 2) * dist;
    cout << "\nFare of your trip would be Rs." << fare << ".00! Are you sure you want to book a cab?[Y/N]:";
    cin >> confirmation;
    fstream file2;
    file2.open("cabdriverRecord.txt", ios::in | ios::out);
    string cname = "";
    string mob;
    string cabno;

    if (confirmation == 'Y')
    {
        while (!file2.eof())
        {
            file2 >> cabname >> user_id >> cab_no >> cabemail_id >> cabcontact_no >> cabaddress >> earnings >> rides;
            if (cabaddress == pickup)
            {
                cname = cabname;
                mob = cabcontact_no;
                cabno = cab_no;

                break;
            }
        }

        if (cname == "")
            cout << "No Cab Drivers Found for this location!";
        else
            cout << endl;
        cout << "******Cab Booked Successfully!******" << endl
             << endl;
        cout << cname << " is on its way will be reaching in few minutes!";
        cout << endl;
        cout << "CONTACT No: " << mob << endl;
        cout << "CAB No: " << cabno << endl;

        file2.close();
    }

    else if (confirmation == 'N')
    {
        cout << "Booking CANCELED!" << endl;
        menu1();
    }
}



void user::display()
{
    system("cls");
    fstream file;

    int total = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- user Record Table ----------------------------------------------" << endl;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n Name\t\tAccount Number\t\tbalance\t\tEmail Id\t\tcontact_no\t\taddress";
    file.open("userRecord.txt", ios::in);

    if (!file)
    {
      
        cout << "\n\t\t\tNo Data Is Present!";
        file.close();
    }
    else
    {
        file >> name >> age >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            cout << "\n"
                 << ((total + 1) + 1) << ")" << name << "\t\t" << account_no << "\t\t" << balance << "\t\t" << email_id << "\t\t" << contact_no << "\t\t\t" << address;
            file >> name >> account_no >> age >> balance >> email_id >> contact_no >> address;
        }
    }
    if (total == 0)
    {
        cout << "\n No Data is present";
    }
    file.close();
    cout << "\n";
    menu1();
}

void user::modify()
{
    system("cls");
    fstream file, file1;
    string mobno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- user Modify Details ------------------------------------------" << endl;
    file.open("userRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        cout << "\nEnter mob no Number of user which you want to Modify: ";
        cin >> mobno;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> age >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (mobno != contact_no)

                file1 << " " << name << " "
                      << " " << age << " "
                      << " " << email_id << " " << contact_no << " " << address << "\n";
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Email Id: ";
                cin >> email_id;
                cout << "\t\t\tEnter Contact No.: ";
                cin >> contact_no;
                cout << "\t\t\tEnter Address PINCODE: ";
                cin >> address;
                file1 << " " << name << " "
                      << " " << age << " "
                      << " " << email_id << " " << contact_no << " " << address << "\n";
                
            }
            file >> name >> age >> email_id >> contact_no >> address;
            if (found == 0)
            {
                cout << "\n\n\t\t\t user Account Number Not Found....";
            }
        }
        file1.close();
        file.close();
        remove("userRecord.txt");
        rename("record.txt", "userRecord.txt");
        menu1();
    }
}

void user::search()

{
    system("cls");
    fstream file;
    int found = 0;
    file.open("userRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- user Search Data ------------------------------------------" << endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string mobno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- user Search Data ------------------------------------------" << endl;
        cout << "\n Enter Mobile Number of user Which You Want to Search: ";
        cin >> mobno;
        file >> name >> age >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (mobno == contact_no)
            {
                cout << "\n\t\t\t user Name: " << name << endl;
                cout << "\t\t\t user Age:" << age << endl;
                cout << "\t\t\t user Email Id.: " << email_id << endl;
                cout << "\t\t\t user Address: " << address << endl;
                found++;
            }
            file >> name >> age >> email_id >> contact_no >> address;
        }

        if (found == 0)
        {
            cout << "\n\t\t\tuser Account Number Not Found...";
        }
        else
        {
            int c;
            cout << "\n 1. DO YOU WANT TO BOOK A RIDE:[YES->PRESS 1 | NO-> Press 2]";
            cout << "\n 3. MODIFY THE Details:";
            cout << "\n ENTER YOUR CHOICE:";
            cin >> c;
            switch (c)
            {
            case 1:
                book_cab();
                break;
            case 2:
                home_page();
            case 3:
                modify();
                break;
            }
        }
        file.close();
        menu1();
    }
}
void user::feed_back()
{
    system("cls");
    string feedback;
    string name;
    string suggestions;
    fstream file;
    int rating;

    cout << "\n Please Rate our cabbooking from 1 to 5";
    cout << "\n 5. Excellent";
    cout << "\n 4. Very Good";
    cout << "\n 3. Good enough";
    cout << "\n 2. Satisfied";
    cout << "\n 1. UnSatisfied";
    cout << "\n";
    cout << "\n Enter the ratings [1-5]:";
    cin >> rating;

    if (rating < 4)
    {
        cout << "\n Please give us Some suggestions to improve our system";
        cout << "\n Enter your Name:";
        cin >> name;
        cout << "\n Enter suggestions (max limit 200 words)::";
        cin >> suggestions;
        file.open("cabbookingFeedback.txt", ios::app | ios::in);
        file << " " << suggestions << "\n";
        file.close();
        cout << "\n Thanks for giving your valuable suggestions!";
        cout << "\n Your feedback will help us improve our services!" << endl;
    }
    else
    {
        cout << "\n Thank You !";
        cout << "\n We Appreciate that You are Loving our Services!!" << endl;
        cout << "\n Kindly rate us on Play Store : www.ridercab.com" << endl;
    }
}

void user::menu1()
{
    int ch;
   ;
    cout << endl;
    cout << "\n 1) Go to Home Page:";
    cout << "\n 2) Press 2 To EXIT!";
    cout << "\n Enter your choice:";
    cin >> ch;
    if (ch == 1)
    {
        home_page();
    }
    else if (ch == 2)
    {
        cout << "\n Thankyou for choosing our app";
    }
}

void user::cabmenu()
{
    system("cls");
    int choice;
    char x;
    cout << "\n ------------------------------------------------ (i) LOGIN------------------------------------------------";
    cout << "\n ------------------------------------------------ (ii) SIGNUP------------------------------------------------";
    cout << endl;
    cout << "\n ENTER YOUR CHOICE:";
    int choice2;
    cin >> choice2;
    switch (choice2)
    {
    case 1:
        cabsearch();
        break;
    case 2:
        cabadd_details();
        break;
    }
}

void user::cabadd_details()
{
    // system("cls");
    fstream file;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << "\n------------------------------------- ADD DETAILS OF NEW cabdriver MEMBER ---------------------------------------------" << endl;
    cout << "\n-----------------------------------------------------------------------------------------------------";
    cout << endl;
    cout << "\t\t\tEnter Name: ";
    cin >> cabname;
    cout << "\t\t\tEnter User Id: ";
    cin >> user_id;
    cout << "\t\t\tEnter cab_no: ";
    cin >> cab_no;
    cout << "\t\t\tEnter Email Id: ";
    cin >> cabemail_id;
    cout << "\t\t\tEnter Contact No: ";
    cin >> cabcontact_no;

    cout << "\t\t\tEnter Address PINCODE: ";

    cin >> cabaddress;
    cout << "\t\t\t Enter TOTAL earnings from our App:";
    cin >> earnings;
    cout << "\t\t\t Enter the Total Number of rides with us:";
    cin >> rides;
    file.open("cabdriverRecord.txt", ios::app | ios::out);
    file << " " << cabname << " " << user_id << " " << cab_no << " " << cabemail_id << " " << cabcontact_no << " " << cabaddress << " " << earnings << " " << rides << "\n";
    file.close();
    fstream file1;
    cout << "\n Maximum price will you charge from the customer:";
    cin >> maxprice;
    file1.open("price.txt", ios::app | ios::in);
    file1 << " " << maxprice << "\n";
    file1.close();
    menu1();
}

void user::cabdisplay()
{
    system("cls");
    fstream file;
    int total = 1;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- cabdriver Record Table ----------------------------------------------" << endl;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n Name\t\tUser Id\t\tcab_no\t\tEmail Id\t\tcontact_no\t\taddress";
    file.open("cabdriverRecord.txt", ios::in);
    if (!file)
    {
    
        cout << "\n\t\t\tNo Data Is Present...";
        file.close();
    }
    else
    {
        file >> cabname >> user_id >> cab_no >> cabemail_id >> cabcontact_no >> cabaddress >> earnings >> rides;
        while (!file.eof())
        {
            cout << "\n"
                 << total++ << ")" << cabname << "\t\t" << user_id << "\t\t" << cab_no << "\t\t" << cabemail_id << "\t\t" << cabcontact_no << "\t\t\t" << cabaddress << " \t\t\t " << earnings << " \t\t\t " << rides;
            file >> cabname >> user_id >> cab_no >> cabemail_id >> cabcontact_no >> cabaddress;
        }
    }
    file.close();
    cout << "\n";
    int ARRAY_SIZE = 10;
    int numbers[ARRAY_SIZE];
    int count = 0;
    fstream file1;

    file1.open("price.txt", ios::in);
    
    while (count < ARRAY_SIZE && file1 >> numbers[count])
    {
        count++;
    }
    file1.close();
    menu1();
}



void user::cabmodify()
{
    system("cls");
    fstream file, file1;
    string uid;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- cabdriver Modify Details ------------------------------------------" << endl;
    file.open("cabdriverRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
    }
    else
    {
        int maxprice[50];
        cout << "\nEnter User Id of cabdriver which you want to Modify: ";
        cin >> uid;
        file1.open("record.txt", ios::app | ios::out);
        file >> cabname >> user_id >> cab_no >> cabemail_id >> cabcontact_no >> cabaddress >> earnings >> rides;
        while (!file.eof())
        {
            if (uid != user_id)

                file1 << " " << cabname << " " << user_id << " " << cab_no << " " << cabemail_id << " " << cabcontact_no << " " << cabaddress << " " << earnings << " " << rides << "\n";
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                cin >> cabname;
                cout << "\t\t\tEnter User Id: ";
                cin >> user_id;
                cout << "\t\t\tEnter cab_no: ";
                cin >> cab_no;
                cout << "\t\t\tEnter Email Id: ";
                cin >> cabemail_id;
                cout << "\t\t\tEnter Contact No.: ";
                cin >> cabcontact_no;
                cout << "\t\t\tEnter Address: 0 -> Sector 62 || 1 -> Sector 128 || 2 -> Botanical Garden || 3 -> Sector 18 || 4 -> Vaishali || 5 -> Anand Vihar || 6 -> Rajiv Chowk || 7 -> Kashmere Gate || 8 -> Nehru Place || 9 -> Pari" << endl;
                cin >> cabaddress;
                file1 << " " << cabname << " " << user_id << " " << cab_no << " " << cabemail_id << " " << cabcontact_no << " " << cabaddress << " " << earnings << " " << rides << "\n";
                found++;
            }
            file >> cabname >> user_id >> cab_no >> cabemail_id >> cabcontact_no >> cabaddress >> earnings >> rides;

            if (found == 0)
            {
                cout << "\n\n\t\t\t cabdriver User Id Not Found....";
            }
        }
        file1.close();
        file.close();
        remove("cabdriverRecord.txt");
        rename("record.txt", "cabdriverRecord.txt");
        menu1();
    }
}

void user::cabsearch() 
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("cabdriverRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- cabdriver Search Data ------------------------------------------" << endl;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "\n\t\t\t No Data Is Present...";
    }
    else
    {
        string uid;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- cabdriver Search Data ------------------------------------------" << endl;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "\n Enter User Id of cabdriver Which You Want to Search: ";
        cin >> uid;
        file >> cabname >> user_id >> cab_no >> cabemail_id >> cabcontact_no >> cabaddress >> earnings >> rides;
        while (!file.eof())
        {
            if (uid == user_id)
            {
                cout << "\n\t\t\t cabdriver Name: " << cabname << endl;
                cout << "\t\t\t cabdriver User Id: " << user_id << endl;
                cout << "\t\t\t cabdriver cab_no: " << cab_no << endl;
                cout << "\t\t\t cabdriver Email Id.: " << cabemail_id << endl;
                cout << "\t\t\t cabdriver Address: " << cabaddress << endl;
                cout << "\t\t\t cabdriver Earnings From APP: " << earnings << endl;
                cout << "\t\t\t cabdriver RIDES: " << rides << endl;
                found++;
            }
            file >> cabname >> user_id >> cab_no >> cabemail_id >> cabcontact_no >> cabaddress >> earnings >> rides;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tcabdriver User Id Not Found...";
        }
        file.close();
        menu1();
    }
}

void user::userHelpdesk()
{

    system("cls");
    int choice_CH;
    cout << "\t\t\t-----------------------------" << endl;
    cout << "\t\t\t cabbooking user helpdesk " << endl;
    cout << "\t\t\t-----------------------------" << endl;
    cout << " 1. Complain A cab Driver" << endl;
    cout << " 2. TECHNICAL ISSUE" << endl;

    cout << " 3. FOR OTHER ISSUES CONTACT US:" << endl;
    // cout << " 5. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Choose Option:" << endl;
    cout << "---------------------------" << endl;
    cout << "Enter Your choice: ";
    cin >> choice_CH;
    cout << "--------------------------------------" << endl;
    cout << "\tWelcome to user helpdesk, How may we help you?" << endl;
    cout << "--------------------------------------" << endl
         << endl;

    switch (choice_CH)

    {

    case 1:
        system("cls");
        cout << "cab driver complain issue solver" << endl;
        cout << "Please reach to your nearest branch with following documents - " << endl
             << endl;
        cout << "1. https://help.cab_booking_system" << endl;
        cout << "2. Attach the screen shot" << endl;
        cout << "3. For Filing a police complaint Dial Helpline No: 991100XXXX" << endl;
        cout << endl;
        cout << "Thank You!!!" << endl;
        break;
    case 2:
        system("cls");
        cout << "Technical Issue" << endl;
        cout << "Please reach to your nearest branch with following documents - " << endl
             << endl;
        cout << "1. https://help.cab_booking_system" << endl;
        cout << "2. Attach the screen shot" << endl;
        cout << "3. Contact the tech team :8168578283|" << endl
             << endl;
        break;
    case 3:
        system("cls");
        cout << "Here are our contact details :" << endl
             << endl;
        cout << "\tCONTACT US AT: ->" << endl;
        cout << "\tLandline : 0124-2342342" << endl;
        cout << "\tMobile : 9899998999" << endl;
        cout
            << "\t** Charges may apply " << endl
            << endl;
        cout << "\tE-MAIL US AT: ->" << endl;
        cout << "\tusercare@rockzzcabbooking.com" << endl;
        cout << "\tusercare@rb99.com" << endl
             << endl;
        cout << "\tFollow us on Instagram at : the_officialRB" << endl;
        cout << "\tThank you!" << endl;
        break;
   
    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
        break;
    }

    int choicer;

    cout << "\n";
    cout << endl;
    cout << " -------------------------------------------------------------------------------------------------------";
    cout << endl;
    cout << "\t\t\t 1. Do You Want more help:";
    cout << endl;
    cout << " \t\t\t 2. Go to Homepage:";
    cout << endl;
    cout << " \t\t\t 3. Press Any Key TO Exit!";
    cout << " ------------------------------------------------------------------------------------------------------";
    cout << endl;
    cout << "\n Enter your Choice:";
    cin >> choicer;
    if (choicer == 1)
    {
        system("cls");
        userHelpdesk();
    }
    else if (choicer == 2)
    {
        home_page();
    }
    else
    {
        cout << "\n Thank You For Using Our cabbooking MANAGEMENT SYSTEM";
    }
}

void cabbooking::home_page()

{

    system("cls");
    cout << "\n\t\t\t\t -----------------------------------------------------------------------";
    cout << "\n\t\t\t\t |\t\t\tWELCOME TO THE HOME PAGE                       | ";
    cout << "\n\t\t\t\t -----------------------------------------------------------------------";
    cout << "\n";

    cout << "\n\t\t\t\t 1) FOR user MANAGEMENT:";
    cout << "\n\t\t\t\t 2) FOR cabdriver MANAGEMENT:";
    cout << "\n\t\t\t\t 3) Feed Back Portal";
    cout << "\n\t\t\t\t 4) user HelpDesk:";
    int ch;
    cout << endl;
    cout << endl;
    cout << "\n Please enter your choice:";
    cin >> ch;
    if (ch == 1)
    {
        user c;
        c.menu();
    }
    else if (ch == 2)
    {
        user s;
        s.cabmenu();
    }
    else if (ch == 3)
    {
        user c1;
        c1.feed_back();
    }
    else if (ch == 4)
    {
        user c3;
        c3.userHelpdesk();
    }
}
void user::cabmenu1()
{

    int ch;
    
    cout << "\n 1) Go to Home Page:";
    cout << "\n 2) Press 2 To EXIT !";
    cout << "\n Enter your choice:";
    cin >> ch;
    if (ch == 1)
    {
        home_page();
    }
    else if (ch == 2)
    {
        cout << "\n\t\tTHANK YOU FOR USING OUR SYSTEM";
        cout << "\n";
        cout << "\n\t\t#cabbooking MANAGEMENT SYSTEM";
        cout << "\n";
    }
    else
    {
        cout << "\n PLEASE ENTER A VALID CHOICE:";
    }
    system("cls");
}



int main()
{
    cout << endl;
    cout << " -----------------------------------------------------------------------";
    cout << endl;
    cout << " |\t\t\tcabbooking  MANAGEMENT  SYSTEM                       |";
    cout << " -----------------------------------------------------------------------";
    cout << endl;
    cout << "\n";

    cabbooking b;

    b.home_page();
}