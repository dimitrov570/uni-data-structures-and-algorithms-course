#include <iostream>

class Event
{
    int start;
    int duration;

public:
    Event(int Start = 0, int Duration = 0) :start(Start), duration(Duration)
    {}

    int getStart() const
    {
        return start;
    }

    int getDuration() const
    {
        return duration;
    }

    int getEnd() const
    {
        return start + duration;
    }

    void setStart(int Start)
    {
        start = Start;
    }

    void setDuration(int Duration)
    {
        duration = Duration;
    }
};

void merge(Event *arr, Event *tmpArr, int start, int mid, int end)
{
    int leftPointer = start;
    int rightPointer = mid + 1;

    for (int i = start; i <= end; ++i)
    {
        if (leftPointer <= mid && (rightPointer > end || arr[leftPointer].getEnd() <= arr[rightPointer].getEnd()))
        {
            tmpArr[i] = arr[leftPointer++];
        }
        else
        {
            tmpArr[i] = arr[rightPointer++];
        }
    }

    for (int i = start; i <= end; ++i)
    {
        arr[i] = tmpArr[i];
    }
}

void mergeSorting(Event *arr, Event *tmpArr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        mergeSorting(arr, tmpArr, start, mid);
        mergeSorting(arr, tmpArr, mid + 1, end);
        merge(arr, tmpArr, start, mid, end);
    }
}

void mergeSort(Event *arr, int length)
{
    Event* tmpArr = new Event[length];
    mergeSorting(arr, tmpArr, 0, length - 1);
    delete[] tmpArr;
}

int main() {

    long int N;
    std::cin >> N;

    if (N == 0)
    {
        std::cout << 0;
        return 0;
    }
    
    Event *events = new Event[N];

    int start, duration;
    int result = 1; //The first event will always be visited

    long int i = 0;
    while (i < N)
    {
        std::cin >> start >> duration;
        events[i].setStart(start);
        events[i].setDuration(duration);
        if (duration == 0)
        {
            ++result;
        }
        ++i;
    }

    mergeSort(events, N);


    for (long int i = 0; i < N - 1; ++i)
    {
        int j = i + 1;
        while (events[i].getEnd() > events[j].getStart() && j < N)
        {
            j++;
        }
        if (events[i].getEnd() <= events[j].getStart() && j < N)
        {
            ++result;
        }
        i = j - 1;
    }
    std::cout << result;

    delete[] events;

    return 0;
}
