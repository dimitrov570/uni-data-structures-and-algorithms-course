#include <iostream>

struct Student
{
    int skill, position;
    Student *next;
    Student *previous;

    inline  bool operator<=(const Student& rhs)
    {
        if (this->skill <= rhs.skill)
        {
            return true;
        }
        return false;
    }
    inline  bool operator>=(const Student& rhs)
    {
        if (this->skill >= rhs.skill)
        {
            return true;
        }
        return false;
    }
    inline  bool operator==(const Student& rhs)
    {
        if (this->skill == rhs.skill)
        {
            return true;
        }
        return false;
    }
    inline  bool operator<(const Student& rhs)
    {
        if (this->skill < rhs.skill)
        {
            return true;
        }
        return false;
    }
    inline  bool operator>(const Student& rhs)
    {
        if (this->skill > rhs.skill)
        {
            return true;
        }
        return false;
    }
};

class List
{
public:
    List()
    {
        head = NULL;
        tail = NULL;
    };

    ~List()
    {
        while (head != NULL)
        {
            Student *tmp = head;
            head = head->next;
            delete tmp;
        }
    };

    void addStudent(Student & student)
    {
        if (head == NULL)
        {
            head = &student;
            tail = &student;
        }
        else
        {
            tail->next = &student;
            student.previous = tail;
            tail = &student;
        }
    };

    void print()
    {
        Student *tmp = head;
        while (tmp != nullptr)
        {
            std::cout << "skill: " << tmp->skill << std::endl;
            tmp = tmp->next;
        }
    }

    bool isEmpty()
    {
        if (head == nullptr)
        {
            return true;
        }
        return false;
    }

    void deleteMultipleElements(Student *from, int numberOfElements, Student *students, bool *studentTeam, bool team)
    {
        int K = numberOfElements;
        studentTeam[from->position] = team;
        Student* tmp = from->previous;
        while (tmp != nullptr && K > 0)
        {
            tmp->skill = 0;
            studentTeam[tmp->position] = team;
            tmp = tmp->previous;
            --K;
        }
        from->previous = tmp;
        if (tmp != nullptr)
        {
            tmp->next = from;
        }

        tmp = from->next;
        while (tmp != nullptr && numberOfElements > 0)
        {
            tmp->skill = 0;
            studentTeam[tmp->position] = team;
            tmp = tmp->next;
            --numberOfElements;
        }
        from->next = tmp;
        if (tmp != nullptr)
        {
            tmp->previous = from;
        }
        from->skill = 0;
        if (from->previous == nullptr && from->next == nullptr)
        {
            head = nullptr;
            tail = nullptr;
        }
        if (from->previous != nullptr)
        {
            tmp = from->previous;
            tmp->next = from->next;
        }
        if (from->next != nullptr)
        {
            tmp = from->next;
            tmp->previous = from->previous;
        }
    }

    Student *head;
    Student *tail;
private:
};

int findMax(Student *students, int N)
{
    int max = 0;
    int index = -1;
    for (int i = 0; i < N; ++i)
    {
        if (students[i].skill > max)
        {
            max = students[i].skill;
            index = i;
        }
    }
    return index;
}

void createTeams(List &participants, Student *students, bool *studentTeam, int N, int K)
{
    bool team = 0;
    while (!participants.isEmpty())
    {
        int i = findMax(students, N);
        if (i < 0)
        {
            return;
        }
        participants.deleteMultipleElements(&students[i], K, students, studentTeam, team);


        team = !team;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int N;
    int K;
    std::cin >> N >> K;
    bool *studentTeam = new bool[N]; //if studentTeam[i]=0 that means that student is in team1, else student is in team2
    Student *students = new Student[N];
    List participants;
    int skill;
    for (int i = 0; i < N; ++i)
    {
        std::cin >> skill;
        students[i] = Student{ skill, i };
        participants.addStudent(students[i]);
        studentTeam[i] = 0;
    }

    createTeams(participants, students, studentTeam, N, K);

    for (int i = 0; i < N; ++i)
    {
        std::cout << (int)studentTeam[i] + 1 ;
    }

    std::cout << std::endl;


    return 0;
}
