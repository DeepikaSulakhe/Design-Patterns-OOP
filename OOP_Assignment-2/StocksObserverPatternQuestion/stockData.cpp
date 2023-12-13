#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>

// Investor observer class
class Observer {
public:
    virtual void update(float nasadaqPrice, float sp500Price) = 0;
};

// Subject
class StockData {
public:
    StockData() {
    }

    void registerObserver(Observer *observer) {
        if (m_observerSet.count(observer) == 0) {
            m_observerSet.insert(observer);
        } else {
            std::cout<<"Trying to re- register existing client"<<std::endl;
        }
    }

    void removeObserver(Observer *observer) {
        if (m_observerSet.count(observer) != 0) {
            m_observerSet.erase(observer);
        } else {
            std::cout<<"Trying to un-register non-existing client"<<std::endl;
        }
    }

    void setState(float nasadaqPrice, float sp500Price) {
        m_nasadqPrice = nasadaqPrice;
        m_sp500Price = sp500Price;
        for(auto &observer:m_observerSet) {
            observer->update(nasadaqPrice, sp500Price);
        }
    }

private:
    float m_nasadqPrice = 0;
    float m_sp500Price = 0;
    std::unordered_set<Observer *> m_observerSet;
};


class Client : public Observer {
public:
    Client(int id) : m_clientID(id) {}

    void update(float nasadaqPrice, float sp500Price) override {
        std::cout<<"Client ID: "<<m_clientID<<" got price for nasadaq: "<< nasadaqPrice<< " price for sp500: "<<sp500Price<<std::endl;
    }

private:
    int m_clientID = 0;
};

int main() {
    StockData stockExchange;
    Client one(1), two(2), three(3);
    float NASDAQ, SP500;
    stockExchange.registerObserver(&one);
    stockExchange.registerObserver(&two);
    stockExchange.registerObserver(&three);
    std::cout << "Enter NASDAQ, SP500 << ";
    std::cin >> NASDAQ >> SP500;

    // All the clients should be notified - simply display clients getting the data using cout 
    stockExchange.setState(NASDAQ,SP500);
    stockExchange.removeObserver(&two);
    std::cout << "Enter NASDAQ, SP500 << ";
    std::cin >> NASDAQ >> SP500;

    // Client 1 and 3 should be notified - simply display clients getting the data using cout
    stockExchange.setState(NASDAQ,SP500);


    return 0;
}