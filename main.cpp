// Terminally Suprising Slots
// Written By: Trentyne Morgan

#include <iostream>		// Standard C++ Input/Output
#include <stdlib.h>		// Standard C Library
#include <ctime>		// C++ Time Library

// =============================================================================
/* Function to check for slot matches (takes three parameters for each slot) */
// =============================================================================
int checkSlotAmount(int num1, int num2, int num3){
	
	// Check if any 2 slots are equal to each other.
	// If they are, give the player 50 dollars.
	if (num1 == num2){
		
		return 50;
		
	} else if (num1 == num3){
		
		return 50;
		
	} else if (num2 == num1){
		
		return 50;
		
	} else if (num2 == num3){
		
		return 50;
		
	} else if (num3 == num1){
		
		return 50;
			
	} else if (num3 == num2){
		
		return 50;
	
	// If three match, give the player 100 dollars.
	} else if (num1 == num2 == num3){
		
		return 100;
	
	// Don't return anything if no match
	} else {
		
		return 0;
	}
}


// ==============================================================================================
/* Function to generate random numbers. *Used references ('&' operator) here to make it easier */
// ==============================================================================================
int rollNumbers(int &slot1, int &slot2, int &slot3){
	
	// Seed RNG so we avoid the same number
	srand(time(NULL));
	
	// Return 3 random numbers between 1 and 9
    slot1 = rand() % 9;
	slot2 = rand() % 9;
	slot3 = rand() % 9;
}

// =================================================================================================================
/* Function to Display our Slot Machine
Has 3 Parameters for slots, 1 for player's cash, and a bool variable to show the earnings chart next to the slots */
/* Tip: these values already defined in the parameters in this function would be called 'default variables' */
// =================================================================================================================
int slotMachineDisplay(int randomNum1 = 0, int randomNum2 = 0, int randomNum3 = 0, int playerMoney = 0, bool showEarnings = false){
	
	// Show just the slot display if showEarnings is false
	if (showEarnings == false){
	
		std::cout << "=====================\n";
		std::cout << "|    C    M     D   |\n";
		std::cout << "=====================\n";
		std::cout << "=     =      =      =\n";
		std::cout << "=     =      =      =\n";
		std::cout << "=  " << randomNum1 << "  =   " << randomNum2 << "  =   " << randomNum3 << "  =\n";
		std::cout << "=     =      =      =\n";
		std::cout << "=     =      =      =\n";
		std::cout << "=====================\n";
		std::cout << "$: " << playerMoney << "\n";
		std::cout << "=====================\n\n";
	
	// Show the earnings chart next to the slots if showEarnings is true
	} else if (showEarnings == true){

		std::cout << "=====================" << "    Earnings Chart:\n";
		std::cout << "|    C    M     D   |" << "    1. 2 Number Match = $50\n";
		std::cout << "=====================" << "    2. 3 Number Match = $100\n";
		std::cout << "=     =      =      =\n";
		std::cout << "=     =      =      =\n";
		std::cout << "=  " << randomNum1 << "  =   " << randomNum2 << "  =   " << randomNum3 << "  =\n";
		std::cout << "=     =      =      =\n";
		std::cout << "=     =      =      =\n";
		std::cout << "=====================\n";
		std::cout << "$: " << playerMoney << "\n";
		std::cout << "=====================\n\n";
		
	} else {
		
		std::cout << "=====================\n";
		std::cout << "|    C    M     D   |\n";
		std::cout << "=====================\n";
		std::cout << "=     =      =      =\n";
		std::cout << "=     =      =      =\n";
		std::cout << "=  " << randomNum1 << "  =   " << randomNum2 << "  =   " << randomNum3 << "  =\n";
		std::cout << "=     =      =      =\n";
		std::cout << "=     =      =      =\n";
		std::cout << "=====================\n";
		std::cout << "$: " << playerMoney << "\n";
		std::cout << "=====================\n\n";
	}
}

// ================
/* Main Function */
// ================
int main(){
	
	// Player's Cash
	int playersCash = 30;
	
	// Slot columns for slot display
	int slotColumn1 = 0;
	int slotColumn2 = 0;
	int slotColumn3 = 0;
	
	// This boolean controls our game loop
	bool gameRun = true;
	
	// Title Message
	std::cout << "== Terminally Suprising Slots -- Written By: Trentyne Morgan ==\n";
	std::cout << "==           Step right up, only costs 5 credits...          ==\n\n";
	
	// Show the slot machine display
	slotMachineDisplay(slotColumn1, slotColumn2, slotColumn3, playersCash);
	
	// While our game loop runs..
	while (gameRun == true){
		
		std::string playerInput = "0";
		
		// Accept Input
		std::cout << "Type 'roll' to try your luck, or type 'score' to see the earnings chart: ";
		std::cin >> playerInput;
		
		if (playerInput == "roll"){
			
			if (playersCash <= 0){
				
				system("CLS");
				std::cout << "You went broke, Game Over...";
				return 0;
				
			} else {
				
				playersCash -= 5;
			}
			
			// Roll new Numbers for the slots
			rollNumbers(slotColumn1, slotColumn2, slotColumn3);
			
			// Return any money made by player
			playersCash += checkSlotAmount(slotColumn1, slotColumn2, slotColumn3);
			
			// Clearing the screen
			system("cls");
			
	 		// Title Message
			std::cout << "== Terminally Suprising Slots -- Written By: Trentyne Morgan ==\n";
			std::cout << "==           Step right up, only costs 5 credits...          ==\n\n";
			
			// Show the Slot Machine
			slotMachineDisplay(slotColumn1, slotColumn2, slotColumn3, playersCash);
			
		} else if (playerInput == "score"){
			
			system("CLS");
			
			// Title Message
			std::cout << "== Terminally Suprising Slots -- Written By: Trentyne Morgan ==\n";
			std::cout << "==           Step right up, only costs 5 credits...          ==\n\n";
		
			// Display Slot Machine
			slotMachineDisplay(slotColumn1, slotColumn2, slotColumn3, playersCash, true);
			
		} else {
			
			std::cout << "\nInvalid Input, please try again\n\n";
		}
	}
	
}