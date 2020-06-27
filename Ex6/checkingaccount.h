#ifndef CHECKINFACCOUNT_H
#define CHECKINFACCOUNT_H

// Base class
class Account
{
public:
    Account(double m_balance);
    virtual ~Account(){};
    virtual void credit(double add);
    virtual void debit(double sub);
    virtual void printBalance();

protected:
    double m_balance;


};


// Derrived
class CheckingAccount : public Account
{
private:
    double m_fee;
public:
    CheckingAccount(double m_balance, double m_fee);
    ~CheckingAccount(){};
    void debit(double sub) override;
};

#endif // CHECKINFACCOUNT_H
