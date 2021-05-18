#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

#include "Researcher.hpp"
#include "Scientist.hpp"
#include "FieldDoctor.hpp"
#include "GeneSplicer.hpp"
#include "OperationsExpert.hpp"
#include "Dispatcher.hpp"
#include "Medic.hpp"
#include "Virologist.hpp"

using namespace pandemic;
#include <iostream>
#include <stdexcept>
using namespace std;

int main()
{
	Board board;
	board[City::Algiers] = 3;
	board[City::Kinshasa] = 2;
	board[City::MexicoCity] = 3;
	board[City::Beijing] = 1;
	board[City::Chicago] = 1;

	OperationsExpert player(board, City::Atlanta);
	OperationsExpert OperationsExpert(board, City::Algiers);
	Dispatcher dispatcher(board, City::Algiers);
	Scientist scientist(board, City::Algiers, 2);
	Researcher researcher(board, City::Atlanta);
	Medic medic(board, City::MexicoCity);
	Virologist virologist(board, City::Montreal);
	GeneSplicer geneSplicer(board, City::Algiers);
	FieldDoctor fieldDoctor(board, City::Seoul);

	cout << "START GAME\n";
	cout << board << endl;
	cout << "cube disease\n";
	cout << "Algiers: " << board[City::Algiers];
	cout << "\nKinshasa: " << board[City::Kinshasa];
	cout << "\nMexicoCity: " << board[City::MexicoCity];
	cout << "\nBeijing: " << board[City::Beijing];
	cout << "\nChicago: " << board[City::Chicago] << "\n\n";

	OperationsExpert.build();
	OperationsExpert.drive(Madrid);
	OperationsExpert.build();
	OperationsExpert.take_card(Chicago);
	OperationsExpert.fly_direct(Chicago);
	OperationsExpert.build();

	cout << OperationsExpert.role() << ": build station in Chicago, Madrid, Algiers.\n";

	dispatcher.fly_direct(Madrid)
		.fly_direct(Chicago)
		.fly_direct(Algiers);

	cout << dispatcher.role() << ": fly direct from Madrid to chicgo and to Algiers.\n";

	scientist
		.take_card(Baghdad)
		.take_card(Algiers)
		.discover_cure(Black);

	cout << scientist.role() << ": discover_cure to black dusease \n";

	researcher
		.take_card(Atlanta)
		.take_card(Chicago)
		.take_card(Essen)
		.take_card(London)
		.take_card(Madrid);
	researcher.discover_cure(Blue);

	cout << researcher.role() << ": discover_cure to blue dusease \n";

	fieldDoctor.treat(Beijing);
	cout << fieldDoctor.role() << ": treat cube disease in beijing \n";

	medic
		.treat(MexicoCity)
		.take_card(Kinshasa)
		.fly_direct(Kinshasa)
		.treat(Kinshasa);
	cout << medic.role() << ": treat cube disease in MexicoCity and Kinshasa \n";

	medic
		.take_card(Algiers)
		.fly_direct(Algiers)
		.take_card(Chicago)
		.fly_direct(Chicago);
	cout << medic.role() << ": treat cube disease in Algiers and Chicago \n";

	cout << board << endl;

	cout << "cube disease\n";
	cout << "Algiers: " << board[City::Algiers];
	cout << "\nKinshasa: " << board[City::Kinshasa];
	cout << "\nMexicoCity: " << board[City::MexicoCity];
	cout << "\nBeijing: " << board[City::Beijing];
	cout << "\nChicago: " << board[City::Chicago] << "\n\n";

	cout << "END GAME\n";
	// prints the board in any reasonable format.
	cout << board.is_clean() << endl; // prints "1" - the board is clean - congratulations!!! You treated all diseases!!!
}
