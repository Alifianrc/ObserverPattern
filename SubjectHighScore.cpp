#include "SubjectHighScore.h"

void HighScore::Attach(Observer* observer) {
	observerList.push_back(observer);
}
void HighScore::Detach(std::string name) {
    std::list<Observer*>::iterator iterator = observerList.begin();
    while (iterator != observerList.end()) {
        if ((*iterator)->GetName() == name)
        {
            observerList.remove(*iterator);
            return;
        }
        ++iterator;
    }
}

void HighScore::NotifyAllObserver(std::string massage) {
    std::list<Observer*>::iterator iterator = observerList.begin();
    while (iterator != observerList.end()) {
        (*iterator)->Update(massage);
        ++iterator;
    }
}

std::list<Observer*> HighScore::GetList() {
    return observerList;
}