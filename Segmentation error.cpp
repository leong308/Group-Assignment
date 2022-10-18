// MAIN MENU

// CASE L 80% DONE (NEED MORE MODIFICAIIONS ON UI/UX)
// CASE T 99% DONE (CURRENTLY PERFECT)
// CASE A 99% DONE (CURRENTLY PERFECT) *CAN HAVE ADD ONS
// CASE P 70% DONE (POOR UI/UX, CAN STILL FIND FOR POSSIBLE BRANCHES TO SPLIT FUNCTIONS)
// TABLE OUTPUTS NEED TO BE MODIFIED
// USING FOR LOOP WITH ARRAYS

// !!!!!!!!!!!!!!!!!!!!!!!
// SEGMENTATION FAULT OCCURS AT T SECTION
// WHILE TURN OFF CALCULATOR
// SYSTEM WILL NOT EXECUTE THE FOR LOOP TABLE
// DIRECTLY TERMINATE PROGRAM
// *****************
// NEED TRACE BACK TO PREVIOUS CODE

#include <iostream> 
#include <iomanip>	// manipulate output
#include <ios>		// for stream size
#include <limits>	// for numeric limits
#include <string>
#include <numeric>	// for accumulate function
using namespace std;

int main() 
	{
		// declare variables
		char menu, proceed, trailer, tcat, edit, edit2, block;					// main menu, proceed to next part, movie trailer, ticket category, edit ticket, block output
		string date;															// date
		int i, mdetail, ticketl;												// counter, movie detial, ticket left,
		int selectm, tdeduct, tempt, tamountt;									// select movie to purchase, deduct ticket, temporary int usage, temporary total amount selected
		int tamount, moret, tbought;											// ticket amount, another x ticket to discount
		double dp;																// discount, discounted price
		double price, tprice, gtprice;											// temporary price, total price, grand total
		
		// arrays
		int seat[3] = {100, 9, 0};																		// seats left
		int count[4] = {1, 2, 3, 4};																	// counter
		int calctickets[4] = {0};																		// calculator tickets amount
		double cprice[4] = {10, 12, 15, 6};																// categorised price
		double discount[2] = {0.90, 0.80};																// ticket discounts
		double calcttotal[4] = {0};																		// calculator tickets total
		int cattickets[4] = {0};																		// tickets based on category
		
		string movie[3] = {"Movie A", "Movie B", "Movie C"};											// movie titles
		string turl[3] = {"start https://github.com/leong308/",
						  "start https://github.com/leong308/", 
						  "start https://github.com/leong308/"};										// movie trailer urls
		string lang[3] = {"Language: EN", "Language: CN", "Subtitle: EN & CN & BM"};					// movie languages and subtitle
		string time[3] = {"Duration: 2 hours 30 minutes", "Start time: 19:00", "End time: 21:30"};		// duration, start and end time
		string redirect[8] = {"\nBack to main menu. Enter 'M'", 										// main redirect output 
							  "Back to movie list. Enter 'L'", 
							  "Open calculator. Enter 'C'", 
							  "Do you still want to purchase more tickets for this movie? Enter 'T'", 
							  "Addeed too much ticket to your purchase list? Edit. Enter 'E'", 
							  "Proceed to payment. Enter 'P'", 
							  "\nContinue to make changes. Enter 'C'", 
							  "Nothing else to make changes. Enter 'Y'"};								// redirect user to other sections to proceed
		string category[4] = {"INTI Student", "INTI Staff", "Adult", "Child (Below 18)"};				// Category
		string displaycat[4] = {"| A | ", "| B | ", "| C | ", "| D | "};								// category display purpose
		string displayno[4] = {"| 1. | ", "| 2. | ", "| 3. | ", "| 4. | "};								// no display purpose
	
		// declare values into var
		block = 'N';
		date = "Date: 12/12/2022";
		
		// calculator
		char scalc, stopcalc;												// select category, stop calculation
		int calct, calct2, x;												// tickets amount, validate input
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
										// movie list display
										for(i = 0;i < 3; i++){
											cout << count[i] << ". " << movie[i] << endl;
										}
									
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
											case  1:	cout << endl << movie[0] << endl;									// movieA name and date
														cout << lang[0] << setw(32) << lang[2] << endl << endl;				// language and subtitle
														cout << time[0] << endl;											// movie duration
														cout << date << endl << time[1] << setw(20) << time[2] << endl;		// start and end time
														cout << "Seats left: " << seat[0] << endl;							// seats left
														break;
											case  2:    cout << endl << movie[1] << endl;									// movieB name
														cout << lang[0] << setw(32) << lang[2] << endl << endl;				// language and subtitle
														cout << time[0] << endl;											// movie duration
														cout << date << endl << time[1] << setw(20) << time[2] << endl;		// date, start and end time
														cout << "Seats left: " << seat[1] << endl;							// seats left
														break;
											case  3:	cout << endl << movie[2] << endl;									// movieC name
														cout << lang[1] << setw(32) << lang[2] << endl << endl;				// language and subtitle
														cout << time[0] << endl;											// movie duration
														cout << date << endl << time[1] << setw(20) << time[2] << endl;		// date, start and end time
														cout << "Seats left: " << seat[2] << endl;							// seats left
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
												system(turl[0].c_str());
											else if(trailer == 'Y' && mdetail == 2)
												system(turl[1].c_str());
											else if(trailer == 'Y' && mdetail == 3)
												system(turl[2].c_str());
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
											for(i = 0;i < 7; i++){
												if(i < 2)
													cout << redirect[i] << endl;
											}
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
								// display table header
								cout << "\n--------Ticket Price List--------" << endl;
								cout << "_________________________________" << endl;
								cout << "|   | " << setw(16) << left << "Category"         << setw(2) << " |" << setw(10) << right << "Price  |"	 << endl;
								cout << "_________________________________" << endl;
								
								// display table data
								for(i = 0; i < 4; i++)
									cout << displaycat[i] << setw(16) << left << category[i] << setw(2) << " |" << setw(7) << right << cprice[i] << "  |" << endl;
								
								// display notes
								cout << "\n*NOTES*" << endl;
								cout << "1. You may purchase more than 1 ticket at once." << endl;
								cout << "2. You may purchase from different categories at once." << endl;
								cout << "3. A 20% discount will be given for INTI Student category with more than 5 tickets in one purchase." << endl;
								cout << "4. A 10% discount will be given for INTI Staff category with more than 5 tickets in one purchase." << endl;
									
									// ask user open calc or back to menu
									cout << redirect[0] << endl;
									cout << redirect[2] << endl;
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
												// display table header
												cout << "\n--------Ticket Price List--------" << endl;
												cout << "_________________________________" << endl;
												cout << "|   | " << setw(16) << left << "Category"         << setw(2) << " |" << setw(10) << right << "Price  |"	 << endl;
												cout << "_________________________________" << endl;
												
												// display table data
												for(i = 0; i < 4; i++){
													cout << displaycat[i] << setw(16) << left << category[i] << setw(2) << " |" << setw(7) << right << cprice[i] << "  |" << endl;
												}
												
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
									           		case 'A':	x = calctickets[0] + calct;
									           					break;
									           		case 'B':	x = calctickets[1] + calct;
									           					break;
									           		case 'C':	x = calctickets[2] + calct;
									           					break;
									           		case 'D':	x = calctickets[3] + calct;
									           					break;
													}
												// add into total
												// validate maximum
													calct2 = calct + calctickets[0] + calctickets[1] + calctickets[2] + calctickets[3];
													
												// cannot deduct until less than 0
									        	if(x < 0)
									           		cout << "Invalid input. Please try again." << endl;
									           	// prevent user from entering too much tickets
									           	else if(calct2 > 200)
									           		cout << "You had selected too much tickets. Please try again." << endl;
									           	else{
									           		switch(scalc){
									           			case 'A':	calctickets[0] = calctickets[0] + calct;
									           						break;
									           			case 'B':	calctickets[1] = calctickets[1] + calct;
									           						break;
									           			case 'C':	calctickets[2] = calctickets[2] + calct;
									           						break;
									           			case 'D':	calctickets[3] = calctickets[3] + calct;
									           						break;
													   }
													
									           		// calculator working based on catgories
													calcttotal[0] = calctickets[0] * cprice[0];
													if(calctickets[0] > 5)
														calcttotal[0] = calcttotal[0] * discount[0];
													calcttotal[1] = calctickets[1] * cprice[1];
													if(calctickets[1] > 5)
														calcttotal[1] = calcttotal[1] * discount[1];
													calcttotal[2] = calctickets[2] * cprice[2];
													calcttotal[3] = calctickets[3] * cprice[3];
													
													// add into total
													tcalc = calcttotal[0] + calcttotal[1] + calcttotal[2] + calcttotal[3];
													
													// display table header
													cout << "\n-------------Ticket Price List Simulator------------" << endl;
													cout << "____________________________________________________" << endl;
													cout << "|   | " << setw(16) << left << "Category"         << setw(2) << " | " << setw(5) << right << "Price" 
														 << setw(2) << " | " << setw(6) << right << "Amount" << setw(2) << " |" << setw(11) << "Total  |"	 << endl;
													cout << "____________________________________________________" << endl;
													
													// display table(calculated) data
													for(i = 0; i < 4 ; i++){
														cout << displaycat[i] << setw(16) << left << category[i] << setw(2) << " | " << setw(5) << right << cprice[i]  
														 << setw(2) << " | "  << setw(6) << right << calctickets[i] << setw(2) << " |" << setw(8) << calcttotal[i] << "  |" << endl;
													}
													
													// display table footer
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
													calctickets[4] = {0};
													calcttotal[4] = {0};
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
								// display table header
								cout << "\n---Availvable seats left---" << endl;
								cout << "___________________________" << endl;
								cout << "| No.| Movie Title" << setw(2) << "|" << setw(8) << "Seats |" << endl;
								cout << "___________________________" << endl;
								
								// display table data
								for(i = 0; i < 3; i++)
									cout << displayno[i] << setw(11) << left << movie[i] << setw(2) << " |" << setw(5) << right << seat[i] << "  |" << endl;
								
								// additional description
								if(seat[0] == 0 && seat[1] == 0)
									cout << "\nOnly " << movie[2] << " is still available at this moment." << endl;
								else if(seat[0] == 0 && seat[2] == 0)
									cout << "\nOnly " << movie[1] << " is still available at this moment." << endl;
								else if(seat[1] == 0 && seat[2] == 0)
									cout << "\nOnly " << movie[0] << " is still available at this moment." << endl;
								else if(seat[0] == 0)
									cout << "\nOnly " << movie[1] << " and " << movie[2] << " are still available at this moment." << endl;
								else if(seat[1] == 0)
									cout << "\nOnly " << movie[0] << " and " << movie[2] << " are still available at this moment." << endl;
								else if(seat[2] == 0)
									cout << "\nOnly " << movie[0] << " and " << movie[1] << " are still available at this moment." << endl;
								// can ignore all == 0 because whole while loop will execute if no ticket left
								else
									cout << "\nAll 3 movies are still available at this moment." << endl;
									
								// user need to return back to main menu
								// infinite loop if proceed != M
								do{
									cout << redirect[0] << endl;
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
					
					// CASE P (70%)
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
							        	// display table header
									    cout << "\n-----Movie List----" << endl;
										cout << "___________________" << endl;
										cout << "| No.| Movie Title |" << endl;
										cout << "___________________" << endl;
										
										// display table data
										for(i = 0; i < 3; i++)
											cout << displayno[i] << setw(11) << left << movie[i] << " |" << endl;
							        	
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
								            case 1:     cout << "\nSeats left: " << seat[0] << endl;
								            			ticketl = seat[0];
								                        break;
								            case 2:     cout << "\nSeats left: " << seat[1] << endl;
								            			ticketl = seat[1];
								                        break;
								            case 3:     cout << "\nSeats left: " << seat[2] << endl;
								            			ticketl = seat[2];
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
										tamountt = tamount + cattickets[0] + cattickets[1] + cattickets[2] + cattickets[3];
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
							    		case 'A':	cattickets[0] = cattickets[0] + tamount;
							    					break;
							    		case 'B':	cattickets[1] = cattickets[1] + tamount;
							    					break;
							    		case 'C':	cattickets[2] = cattickets[2] + tamount;
							    					break;
							    		case 'D':	cattickets[3] = cattickets[3] + tamount;
							    					break;
									}
									
									// display added tickets
									for(i = 0; i < 4; i++){
										if(i == 0)
											cout << "\nYou had added " << cattickets[0] << " tickets from " << category[0] << " into your purchase list." << endl;
										else
											cout << "You had added " << cattickets[i] << " tickets from " << category[i] << " into your purchase list." << endl;
									}
									
									if(cattickets[0] < 6 && cattickets[0] != 0){
										moret =  6 - cattickets[0];
										cout << "\nYou will get a 20% discount if you purchase another " << moret << " tickets from INTI Student category." << endl;
									}
									else if(cattickets[0] > 5)
										cout << "\nYou are eligible for the 20% discount because the amount of tickets for INTI Student category is "
										<< cattickets[0] << " tickets." << endl;
										
									if(cattickets[1] < 6 && cattickets[1] != 0){
										moret =  6 - cattickets[1];
										cout << "\nYou will get a 10% discount if you purchase another " << moret << " tickets from INTI Staff category." << endl;
									}
									else if(cattickets[1] > 5)
										cout << "\nYou are eligible for the 10% discount because the amount of tickets for INTI Staff category is "
										<< cattickets[1] << " tickets." << endl;	
									
									do{
										// will not appear this section if all available tickets added for the movie
										// will block this output wheen block == 'Y' and tamount == ticketl
										// during second loop ++
										cout << endl;
										
										if(block == 'N' || tamountt != ticketl)
											cout << redirect[3] << endl;
											
											cout << redirect[4] << endl;
											cout << redirect[5] << endl;
										
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
											if(cattickets[0] > 0)
												cout << setw(22) << left << "| A | INTI Student"     << setw(2) << " |" << setw(7) << right << cattickets[0] << " |" << endl;
											if(cattickets[1] > 0)
												cout << setw(22) << left << "| B | INTI Staff"       << setw(2) << " |" << setw(7) << right << cattickets[1] << " |" << endl;
											if(cattickets[2] > 0)
												cout << setw(22) << left << "| C | Adult"            << setw(2) << " |" << setw(7) << right << cattickets[2] << " |" << endl;
											if(cattickets[3] > 0)
												cout << setw(22) << left << "| D | Child (Below 18)" << setw(2) << " |" << setw(7) << right << cattickets[3] << " |" << endl;
												
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
												if(edit == 'A' && cattickets[0] == 0){
													cout << "You have no ticket to deduct for category A. Please choose other category and try again." << endl;
													edit = 'X';
												}	
												else if(edit == 'B' && cattickets[1] == 0){
													cout << "You have no ticket to deduct for category B. Please choose other category and try again." << endl;
													edit = 'X';
												}
												else if(edit == 'C' && cattickets[2] == 0){
													cout << "You have no ticket to deduct for category C. Please choose other category and try again." << endl;
													edit = 'X';
												}
												else if(edit == 'D' && cattickets[3] == 0){
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
														// will not declare cattickets[4] back at here
														// to prevent false value overwrite cattickets[4]
														switch(edit){
															case 'A':	tempt = cattickets[0];
																		tempt = tempt - tdeduct;
																		break;
															case 'B':	tempt = cattickets[1];
																		tempt = tempt - tdeduct;
																		break;
															case 'C':	tempt = cattickets[2];
																		tempt = tempt - tdeduct;
																		break;
															case 'D':	tempt = cattickets[3];
																		tempt = tempt - tdeduct;
																		break;
														}
														
														// validation output
														if(tdeduct == 0)
															cout << "You must deduct at least 1 ticket." << endl;
														if(tdeduct < 0 || tempt < 0)
															cout << "Invalid input. Please try again." << endl;
														// declare temp back to cattickets[4] after validation
														// to ensure that cattickets[4] will not take back negative value
														else
														{
															switch(edit){
																case 'A':	cattickets[0] = tempt;
																			break;	
																case 'B':	cattickets[1] = tempt;
																			break;			
																case 'C':	cattickets[2] = tempt;
																			break;
																case 'D':	cattickets[3] = tempt;
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
									tbought = accumulate(cattickets, cattickets+4, tbought);
									
									// update seats available
									if	   (selectm == 1)
										seat[0] = seat[0] - tbought;
									else if(selectm == 2)
										seat[1] = seat[1] - tbought;
									else if(selectm == 3)
										seat[2] = seat[2] - tbought;
									
									// calc total for A category tickets	
									price = cattickets[0] * cprice[0];
									tprice = tprice + price;
										
										if(cattickets[0] > 5){
											dp = tprice * discount[0];
											gtprice = gtprice + dp;
										}
										else
											gtprice = gtprice + tprice;
											
									// remove tprice data to prevent overwrite
									tprice = 0;
										
									// calc total for B category tickets	
									price = cattickets[1] * cprice[1];
									tprice = tprice + price;
									
										if(cattickets[1] > 5){
											dp = tprice * discount[1];
											gtprice = gtprice + dp;
										}
										else
											gtprice = gtprice + tprice;
											
									// remove tprice data to prevent overwrite
									tprice = 0;
									
									// calc total for C category tickets	
									price = cattickets[2] * cprice[2];
									tprice = tprice + price;
									gtprice = gtprice + tprice;
									// remove tprice data to prevent overwrite
									tprice = 0;
									
									// calc total for D category tickets	
									price = cattickets[3] * cprice[3];
									tprice = tprice + price;
									gtprice = gtprice + tprice;
									// remove tprice data to prevent overwrite
									tprice = 0;
									// erase tamountt data
									tamountt = 0;
									
									cout << gtprice << endl;								// print grand total
									cout << seat[0] << " " << seat[1] << " " << seat[2];	// print seats left, for admin reference
									
									// throw in false char into menu to force whole program to loop again
									menu = 'X';
									
									// erase proceed data to prevent infinity loop
									// temporary force menu loop
									// need rediret to other page (TBE)
									proceed = 'X';
								}
							    // payment section
							    }
							    while(selectm < 1 || selectm > 3);
								break;  
				}       									
		}  
		while(menu != 'L' && menu != 'T' && menu != 'A' && menu != 'P');
		
		return 0; 
}
