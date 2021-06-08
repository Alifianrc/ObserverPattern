#include "Player.h"
#include "SubjectHighScore.h"

const int MAX_PLAYER = 3;

struct  DataPlayer
{
	std::string name;
	int score;
};

std::string CalculatePosition(std::list<Observer*> theList) {
	std::string highScore;
	DataPlayer temp[MAX_PLAYER];

	std::list<Observer*>::iterator iterator = theList.begin();
	int count = 0;
	while (iterator != theList.end()) {
		temp[count].name = (*iterator)->GetName();
		temp[count].score = (*iterator)->GetScore();
		count++;
		++iterator;
	}

	for (int i = 0; i < MAX_PLAYER; i++) {
		for (int j = 1; j < MAX_PLAYER; j++) {
			if (temp[i].score < temp[j].score) {
				DataPlayer Alpha = temp[i]; 
				temp[i] = temp[j];
				temp[j] = Alpha;
			}
		}
	}

	for (int i = 0; i < MAX_PLAYER; i++) {
		highScore += temp[i].name + "    " + std::to_string(temp[i].score) + " \n";
	}

	return highScore;
}

void ShowPlayerMassage(std::list<Observer*> theList) {
	std::list<Observer*>::iterator iterator = theList.begin();
	while (iterator != theList.end()) {
		(*iterator)->ShowMassage();
		++iterator;
	}
}

int main() {
	srand(time(NULL));

	HighScore subject;
	std::string massage;

	// Create Player
	for (int i = 0; i < MAX_PLAYER; i++) {
		Player* a = new Player("Player-" + std::to_string(i), (rand() % 90) + 11);
		subject.Attach(a);
	}

	// Calculate Scoreboard
	massage = CalculatePosition(subject.GetList());

	// Notify Player
	subject.NotifyAllObserver(massage);

	// Show Massage
	ShowPlayerMassage(subject.GetList());

	return 0;
}