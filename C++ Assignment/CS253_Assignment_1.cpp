#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;
#include <string>
#include <vector>
// A space_Travel System for travellimg form one plane to another planet on same date for more than 2 passengers
class Space_Travel
{
private:
    string Astro;        // Astronaut id for this travel
    string Commander;    // Commnander id for this travel
    vector<string> arr;  // arr storing traveller_id
    vector<string> name; // name storing traveller's name according to his/her id
    vector<string> id;   // id storing traveller's id set up by his/her
public:
    string Astro_name;         // Name of Astronaut for this travel
    string Commander_name;     // Name of Commander for this travel
    string source_planet;      // Source Planet for this travel
    string destination_planet; // Destination Planet for this travel
    int numberofdays;
    string date; // date on which this travel will take place
    int price;
    int l = 1;

public:
    void Add_Travellers(int r, string str); // function to add all the travellers for this travel
    string Return_Astronaut_id();
    string Return_Commander_id();
    string Return_traveller_id(string traveller_id);
    string Return_traveller_name(string traveller_id);
    string Return_id(string traveller_id);
    void List_All_Travellers(); // function to list all the travellers for this travel
    void Set_Astronaut_ID();
    void Set_Commander_ID();
    void Update_Astronaut_ID();
    void Update_Commander_ID();
    void Add_traveller_id(int x, string str);
    void Add_traveller_name(int x, string str);
    void Add_id(int x, string str); // function to store the id set up by each traveller
};
void Space_Travel ::Add_traveller_id(int x, string str)
{
    arr[x] = str;
}
void Space_Travel ::Add_traveller_name(int x, string str)
{
    name[x] = str;
}
void Space_Travel ::Add_id(int x, string str)
{
    id[x] = str;
}
void Space_Travel ::Add_Travellers(int r, string str)
{

    Add_traveller_id(r, str);

    // s.name[s.l] = t.Name;
    Add_traveller_name(r, str);
    // s.id[s.l] = t.ID;
    Add_id(r, str);
}

string Space_Travel ::Return_Astronaut_id()
{
    return Astro;
}
string Space_Travel ::Return_Commander_id()
{
    return Commander;
}
string Space_Travel ::Return_traveller_id(string traveller_id)
{
    int x = stoi(traveller_id, 0, 2);
    return arr[x];
}
string Space_Travel ::Return_id(string traveller_id)
{
    int x = stoi(traveller_id, 0, 2);
    return id[x];
}
string Space_Travel ::Return_traveller_name(string traveller_id)
{
    int x = stoi(traveller_id, 0, 2);
    return name[x];
}

class Planet
{
public:
    int x, y, z;
    string name;

public:
    void planetname();
};
void Planet ::planetname()
{
    cin >> name;
}
class Traveller
{
public:
    string Name;
    string ID;

    Space_Travel s1;

private:
    string Traveller_id; // unique id given to traveller for this travel

public:
    void set_traveller_id(int x);
    string get_traveller_id();
    void getname(string traveller_id);
    void getid(string traveller_id);
    int verifyid(string traveller_id);
    void get_ticket(string traveller_id);
    void updateid(string traveller_id);
};
void Traveller ::set_traveller_id(int x) // this function simply converting the number at which traveller is booking ticket to the base of 2 (binary number) and then putting it as traveller_id for that traveller
{
    int n = (int)(log2(x));

    // binary output
    // using the inbuilt function
    Traveller_id = bitset<64>(x).to_string().substr(64 - n - 1);
}
string Traveller ::get_traveller_id()
{
    return Traveller_id;
}
int Traveller ::verifyid(string traveller_id)
{ // this function is converting the traveller_id to decimal number and checking if it is less than toatl number of passenger the id is verified
    int x = stoi(traveller_id, 0, 2);
    if (x <= s1.l)
    {
        cout << "ID is verified";
        return 1;
    }

    else
    {
        cout << "ID is not verified";
        return 0;
    }
}

class Astronaut : public Traveller
{
private:
    int Years_Of_Experience;
    string license_id;

public:
    int get_YOE();

    string get_license_id();
};
class Commander : public Traveller
{
private:
    string Authority;

public:
    int Experience;
    string LicenseID;
    string get_authority();
};
class Ticket
{
public:
    int price_of_ticket;
    int number_of_days;

public:
    string date;
    // Traveller t;
    string source_station;
    string destination_station;
    Space_Travel s;
    Astronaut A;
    Commander C;

public:
    void bookTicket(Traveller t);
    void updateTicket(string traveller_id, Traveller t);
    void cancelTicket(string traveller_id, Traveller t);
    int total_price();
};
void Ticket ::cancelTicket(string traveller_id, Traveller t)
{
    int x = stoi(traveller_id, 0, 2);
    s.Add_traveller_id(x, "Ticket Cancelled");
    s.Add_traveller_name(x, "Ticket_Cancelled");
    s.Add_id(x, "Ticket Cancelled");
}
int distance(int x, int y, int z, int x1, int y1, int z1)
{
    int ans = sqrt((pow((x1 - x), 2)) + (pow((y1 - y), 2)) + (pow((z1 - z), 2)));
    return ans;
}
void Traveller ::getname(string traveller_id)
{

    cout << s1.Return_traveller_name(traveller_id);
}
void Traveller ::getid(string traveller_id)
{

    cout << s1.Return_id(traveller_id);
}
void Traveller ::get_ticket(string traveller_id)
{
    if (verifyid(traveller_id) == 1)
    { // if id is verified then only you will see your ticket
        int x = stoi(traveller_id, 0, 2);
        cout << traveller_id;

        cout << s1.Astro_name;
        cout << s1.Return_Astronaut_id();
        cout << s1.Commander_name;
        cout << s1.Return_Commander_id();
        cout << s1.date;
        cout << s1.Return_traveller_name(traveller_id) << endl;
        cout << s1.Return_id(traveller_id) << endl;
        cout << s1.source_planet;
        cout << s1.destination_planet;
        cout << s1.price;
        cout << s1.numberofdays;
    }
}

