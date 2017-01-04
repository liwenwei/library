#include <Windows.h>

class time_count
{
public:
    time_count(){};
    ~time_count(){};

    BOOL init();

    // Operations
public:
    void start();
    void end();

    double getSeconds() const;
    double getMilliseconds() const;

private:
    LARGE_INTEGER frequency;
    LARGE_INTEGER m_start;     // Start of measurement period
    LARGE_INTEGER m_end;       // End of measurement period
    double elapsedTime = 0.0;
};

inline BOOL time_count::init()
{
    return QueryPerformanceFrequency(&frequency);
}

inline void time_count::start()
{
    QueryPerformanceCounter(&m_start);
}

inline void time_count::end()
{
    QueryPerformanceCounter(&m_end);
}

inline double time_count::getSeconds() const
{
    return (double)(m_end.QuadPart - m_start.QuadPart) / frequency.QuadPart;
}

inline double time_count::getMilliseconds() const
{
    return (double)(m_end.QuadPart - m_start.QuadPart) / frequency.QuadPart * 1000;
}