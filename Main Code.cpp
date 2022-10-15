#include <iostream> 
#include <iomanip>	// manipulate output
#include <ios>		// for stream size
#include <limits>	// for numeric limits
#include <string>
using namespace std;

int main() 
	{
		// declare variables
		
		char menu, proceed, trailer, tcat;					// main menu, proceed to next part, movie trailer, ticket category
		string movA, movB, movC;							// 3 movies title
		string date, dur, stime, etime;						// date, duration, start time, end time
		string turl1, turl2, turl3;							// movie trailers url
		string lang1, lang2, subt;							// languages and subtitles
		int mdetail, ticket1, ticket2, ticket3, selectm;	// movie detial, 3 types of seats left, select movie to purchase
		int tamount;										// ticket amount
		double studp, staffp, adultp, childp, d10, d20;		// categorize prices and discount
		
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
		studp = 10, staffp = 12, adultp = 15, childp = 6;	// ticket prices
		d10 = 0.90, d20 = 0.80;									// ticket discounts
		
		// modify double output
		cout << setprecision(2) << fixed;
		
		// need modify more
		cout << "Welcome!" << endl;
		cout << "_____________________________" << endl;
		
		
		// infinite loop while != L or T or A or P
		do{
			// 3 selections in main menu
			cout << "\nView movie list. Enter 'L'" << endl;
			cout << "View ticket price. Enter 'T'" << endl;
			cout << "View movie that still have available seats. Enter 'A'" << endl;
			cout << "Buy ticket now! Enter 'P'" << endl;
			cout << "\nYour selection: ";
			cin >> menu;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
			if(menu != 'L' && menu != 'T' && menu != 'A' && menu != 'P')
				cout << "Invalid input. Please try again.\n" << endl;
            
				// L or T or A or P condition
				switch(menu)
				{	
					// CASE L IS PARTIALLY DONE (CORE FUNCTION + VALIDITY)
					// STILL CAN BE MODIFIED
					
					// display movie list
					case 'L':   
								// infinite loop while mdetail < 1 or > 3
								do{
									// infinite loop while mdetail < 1 or > 3
									/* additional do while branch is needed to prevent
									   false overall output while triggers default case */ 
									do{	
										cout << "\n1. " << movA << endl;
										cout << "2. " << movB << endl;
										cout << "3. " << movC << endl;
									
		            					cout << "\nEnter the number of a movie for more details." << endl;
		            					cin >> mdetail;
			            			
										// movie details selection
			            				switch(mdetail)
										{
											case  1:	cout << endl << movA << endl;								// movieA name and date
														cout << lang1 << setw(32) << subt << endl << endl;			// language and subtitle
														cout << dur << endl;										// movie duration
														cout << date << endl << stime << setw(20) << etime << endl;	// start and end time
														cout << "Seats left: " << ticket1 << endl;					// seats left
														break;
											case  2:    cout << endl << movB << endl;								// movieB name
														cout << lang1 << setw(32) << subt << endl << endl;			// language and subtitle
														cout << dur << endl;										// movie duration
														cout << date << endl << stime << setw(20) << etime << endl;	// date, start and end time
														cout << "Seats left: " << ticket2 << endl;					// seats left
														break;
											case  3:	cout << endl << movC << endl;								// movieC name
														cout << lang2 << setw(32) << subt << endl << endl;			// language and subtitle
														cout << dur << endl;										// movie duration
														cout << date << endl << stime << setw(20) << etime << endl;	// date, start and end time
														cout << "Seats left: " << ticket3 << endl;					// seats left
														break;
											default:	cout << "Invalid input. Please try again." << endl;										
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
												cout << "Invalid input. Please try again." << endl;
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
												cout << "Invalid input. Please try again." << endl;
										
											// throw in false int to force mdetail to loop againn
											else if(proceed == 'L')
												mdetail = 0;
											// throw in a false char to force menu to loop again
											else
												menu = 'X';
										}
										while(proceed != 'L' && proceed != 'M');
										
										// reset proceed data to null
										proceed = 'X';
								}
								while(mdetail < 1 || mdetail > 3);
								break;
					
					// CASE T IS COMPLETELY DONE (CORE DISPLAY + VALIDITY)
					// STILL CAN MODIFY OUTPUT UI
					
					// display ticket price         
					case 'T':	
								// display table
								cout << "\n--------Ticket Price List--------" << endl;
								cout << "_________________________________" << endl;
								cout << "|   | " << setw(16) << left << "Category"         << setw(2) << " |" << setw(10) << right << "Price  |"	 << endl;
								cout << "_________________________________" << endl;
								cout << "| A | " << setw(16) << left << "INTI Student"     << setw(2) << " |" << setw(7) << right << studp  << "  |" << endl;
								cout << "| B | " << setw(16) << left << "INTI Staff"       << setw(2) << " |" << setw(7) << right << staffp << "  |" << endl;
								cout << "| C | " << setw(16) << left << "Adult"            << setw(2) << " |" << setw(7) << right << adultp << "  |" << endl;
								cout << "| D | " << setw(16) << left << "Child (Below 18)" << setw(2) << " |" << setw(7) << right << childp << "  |" << endl;
								
								// display notes
								cout << "\n*NOTES*" << endl;
								cout << "1. You may purchase more than 1 ticket at once." << endl;
								cout << "2. You may purchase from different categories at once." << endl;
								cout << "3. A 20% discount will be given for INTI Student category with more than 5 tickets in one purchase." << endl;
								cout << "4. A 10% discount will be given for INTI Staff category with more than 5 tickets in one purchase." << endl;
								
								do{
									cout << "\nBack to main menu. Enter 'M'" << endl;
									cin >> proceed;
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
											
									if(proceed != 'M')
										cout << "Invalid input. Please try again." << endl;
									// throw in a false char to force menu to loop again
									else
										menu = 'X';
								}
								while(proceed != 'M');
										
								// reset proceed data to null
								proceed = 'X';
								
								break;   
					
					// CASE A IS COMPLETELY DONE (CORE DISPLAY + FUNCTION + VALIDITY)
					// STILL CAN MODIFY OUTPUT UI
					
					// display available seats left
					case 'A':	
								// display table
								cout << "\n---Availvable seats left---" << endl;
								cout << "___________________________" << endl;
								cout << "| No.| Movie Title" << setw(2) << "|" << setw(8) << "Seats |" << endl;
								cout << "___________________________" << endl;
								cout << "| 1. | " << setw(11) << left << movA << setw(2) << " |" << setw(5) << right << ticket1 << "  |" << endl;
								cout << "| 2. | " << setw(11) << left << movB << setw(2) << " |" << setw(5) << right << ticket2 << "  |" << endl;
								cout << "| 3. | " << setw(11) << left << movC << setw(2) << " |" << setw(5) << right << ticket3 << "  |" << endl;
								
								// additional description
								if(ticket1 == 0 && ticket2 == 0)
									cout << "\nOnly " << movC << " is still available at this moment." << endl;
								else if(ticket1 == 0 && ticket3 == 0)
									cout << "\nOnly " << movB << " is still available at this moment." << endl;
								else if(ticket2 == 0 && ticket3 == 0)
									cout << "\nOnly " << movA << " is still available at this moment." << endl;
								else if(ticket1 == 0)
									cout << "\nOnly " << movB << " and " << movC << " are still available at this moment." << endl;
								else if(ticket2 == 0)
									cout << "\nOnly " << movA << " and " << movC << " are still available at this moment." << endl;
								else if(ticket3 == 0)
									cout << "\nOnly " << movA << " and " << movB << " are still available at this moment." << endl;
								// can ignore all == 0 because whole while loop will execute if no ticket left
								else
									cout << "\nAll 3 movies are still available at this moment." << endl;
									
								// user need to return back to main menu
								// infinite loop if proceed != M
								do{
									cout << "\nBack to main menu. Enter 'M'" << endl;
									cin >> proceed;
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
											
									if(proceed != 'M')
										cout << "Invalid input. Please try again." << endl;
									// throw in a false char to force menu to loop again
									else
										menu = 'X';
								}
								while(proceed != 'M');
										
								// reset proceed data to null
								proceed = 'X';
								
								break;
					
					// CASE P
					// MORE VALIDATIONS NEEDED
					// DONT EXECUTE THIS PART --> WORKING HALFWAY (INCOMPLETE FUNCTIONS OR OUTPUT MIGHT OCCURS)
					// proceed to payment
					case 'P':	
								// choose a movie to purchase
							    do{
							        cout << "movie list\n" << endl;
							        cout << "Which movie ticket?" << endl;
							        
							        cout << "\n1. " << movA << endl;
									cout << "2. " << movB << endl;
									cout << "3. " << movC << endl;
									
		            				cout << "\nSelect a movie ticket that you want to purchase." << endl;
							        cin >> selectm;
									
									// display seats left for each movie
							        switch(selectm)
									{
							            case 1:     cout << "Seats left: " << ticket1 << endl;
							                        break;
							            case 2:     cout << "Seats left: " << ticket2 << endl;
							                        break;
							            case 3:     cout << "Seats left: " << ticket3 << endl;
							                        break;
							            default:    cout << "Invalid input. Please try again." << endl;
							                        break;
							        }
							    }
							    while(selectm != 1 && selectm != 2 && selectm != 3);
								
								// need restructure based on category
							    // insert ticket amount
							    do{
							    	cout << "Which category would you like to purchase?" << endl;
							    	cin >> tcat;
							    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
							    	
							    	do{
							        	cout << "How many tickets do you want to purchase for this category?" << endl;
							        	cin >> tamount;
							
							        	if(tamount < 0 || tamount > 100)
							           	 cout << "Invalid input. Please try again." << endl;
							   		}
							    	while(tamount < 0 || tamount > 100);
							    	
								// need a highly composite switch case
								// to calculate combination of movie type, category and amount
								// movie type is not important --> fetch type just to deduct seats left after purchasing
								}
								while(tcat != 'A' && tcat != 'B' && tcat != 'C' && tcat != 'D');
							    // recall back to ask for more purchase
							    // add if statement another x to have discount
							
							    // calc total
							    // deduct seats booked
							
							    // output
								break;  
				}       									
		}  
		while(menu != 'L' && menu != 'T' && menu != 'A' && menu != 'P');
		
		// payment section
		
		return 0; 
}
