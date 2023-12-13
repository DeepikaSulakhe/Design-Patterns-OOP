#include <iostream>
#include <ctime>
using namespace std;

class Zone{
    public:
       virtual void displayZoneName() = 0;
       virtual int getOffset() = 0;
       virtual tm createTimeZone() =0;

};
enum class ZoneType {
    EasternTime,
    CentralTime, 
    MountainTime, 
    PacificTime
};

class EasternTime : public Zone{
   public:
      void displayZoneName() override {
        cout<<"USEastern"<< endl;
      }

      int getOffset() override{
        cout<< offsetFromGMT << endl;
        return offsetFromGMT;
      }
      tm createTimeZone() override {
        timeInfo = {};
        timeInfo.tm_zone = "EST";
        offsetFromGMT = -5;
        return timeInfo;
    }
private:
    std::tm timeInfo;
    int offsetFromGMT;

};

class CentralTime : public Zone{
    public:
      void displayZoneName() override {
        cout<<"USCentral"<< endl;
      }
      int getOffset() override{
        cout<< offsetFromGMT << endl;
        return offsetFromGMT;
      }
      tm createTimeZone() override {
        timeInfo = {};
        timeInfo.tm_zone = "CST";
        offsetFromGMT = -6;
        return timeInfo;
    }
private:
    std::tm timeInfo;
    int offsetFromGMT;
};

class MountainTime : public Zone{

    public:
      void displayZoneName() override {
        cout<<"USMountain"<< endl;
      }
       int getOffset() override{
        cout<< offsetFromGMT << endl;
        return offsetFromGMT;
      }
      tm createTimeZone() override {
        timeInfo = {};
        timeInfo.tm_zone = "MST";
        offsetFromGMT = -7;
        return timeInfo;
    }
private:
    std::tm timeInfo;
    int offsetFromGMT;
};

class PacificTime : public Zone{
    public:
      void displayZoneName() override {
        cout<<"USPacific"<< endl;
      }
      int getOffset() override{
        cout<< offsetFromGMT << endl;
        return offsetFromGMT;
      }
      tm createTimeZone() override {
        timeInfo = {};
        timeInfo.tm_zone = "PST";
        offsetFromGMT = -8;
        return timeInfo;
    }
private:
    std::tm timeInfo;
    int offsetFromGMT;
};

//Factory Class

class ZoneFactory {
    public:
       Zone* createZone(ZoneType zoneType){
        Zone *zone = nullptr;
        switch (zoneType)
        {
        case ZoneType::EasternTime:
        zone = (Zone*) new EasternTime();
        break;
        case ZoneType::CentralTime:
        zone = (Zone*) new CentralTime();
        break;
        case ZoneType::MountainTime:
        zone = (Zone*) new MountainTime();
        break;
        case ZoneType::PacificTime:
        zone = (Zone*) new PacificTime();
        break; 
        }
        return zone;
    }

};

int main(){
    time_t rawtime;
    struct tm * ptm;
    time ( &rawtime );
    ptm = gmtime ( &rawtime );
    ZoneFactory zoneFactory;
    Zone *zone = nullptr;
    cout<<endl<<"Displaying PacificTime"<<endl;
    zone = zoneFactory.createZone(ZoneType::PacificTime);
    zone->displayZoneName();
    zone->getOffset();
    tm timeInfo = zone->createTimeZone();
    cout << "Time Zone: " << timeInfo.tm_zone << endl;
    cout << "Time Update: " << (ptm->tm_hour + zone->getOffset())%24<<":"<<ptm->tm_min << endl;
    return 0;
}

