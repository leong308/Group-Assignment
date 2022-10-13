// ZI QI editing

#include <iostream> 
#include <iomanip> 
#include <string>
using namespace std;

int main() 
{ 
		// declare variables
		char mlist, proceed, trailer;
		string movA, movB, movC, date, dur, stime, etime, turl1, turl2, turl3, lang1, lang2, subt;
		unsigned int space;
		int mdetail, ticket1, ticket2, ticket3;
	
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
	
		cout << "Welcome!" << endl;
		
		// display section
		
		// infinite loop while != Y or N
		do{
			cout << "\nDo you want to see the movie list? Y or N" << endl;
			cin >> mlist;

			if(mlist != 'Y' && mlist != 'N')
				cout << "Invalid input. Please try again.\n" << endl;
            
				// Y or N condition
				switch(mlist)
				{
					// display movie list
					case 'Y':   cout << "\n1. " << movA << endl;
								cout << "2. " << movB << endl;
								cout << "3. " << movC << endl;
		            				
									// infinite loop while mdetail < 1 or > 3
									do{
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
										
											// open trailer url
											do{
												cout << "\nDo you want to play the trailer? Enter 'Y' for yes or 'N' for no." << endl;
												cin >> trailer;
															
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
											
											// infinite loop if proceed != P or B
											do{
												cout << "\nEnter P if you want to proceed to payment." << endl;
												cout << "Enter B if you want to go back to menu." << endl;
												cin >> proceed;
												
												if(proceed != 'P' && proceed != 'B')
													cout << "\nInvalid input. Please try again." << endl;
											
												// throw in a false char to force the mlist to loop again
												else if(proceed == 'B')
												mlist = 'X';
											}
											while(proceed != 'P' && proceed != 'B');
									}
									while(mdetail < 1 || mdetail > 3);				
								break;
								
					// ask whether user want to proceed or back to selection           
					case 'N':	do{
									cout << "\nEnter P if you want to proceed to payment." << endl;
									cout << "Enter B if you want to go back to menu." << endl;
									cin >> proceed;
									
									if(proceed != 'P' && proceed != 'B')
										cout << "\nInvalid input. Please try again." << endl;
		            					
									// throw in a false char to force the mlist to loop again
									else if(proceed == 'B')
										mlist = 'X';
								}
								while(proceed != 'P' && proceed != 'B');
								break;      
				}       									
		}  
		while(mlist != 'Y' && mlist != 'N');
		
		// payment section
		
		return 0; 
}
