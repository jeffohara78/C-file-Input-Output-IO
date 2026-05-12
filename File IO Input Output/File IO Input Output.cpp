// File IO Input Output.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
Jeff O'Hara
CSC275
File I/O (Input Output
A program that writes data to a .txt file and reads that data from it
*/

//included libraries
#include <iostream>
#include <fstream>

//using standard namespace
using namespace std;

//Main Function
int main() 
{
	//initialize variables
	char character[50];
	int health;

	//initialize a new file for input and output
	fstream myNewSaveFile;

	//Open/Create a new text file called "save" for output only
	myNewSaveFile.open("save.txt", ios::out);
	//check to make sure file opened
	if (!myNewSaveFile)
	{
		cout << "Could not create file. " << endl;
		return 0;
	}
	//Simple output to user stating a new file has been created
	cout << "File created successfully!" << endl;

	//Display and get info from user for the program
	cout << "Enter a name for your character: " << endl;
	cin.getline(character, 50);//using the cin.getline instead of cin for reading user input in case there is a space or special character
	cout << "Enter the current health of your character: " << endl;
	cin >> health;

	//using myNewSaveFile for output instead of using a cout statement to display output 
	myNewSaveFile << character << " " << health << endl;

	//closing the file after inputting date to the file
	myNewSaveFile.close();
	cout << "File saved and closed successfully." << endl;//letting user know that file has been successfully closed

	//opening "save.txt" for reading from the file for input
	myNewSaveFile.open("save.txt", ios::in);
	//check to make sure file opened
	if (!myNewSaveFile)
	{
		cout << "Could not create file. " << endl;
		return 0;
	}
	//Simple output to user stating a new file has been created
	cout << "File created successfully!" << endl;

	//read data from saved file
	myNewSaveFile >> character;
	myNewSaveFile >> health;

	//output to console what had been collected previously and stored in a separate .txt file 
	cout << "Character name: " << character << ", Health left: " << health << endl;

	return 0;
}