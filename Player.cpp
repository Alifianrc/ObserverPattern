#include "Player.h"

Player::Player() {
	name = "Default";
	score = 0;
}
Player::Player(std::string nam, int value) {
	name = nam;
	score = value;
}

void Player::SetName(std::string nam) {
	name = nam;
}
std::string Player::GetName() {
	return name;
}

void Player::SetScore(int val) {
	score = val;
}
int Player::GetScore() {
	return score;
}

void Player::Update(std::string Themassage) {
	massage = Themassage;
}

void Player::ShowMassage() {
	std::cout << "\nMassage in " << name << " : \n";
	std::cout << massage;
}