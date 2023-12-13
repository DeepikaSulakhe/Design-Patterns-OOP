#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <unordered_map>

// filter strategy
class LineFilter {
public:
    virtual bool shouldNotify(const std::string& line) = 0;
};

// returns true if matching keyword is found
class KeywordFilter: public LineFilter {
public:
    KeywordFilter(std::string const &filterStr) : m_filterStr(filterStr) {}
    bool shouldNotify(const std::string& line) override {
        auto compare = [] (char c1, char c2) { return std::toupper(c1) == std::toupper(c2); };
        bool found = std::search(line.begin(), line.end(), m_filterStr.begin(), m_filterStr.end(), compare) != line.end();
        return found;
    }

private:
    std::string m_filterStr;
};

// returns true if charcount in line is equal or exceeds a thresholds
class CharCountFilter: public LineFilter {
public:
    CharCountFilter(size_t threshold) : m_charCountThreshold(threshold) {}
    bool shouldNotify(const std::string& line) override {
        return line.length() >= m_charCountThreshold;
    }

private:
    size_t m_charCountThreshold;
};

// Observer class
class LineObserver {
public:
    virtual void printFilteredLine(const std::string& line) = 0;
};

// Observers
class KeywordObserver: public LineObserver {
public:
    void printFilteredLine(const std::string& line) override {
        std::cout<<"Yes! "<<line<<std::endl;
    }
};

class CharCountObserver: public LineObserver {
public:
    void printFilteredLine(const std::string& line) override {
        std::cout<<"So long....! "<<line<<std::endl;
    }
};

// TextAnalyzer class Subject 
class TextAnalyzer {
public:
    TextAnalyzer(std::string const fileName) : m_filename(fileName) {}
    void registerObsever(LineObserver *observer, LineFilter *lineFilter){
        if(m_linObserverMap.count(observer) != 0) {
            std::cout<<"This line observer is already registered"<<std::endl;
            return;
        }

        m_linObserverMap[observer] = lineFilter;
    }

    void notifyObservers() {
        std::ifstream inputFileObj (m_filename);
        if (inputFileObj.is_open()) {
            for (std::string line; std::getline(inputFileObj, line);) {
                for (auto &[observer, filter]: m_linObserverMap) {
                    if (filter->shouldNotify(line)) {
                        observer->printFilteredLine(line);
                    }
                }
            }
            inputFileObj.close();
        }
    }

private:
    std::string m_filename;
    std::unordered_map<LineObserver*, LineFilter*> m_linObserverMap;
};

int main() {
    TextAnalyzer textAnalyzer("sample.txt");
    
    KeywordObserver keywordObserver;
    CharCountObserver charCountObserver;

    KeywordFilter keywordFilter("interesting");
    CharCountFilter charCountFilter(60);

    // register observers with their respective filters
    textAnalyzer.registerObsever(&keywordObserver, &keywordFilter);
    textAnalyzer.registerObsever(&charCountObserver, &charCountFilter);

    // read file and notify registered observers
    textAnalyzer.notifyObservers();

    return 0;
}