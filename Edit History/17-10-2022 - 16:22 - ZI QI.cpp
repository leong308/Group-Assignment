// MAIN MENU

// CASE L 80% DONE (NEED MORE MODIFICAIION ON UI/UX)
// CASE T 99% DONE (CURRENTLY PERFECT)
// CASE A 99% DONE (CURRENTLY PERFECT) *CAN HAVE ADD ONS
// CASE P 80% DONE (POOR UI/UX, CAN STILL FIND FOR POSSIBLE BRANCHES TO SPLIT FUNCTIONS)

#include <iostream> 
#include <iomanip>	// manipulate output
#include <ios>		// for stream size
#include <limits>	// for numeric limits
#include <string>
using namespace std;

int main() 
	{
		// declare variables
		char menu, proceed, trailer, tcat, edit, edit2, block;					// main menu, proceed to next part, movie trailer, ticket category, edit ticket, block output
		string movA, movB, movC;												// 3 movies title
		string date, dur, stime, etime;											// date, duration, start time, end time
		string turl1, turl2, turl3;												// movie trailers url
		string lang1, lang2, subt;												// languages and subtitles
		int mdetail, ticket1, ticket2, ticket3, ticketl;						// movie detial, 3 types of seats left, ticket left,
		int selectm, tdeduct, tempt, tamountt;									// select movie to purchase, deduct ticket, temporary int usage, temporary total amount selected
		int tamount, tamountA, tamountB, tamountC, tamountD, moret, tbought;	// ticket amount, another x ticket to discount
		double studp, staffp, adultp, childp, d10, d20, dp;						// categorize prices and discount, discounted price
		double price, tprice, gtprice;											// temporary price, total price, grand total
		
		// declare values into var
		block = 'N';
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
		ticket1 = 100, ticket2 = 9, ticket3 = 0;
		tamount = 0, tamountA = 0, tamountB = 0, tamountC = 0, tamountD = 0;
		turl1 = "start https://github.com/leong308/";
		turl2 = "start https://github.com/leong308/";
		turl3 = "start https://github.com/leong308/";
		studp = 10, staffp = 12, adultp = 15, childp = 6;					// ticket prices
		d10 = 0.90, d20 = 0.80;												// ticket discounts
		
		// calculator
		char scalc, stopcalc;												// select category, stop calculation
		int acalc = 0, bcalc = 0, ccalc = 0, dcalc = 0, calct, calct2, x;	// abcd tickets, tickets amount, validate input
		double atcalc = 0, btcalc = 0, ctcalc = 0, dtcalc = 0;				// abcd total price
		double tcalc;														// total after add up
		
		// modify double output
		cout << setprecision(2) << fixed;
		
		// need modify more
		cout << "Welcome!" << endl;
		cout << "_____________________________" << endl;
		
		// infinite loop while != L or T or A or P
		do{
			// 4 selections in main menu
			// CAN CONSIDER ADD ADMIN SECTION SELECTION
			/*
				Admin section
				- PASSWORD TO ENTER (MANDATORY)
				- VIEW EARNING STATUS
				- PRINT STATEMENT
				- ADD/MINUS AVAILABLE TICKETS
				- TERMINATE/END SYSTEM
				
				// features can still be added or modify
				// **not necessary needed
			*/
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
					// CASE L (80%)
					// PARTIALLY DONE (CORE FUNCTION + VALIDITY) (80%)
					// NEEED MODIFY OUTPUT UI/UX (10%)
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
		            					
		            					// prevent infinite loop if char entered 
							        	if(cin.fail()){
							        		mdetail = -1;				// declare false value to force whole do while to loop again
							        		cin.clear();				// clear input buffer
							        		cin.ignore(INT_MAX, '\n'); 	// ignore last input
										}
			            			
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
											else if(proceed == 'M')
												menu = 'X';
										}
										while(proceed != 'L' && proceed != 'M');
										
										// reset proceed data to null
										proceed = 'X';
								}
								while(mdetail < 1 || mdetail > 3);
								break;
					
					// CASE T (99%)
					// COMPLETELY DONE (CORE DISPLAY + CALCULATOR + VALIDITY)
					// OUTPUT UI/UX (99%)
					
					// display ticket price         
					case 'T':	
								do{
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
								
								
									cout << "\nOpen calculator. Enter 'C'" << endl;
									cout << "Back to main menu. Enter 'M'" << endl;
									cin >> proceed;
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									
									if(proceed != 'M' && proceed != 'C')
										cout << "Invalid input. Please try again." << endl;
									
									else if(proceed == 'C'){
										// additional do while loop required
										// recall back here if not leaving calculator
										do{
											// infinite loop while false tcat input
											do{
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
												cout << "1. You may use this calculator to calculate a certain amount of ticket price." << endl;
												cout << "2. To reduce amount of tickets, kindly use negative value (-) to deduct." << endl;
												cout << "3. The maximum of tickets can be calculate is hard capped at 200 only." << endl;
												
												// choose catgory to proceed
												cout << "\nWhich category would you like to choose?" << endl;
								    			cin >> scalc;
								    			cin.ignore(numeric_limits<streamsize>::max(), '\n');
								    		
								    			if(scalc != 'A' && scalc != 'B' && scalc != 'C' && scalc != 'D')
								    				cout << "Invalid input. Please try again." << endl;
									    	}
									    	while(scalc != 'A' && scalc != 'B' && scalc != 'C' && scalc != 'D');
									    	
									    	// ask user to enter amount of tickets wanted for the specific category
									    	do{
												cout << "\nHow many tickets do you want to purchase for this category?" << endl;
									        	cin >> calct;	        		
									        		
									        	// prevent infinite loop if char entered 
									        	if(cin.fail()){
									        		calct = -1000;				// declare false value to force whole do while to loop again
									        		cin.clear();				// clear input buffer
									        		cin.ignore(INT_MAX, '\n'); 	// ignore last input
												}
												
												// enable user to input negative value after first loop
												// validate negative values / minimum
												switch(scalc){
									           		case 'A':	x = acalc + calct;
									           					break;
									           		case 'B':	x = bcalc + calct;
									           					break;
									           		case 'C':	x = ccalc + calct;
									           					break;
									           		case 'D':	x = dcalc + calct;
									           					break;
													}
												// add into total
												// validate maximum
													calct2 = calct + acalc + bcalc + ccalc + dcalc;
													
												// cannot deduct until less than 0
									        	if(x < 0)
									           		cout << "Invalid input. Please try again." << endl;
									           	// prevent user from entering too much tickets
									           	else if(calct2 > 200)
									           		cout << "You had selected too much tickets. Please try again." << endl;
									           	else{
									           		switch(scalc){
									           			case 'A':	acalc = acalc + calct;
									           						break;
									           			case 'B':	bcalc = bcalc + calct;
									           						break;
									           			case 'C':	ccalc = ccalc + calct;
									           						break;
									           			case 'D':	dcalc = dcalc + calct;
									           						break;
													   }
													
									           		// calculator working based on catgories
													atcalc = acalc * studp;
													if(acalc > 5)
														atcalc = atcalc * d20;
													btcalc = bcalc * staffp;
													if(bcalc > 5)
														btcalc = btcalc * d10;
													ctcalc = ccalc * adultp;
													dtcalc = dcalc * childp;
													
													// add into total
													tcalc = atcalc + btcalc + ctcalc + dtcalc;
													
													// display table
													cout << "\n-------------Ticket Price List Simulator------------" << endl;
													cout << "____________________________________________________" << endl;
													// first line of table
													cout << "|   | " << setw(16) << left << "Category"         << setw(2) << " | " << setw(5) << right << "Price" 
														 << setw(2) << " | " << setw(6) << right << "Amount" << setw(2) << " |" << setw(11) << "Total  |"	 << endl;
													cout << "____________________________________________________" << endl;
													// categoory A
													cout << "| A | " << setw(16) << left << "INTI Student"     << setw(2) << " | " << setw(5) << right << studp  
														 << setw(2) << " | "  << setw(6) << right << acalc << setw(2) << " |" << setw(8) << atcalc  << "  |" << endl;
													// category B
													cout << "| B | " << setw(16) << left << "INTI Staff"       << setw(2) << " | " << setw(5) << right << staffp 
														 << setw(2) << " | "  << setw(6) << right << bcalc << setw(2) << " |" << setw(8) << btcalc << "  |" << endl;
													// category C
													cout << "| C | " << setw(16) << left << "Adult"            << setw(2) << " | " << setw(5) << right << adultp 
														 << setw(2) << " | "  << setw(6) << right << ccalc << setw(2) << " |" << setw(8) << ctcalc << "  |" << endl;
													// category D
													cout << "| D | " << setw(16) << left << "Child (Below 18)" << setw(2) << " | " << setw(5) << right << childp 
														 << setw(2) << " | "  << setw(6) << right << dcalc << setw(2) << " |" << setw(8) << dtcalc << "  |" << endl;
													cout << "____________________________________________________" << endl;
													// grand total
													cout << setw(30) << left << "| Grand Total" << setw(2) << " | " << setw(6) << right << calct2 
														 << setw(2) << " |" << setw(8) << tcalc << "  |" << endl;
												   }
									   		}
									    	while(x < 0 || calct2 > 200);
									    	
									    	while(stopcalc != 'Y' && stopcalc != 'N'){
									    		cout << "\nDo you still want to edit tickets and calculate price? " << endl;
									    		cout << "Calculation data will be erased if you leave this session." << endl;
									    		cout << "\nEnter 'Y' to contiue calculate or 'N' to exit calculator." << endl;
									    		cin >> stopcalc;
									    		cin.ignore(numeric_limits<streamsize>::max(), '\n');
									    		
									    		if(stopcalc != 'Y' && stopcalc != 'N')
									    			cout << "Invalid input. Please try again." << endl;
									    		if(stopcalc == 'Y')
									    			scalc = 'X';
									    		// throw in false char to force scalc do while to loop again
									    		else{
									    			proceed = 'X';
									    			
									    			// erase all calculation data to default if exits calculator session
													acalc = 0, bcalc = 0, ccalc = 0, dcalc = 0, calct = 0, calct2 = 0;
													atcalc = 0, btcalc = 0, ctcalc = 0, dtcalc = 0;
													tcalc = 0;
												}
											}
											// reset stopcalc to false car after leaving while loop
											// prevent it to directly skip during upcoming loops
											stopcalc = 'X';
										}
										while(scalc != 'A' && scalc != 'B' && scalc != 'C' && scalc != 'D');
									}
									// throw in a false char to force menu to loop again
									else
										menu = 'X';
								}
								while(proceed != 'M' && proceed != 'C');
										
								// reset proceed data to null
								proceed = 'X';
								
								break;   
					
					// CASE A (99%)
					// COMPLETELY DONE (CORE DISPLAY + VALIDITY)
					// OUTPUT UI/UX (95%)
					
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
					
					// CASE P (80%)
					// NEED IMPROVEMENT IN UI/UX (20%)
					// NEED TO FIND FOR ANOTHER FEW POSSIBLE VALIDATIONS
					// ALMOST DONE FOR ADDING TICKET TO PAY (***NEED ADD EDIT AND CHANGE BETWEEN MOVIE)
					// CAN HELP TO IDENTIFY ERRORS
					
					// proceed to payment
					case 'P':	
								// choose a movie to purchase
							    do{
							    	// infinite loop while selectm < 1 or > 3
									/* additional do while branch is needed to prevent
									   false overall output while triggers default case */ 
							        do{
									    cout << "\n-----Movie List----" << endl;
										cout << "___________________" << endl;
										cout << "| No. | Movie Title |" << endl;
										cout << "___________________" << endl;
										cout << "|  1. | " << setw(11) << left << movA << " |" << endl;
										cout << "|  2. | " << setw(11) << left << movB << " |" << endl;
										cout << "|  3. | " << setw(11) << left << movC << " |" << endl;
							        	
								        cout << "Please choose a movie to proceed." << endl;
								        cin >> selectm;
								        
								        // prevent infinite loop if char entered 
								        if(cin.fail()){
								        	selectm = -1;				// declare false value to force whole do while to loop again
								        	cin.clear();				// clear input buffer
								        	cin.ignore(INT_MAX, '\n'); 	// ignore last input
										}
										
										// display seats left for each movie
										// throw value into ticketl for further validation purpose
										// prevent user purchase exceed available seats for the specific movie
								        switch(selectm)
										{
								            case 1:     cout << "\nSeats left: " << ticket1 << endl;
								            			ticketl = ticket1;
								                        break;
								            case 2:     cout << "\nSeats left: " << ticket2 << endl;
								            			ticketl = ticket2;
								                        break;
								            case 3:     cout << "\nSeats left: " << ticket3 << endl;
								            			ticketl = ticket3;
								                        break;
								            default:    cout << "Invalid input. Please try again." << endl;
								                        break;
								        }
								        
								        // need add selectm validation in here to
								        // prevent default output and this output execute at the same time
								        // while invalid input was inserted
								        if((selectm == 1 || selectm == 2 || selectm == 3) && (ticketl == 0)){
								        	cout << "Unfortunately there is no seat left for this movie." << endl;
											cout << "Please choose other movie to proceed." << endl;
								        	selectm = 0;
										}	
										// output while seats left for the movie is below 10
										else if((selectm == 1 || selectm == 2 || selectm == 3) && (ticketl < 10))
											cout << "Hurry up! The available seats are running out soon!" << endl;
							    	}
									while(selectm < 1 || selectm > 3);
								
								// need restructure based on category
							    // insert ticket amount
							    do{
							    	do{
										cout << "\nWhich category would you like to purchase?" << endl;
							    		cin >> tcat;
							    		cin.ignore(numeric_limits<streamsize>::max(), '\n');
							    		
							    		if(tcat != 'A' && tcat != 'B' && tcat != 'C' && tcat != 'D')
							    			cout << "Invalid input. Please try again." << endl;
							    	}
							    	while(tcat != 'A' && tcat != 'B' && tcat != 'C' && tcat != 'D');
							    	
							    	// ask user to enter amount of tickets wanted for the specific category
							    	do{
											cout << "\nHow many tickets do you want to purchase for this category?" << endl;
							        		cin >> tamount;	        		
							        		
							        		// prevent infinite loop if char entered 
							        		if(cin.fail()){
							        			tamount = -1;				// declare false value to force whole do while to loop again
							        			cin.clear();				// clear input buffer
							        			cin.ignore(INT_MAX, '\n'); 	// ignore last input
											}
										
										// temporary total amount to go through validation
										// prevent exceed total available seats
										tamountt = tamount + tamountA + tamountB + tamountC + tamountD;
										cout << "\nYou had selected " << tamountt << " tickets in total." << endl;
							        		
							        	if(tamount < 0)
							           		cout << "Invalid input. Please try again." << endl;
							           	else if(tamount > ticketl || tamountt > ticketl){
							           		cout << "Total amount had exceeded the available ticket amount for this movie. Please try again." << endl;
										   }
							   		}
							    	while(tamount < 0 || tamount > ticketl || tamountt > ticketl);
							    	
							    	switch(tcat)
									{
							    		case 'A':	tamountA = tamountA + tamount;
							    					break;
							    		case 'B':	tamountB = tamountB + tamount;
							    					break;
							    		case 'C':	tamountC = tamountC + tamount;
							    					break;
							    		case 'D':	tamountD = tamountD + tamount;
							    					break;
									}
									
									// display added tickets
									cout << "\nYou had added " << tamountA << " tickets from INTI Student Category into your purchase list." << endl;
									cout << "You had added " << tamountB << " tickets from INTI Staff Category into your purchase list." << endl;
									cout << "You had added " << tamountC << " tickets from Adult Category into your purchase list." << endl;
									cout << "You had added " << tamountD << " tickets from Child (Below 18) Category innto your purchase list." << endl;
									
									if(tamountA < 6 && tamountA != 0){
										moret =  6 - tamountA;
										cout << "\nYou will get a 20% discount if you purchase another " << moret << " tickets from INTI Student category." << endl;
									}
									else if(tamountA > 5)
										cout << "\nYou are eligible for the 20% discount because the amount of tickets for INTI Student category is "
										<< tamountA << " tickets." << endl;
										
									if(tamountB < 6 && tamountB != 0){
										moret =  6 - tamount;
										cout << "\nYou will get a 10% discount if you purchase another " << moret << " tickets from INTI Staff category." << endl;
									}
									else if(tamountB > 5)
										cout << "\nYou are eligible for the 10% discount because the amount of tickets for INTI Staff category is "
										<< tamountB << " tickets." << endl;	
									
									do{
										// will not appear this section if all available tickets added for the movie
										// will block this output wheen block == 'Y' and tamount == ticketl
										// during second loop ++
										if(block == 'N' || tamountt != ticketl){
											cout << "\nDo you still want to purchase more tickets for this movie? Enter 'T'" << endl;
											block = 'N';
										}
										cout << "Addeed too much ticket to your purchase list? Edit. Enter 'E'" << endl;
										cout << "Proceed to payment. Enter 'P'" << endl;
										cin >> proceed;
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
												
										if(proceed != 'T' && proceed != 'P' && proceed != 'E')
											cout << "Invalid input. Please try again." << endl;
										// if no available tickets left
										else if(proceed == 'T' && tamountt == ticketl){
											cout << "\nThere is no available ticket left for this movie. Please proceed to other sections.\n" << endl;
											proceed = 'X';
											block = 'Y';
										}
										// throw in a false char to force tcat to loop again
										else if(proceed == 'T')
											tcat = 'X';
										// throw in a false char to force menu to loop again
										else if(proceed == 'P')
											;
										else if(proceed == 'E')
											// throw in E to triggers edit while loop
											edit2 = 'E';
										
										while(edit2 == 'E'){
											cout << "\n--------Your Purchase List--------" << endl;
											cout << "_________________________________" << endl;
											cout << setw(22) << left << "|   | Category"		     << setw(2) << " |" << setw(10) << right << "Amount  |"	 << endl;
											cout << "_________________________________" << endl;
											
											// only output selected amount
											// 
											if(tamountA > 0)
												cout << setw(22) << left << "| A | INTI Student"     << setw(2) << " |" << setw(7) << right << tamountA << " |" << endl;
											if(tamountB > 0)
												cout << setw(22) << left << "| B | INTI Staff"       << setw(2) << " |" << setw(7) << right << tamountB << " |" << endl;
											if(tamountC > 0)
												cout << setw(22) << left << "| C | Adult"            << setw(2) << " |" << setw(7) << right << tamountC << " |" << endl;
											if(tamountD > 0)
												cout << setw(22) << left << "| D | Child (Below 18)" << setw(2) << " |" << setw(7) << right << tamountD << " |" << endl;
												
											// display notes
											cout << "\n*NOTES*" << endl;
											cout << "1. You may only deduct additional ticket/s added in this section." << endl;
											cout << "2. The list above shows your current purchase list status." << endl;
											
											// will execute if the while loop once
											// will not execute at the first round
											if(!(edit != 'A' && edit != 'B' && edit != 'C' && edit != 'D'))
												do{
													cout << "\nContinue to make changes. Enter 'C'" << endl;
													cout << "Nothing else to make changes. Enter 'Y'" << endl;
													cin >> proceed;
													cin.ignore(numeric_limits<streamsize>::max(), '\n');
													
													if(proceed != 'C' && proceed != 'Y')
														cout << "Invalid input. Please try again." << endl;
													// throw in a false char to trigger while edit loop
													else if(proceed == 'C')
														edit = 'X';
													// throw in a false char into edit2 to end while edit2 loop
													else{
														edit2 = 'X';
														// as user had removed at least a ticket here
														// will stop blocking proceed T selection output
														block = 'N';
													}
												}
												while(proceed != 'C' && proceed != 'Y');
											
											// edit section
											while(edit != 'A' && edit != 'B' && edit != 'C' && edit != 'D'){
												cout << "\nPlease enter the category that you wish to edit." << endl;
												cin >> edit;
												cin.ignore(numeric_limits<streamsize>::max(), '\n');
												
												// 4 additional if else if functions added here
												// or else it will cause a death loop if the tamount is 0
												// throw in false char to force while edit loop to run again
												if(edit == 'A' && tamountA == 0){
													cout << "You have no ticket to deduct for category A. Please choose other category and try again." << endl;
													edit = 'X';
												}	
												else if(edit == 'B' && tamountB == 0){
													cout << "You have no ticket to deduct for category B. Please choose other category and try again." << endl;
													edit = 'X';
												}
												else if(edit == 'C' && tamountB == 0){
													cout << "You have no ticket to deduct for category C. Please choose other category and try again." << endl;
													edit = 'X';
												}
												else if(edit == 'D' && tamountB == 0){
													cout << "You have no ticket to deduct for category D. Please choose other category and try again." << endl;
													edit = 'X';
												}
												else if(edit != 'A' && edit != 'B' && edit != 'C' && edit != 'D') 
													cout << "Invalid input. Please try again." << endl;
												else{
													// fetch amount of tickets need to be deducted
													// calculate deducted tickets
													// this validation section is needed because
													// user can't deduct until ticket is less than 0
													do{
														cout << "\nPlease enter the amount of addtional tickets." << endl;
														cin >> tdeduct;
														
														// prevent infinite loop if char entered 
								        				if(cin.fail()){
								        					tdeduct = -1;				// declare false value to force whole do while to loop again
								        					cin.clear();				// clear input buffer
								        					cin.ignore(INT_MAX, '\n'); 	// ignore last input
														}
														
														// deduction area
														// will not declare tamount() back at here
														// to prevent false value overwrite tamount()
														switch(edit){
															case 'A':	tempt = tamountA;
																		tempt = tempt - tdeduct;
																		break;
															case 'B':	tempt = tamountB;
																		tempt = tempt - tdeduct;
																		break;
															case 'C':	tempt = tamountC;
																		tempt = tempt - tdeduct;
																		break;
															case 'D':	tempt = tamountD;
																		tempt = tempt - tdeduct;
																		break;
														}
														
														// validation output
														if(tdeduct == 0)
															cout << "You must deduct at least 1 ticket." << endl;
														if(tdeduct < 0 || tempt < 0)
															cout << "Invalid input. Please try again." << endl;
														// declare temp back to tamount() after validation
														// to ensure that tamount() will not take back negative value
														else
														{
															switch(edit){
																case 'A':	tamountA = tempt;
																			break;	
																case 'B':	tamountB = tempt;
																			break;			
																case 'C':	tamountC = tempt;
																			break;
																case 'D':	tamountD = tempt;
																			break;
															}
															// update tamountt to prevent tamountt still == false when 
															// proceed 'T' was ran after proceed 'Y' was selected
															tamountt = tempt;
														}
													}
													while(tdeduct <= 0 || tempt < 0);
												}
											}
										}
									}
									while(proceed != 'T' && proceed != 'P' && proceed != 'E');
										
									// reset proceed data to null
									if(proceed != 'P')
										proceed = 'X';
									
								// need to record down all selected tickets if want to chg novie type
								}
								while(tcat != 'A' && tcat != 'B' && tcat != 'C' && tcat != 'D');
								
								while(proceed == 'P'){
									// to update seats left for the movie
									tbought = tamountA + tamountB + tamountC + tamountD;
									
									// update seats available
									if	   (selectm == 1)
										ticket1 = ticket1 - tbought;
									else if(selectm == 2)
										ticket2 = ticket2 - tbought;
									else if(selectm == 3)
										ticket3 = ticket3 - tbought;
									
									// calc total for A category tickets	
									price = tamountA * studp;
									tprice = tprice + price;
										
										if(tamountA > 5){
											dp = tprice * d20;
											gtprice = gtprice + dp;
										}
										else
											gtprice = gtprice + tprice;
											
									// remove tprice data to prevent overwrite
									tprice = 0;
										
									// calc total for B category tickets	
									price = tamountB * staffp;
									tprice = tprice + price;
									
										if(tamountB > 5){
											dp = tprice * d10;
											gtprice = gtprice + dp;
										}
										else
											gtprice = gtprice + tprice;
											
									// remove tprice data to prevent overwrite
									tprice = 0;
									
									// calc total for C category tickets	
									price = tamountC * adultp;
									tprice = tprice + price;
									gtprice = gtprice + tprice;
									// remove tprice data to prevent overwrite
									tprice = 0;
									
									// calc total for D category tickets	
									price = tamountD * childp;
									tprice = tprice + price;
									gtprice = gtprice + tprice;
									// remove tprice data to prevent overwrite
									tprice = 0;
									
									cout << gtprice;
									
									// erase proceed data to prevent infinity loop
									// temporary force menu loop
									// need rediret to other page (TBE)
									proceed = 'X';
								}
							    // output
							    }
							    while(selectm < 1 || selectm > 3);
								break;  
				}       									
		}  
		while(menu != 'L' && menu != 'T' && menu != 'A' && menu != 'P');
		
		// payment section
		
		return 0; 
}
