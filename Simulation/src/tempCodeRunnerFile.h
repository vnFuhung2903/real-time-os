class Task

{
private:
    int m_priorityLevel;
    string m_name ;
    int m_startTime;
    int m_computationTime;
    int m_hardDeadline;
    int m_period;
    int m_currPeriod;
    int m_laxity;

public:
    Task(string name = "", int startTime = 0, int computationTime = 0, int hardDeadline = 0, int period = 0)
    {
        m_priorityLevel = hardDeadline;
        m_name = name;
        m_startTime = startTime;
        m_computationTime = computationTime;
        m_hardDeadline = hardDeadline;
        m_period = period;
        m_currPeriod = 1;
        m_laxity = hardDeadline - startTime - computationTime;
    };

    Task &operator=(const Task &task)
    {
        if (this == &task)
        {
            return *this;
        }
        m_priorityLevel = task.m_priorityLevel;
        m_name = task.m_name;
        m_startTime = task.m_startTime;
        m_computationTime = task.m_computationTime;
        m_hardDeadline = task.m_hardDeadline;
        m_period = task.m_period;
        m_currPeriod = task.m_currPeriod;
        m_laxity = task.m_laxity;
        return *this;
    };
    struct CompareTasks {
        bool operator()(const Task& task1, const Task& task2) const {
            return task1.getPriorityLevel() < task2.getPriorityLevel();
        }
    };

    int getPriorityLevel() const
    {
        return m_priorityLevel;
    };