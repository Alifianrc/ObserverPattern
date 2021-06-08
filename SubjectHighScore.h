#pragma once
#include "Observer.h"
#include <list>

class HighScore {
private:
	std::list <Observer*> observerList;

public:
	HighScore() = default;

	void Attach(Observer* observer);
	void Detach(std::string name);

	void NotifyAllObserver(std::string massage);

	std::list<Observer*> GetList();
};