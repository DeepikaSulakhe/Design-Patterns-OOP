#include <iostream>
#include <vector>

// abstract command class
class Command {
public:
    virtual void execute() = 0;
};

// invoker class
class RemoteControl {
public:
    void addCommand(Command *command) {
        commandList.push_back(command);
    }

    int executeCommand() {
        if (!commandList.empty()) {
            Command* currentCommand = commandList.back();
            commandList.pop_back();
            if (currentCommand) {
                currentCommand->execute();
                m_lastCommand = currentCommand;
                return 0;
            }
        } else {
            std::cout<<"No command to execute"<<std::endl;
            return -1;
        }
        return -1;
    }

private:
    Command *m_lastCommand = nullptr;
    std::vector<Command*> commandList;
};

// Receiver classes:
class TV {
public:
    void turnOnTV() {
        std::cout<<"TV turned On"<<std::endl;
    }

    void turnOffTV() {
        std::cout<<"TV turned Off"<<std::endl;
    }
};

class SoundSystem {
public:
    void volumeUp() {
        std::cout<<"SoundSystem volume increased"<<std::endl;
    }

    void volumeDown() {
        std::cout<<"SoundSystem volume decreased"<<std::endl;
    }
};

class Lights {
public:
    void increaseBrightness() {
        std::cout<<"Lights brightness increased"<<std::endl;
    }

    void decreaseBrightness() {
        std::cout<<"Lights brightness decreased"<<std::endl;
    }
};

// concrete command classes
class TurnTVOnCommand: public Command {
public:
    TurnTVOnCommand(TV *tv) : m_tv(tv) {}
    void execute() override {
        if (m_tv) {
            m_tv->turnOnTV();
        }
    }
private:
    TV *m_tv = nullptr;
};

class TurnTVOffCommand: public Command {
public:
    TurnTVOffCommand(TV *tv) : m_tv(tv) {}
    void execute() override {
        if (m_tv) {
            m_tv->turnOffTV();
        }
    }
private:
    TV *m_tv = nullptr;
};

class SoundSystemVolumeUpCommand: public Command {
public:
    SoundSystemVolumeUpCommand(SoundSystem *soundSystem) : m_soundSystem(soundSystem) {}
    void execute() override {
        if (m_soundSystem) {
            m_soundSystem->volumeUp();
        }
    }
private:
    SoundSystem *m_soundSystem = nullptr;
};

class SoundSystemVolumeDownCommand: public Command {
public:
    SoundSystemVolumeDownCommand(SoundSystem *soundSystem) : m_soundSystem(soundSystem) {}
    void execute() override {
        if (m_soundSystem) {
            m_soundSystem->volumeDown();
        }
    }
private:
    SoundSystem *m_soundSystem = nullptr;
};

class LightBrightnessIncreaseCommand: public Command {
public:
    LightBrightnessIncreaseCommand(Lights *lights) : m_lights(lights) {}
    void execute() override {
        if (m_lights) {
            m_lights->increaseBrightness();
        }
    }
private:
    Lights *m_lights = nullptr;
};

class LightBrightnessDecreaseCommand: public Command {
public:
    LightBrightnessDecreaseCommand(Lights *lights) : m_lights(lights) {}
    void execute() override {
        if (m_lights) {
            m_lights->decreaseBrightness();
        }
    }
private:
    Lights *m_lights = nullptr;
};

int main() {
    // create receiver objects on the stack
    TV tv;
    Lights lights;
    SoundSystem soundSystem;

    // create invoker
    RemoteControl remoteControl;

    int commandCount = 0;
    // create concrete command objects and add it to remote control;
    TurnTVOffCommand turnTVOffCommand(&tv);
    remoteControl.addCommand(&turnTVOffCommand);
    commandCount++;
    TurnTVOnCommand turnTVOnCommand(&tv);
    remoteControl.addCommand(&turnTVOnCommand);
    commandCount++;

    SoundSystemVolumeDownCommand soundSystemVolumeDownCommand(&soundSystem);
    remoteControl.addCommand(&soundSystemVolumeDownCommand);
    commandCount++;
    SoundSystemVolumeUpCommand soundSystemVolumeUpCommand(&soundSystem);
    remoteControl.addCommand(&soundSystemVolumeUpCommand);
    commandCount++;

    LightBrightnessIncreaseCommand lightBrightnessIncreaseCommand(&lights);
    remoteControl.addCommand(&lightBrightnessIncreaseCommand);
    commandCount++;
    LightBrightnessDecreaseCommand lightBrightnessDecreaseCommand(&lights);
    remoteControl.addCommand(&lightBrightnessDecreaseCommand);
    commandCount++;

    // run commands
    for(int i = 0; i < commandCount; ++i) {
        remoteControl.executeCommand();
    }

    return 0;
}