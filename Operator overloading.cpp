#include <iostream>

class Student
{
private:
    char mName[20];
    int mScore;

public:
    Student(const char name[], int score);
    //operator int() const;
    int operator + (Student& rhs)
    {
        return mScore + rhs.mScore;
    }
    int operator + (const int sum)
    {
        return sum + mScore;
    }
    

    int operator += (const int total);
    
};

Student::Student(const char name[], int score)
{
    for (int i = 0; i < sizeof(name); i++)
    {
        mName[i] = name[i];
    }
    mScore = score;
}

/*
Student::operator int() const
{
    return mScore;
}
*/


int Student::operator+=(const int total)
{
    return total + mScore;
}



int main()
{
    Student a("Doggy", 100), b("Kitty", 90), c("Piggy", 50);

    int total1 = a + b + c;

    std::cout << total1 << std::endl;

    Student students[]
    {
        Student("Doggy", 100),
        Student("Kitty", 90),
        Student("Piggy", 50)
    };

    int total2{};
    for (int i = 0; i < 3; i++)
    {
        total2 += students[i];
    }

    std::cout << total2 << std::endl;
}

