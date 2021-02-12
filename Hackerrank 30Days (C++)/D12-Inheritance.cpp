#include <iostream>
#include <vector>

using namespace std;

class Person
{
protected:
    string firstName;
    string lastName;
    int id;

public:
    Person(string firstName, string lastName, int identification)
    {
        this->firstName = firstName;
        this->lastName = lastName;
        this->id = identification;
    }
    void printPerson()
    {
        cout << "Name: " << lastName << ", " << firstName << "\nID: " << id << "\n";
    }
};

class Student : public Person
{
private:
    vector<int> scores;

public:
    Student(string firstName, string lastName, int identification, vector<int> scores) : Person(firstName, lastName, identification)
    {
        this->scores = scores;
    }
    char calculate()
    {
        int avg = 0;
        int i = 0;
        for (i = 0; i < (int)scores.size(); i++)
        {
            avg += scores[i];
        }
        avg /= i;
        if (avg >= 90 && avg <= 100)
        {
            return 'O';
        }
        else if (avg >= 80 && avg < 90)
        {
            return 'E';
        }
        else if (avg >= 70 && avg < 80)
        {
            return 'A';
        }
        else if (avg >= 55 && avg < 70)
        {
            return 'P';
        }
        else if (avg >= 40 && avg < 55)
        {
            return 'D';
        }
        else
        {
            return 'T';
        }
    }
};

int main()
{