#include <iostream>

#include <pthread.h>


using namespace std;


class A
{
public:
    static A *Instance(void)
    {
        pthread_once(&m_once, thread_once);
    }
private:
    A *m_pa;
    pthread_once_t m_once;
    pthread_key_t m_key;
private:
    A(void){}
    A(const A&){}
    A& operator=(const A&){}

    ~A(void){}

    void thread_once(void)
    {
        pthread_key_create(&m_key, detach);
        m_pa = (A *)pthread_getspecific(&m_key);
    }

    void detach(void *arg)
    {
        delete (A *)arg;
    }
};


int main(int argc, char *argv[])
{
    return EXIT_SUCCESS;
}
