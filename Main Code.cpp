// ZI QI editing

#include <iostream> 
#include <iomanip>	// manipulate output
#include <ios>		// for stream size
#include <limits>	// for numeric limits
#include <string>
using namespace std;

int main() 
	{
		// declare variables
		char menu, proceed, trailer;
		string movA, movB, movC, date, dur, stime, etime, turl1, turl2, turl3, lang1, lang2, subt;
		unsigned int space;
		int mdetail, ticket1, ticket2, ticket3;
		double studentp, staffp, childp, adultp, d10, d20;
	
		// declare values into var
		movA = "Movie A";
		movB = "Movie B";
		movC = "Movie C";
		date = "Date: 12/12/2022";
		dur = "Duration: 2 hours 30 minutes";
		stime = "Start time: 19:00";
		etime = "End time: 21:30" ;
		lang1 = "Language: EN";
		lang2 = "Language: CN";
		subt = "Subtitle: EN & CN & BM";
		ticket1 = 100, ticket2 = 100, ticket3 = 100;
		turl1 = "start https://github.com/leong308/";
		turl2 = "start https://github.com/leong308/";
		turl3 = "start https://github.com/leong308/";
		studentp = 10, staffp = 12, childp = 6, adultp = 15;	// ticket prices
		d10 = 0.90, d20 = 0.80;									// ticket discounts
		
		// need modify more
		cout << "Welcome!" << endl;
		cout << "_____________________________" << endl;
		
		// display section
		
		// infinite loop while != Y or N
		do{
			// 3 selections in main menu
			cout << "\nView movie list. Enter 'L'" << endl;
			cout << "View ticket price. Enter 'T'" << endl;
			cout << "Buy ticket now! Enter 'P'" << endl;
			cout << "\nYour selection: ";
			cin >> menu;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
			if(menu != 'L' && menu != 'T' && menu != 'P')
				cout << "Invalid input. Please try again.\n" << endl;
            
				// Y or N condition
				switch(menu)
				{
					// display movie list
					case 'L':   // infinite loop while mdetail < 1 or > 3
								do{
									// infinite loop while mdetail < 1 or > 3
									/* additional do while branch is needed to prevent
									   fals overall output while triggers default case */ 
									do{	
										cout << "\n1. " << movA << endl;
										cout << "2. " << movB << endl;
										cout << "3. " << movC << endl;
									
		            					cout << "\nEnter the number of a movie for more details." << endl;
		            					cin >> mdetail;
			            			
										// movie details selection
			            				switch(mdetail)
										{
											case  1:	cout << endl << movA << endl;										// movieA name and date
														cout << lang1 << setw(space = 32) << subt << endl << endl;			// language and subtitle
														cout << dur << endl;												// movie duration
														cout << date << endl << stime << setw(space = 20) << etime << endl;	// start and end time
														cout << "Seats left: " << ticket1 << endl;							// seats left
														break;
											case  2:    cout << endl << movB << endl;										// movieB name
														cout << lang1 << setw(space = 32) << subt << endl << endl;			// language and subtitle
														cout << dur << endl;												// movie duration
														cout << date << endl << stime << setw(space = 20) << etime << endl;	// date, start and end time
														cout << "Seats left: " << ticket2 << endl;							// seats left
														break;
											case  3:	cout << endl << movC << endl;										// movieC name
														cout << lang2 << setw(space = 32) << subt << endl << endl;			// language and subtitle
														cout << dur << endl;												// movie duration
														cout << date << endl << stime << setw(space = 20) << etime << endl;	// date, start and end time
														cout << "Seats left: " << ticket3 << endl;							// seats left
														break;
											default:	cout << "\nInvalid input. Please try again." << endl;										
														break;
										}				
									}
									while(mdetail < 1 || mdetail > 3);
									
										// user can decide to watch movie trailer
										do{
											cout << "\nDo you want to play the movie trailer? Enter 'Y' for yes or 'N' for no." << endl;
											cin >> trailer;
											cin.ignore(numeric_limits<streamsize>::max(), '\n');
															
											if(trailer == 'Y' && mdetail == 1)
												system(turl1.c_str());
											else if(trailer == 'Y' && mdetail == 2)
												system(turl2.c_str());
											else if(trailer == 'Y' && mdetail == 3)
												system(turl3.c_str());
											else if(trailer == 'N')
												;
											else
												cout << "\nInvalid input. Please try again." << endl;
										}
										while(trailer != 'Y' && trailer != 'N');
										// end of movie details section
										
										// user choose either back to movie list or main menu
										// infinite loop if proceed != L or M
										do{
											cout << "\nBack to movie list. Enter 'L'" << endl;
											cout << "Back to main menu. Enter 'M'" << endl;
											cin >> proceed;
											cin.ignore(numeric_limits<streamsize>::max(), '\n');
											
											if(proceed != 'L' && proceed != 'M')
												cout << "\nInvalid input. Please try again." << endl;
										
											// throw in false int to force mdetail to loop againn
											else if(proceed == 'L')
												mdetail = 0;
											// throw in a false char to force menu to loop again
											else
												menu = 'X';
										}
										while(proceed != 'L' && proceed != 'M');
								}
								while(mdetail < 1 || mdetail > 3);
								break;
								
					// display ticket price         
					case 'T':	
								break;    
					
					// proceed to payment
					case 'P':
								break;  
				}       									
		}  
		while(menu != 'L' && menu != 'T' && menu != 'P');
		
		// payment section
		
		return 0; 
}
