#include <iostream>
#include <string>

struct Student
{
    std::string name;
    int group;
    int entryNumber;
    int exitNumber;
    Student *previous;

    Student(std::string Name = "", int Group = -1, int EntryNr = -1, Student* Previous = nullptr) :name(Name), group(Group),
        entryNumber(EntryNr), previous(Previous)
    {}
};

class StudentQueue
{
    Student *back;
    Student *front;

public:
    StudentQueue() :back(nullptr), front(nullptr)
    {}

    void push(std::string name, int group, int entryNumber)
    {
        Student *student = new Student{ name, group, entryNumber };

        if (back == nullptr && front == nullptr)
        {
            back = front = student;
        }
        else
        {
            back->previous = student;
            back = student;
        }
    }

    Student *addBehindStudent(Student *student, std::string name, int entryNumber)
    {
        Student *newStudent = new Student{ name, student->group, entryNumber, student->previous };
        student->previous = newStudent;
        if (back == student)
        {
            back = newStudent;
        }
        return newStudent;
    }

    void pop()
    {
        Student *tmp = front;
        if (tmp != nullptr)
        {
            if (back == front)
            {
                back = front = nullptr;
            }
            else
            {
                front = front->previous;
            }
            delete tmp;
        }
    }

    Student getFrontStudent()
    {
        Student tmp;
        tmp.name = front->name;
        tmp.group = front->group;
        tmp.entryNumber = front->entryNumber;
        return tmp;
    }

    Student *getBackAddress()
    {
        return back;
    }

    Student *getFrontAddress()
    {
        return front;
    }

    bool isEmpty()
    {
        return (back == nullptr && front == nullptr);
    }

};

int main()
{

    int studentsNumber, groupsNumber;
    std::cin >> studentsNumber >> groupsNumber;
    Student **groups = new Student*[groupsNumber];
    for (int i = 0; i < groupsNumber; ++i)
    {
        groups[i] = nullptr;
    }

    std::string name;
    int group;
    Student *array = new Student[studentsNumber];

    for (int i = 0; i < studentsNumber; ++i)
    {
        std::cin >> name >> group;
        array[i] = Student{ name, group };
    }

    StudentQueue students;

    int j;
    Student tmpStudent;
    int entryNumber = 0;
    int timeElapsed = 0;

    j = -1;
    for (int i = 0; i < studentsNumber;)
    {
        while (i < studentsNumber && j < 2)
        {
            if (groups[array[i].group - 1] == nullptr)
            {
                students.push(array[i].name, array[i].group, entryNumber++);
                groups[array[i].group - 1] = students.getBackAddress();
            }
            else
            {
                groups[array[i].group - 1] = students.addBehindStudent(groups[array[i].group - 1], array[i].name, entryNumber++);
            }
            ++i;
            ++j;
        }
        j = 0;
        if (!students.isEmpty())
        {
            tmpStudent = students.getFrontStudent();
            timeElapsed += 2;
            tmpStudent.exitNumber = timeElapsed;
            if (groups[tmpStudent.group - 1] == students.getFrontAddress())
            {
                groups[tmpStudent.group - 1] = nullptr;
            }
            std::cout << tmpStudent.name << " " << tmpStudent.entryNumber << " " << tmpStudent.exitNumber << std::endl;
            students.pop();
        }
    }

    while (!students.isEmpty())
    {
        tmpStudent = students.getFrontStudent();
        timeElapsed += 2;
        tmpStudent.exitNumber = timeElapsed;
        if (groups[tmpStudent.group - 1] == students.getFrontAddress())
        {
            groups[tmpStudent.group - 1] = nullptr;
        }
        std::cout << tmpStudent.name << " " << tmpStudent.entryNumber << " " << tmpStudent.exitNumber << std::endl;
        students.pop();
    }

    return 0;
}
