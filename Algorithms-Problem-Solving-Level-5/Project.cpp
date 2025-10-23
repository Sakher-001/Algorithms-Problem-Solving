#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std ; 

enum enChoice { Stone = 1, Paper = 2, Seissors = 3 };
enum enGameResult { PlayerWinner = 1 , ComputerWinner = 2 , Draw = 3 };


struct stGameResult {
	short GameRounds = 0 ;
	short PlayerWinsTimes = 0 ;
	short ComputerWinsTimes = 0 ;
	short DrawTimes = 0 ;
	enGameResult Winner ; 
	string WinnerName = "" ;
};

struct stRoundInfo{
	short RoundNumber = 0 ;
	enChoice PlayerChoice ; 
	enChoice ComputerChoice ; 
	enGameResult Winner ; 
	string WinnerName = "" ;
};

int ReadHowManyRounds() {
    int GameRounds = 0 ;
    do {
        cout << "Please Enter Number Of Rounds  1 , 10 : ";
        cin >> GameRounds;
    } while (GameRounds <= 0 || GameRounds > 10);
    return GameRounds;
}

string WinnerName(enGameResult Winner){
	string WinnerName[3] =  {"Player" , "Computer" , "No Winner"} ;
	return WinnerName[Winner - 1] ;
}

int RandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from;
}

enChoice ReadPlayerChoice() {
    int Choice = 1 ;
    do {
        cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors? ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);
    return (enChoice)Choice;
}

enChoice GetComputerChoice (){
	return (enChoice)RandomNumber( 1 , 3 ) ;
}

enGameResult WhoWinTheRound(stRoundInfo RoundInfo){
	if (RoundInfo.PlayerChoice == RoundInfo.ComputerChoice){
		return enGameResult::Draw ;
	}
	switch (RoundInfo.PlayerChoice){
		case enChoice::Stone :
		if (RoundInfo.ComputerChoice == enChoice::Paper)
		{
			return enGameResult::ComputerWinner ;
		}
		break ;
		case enChoice::Paper : 
		if (RoundInfo.ComputerChoice == enChoice::Seissors)
		{
			return  enGameResult::ComputerWinner ;
		}
		break; 
		case enChoice::Seissors :
		if (RoundInfo.ComputerChoice == enChoice::Stone)
		{
			return enGameResult::ComputerWinner ;
		}
	}
	return enGameResult::PlayerWinner ;
}

enGameResult WhoWonTheGame(short PlayerWinTimes , short ComputerWinTimes) {
	if (PlayerWinTimes  > ComputerWinTimes) return enGameResult::PlayerWinner ;
	else if (ComputerWinTimes > PlayerWinTimes) return enGameResult::ComputerWinner ;
	else return enGameResult::Draw ;
}

void SetWinnerScreenColor(enGameResult GameResult){
	switch(GameResult){ 
		case enGameResult::PlayerWinner : 
		system("color 2F");
		break ;
		case enGameResult::ComputerWinner : 
		system("color 4F") ;
		cout << "\a" ;
		break;
		case enGameResult::Draw :
		system("color 6F");
        break;
        default : 
        system("color 0F") ;
	}
}

stGameResult FillGameResult (int GameRounds , short PlayerWinTimes , short ComputerWinTimes , short DrawTimes){
	stGameResult GameResult ;
	GameResult.GameRounds = GameRounds ;
	GameResult.PlayerWinsTimes = PlayerWinTimes ;
	GameResult.ComputerWinsTimes = ComputerWinTimes ;
	GameResult.DrawTimes = DrawTimes ;
	GameResult.Winner = WhoWonTheGame(PlayerWinTimes , ComputerWinTimes) ;
	GameResult.WinnerName  = WinnerName(GameResult.Winner);
	return GameResult ;
}


string ChoiceName (enChoice Choice){
	string arrGameChoice[3] = {"Stone" , "Paper" , "Seissors"};
	return arrGameChoice[Choice - 1] ;
}

void PrintRoundResult(stRoundInfo RoundInfo){
	cout << "\n_____________________Round [" << RoundInfo.RoundNumber << "]_________________\n\n" ;
	cout << "Player Choice : " << ChoiceName(RoundInfo.PlayerChoice)     << endl ;
	cout << "Computer Choice : " << ChoiceName(RoundInfo.ComputerChoice) << endl ;
	cout << "Round Winner : [" << RoundInfo.WinnerName << "]\n" ;
	cout << "________________________________________________________________________________________\n\n";
	SetWinnerScreenColor(RoundInfo.Winner);
}

stGameResult PlayGame(short HowManyRounds) {
	stRoundInfo RoundInfo ;
	short PlayerWinTimes = 0 , ComputerWinsTime = 0 , DrawTimes = 0 ;
	for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begins : \n" ;
		RoundInfo.RoundNumber = GameRound ;
		RoundInfo.PlayerChoice = ReadPlayerChoice() ;
		RoundInfo.ComputerChoice = GetComputerChoice() ;
		RoundInfo.Winner = WhoWinTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner) ;

		if (RoundInfo.Winner == enGameResult::PlayerWinner) PlayerWinTimes++;
		else if(RoundInfo.Winner == enGameResult::ComputerWinner) ComputerWinsTime++;
		else DrawTimes++;
		PrintRoundResult(RoundInfo) ;
	}
	return FillGameResult(HowManyRounds , PlayerWinTimes  , ComputerWinsTime , DrawTimes ) ;
}

string Taps(short NumberOfTaps){
	string t = "" ;
	for (int i = 1; i < NumberOfTaps; i++)
	{
		t += "\t"; 
		cout << t ;
	}
	return t ;
}


void ShowGameOverScreen(){
	cout << Taps(2) << "____________________________________________________________\n\n" ;
	cout << Taps(2) << "                        +++   Game Over   +++            \n" ;
	cout << Taps(2) << "____________________________________________________________\n\n" ;
}


void ShowFinalGameResult(stGameResult GameResult){
	cout << Taps(2) << "_______________________[ Game Results ]_____________________\n\n" ;
	cout << Taps(2) << "Game Ronunds : " << GameResult.GameRounds << endl ;
	cout << Taps(2) << "PLayer Won Times : " << GameResult.PlayerWinsTimes << endl  ;
	cout << Taps(2) << "Computer Won Times : " << GameResult.ComputerWinsTimes << endl  ;
	cout << Taps(2) << "Draw Times : " << GameResult.DrawTimes << endl ;
	cout << Taps(2) << "Final Winner : " << GameResult.WinnerName  << endl ;
	cout << Taps(2) << "____________________________________________\n\n" ;

    SetWinnerScreenColor(GameResult.Winner);
}

void StartGame(){
	char PlayAgain = 'Y' ;
	do
	{
        system("cls");  // Clear the screen before starting a new game.
		system("color 0F");
		stGameResult GameResult = PlayGame(ReadHowManyRounds());
		ShowGameOverScreen();
		ShowFinalGameResult(GameResult);
		cout << endl << Taps(3) << "Do You Want To Play Again Y/N : " ;
		cin >> PlayAgain ;
	} while (PlayAgain == 'y' || PlayAgain == 'Y');
	
}

int main(){
	srand((unsigned)time(NULL));
	StartGame();
	return 0 ;
}