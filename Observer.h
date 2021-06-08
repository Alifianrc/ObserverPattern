#pragma once
#include <string>

class Observer {
public:
	virtual void SetName(std::string nam) = 0;
	virtual std::string GetName() = 0;

	virtual void SetScore(int val) = 0;
	virtual int GetScore() = 0;

	virtual void Update(std::string Themassage) = 0;

	virtual void ShowMassage() = 0;
};