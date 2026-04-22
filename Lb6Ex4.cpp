#include <iostream>
#include <string>

using namespace std;

struct VolleyballCompetitive
{
    string teamName;
    string teamCity;
    int countPoints;
    VolleyballCompetitive* next;
};

VolleyballCompetitive* head = nullptr;
VolleyballCompetitive* tail = nullptr;

struct CityNode
{
    string city;
    CityNode* next;
};

CityNode* cityHead = nullptr;


void enqueue(string teamName, string teamCity, int countPoints)
{
    VolleyballCompetitive* team = new VolleyballCompetitive;

    team->teamName = teamName;
    team->teamCity = teamCity;
    team->countPoints = countPoints;
    team->next = nullptr;

    if (head == nullptr)
    {
        head = tail = team;
    }
    else
    {
        tail->next = team;
        tail = team;
    }
}

void addUniqueCity(string city)
{
    CityNode* current = cityHead;
    while (current != nullptr)
    {
        if (current->city == city)
        {
            return; 
        }
        current = current->next;
    }


    CityNode* newCity = new CityNode;
    newCity->city = city;
    newCity->next = nullptr;

    if (cityHead == nullptr)
    {
        cityHead = newCity;
    }
    else
    {
        current = cityHead;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newCity;
    }
}


void displayAllTeams()
{
    if (head == nullptr)
    {
        cout << "Черга порожня!" << endl;
        return;
    }

    cout << "\n================================================================" << endl;
    cout << "                  All teams" << endl;
    cout << "================================================================" << endl;
    cout << "|  №  |     Team name     |       City         |  Score    |" << endl;
    cout << "================================================================" << endl;

    VolleyballCompetitive* current = head;
    int count = 1;
    while (current != nullptr)
    {
        cout << "| " << count++ << "   | " << current->teamName;

        int len = current->teamName.length();
        for (int i = len; i < 23; i++) cout << " ";

        cout << "| " << current->teamCity;

        len = current->teamCity.length();
        for (int i = len; i < 16; i++) cout << " ";

        cout << "| " << current->countPoints;

        string pointsStr = to_string(current->countPoints);
        for (int i = pointsStr.length(); i < 6; i++) cout << " ";

        cout << "|" << endl;

        current = current->next;
    }
    cout << "================================================================" << endl;
}


void createUniqueCitiesList()
{
    if (head == nullptr)
    {
        return;
    }

    VolleyballCompetitive* current = head;
    while (current != nullptr)
    {
        addUniqueCity(current->teamCity);
        current = current->next;
    }
}


void displayCities()
{
    cout << "\n========================================" << endl;
    cout << "     City' s  list" << endl;
    cout << "========================================" << endl;

    if (cityHead == nullptr)
    {
        cout << "Any cities" << endl;
        return;
    }

    CityNode* current = cityHead;
    int count = 1;
    while (current != nullptr)
    {
        cout << count++ << ". " << current->city << endl;
        current = current->next;
    }
    cout << "========================================" << endl;
}


void findLeaderAndOutsider(string& leaderName, string& leaderCity, int& leaderPoints,
    string& outsiderName, string& outsiderCity, int& outsiderPoints)
{
    if (head == nullptr)
    {
        cout << "Queue is empty" << endl;
        return;
    }

    VolleyballCompetitive* current = head;

    leaderName = current->teamName;
    leaderCity = current->teamCity;
    leaderPoints = current->countPoints;

    outsiderName = current->teamName;
    outsiderCity = current->teamCity;
    outsiderPoints = current->countPoints;

    current = current->next;

  
    while (current != nullptr)
    {
        if (current->countPoints > leaderPoints)
        {
            leaderPoints = current->countPoints;
            leaderName = current->teamName;
            leaderCity = current->teamCity;
        }

  
        if (current->countPoints < outsiderPoints)
        {
            outsiderPoints = current->countPoints;
            outsiderName = current->teamName;
            outsiderCity = current->teamCity;
        }

        current = current->next;
    }
}

void displayLeaderAndOutsider()
{
    string leaderName, leaderCity, outsiderName, outsiderCity;
    int leaderPoints, outsiderPoints;

    findLeaderAndOutsider(leaderName, leaderCity, leaderPoints,
        outsiderName, outsiderCity, outsiderPoints);

    cout << "\n========================================" << endl;
    cout << "           Result           " << endl;
    cout << "========================================" << endl;

    cout << "\n Leader:" << endl;
    cout << "   Team: " << leaderName << endl;
    cout << "   City: " << leaderCity << endl;
    cout << "   Score: " << leaderPoints << endl;

    cout << "\n Outsider:" << endl;
    cout << "   Team: " << outsiderName << endl;
    cout << "   City: " << outsiderCity << endl;
    cout << "   Score: " << outsiderPoints << endl;

    cout << "========================================" << endl;
}


void freeQueueMemory()
{
    VolleyballCompetitive* current = head;
    VolleyballCompetitive* next;

    int count = 0;
    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
        count++;
    }

    head = tail = nullptr;
    cout << "Free" << count << " elements queue" << endl;
}


void freeCitiesMemory()
{
    CityNode* current = cityHead;
    CityNode* next;

    int count = 0;
    while (current != nullptr)
    {
        next = current->next;
        delete current;
        current = next;
        count++;
    }

    cityHead = nullptr;
    cout << "Free " << count << " elements" << endl;
}

void freeMemory()
{
    freeQueueMemory();
    freeCitiesMemory();
    cout << "All dynamic memory is free!" << endl;
}

int main()
{
    int n;
    string teamName, teamCity;
    int countPoints;

    cout << "========================================" << endl;
    cout << "   Voleyball competetive" << endl;
    cout << "========================================" << endl;
    cout << "Enter count of teams ";
    cin >> n;
    cin.ignore(); 

    if (n <= 0)
    {
        cout << "Team count must be more than 0" << endl;
        return 1;
    }


    cout << "\n--- Enter data about teams ---" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "\nTeam #" << i + 1 << ":" << endl;

        cout << "Name of team: ";
        getline(cin, teamName);

        cout << "City: ";
        getline(cin, teamCity);

        cout << "Count o ";
        cin >> countPoints;
        cin.ignore();

        enqueue(teamName, teamCity, countPoints);
    }

    displayAllTeams();

    createUniqueCitiesList();
    displayCities();

    displayLeaderAndOutsider();

    freeMemory();


    return 0;
}