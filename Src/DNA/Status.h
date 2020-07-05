#ifndef DNAANALYZERPROJECT_STATUS_H
#define DNAANALYZERPROJECT_STATUS_H


class Status
{
public:
    enum EStatus{
        E_NEW,
        E_MODIFY,
        E_UP_TO_DATE
    };
    Status() { m_status = statuses[E_NEW];}
    const char*  get()const;
    void set(EStatus status);
private:
    const char* m_status;
    static const char *const statuses[];
};


#endif //DNAANALYZERPROJECT_STATUS_H
