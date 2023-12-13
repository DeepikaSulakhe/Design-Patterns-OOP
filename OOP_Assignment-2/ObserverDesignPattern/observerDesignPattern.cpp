#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>

enum class StockType {
    HEALTHCARE,
    TECH
};

// Investor observer class
class Investor {
public:
    virtual void update(StockType stockType, float currentPrice) = 0;
};

// Subject
class Stock {
public:
    Stock(StockType stockType, float price) : m_stockType(stockType), m_currentPrice(price) {
    }

    void registerInvestor(Investor *investor) {
        if (m_investorSet.count(investor) == 0) {
            m_investorSet.insert(investor);
        } else {
            std::cout<<"Trying to re- register existing investor"<<std::endl;
        }
    }

    void removeInvestor(Investor *investor) {
        if (m_investorSet.count(investor) != 0) {
            m_investorSet.erase(investor);
        } else {
            std::cout<<"Trying to un-register non-existing investor"<<std::endl;
        }
    }

    void notifyInvestors() {
        for(auto &investor: m_investorSet) {
            investor->update(m_stockType, m_currentPrice);
        }
    }

    void setStockPrice(float price) {
        m_currentPrice = price;
        for(auto &[investor, limits]: m_notifyLimitMap) {
            // if the current stock price has crossed upper threshold, notify
            if (m_currentPrice >= limits.first) {
                investor->update(m_stockType, m_currentPrice);
            }

            // if the current stock price has crossed lower threshold, notify
            if (m_currentPrice <= limits.second) {
                 investor->update(m_stockType, m_currentPrice);
            }
        }
    }

    void setNotificationThreshold(Investor *investor, float upperLimit, float lowerLimit){
        if (m_investorSet.count(investor) == 0) {
            std::cout<<"Investor not registered"<<std::endl;
            return;
        }

        if (upperLimit < 0 || lowerLimit < 0 || upperLimit <= lowerLimit) {
            std::cout<<"Invalid stock price limits requested"<<std::endl;
            return;
        }

        m_notifyLimitMap[investor] = {upperLimit, lowerLimit};
    }

private:
    StockType m_stockType;
    float m_currentPrice;
    std::unordered_map<Investor *, std::pair<float, float>> m_notifyLimitMap;
    std::unordered_set<Investor *> m_investorSet;
};


class ClientA : public Investor {
public:
    void update(StockType stockType, float currentPrice) override {
        std::string stockstr;
        stockstr = stockType == StockType::HEALTHCARE ? "Healthcare" : "Tech";
        std::cout<<"ClientA notification: "<<stockstr<<" stock's current price has moved to: $"<<currentPrice<<std::endl;
    }
};

class ClientB : public Investor {
public:
    void update(StockType stockType, float currentPrice) override {
        std::string stockstr;
        stockstr = stockType == StockType::HEALTHCARE ? "Healthcare" : "Tech";
        std::cout<<"ClientB notification: "<<stockstr<<" stock's current price has moved to: $"<<currentPrice<<std::endl;
    }
};

class ClientC : public Investor {
public:
    void update(StockType stockType, float currentPrice) override {
        std::string stockstr;
        stockstr = stockType == StockType::HEALTHCARE ? "Healthcare" : "Tech";
        std::cout<<"ClientC notification: "<<stockstr<<" stock's current price has moved to: $"<<currentPrice<<std::endl;
    }
};

int main() {
    ClientA clientA;
    ClientB clientB;
    ClientC clientC;
    Stock healthStock(StockType::HEALTHCARE, 32.0);
    Stock techStock(StockType::TECH, 79.0);

    healthStock.registerInvestor(&clientA);
    healthStock.registerInvestor(&clientC);
    techStock.registerInvestor(&clientB);
    techStock.registerInvestor(&clientC);

    // notify investor of current price
    healthStock.notifyInvestors();
    techStock.notifyInvestors();


    // now clients can set thresholds for notification whenever price changes
    healthStock.setNotificationThreshold(&clientA, 50.0, 16.0);
    healthStock.setNotificationThreshold(&clientC, 55.0, 30.0);

    techStock.setNotificationThreshold(&clientB, 100.0, 60.0);
    techStock.setNotificationThreshold(&clientC, 95.0, 55.0);

    // change prices to trigger notifications
    healthStock.setStockPrice(10.0);
    healthStock.setStockPrice(60.0);

    // this should not trigger notification
    healthStock.setStockPrice(45.0);    

    techStock.setStockPrice(40.0);
    techStock.setStockPrice(110.0);

    // this should not trigger notification
    techStock.setStockPrice(65.0);


    return 0;
}