void Traveller ::updateid(string traveller_id)
{ if (verifyid(traveller_id) == 1){ // if id is verified then only u can update your id

    string newid;
    cout << newid;
    ID = newid;
    }
}
class Passenger : public Traveller
{
private:
    int validity;
};

string Astronaut::get_license_id()
{
    return license_id;
}
int Astronaut::get_YOE()
{
    return Years_Of_Experience;
}

string Commander::get_authority()
{
    return Authority;
}

void Ticket ::updateTicket(string traveller_id, Traveller t)
{
    string update;
    cin >> update;
    t.Name = update;
    cin >> update;
    t.ID = update;
    int number;
    cin >> number;
    number_of_days = number;
    cin >> update;
    date = update;
}
void Ticket ::bookTicket(Traveller t)
{
    Planet p1, p2;
    cout << "Enter sourceplanet";
    cin >> p1.name;
    cout << "Enter destinationplanet";
    cin >> p2.name;
    source_station = p1.name;

    destination_station = p2.name;

    int d = distance(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z); // where unit of d is million km
    if (d > 200)
        price_of_ticket = 60000;
    else
        price_of_ticket = 30000;

    cout << "Enter Your Name :";
    cin >> t.Name;
    cout << "Enter Your id";
    cin >> t.ID;
    cout << endl;

    cout << "Enter Date :";
    cin >> date;
    cout << "number of days";
    cin >> number_of_days;

    cout << "price of ticket:" << total_price() << "Rs." << endl;

    int r = s.l;

    t.set_traveller_id(r);
    cout << "Your Traveller id is:";
    cout << t.get_traveller_id() << endl;

    s.l++;
}
void Space_Travel ::List_All_Travellers()
{
    for (int r = 0; r < l; r++)
    {
        cout << arr[r] << endl;
        cout << name[r] << endl;
        cout << id[r] << endl;
    }
}
void Space_Travel ::Set_Astronaut_ID()
{
    int q = l + 1;

    int r = (int)(log(q));
    Astro = bitset<64>(q).to_string().substr(64 - r - 1);
}
void Space_Travel ::Set_Commander_ID()
{
    int q = l + 2;

    int r = (int)(log(q));
    Commander = bitset<64>(q).to_string().substr(64 - r - 1);
}

void Space_Travel ::Update_Astronaut_ID()
{
    string newid;
    cin >> newid;
    Astro = newid;
}
void Space_Travel ::Update_Commander_ID()
{
    string newid;
    cin >> newid;
    Commander = newid;
}
int Ticket ::total_price()
{
    return (number_of_days + 1) * price_of_ticket;
}
/*In main function there is 3 planet and 11 passengers and 2 Astronaut and 2 Commanders . There is two space travel system one is S1 nad other one is S2
S1 goes from planet p1 to p2 on date 30th September, 2025 for 90 days and S2 goes from planet p1 to p3 on date 10th Septemmber 2025 for 120 days and
according what planet,date and day passengers are choosing they are being added to that Specific space travel with attributes choosen according to them.
*/
int main()
{
    Planet p1, p2, p3;
    cin >> p1.name;
    cin >> p1.x >> p1.y >> p1.z;
    cin >> p2.name;

    cin >> p2.x >> p2.y >> p2.z;
    cin >> p3.name;

    cin >> p3.x >> p3.y >> p3.z;

    Ticket Ti;

    Passenger tr[11];
    Astronaut A1, A2;
    Commander C1, C2;
    Space_Travel S1, S2;
    S1.Astro_name = A1.Name;
    S1.Commander_name = C1.Name;
    S2.Astro_name = A2.Name;
    S2.Commander_name = C2.Name;
    S1.date = 30 / 9 / 2025;
    S2.date = 10 / 9 / 2025;
    S1.numberofdays = 90;
    S2.numberofdays = 120;
    Ti.bookTicket(tr[0]);
    for (int i = 0; i < 11; i++)
    {
        Ti.bookTicket(tr[i]);
        if (Ti.destination_station == p2.name && Ti.date == S1.date && Ti.number_of_days == S1.numberofdays)
        {
            Ti.s = S1;
            Ti.A = A1;
            Ti.C = C1;
        }
        else
        {
            Ti.s = S2;
            Ti.A = A2;
            Ti.C = C2;
        }
    }

    return 0;
}
