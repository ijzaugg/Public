#include "SpaceDogs.h"
#include "SDDog.h"
#include "SDDogBeagle.h"
#include "SDDogChihuahua.h"
#include "SDDogCorgi.h"
#include "SDDogDachshund.h"

#include <iostream>
#include <thread>

namespace CSC234 {
	/* Constructor.
	Precondition: SpaceDogs selected as game choice from main casino.
	Postcondition: SpaceDogs game initialized.*/
	SpaceDogs::SpaceDogs() {
	}

	/* Destructor.
	Precondition: Game finished (object out of scope).
	Postcondition: Deletes dynamically allocated memory for cats and dogs arrays. */
	SpaceDogs::~SpaceDogs() {
		delete dogs;
		delete cats;
	}

	/* Calls game object.
	Precondition: Main Casino calls SpaceDogs as a command line parameter.
	Postcondition: Returns reference to a new SpaceDogs object. */
	SpaceDogs* SpaceDogs::makeGame() {
		return new SpaceDogs();
	}

	/* Roll opening credits. Allows players to set up game.
	Precondition: Casino calls start function.
	Postcondition: Allows user to choose number of human and AI players, initializes
	game map, and sets up individual Dog and Cat objects. */
	void SpaceDogs::start() {
		/*** Opening Credits ***/
		cout << "--------------------------------------------------" << endl;
		cout << "                   SPACE DOGS" << endl;
		cout << "              .--.             .---." << endl;
		cout << "             /:.  \'.         .\' ..  \'._.---." << endl;
		cout << "            /:::-.  \\.-\"\"\"-;` .-:::.     .::\\" << endl;
		cout << "           /::\'|   \\/  _ _  \\\'   `\\:'   ::::|" << endl;
		cout << "       __.'    |   /  (o|o)  \\     `\'.   \':/" << endl;
		cout << "      /    .:. /   |   ___   |        \'---\'" << endl;
		cout << "     |    ::::\'   /:  (._.) .:\\" << endl;
		cout << "     \\    .=\'    |:\'        :::|" << endl;
		cout << "      `\"\"`       \\     .-.   \':/" << endl;
		cout << "                  \'---`|I|`---\'" << endl;
		cout << "                       \'-\'" << endl;
		cout << endl;
		cout << "                A trading adventure game..." << endl;
		cout << "                             ...in SPAAAAAaaace!" << endl;
		cout << "--------------------------------------------------\n" << endl;
		
		/*** Print Rules ***/
		char rulesInput;

		cout << endl;
		cout << "Would you like to read the space rules? ";
		cin >> rulesInput;
		rulesInput = tolower(rulesInput);
		if (rulesInput == 'y') {
			printRules();
		}
		cout << endl;

		/*** Setup Players ***/
		cout << "Enter number of human players (1-4): ";
		while (!(cin >> numDogs)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "I'm sorry, I didn't catch that. Try again." << endl;
			cout << "Enter number of human players (1-4): ";
		}
		while (numDogs < 1 || numDogs > 4) {
			cout << "There's only room in this galaxy for 4 Space Dogs. Try again: ";
			while (!(cin >> numDogs)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "I'm sorry, I didn't catch that. Try again." << endl;
				cout << "Enter number of human players (1-4): ";
			}
		}

		numCats = 0; // Will implement AI cats later.
		//cout << "Enter number of computer players (0-4): ";
		//cin >> numCats;
		//while (numCats < 0 || numCats > 4) {
		//	cout << "No, human! There can't be more than 4 of us. Answer correctly or face annihilation: ";
		//}

		/*** Setup game parameters ***/
		cout << "How many rounds would you like to play (3-50)? ";
		while (!(cin >> numRounds)) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "I'm sorry, I didn't catch that." << endl;
			cout << "How many rounds would you like to play? (3-50)? ";
		}
		while (numRounds < 3 || numRounds > 50) {
			cout << "Well, that's just not reasonable, even in space. Try again: ";
			cin.clear();
			cin.ignore(100, '\n');

			while (!(cin >> numRounds)) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "I'm sorry, I didn't catch that." << endl;
				cout << "How many rounds would you like to play? (3-50)? ";
			}
		}

		/*** Map created based on number of players ***/
		setupMap();

		/*** Build dogs and cats arrays ***/
		dogs = new DOG_PTR[numDogs];
		cats = new CAT_PTR[numCats];

		// Initialize players vectors.
		setupPlayers();
		setupAIs();

		/*** Run game with current settings ***/
		playGame();
	}

	/* Prints rules for the game.
	Precondition: Player choose to view rules in setup or from main menu.
	Postcondition: Prints rules to screen. */
	void SpaceDogs::printRules() {
		cout << "Space Dogs!" << endl;
		cout << "We sent dogs to space. We thought we were learning from them." << endl;
		cout << endl;
		cout << "They learned from us. They were Good Space Dogs." << endl;
		cout << endl;
		cout << "In the far distant future, Space Dogs have developed their own" << endl;
		cout << "intergalactic travel technology. They established the empire of" << endl;
		cout << "the Space Dogs." << endl;
		cout << endl;
		cout << "But the Space Cats made it out here too. Some of them were once" << endl;
		cout << "sweet lap-kitties. Those friendly cats want nothing but to sit" << endl;
		cout << "in the sun on other worlds and munch on Space Treats. They" << endl;
		cout << "established the empire of the Space Cats and now compete with" << endl;
		cout << "the Space Dogs for the biggest share of the Space Treats." << endl;
		cout << endl;
		cout << "But some kitties were never quite so friendly, those alley cats" << endl;
		cout << "and aloof under-the-bed sneakers evolved to become Space Pirates." << endl;
		cout << "They block the Space Trading Lanes and harass the Space Dogs and" << endl;
		cout << "Space Cats on their endless Space Trading throughout the galaxy." << endl;
		cout << "In space." << endl;
		cout << endl;
		cout << "Your Space Mission, Space Dog, is to get as many Space Treats as" << endl;
		cout << "you can and empower the might of the Space Dog Space Empire." << endl;
		cout << endl;
		system("pause");
		printf("\033c");

		cout << "***The Space Map***" << endl;
		cout << "You can |F|ly to another system in the map by typing F into the" << endl;
		cout << "main menu. Doing so will allow you to end your turn and move to" << endl;
		cout << "another Space Trade System." << endl;
		cout << endl;
		cout << "The map shows the currently known systems as well as Space Objects" << endl;
		cout << "in each system:" << endl;
		cout << "p: Space Cat Pirate(s)" << endl;
		cout << "t: Space Trade Post" << endl;
		cout << "s: Space Ship Depot" << endl;
		system("pause");
		printf("\033c");

		cout << "***Cat Pirates***" << endl;
		cout << "You can choose to B|A|rk or B|I|te a cat pirate. Biting a pirate" << endl;
		cout << "will cause damage. However, the pirate will be able to attack you" << endl;
		cout << "as well. If your Space Ship hull falls to 0, you will be destroyed" << endl;
		cout << "and return to your home system, minus some of your Space Treats." << endl;
		cout << endl;
		cout << "Barking will attempt to scare the Cat Pirate out of the system. If" << endl;
		cout << "successful, the pirate will flee to an adjacent system." << endl;
		system("pause");
		printf("\033c");

		cout << "***Trade Posts***" << endl;
		cout << "You can |B|uy and |S|ell goods at the Space Trade Posts. Fill your" << endl;
		cout << "cargo hold and attempt to make a Space Profit!" << endl;
		cout << endl;
		cout << "Each Trade Post will offer different goods for sale for different" << endl;
		cout << "prices." << endl;
		system("pause");
		printf("\033c");

		cout << "***Ship Depots***" << endl;
		cout << "You can |R|epair your Space Ship's hull or |B|uy a new ship here." << endl;
		cout << "Different depots have different prices for repairs, and offer a" << endl;
		cout << "different set of ships. Buying a new ship will trade in your old" << endl;
		cout << "one for its Value and automatically transfer your cargo to the new" << endl;
		cout << "ship's hold." << endl;
		system("pause");
		printf("\033c");

		cout << "***Scoring***" << endl;
		cout << "Each player's score is a sum of the total value of the cargo in their" << endl;
		cout << "hold, their ship's value, and the number of Space Treats they have on-" << endl;
		cout << "hand. The player with the highest Space Score wins the game." << endl;
		system("pause");
		printf("\033c");

		cout << "***Special Abilities***" << endl;
		cout << "Each Space Breed has a different Space Special Ability. This ability" << endl;
		cout << "is unique to the Space Breed and is only available every 5 Space Rounds." << endl;
		system("pause");
		printf("\033c");		
	}

	/* Fills dogs array.
	Precondition: Game started. Function called during setup phase.
	Postcondition: dogs array populated with player SDDog objects. */
	void SpaceDogs::setupPlayers() {
		string name;

		for (int i = 0; i < numDogs; i++) {
			// Set name.
			cout << "Space Dog " << i + 1 << ", enter your name: ";
			cin >> name;
			cout << "Good Space Dog, " << name << "! Now choose a breed: ";

			// Set breed.
			dogs[i] = chooseBreed(name);
		}
	}

	/* TODO */
	/* Sets up computer player array.
	Precondition: Setup called by start function during intial setup phase.
	Postcondition: cats array populated with SDCat objects. */
	void SpaceDogs::setupAIs() {
		// AI implementation will be my last step.
	}

	/* Sets correct type of breed for player.
	Precondition: Called while each player is choosing setup options. 
	Postcondition: Returns object of appropriate subclass for breed choice. */
	SDDog* SpaceDogs::chooseBreed(string name) {
		char breedChosen = 'n';
		char breedName;

		do {
			cout << "Type the highlighted letter to chose a breed:" << endl;
			cout << "|B|eagle" << endl;
			cout << "|C|hihuahua" << endl;
			cout << "C|O|rgi" << endl;
			cout << "|D|achshund" << endl;
			cout << "|M|utt" << endl;
			
			cin >> breedName;
			breedName = tolower(breedName);

			// Handle improper input.
			while (breedName != 'b' && breedName != 'c' && breedName != 'o' && breedName != 'd' && breedName != 'm') {
				cout << "That breed hasn't developed space travel yet. Please try again." << endl;
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> breedName;
				breedName = tolower(breedName);
			}

			SDDog newDog;
			// Handle player's decision. Offers y/n option.
			switch (breedName) {
			/* Beagle */
			case 'b':
				cout << "Known for your baying bark and powerful nose, you're a great" << endl;
				cout << "hunting companion." << endl;
				cout << endl;
				cout << "Traits:" << endl;
				cout << "Bite bonus: 1" << endl;
				cout << "Bark bonus: 5" << endl;
				cout << "Trade bonus: 0" << endl;
				cout << "Special Ability: BaROOOO!" << endl;
				cout << "Scare the local cats out of hiding. One cat pirate will launch" << endl;
				cout << "its ship in a panic (adds one cat pirate to the local system." << endl;
				cout << endl;

				cout << "Choose this breed? (y / n)";
				cin >> breedChosen;
				if (breedChosen == 'y' || breedChosen == 'Y')
					return new SDDogBeagle(name, map);

				break;

			/* Chihuahua */
			case 'c':
				cout << "You're little, but scrappy. Everyone knows your bite is far" << endl;
				cout << "worse than your bark - including you. And you *own* the space park." << endl;
				cout << "...Own. It." << endl;
				cout << endl;
				cout << "Traits:" << endl;
				cout << "Bite bonus: 5" << endl;
				cout << "Bark bonus: 1" << endl;
				cout << "Trade bonus: 0" << endl;
				cout << "Special ability: Mighty Bite" << endl;
				cout << "Though you be small, you be but fierce. You're in charge and you know it." << endl;
				cout << "Your bite can destroy all pirates, trade posts, and ship depots in a" << endl;
				cout << "system." << endl;
				cout << endl;

				cout << "Choose this breed ? (y / n)";
				cin >> breedChosen;
				if (breedChosen == 'y' || breedChosen == 'Y')
					return new SDDogChihuahua(name, map);
				break;

			/* Corgi */
			case 'o':
				cout << "Everyone thinks you're smiling, but mostly, you're grinning" << endl;
				cout << "thinking of all the space trouble you're about to get into." << endl;
				cout << endl;
				cout << "Traits:" << endl;
				cout << "Bite bonus: 0" << endl;
				cout << "Bark bonus: 1" << endl;
				cout << "Trade bonus: 5" << endl;
				cout << "Special ability: Happy Smile" << endl;
				cout << "Your smile makes everyone think they're your friend." << endl;
				cout << "You convince the local merchants to build a new Ship Depot or" << endl;
				cout << "Trade Post in the local system (Depots must be built in Large" << endl;
				cout << "systems, and Trade Posts must be built in Medium or Large systems." << endl;
				cout << endl;

				cout << "Choose this breed? (y / n)";
				cin >> breedChosen;
				if (breedChosen == 'y' || breedChosen == 'Y')
					return new SDDogCorgi(name, map);
				break;

			/* Dachshund */
			case 'd':
				cout << "Those short little paws can dig, dig, dig! Whole planets have" << endl;
				cout << "become...well, holes. Space holes. The Dachshund homeworld is" << endl;
				cout << "basically just one giant sandpit." << endl;
				cout << endl;
				cout << "Traits:" << endl;
				cout << "Bite bonus: 2" << endl;
				cout << "Bark bonus: 2" << endl;
				cout << "Trade bonus: 2" << endl;
				cout << "Special ability: Dig for Treasure" << endl;
				cout << "Dig up some long-lost Space Cargo in the local system and" << endl;
				cout << "add it to your cargo hold." << endl;
				cout << endl;

				cout << "Choose this breed?";
				cin >> breedChosen;
				if (breedChosen == 'y' || breedChosen == 'Y')
					return new SDDogDachshund(name, map);
				break;

			/* Mutt */
			case 'm':
				cout << "Breed is just a state of mind anyways." << endl;
				cout << "You're space scrappy. Or maybe space gentle. Or maybe space cuddly." << endl;
				cout << "No one space knows, but you have a ship and you're ready to take on" << endl;
				cout << "all those uppity pure-breeds." << endl;
				cout << endl;
				cout << "Traits:" << endl;
				cout << "Bite bonus: Random." << endl;
				cout << "Bark bonus: Random." << endl;
				cout << "Trade bonus: Random." << endl;
				cout << "Special ability: Space Junkyard:" << endl;
				cout << "You're not one of those plush pure-breeds. You've spent" << endl;
				cout << "a fair amount of time in the space junkyards and you" << endl;
				cout << "know your way around." << endl;;
				cout << "You can repair 5 hull points on your ship every 5 rounds." << endl;
				cout << endl;

				cout << "Choose this breed? (y/n)";
				cin >> breedChosen;
				if (breedChosen == 'y' || breedChosen == 'Y')
					return new SDDog(name, map);
				break;

			/* Incorrect input */
			default:
				cout << "Sorry, what?" << endl;
				break;
			}
			
			breedChosen = tolower(breedChosen);
			// Clear input.
			cin.clear();
			cin.ignore(1000, '\n');
		} while (breedChosen != 'y'); // Breed successful set when player enters 'y'.

		return new SDDog(name, map); // Just in case, return default dog (mutt).
	}

	/* Sets up the map.
	Precondition: Game initialized. Called by start function.
	Postcondition: map vector populated with number of players * 3 TradeSystem objects. */
	void SpaceDogs::setupMap() {
		srand(time(NULL));
		int numPlayers = numDogs + numCats;

		int chooser = 0;
		/* Small system: 50% chance
		Medium system: 30% chance
		Large system: 20% chance */
		for (int i = 0; i < numPlayers * 3; i++) {
			chooser = rand() % 8;

			if (chooser >= 0 && chooser < 4)
				map.push_back(new SDTradeSystem("small"));
			else if (chooser >= 4 && chooser < 7)
				map.push_back(new SDTradeSystem("medium"));
			else
				map.push_back(new SDTradeSystem("large"));

			// Print cute pause messages to disguise the time between RNGs.
			if (i == 0)
				cout << "Building the galaxy..." << endl;
			if (i == numPlayers)
				cout << "Burying the space bones....." << endl;
			if (i == (numPlayers * 3) - 1)
				cout << "Fencing the ship yards........" << endl;
			
			// Sleep to allow rand() to use random timesets.
			this_thread::sleep_for(chrono::milliseconds(1000));
		}

		cout << endl;
		cout << "Ready! Go Space Fetch, Space Dogs!" << endl;
		cout << "*=============^o.o^==============*" << endl;
	}

	/* Runs main game.
	Precondition: Set up in start() finished and call to playGame() made.
	Postcondition: Runs game loop until all rounds have been played. */
	void SpaceDogs::playGame() {
		char input;
		/* FULL GAME WHILE LOOP */
		do {

			/* PLAYER TURNS FOR/WHILE LOOP */
			for (int i = 0; i < numDogs; i++) {
				do {
					cout << "---^o.o^-------------" << endl;
					cout << "ROUND " << roundsPlayed + 1 << endl;
					cout << "-------------^o.o^---" << endl;

					printMap(i);
					cout << dogs[i]->getName() << "'s Turn:" << endl;
					cout << endl;
					dogs[i]->getLocation()->systemInfo();
					cout << "------------------^o.o^-------------------" << endl;
					cout << "Choose an option:" << endl;

					/*** MAIN MENU ***/
					if (dogs[i]->getLocation()->getNumPirates() > 0)
						cout << "Fight Cat |P|irates." << endl;
					if (dogs[i]->getLocation()->tradePostPresent())
						cout << "Visit the |T|rade Post." << endl;
					if (dogs[i]->getLocation()->shipDepotPresent())
						cout << "Visit the |S|hip depot." << endl;

					/*** Special Ability available here for some breeds. ***/
					// Mutt, Chihuahua, Beagle and Dachshund always available.
					if (dogs[i]->getBreed() == "Mutt" || dogs[i]->getBreed() == "Chihuahua" ||
						dogs[i]->getBreed() == "Dachshund" || dogs[i]->getBreed() == "Beagle")
						cout << "Use Special |A|bility." << endl;

					// Corgi available in medium or large systems.
					if (dogs[i]->getBreed() == "Corgi" && (dogs[i]->getLocation()->getSize() == "medium" ||
						dogs[i]->getLocation()->getSize() == "large"))
						cout << "Use Special |A|bility." << endl;

					cout << "|F|ly to a new system (ends turn)." << endl;
					cout << "|?| for information." << endl;
					cout << "Hull: " << dogs[i]->shipFunctions()->getHull() << "/" <<
						dogs[i]->shipFunctions()->getMaxHull();
					cout << "  Treats: " << dogs[i]->getTreats();
					cout << "  Cargo Space: " << dogs[i]->shipFunctions()->getAvailableSpace() << endl;

					cin >> input;

					input = tolower(input);

					switch (input) {
					/* Fight pirates */
					case 'p':
						runCombat(*dogs[i], dogs[i]->getLocation());
						break;
					
					/* Visit trade post */
					case 't':
						// Cannot visit if there are any pirates in the system.
						if ((dogs[i]->getLocation()->getNumPirates() == 0) && (dogs[i]->getLocation()->tradePostPresent()))
							runTradePost(*dogs[i], dogs[i]->getLocation());
						else {
							if (dogs[i]->getLocation()->getNumPirates() > 0)
								cout << "The cat pirates are blocking the trade routes in this system." << endl;
							else
								cout << "There is no trade post here, Space Dog!" << endl;
						}
						break;

					/* Visit ship depot */
					case 's':
						// Cannot visit if there are any pirates in the system.
						if ((dogs[i]->getLocation()->getNumPirates() == 0) && (dogs[i]->getLocation()->shipDepotPresent()))
							runShipDepot(*dogs[i], dogs[i]->getLocation());
						else {
							if (dogs[i]->getLocation()->getNumPirates() > 0)
								cout << "The cat pirates are blocking the trade routes in this system." << endl;
							else
								cout << "There is no ship depot here, Space Dog!" << endl;
						}
						break;

					/* Use special ability */
					case 'a':
						dogs[i]->specialAbility();
						break;

					/* Fly */
					case 'f':
						runFly(*dogs[i], dogs[i]->getLocation());
						break;

					/* Get information */
					case '?':
						getInfo(*dogs[i]);
						break;

					/* Incorrect input */
					default:
						cout << "I'm sorry, that's not a space option. Try again, Space Dog:" << endl;
					}
					cout << endl;

				} while (input != 'f'); // End player turn with fly option.

				// Update information for all players.
				for (int i = 0; i < numDogs; i++)
					dogs[i]->endTurn();

				printf("\033c"); // Clears terminal.
			} // End all human players' turns.
		
			/* CAT AI TURNS */
			//do {

			//} while ();
			
			cout << "Round finished." << endl;
			printScores();
			system("pause");
			roundsPlayed++;
			printf("\033c"); // Clears terminal.
		} while (!gameOver());
	}

	/* Runs combat options.
	Precondition: Player chooses to run combat from main menu.
	Postcondition: Bite or Bark actions resolved. Loops until player
	chooses to end combat or opponent destroyed/flees. */
	void SpaceDogs::runCombat(SDDog& player, SDTradeSystem* location) {
		char input;
		int barkDamage = 0;
		int biteDamage = 0;

		cout << "You've chosen to space fight!" << endl;
		location->getNumPirates();
		do {
			cout << "You have " << location->getNumPirates() << " opponents." << endl;
			cout << "What would you like to do?" << endl;
			cout << endl;
			cout << "B|A|rk." << endl; // Tries to force pirate to flee system.
			cout << "B|I|te." << endl; // Tries to destroy pirate and loot goods.
			cout << "E|X|it combat." << endl; // Return to main menu.
			cin >> input;

			input = tolower(input);

			switch (input) {
			/* Bark */
			case 'a':
				barkDamage = player.bark(); // Player's barkBonus + ship's bark strength.
				if (location->getPirateInfo(0)->resistBark(barkDamage)) { // Pirate's resistance.
					cout << "Your mighty space bark rings out with a strength of " << barkDamage << endl;
					cout << "The cat pirate flees to another system!" << endl;
					int flee = rand() % 2;
					cout << "Flee: " << flee << endl;

					if ((flee == 0 && location != *map.begin()) || location == map.back()) {
						SDTradeSystem* prevSystem = *map.begin();
						for (auto i = map.begin(); i != map.end(); i++) {
							if (*i == location)
								prevSystem->addPirate(location->removePirate(0));
							else
								prevSystem = *i;
						}
					}
					else {
						SDTradeSystem* nextSystem = *map.rbegin();
						for (auto i = map.rbegin(); i != map.rend(); i++) {
							if (*i == location)
								nextSystem->addPirate(location->removePirate(0));
							else
								nextSystem = *i;
						}
					}
				}
				else {
					cout << "In space, no one can hear you bark." << endl;
					cout << "The cat pirate is unphased by your bark of strength " << barkDamage << endl;
				}
				break;

			/* Bite */
			case 'i':
				// Player does damage to pirate.
				biteDamage = player.bite();

				location->getPirateInfo(0)->takeDamage(biteDamage);
				cout << "Your ship chomps down on the cat pirate for " << biteDamage << " damage!" << endl;
				// Pirate destroyed?
				if (location->getPirateInfo(0)->getHull() <= 0) {
					cout << "You blew up a pirate!" << endl;
					SDTradeGood* lootedGoods = location->getPirateInfo(0)->lootCargo();
					cout << "You looted " << lootedGoods->getQuantity() << " units of "
						<< lootedGoods->getName() << endl;
					player.shipFunctions()->addCargo(*lootedGoods);

					location->removePirate(0);
				}
				// If any pirates survive, they attack.
				else {
					cout << "The pirates attack!" << endl;
					for (int i = 0; i < location->getNumPirates(); i++) {
						int pirateDamage = location->getPirateInfo(i)->attackPlayer();
						player.shipFunctions()->takeDamage(pirateDamage);
						cout << "You were hit for " << pirateDamage << " damage!" << endl;
						if (player.shipFunctions()->getHull() <= 0) {
							cout << "Your ship blew up! Darn space cats..." << endl;
							player.death();
							input = 'x'; // Player dies. Automatically exits loop.
						}
					}
				}
				// Print player's hull.
				cout << "Hull: " << player.shipFunctions()->getHull() << "/" << player.shipFunctions()->getMaxHull() << endl;
				break;
			
			/* Exit and return to main menu. */
			case 'x':
				cout << "Leaving combat." << endl;
				break;

			/* Incorrect input. */
			default:
				cout << "That's not how you fight! Try again.";
				break;
			}

		} while (location->getNumPirates() > 0 && input != 'x');
	}

	/* Runs trade post optoins.
	Precondition: Player chooses to visit trade post from main menu.
	Postcondition: Player is able to make buy/sell choices and returns main
	menu when finished. */
	void SpaceDogs::runTradePost(SDDog& player, SDTradeSystem* location) {
		char input;
		int goodIndex = 0;
		int quantity = 0;
		int goodCost = 0;

		// Set playerBonus as a percentage.
		double playerBonus = (player.getTradeBonus() * 5) / 100.0; // Bonus of 1 = 5%, 2 = 10%...5 = 25%

		// Run trade post functions in loop.
		do {
			cout << "Welcome to the Trade Post! What would you like to do?" << endl;
			cout << "|B|uy goods." << endl;
			cout << "|S|ell goods." << endl;
			cout << "E|X|it." << endl;

			while (!(cin >> input)) {
				cout << "I'm sorry, I didn't catch that. Try again: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}

			input = tolower(input);

			switch (input) {
			/* Buy goods */
			case 'b':
				do {
					cout << "These goods are for sale here:" << endl;
					location->tradePostFunction()->printGoodsForSale(player.getTradeBonus());
					cout << endl;
					cout << "Enter the listing number for the good you would like to buy (type -1 to return): ";
					while (!(cin >> goodIndex)) {
						cout << "I'm sorry, I didn't catch that. Try again: ";
						cin.clear();
						cin.ignore(1000, '\n');
					}

					while (goodIndex > location->tradePostFunction()->getNumGoodsForSale() ||
						goodIndex == 0) {
						cout << "That good doesn't exist. Try again: ";
						while (!(cin >> goodIndex)) {
							cout << "I'm sorry, I didn't catch that." << endl;
							cin.clear();
							cin.ignore(1000, '\n');
							cout << "Enter the number for the good you would like to sell (-1 to quit): ";
						}
					}

					goodIndex--; // Make good index compatible with vector.
					if (goodIndex < 0)
						break;

					// Examine chosen good's attributes.
					SDTradeGood* newGood = location->checkoutGood(goodIndex);
					int maxWeight; // Maximum number of goods buyable by weight.
					int maxPrice; // Maxiumum number of goods buyable by price.
					int buyable = 0; // Least of either maxWeight or maxPrice.

					goodCost = location->tradePostFunction()->getGoodForSalePrice(newGood->getName());
					goodCost = goodCost - (playerBonus * goodCost);
					
					maxWeight = player.shipFunctions()->getAvailableSpace() / newGood->getIndividualWeight();
					maxPrice = player.getTreats() / goodCost;

					if (maxWeight < maxPrice)
						buyable = maxWeight;
					else
						buyable = maxPrice;
					
					// If buyable is more goods than is available at this post, set to quantity.
					if (newGood->getQuantity() < buyable)
						buyable = newGood->getQuantity();
					
					// Cannot afford goods. Exit buy.
					if (buyable <= 0) {
						cout << "You can't buy any " << newGood->getName() << "!" << endl;
						break;
					}

					// Buyable requirements met.
					cout << "You can buy up to " << buyable << " " << newGood->getName() << "." << endl;
					cout << "You have " << player.shipFunctions()->getAvailableSpace() << 
						" space available in your cargo hold and " << player.getTreats() << " treats." << endl;
					cout << "How many goods would you like to purchase? ";
					while (!(cin >> quantity)) {
						cin.clear();
						cin.ignore(1000, '\n');
						cout << "Try again. How many goods would you like to purchase? ";
					}
					while (quantity < 0 || quantity > buyable) {
						cout << "You can't buy that many! Try again: ";
						while (!(cin >> quantity)) {
							cin.clear();
							cin.ignore(1000, '\n');
							cout << "Try again. How many goods would you like to purchase? ";
						}
					}

					if (quantity == 0)
						break;

					SDTradeGood boughtGood = location->tradePostFunction()->buyGood(goodIndex, quantity);
					player.shipFunctions()->addCargo(boughtGood);
					player.spendOrEarnTreats(-goodCost);

					cout << "You spent " << goodCost << " treats." << endl;
					cout << "You now have " << player.getTreats() << " treats." << endl;

				} while (goodIndex != -1);
				break;

			/* Sell goods */
			case 's':
				do {
					cout << "The trade post will buy these goods:" << endl;
					location->tradePostFunction()->printGoodsForPurchase(player.getTradeBonus());
					cout << endl;
					cout << "----------------" << endl;
					cout << "Your cargo hold:" << endl;
					cout << "----------------" << endl;
					player.shipFunctions()->printCargo();
					cout << "Enter the number for the good you would like to sell (-1 to quit): ";
					while (!(cin >> goodIndex)) {
						cout << "I'm sorry, I didn't catch that." << endl;
						cin.clear();
						cin.ignore(1000, '\n');
						cout << "Enter the number for the good you would like to sell (-1 to quit): ";
					}

					while (goodIndex > player.shipFunctions()->getNumGoods() ||
						goodIndex == 0) {
						cout << "That good doesn't exist. Try again: ";
						while (!(cin >> goodIndex)) {
							cout << "I'm sorry, I didn't catch that." << endl;
							cin.clear();
							cin.ignore(1000, '\n');
							cout << "Enter the number for the good you would like to sell (-1 to quit): ";
						}
					}

					goodIndex--;
					if (goodIndex < 0)
						break;

					cout << "How many would you like to sell? ";
					while (!(cin >> quantity)) {
						cout << "I'm sorry, I didn't catch that. Try again: ";
						cin.clear();
						cin.ignore(1000, '\n');
					}
					if (quantity <= 0)
						break;
					while (quantity > player.shipFunctions()->getCargoQuantity(goodIndex) ||
						quantity < 0) {
						cout << "You don't have that many! Try again: " << endl;
						while (!(cin >> quantity)) {
							cout << "I'm sorry, I didn't catch that. Try again: ";
							cin.clear();
							cin.ignore(1000, '\n');
						}
					}
					// Goods sold. Create comparable goods object with given quantity and pass to trade post.
					SDTradeGood soldCargo = player.shipFunctions()->removeCargo(goodIndex, quantity);
					goodCost = location->tradePostFunction()->getGoodForPurchasePrice(soldCargo.getName());
					goodCost = goodCost + (goodCost * playerBonus);
					player.spendOrEarnTreats(goodCost);
					cout << "You earned " << goodCost << " treats!" << endl;
				} while (goodIndex != -1); // End sell functions.
				break;

			/* Exit trade post menu */
			case 'x':
				break;

			/* Incorrect input */
			default:
				cout << "I'm sorry, I didn't catch that." << endl;
				break;
			}
		} while (input != 'x'); // End trade post menu functions and return to main menu.
	}

	/* Runs ship depot options.
	Precondition: Player chooses to visit ship depot from main menu.
	Postcondition: Player repairs ship or trades for new ship and returns to
	main menu. */
	void SpaceDogs::runShipDepot(SDDog& player, SDTradeSystem* location) {
		char input;
		int index;
		int cost;
		int tradeValue;
		do { // Run menu loop.
			cout << "Your current ship is a " << player.shipFunctions()->getName() <<
				" worth " << player.shipFunctions()->getShipValue() << endl;
			cout << "Your current hull strength is " << player.shipFunctions()->getHull()
				<< "/" << player.shipFunctions()->getMaxHull() << endl;
			cout << "You have " << player.getTreats() << " treats." << endl;

			cout << endl;
			cout << "|R|epair ship." << endl;
			cout << "|B|uy ship." << endl;
			cout << "E|X|it." << endl;
			cout << "What would you like to do? ";
			cin >> input;

			input = tolower(input);

			switch (input) {
			/* Repair ship */
			case 'r':
				int hullRepair;
				cout << "Your current hull is " << player.shipFunctions()->getHull() << "/" <<
					player.shipFunctions()->getMaxHull() << endl;
				cout << "You have " << player.getTreats() << endl;
				cout << "The station will repair your ship for " << location->shipDepotFunction()->getRepairPrice() <<
					" treats per point." << endl;
				cout << "How many points would you like to repair? ";
				cin >> hullRepair;

				if (hullRepair > player.shipFunctions()->getMaxHull() - player.shipFunctions()->getHull()) {
					hullRepair = player.shipFunctions()->getMaxHull() - player.shipFunctions()->getHull();
					cout << "That's too many! Repairing " << hullRepair << " points instead." << endl;
				}

				cost = hullRepair * location->shipDepotFunction()->getRepairPrice();
				if (cost > player.getTreats())
					cout << "You don't have " << cost << " treats." << endl;
				else {
					player.shipFunctions()->repairHull(hullRepair);
					player.spendOrEarnTreats(-cost);
				}

				break;

			/* Buy ship (trades in old ship) */
			case 'b':
				cout << "These ships are for sale:" << endl;
				location->shipDepotFunction()->listShips();

				cout << "Type the number of the ship you would like to trade for" << endl;
				cout << "or type -1 to exit: ";
				while (!(cin >> index)) {
					cout << "I'm sorry, I didn't catch that. Try again: ";
					cin.clear();
					cin.ignore(1000, '\n');
				}

				while (index > location->shipDepotFunction()->numShipsForSale() ||
					index == 0) {
					cout << "That ship doesn't exist. Try again: ";
					while (!(cin >> index)) {
						cout << "I'm sorry, I didn't catch that. Try again: ";
						cin.clear();
						cin.ignore(1000, '\n');
					}
				}

				index--;
				if (index < 0)
					break;

				// Determine available trade value based on player's current ship and number
				// of treats on-hand.
				tradeValue = player.shipFunctions()->getShipValue() + player.getTreats();
				if (tradeValue < location->shipDepotFunction()->shipPrice(index))
					cout << "You can't afford that ship." << endl;
				else {
					location->shipDepotFunction()->getShipForSaleInfo(index);
					cout << "Would you like to buy this ship? ";
					cin >> input;

					input = tolower(input);
					if (input == 'y') {
						SDShip* oldShip = player.shipFunctions();
						int oldShipValue = oldShip->getShipValue();
						SDShip newShip = location->shipDepotFunction()->tradeShip(*oldShip, index);
						player.buyNewShip(&newShip);

						int treatsSpent = newShip.getShipValue() - oldShipValue;
						cout << "oldShip: " << oldShipValue << endl;
						cout << "newShip: " << newShip.getShipValue();
						cout << "treatsSpent: " << treatsSpent;
						player.spendOrEarnTreats(-treatsSpent);
					}
				}
				break;

			/* Exit depot menu. */
			case 'x':
				break;

			/* Incorrect input. */
			default:
				cout << "That's not an option. Please try again." << endl;
				break;
			}
		} while (input != 'x');
	}

	/* Player flies to new system.
	Precondition: Player chooses this option from the main menu.
	Postcondition: Player's location changed to new system. If system is beyond
	scope of "explored" map, add a new system to either the front or back of 
	map vector, as required. */
	void SpaceDogs::runFly(SDDog& player, SDTradeSystem* location) {
		char input;
		int chooser;
		SDTradeSystem* temp;
		do {
			cout << "Fly |L|eft or |R|ight ('x' to end turn without moving)? ";
			cin >> input;
			input = tolower(input);
			switch (input) {
			/* Fly left */
			case 'l':
				if (location == map.front()) {
					chooser = rand() % 8;

					if (chooser >= 0 && chooser < 4)
						map.insert(map.begin(), new SDTradeSystem("small"));
					else if (chooser >= 4 && chooser < 7)
						map.insert(map.begin(), new SDTradeSystem("medium"));
					else
						map.insert(map.begin(), new SDTradeSystem("large"));
				}
				temp = map.front();
				// Iterate through map until current location found, then move
				// pointer to previous object.
				for (auto i = map.begin(); i != map.end(); i++) {
					if (*i == location) {
						location = temp;
						break;
					}
					else
						temp = *i;
				}
				player.flyTo(location);
				break;
			case 'r':
				if (location == map.back()) {
					chooser = rand() % 8;

					if (chooser >= 0 && chooser < 4)
						map.push_back(new SDTradeSystem("small"));
					else if (chooser >= 4 && chooser < 7)
						map.push_back(new SDTradeSystem("medium"));
					else
						map.push_back(new SDTradeSystem("large"));
				}
				
				// Reverse iterate through map until location found,
				// then move pointer to next object.
				temp = map.back();
				for (auto i = map.rbegin(); i != map.rend(); i++) {
					if (*i != location) {
						temp = *i;
					}
					else {
						location = temp;
						break;
					}
				}
				player.flyTo(location);
				break;

			/* Exit without moving. */
			case 'x':
				break;

			/* Incorrect input. */
			default:
				cout << "Not a valid space option. Please try again." << endl;
				break;
			}
		} while (input != 'x' && input != 'l' && input != 'r'); // End fly loop.
	}

	/* Allows player to request info on current status.
	Precondition: '?' entered on main menu.
	Postcondition: Prints info as player requests it from this menu. */
	void SpaceDogs::getInfo(SDDog& player) {
		char input;
		do {
			cout << "What woudld you like to view?" << endl;
			cout << "|R|ules." << endl;
			cout << "My |D|og." << endl;
			cout << "My |S|hip." << endl;
			cout << "My |C|argo." << endl;
			cout << "My |T|reats." << endl;
			cout << "My Sc|O|re." << endl;
			cout << "E|X|it." << endl;

			while (!(cin >> input)) {
				cout << "I'm sorry, I didn't catch that. Try again: ";
				cin.clear();
				cin.ignore(1000, '\n');
			}

			input = tolower(input);

			printf("\033c");
			switch (input) {

			/* Print rules */
			case 'r':
				printRules();
				break;

			/* Print dog info */
			case 'd':
				player.printInfo();
				break;

			/* Print ship info */
			case 's':
				player.shipFunctions()->printShipInfo();
				break;

			/* Print cargo list */
			case 'c':
				player.shipFunctions()->printCargo();
				break;

			/* Print number of treats. */
			case 't':
				cout << "Your Space Treats: " << player.getTreats() << endl;
				break;

			/* Print score */
			case 'o':
				cout << "Your Space Score: " << player.getScore() << endl;
				break;

			/* Exit menu */
			case 'x':
				break;

			/* Incorrect input */
			default:
				cout << "I'm sorry, I didn't catch that. Try again: ";
				break;
			}
			cout << endl;
		} while (input != 'x');
	}

	/* Returns true if game is over.
	Precondition: Game round finished.
	Postcondition: Returns true if chosen number of rounds have been played. Else false. */
	bool SpaceDogs::gameOver() {
		// If played number of chosen rounds, game is over.
		if (roundsPlayed >= numRounds) {
			// Determine winner (highest score).
			int winner = 0;
			string winnerName = "";
			for (int i = 0; i < numDogs; i++) {
				if (dogs[i]->getScore() > winner) {
					winner = dogs[i]->getScore();
					winnerName = dogs[i]->getName();
				}
			}
			/**TODO**/
			/*for (int i = 0; i < numCats; i++) {
				if (cats[i]->getScore() > winner) {
					winner = cats[i]->getScore();
					winnerName = cats[i]->getName();
				}
			}*/
			
			// Print winner.
			cout << "*******************" << endl;
			cout << "All Rounds Finished" << endl;
			cout << "***^o.o^***********" << endl;

			cout << endl;
			printScores();
			cout << endl;
			cout << winnerName << " is the space winner!" << endl;
			cout << "Until next time, Space Dogs!" << endl;
			return true;
		}
		else // Game not over.
			return false;
	}

	/* Prints scores to output.
	Precondition: Called at end of each round.
	Postcondition: Scores printed to output. */
	void SpaceDogs::printScores() {
		cout << "Scores:" << endl;
		printf("%-15s%-10s%s\n", "Name", "Breed", "Treats");
		cout << "-------^o.o^----------------" << endl;

		if (numDogs > 0) {
			for (int i = 0; i < numDogs; i++) {
				string name = dogs[i]->getName();
				string breed = dogs[i]->getBreed();
				int score = dogs[i]->getScore();
				printf("%-15s%-10s%i\n", name.c_str(), breed.c_str(), score);
			}
		}
		/*
		if (numCats > 0) {
			for (int i = 0; i < numCats; i++) {
				string name = cats[i]->getName();
				int score = cats[i]->getScore();
				printf("%-15s%-10s%i\n", name.c_str(), "Space Cat", score);
			}
		}*/
	}

	/* Prints the map.
	Precondition: Beginning of player's turn.
	param int currentDog: Index of current player in dogs array.
	
	Postcondition: map is printed to output. */
	void SpaceDogs::printMap(int currentDog) {
		int counter = 0;
		int currentSector = 0;
		int lastSector = 0;

		while (lastSector < map.size()) {
			counter = 0;
			currentSector = lastSector;
			/* Top Row */
			if (currentSector == 0)
				cout << "               ";

			while (counter < 11 && currentSector < map.size()) {
				if (map[currentSector]->getSize() == "small")
					cout << "  ___  ";
				else if (map[currentSector]->getSize() == "medium")
					cout << "  ____  ";
				else
					cout << "  _____  ";
				counter++;
				currentSector++;
			}
			counter = 0;
			currentSector = lastSector;
			cout << endl;
			
			/* Middle Row */
			if (lastSector == 0)
				cout << "Unknown Space<-";

			while (counter < 11 && currentSector < map.size()) {
				cout << "->|";
				if (map[currentSector]->getNumPirates() != 0)
					cout << "p";
				else
					cout << " ";
				if (map[currentSector]->getSize() == "small") {
					cout << "|<-";
				}
				else if (map[currentSector]->getSize() == "medium") {
					if (map[currentSector]->tradePostPresent())
						cout << "t";
					else
						cout << " ";

					cout << "|<-";
				}
				else if (map[currentSector]->getSize() == "large") {
					if (map[currentSector]->tradePostPresent())
						cout << "t";
					else
						cout << " ";

					if (map[currentSector]->shipDepotPresent())
						cout << "s";
					else
						cout << " ";

					cout << "|<-";
				}
				counter++;
				currentSector++;
			}
			if (currentSector == map.size())
			cout << "->Unknown Space";
			cout << endl;
			
			/* Bottom Row */
			counter = 0;
			currentSector = lastSector;
			
			if (currentSector == 0)
				cout << "               ";

			while (counter < 11 && currentSector < map.size()) {
				if (map[currentSector]->getSize() == "small")
					cout << "  \"\"\"  ";
				else if (map[currentSector]->getSize() == "medium")
					cout << "  \"\"\"\"  ";
				else
					cout << "  \"\"\"\"\"  ";
				counter++;
				currentSector++;
			}
			cout << endl;

			/* Player Row */
			counter = 0;
			currentSector = lastSector;
			if (currentSector == 0)
				cout << "               ";

			while (counter < 11 && currentSector < map.size()) {
				bool printed = false;
				if(dogs[currentDog]->getLocation() == map[currentSector])
					if (map[currentSector] == dogs[currentDog]->getLocation()) {
						cout << "  ";
						if (map[currentSector]->getSize() == "medium")
							cout << " ";
						else if (map[currentSector]->getSize() == "large")
							cout << "  ";
						string dogName = dogs[currentDog]->getName().substr(0, 3);
						while (dogName.length() < 3)
							dogName += " ";
						cout << dogName << "  ";
						printed = true;
					}

				if (!printed) {
					if (map[currentSector]->getSize() == "small")
						cout << "       ";
					else if (map[currentSector]->getSize() == "medium")
						cout << "        ";
					else if (map[currentSector]->getSize() == "large")
						cout << "         ";
				}

				counter++;
				currentSector++;
			}

			cout << endl;
			/* Reset for next round of prints. */
			lastSector += currentSector;
		}

	}
}