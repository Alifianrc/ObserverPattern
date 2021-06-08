#pragma once
#include "Observer.h"
#include <iostream>

class Player : public Observer {
private :
	std::string name;
	int score;
	std::string massage;

public :
	Player();
	Player(std::string nam, int value);

	void SetName(std::string nam);
	std::string GetName();
	
	void SetScore(int val);
	int GetScore();

	void Update(std::string Themassage);

	void ShowMassage();
};