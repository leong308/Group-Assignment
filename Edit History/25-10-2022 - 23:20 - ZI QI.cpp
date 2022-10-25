// ZI QI editing

// CASE L (Movie List)  100% DONE (CORE FUNCTION + DISPLAY + VALIDITY)
//						99% DONE (OUTPUT UI/UX)
// CASE T (Ticket price) 99% DONE (CURRENTLY PERFECT)
// CASE S (Seats left)   99% DONE (CURRENTLY PERFECT) *CAN HAVE ADD ONS
// CASE P (Purchase)     99% DONE (POOR UI/UX, CAN STILL FIND FOR POSSIBLE BRANCHES TO SPLIT FUNCTIONS)
// CASE A (Admin)		  0% (OPTIONAL)

// PROCEED MESSAGES
// MODIFY OUTPUT LIKE MAIN MENU

// VALIDATIONS MODIFY UNTIL L ONLY
// CONTINUE

#include <iostream> 
#include <iomanip>	// manipulate output
#include <limits>	// for numeric limits
#include <fstream>	// for file access
#include <ctime>
using namespace std;

// fetch time for receipt
// current date/time based on current system
time_t now = time(0);
// convert now to string form
char* dt = ctime(&now);

int main() 
	{
		// counters
		int i, j, k, l, m;
		
		// validation error msg
		string error[2] = {"Invalid input. Please try again."};	// error message
		
		// menu part
		char menu;												// take menu input
		string tdisplay = "--------------------------------";	// table designation
		bool menuv;												// validate menu input
		
		// CASE L part
		char mdetail;											// movie detail input
		char trailer;											// movie trailer
		char proceed;											// proceed to next part
		string ldisplay[3] = {"----------------------------",
							  "\n========================================\n\n",
							  "\n========================================\n"	};	// table designation
		string movie[3] = {"mov1", "mov2", "mov3"};									// movies
		string lang[3] = {"EN", "BM", "CN"};										// languages
		string subt = "EN & BM & CN";												// subtitles
		string date = "12/12/2022";													// date
		string dur = "2 hours 30 minutes";											// duration
		string stime = "19:00";														// start time
		string etime = "21:30";														// end time
		bool mdetailv;																// validate movie detail input
		bool proceedv;																// proceed validation
		
		
		// declare variables
		char tcat, edit, edit2, mov, cfm, psuc = 'N';	// main menu, proceed to next part, movie trailer, ticket category, edit ticket, block output
		
		string turl1, turl2, turl3;												// movie trailers url
		int ticketl;															// 3 types of seats left, ticket left,
		int selectm, tdeduct, tempt, tamountt;									// select movie to purchase, deduct ticket, temporary int usage, temporary total amount selected
		int tamount, tamountA, tamountB, tamountC, tamountD, moret, tbought;	// ticket amount, another x ticket to discount
		int col, row, rowcol;													// column, row, rowcolumn validation
		double price, tprice, gtprice;											// temporary price, total price, grand total
		
		// declare values into var
		
		
		tamount = 0, tamountA = 0, tamountB = 0, tamountC = 0, tamountD = 0;
		turl1 = "start https://github.com/leong308/";
		turl2 = "start https://github.com/leong308/";
		turl3 = "start https://github.com/leong308/";
		bool finish = false, alert = false, block = false, confirm = false, deduct = true, con;
		
		// calculator
		int ccalc;											// user input category to perform calculation
		char stopcalc;												// select category, stop calculation
		int calct, calct2, x;	// tickets amount, validate input
		double tcalc;														// total after add up
		
		int cat = 0;
		
		// arrays
		int ticket[3] = {100, 0, 100};														// available seats
		int ticket2[3] = {0};																// available seats (for temporary use)
		// 4 rows 3 columns
		int ticketamt[4][3] = {0};															// ticket amount
		int ticketamt2;																		// temp ticket amount
		int tickett = 0;																	// tickets total
		int categoryt[4] = {0};																// category total
		int moviet[3] = {0};																// movie total
		int pmethod;																		// choose payment method
		string category[4] = {"INTI Student", "INTI Staff", "Adult", "Child (Below 18)"};	// category
		string movtable[3] = {"| A | ", "| B | ", "| C | "};
		
		string tablec[5] = {"|  1. | ", "|  2. | ", "|  3. | ", "|  4. | ", "|  5. | "};	// table count
		string paym[5] = {"Cash", "Credit/Debit Card", "Touch N Go E-Wallet", "Paypal", "Bitcoin"};	// payment method
		
		
		int calccatamt[4] = {0};
		double calccattot[4] = {0};
		
		// for receipt
		string receipt = "receipt";
		int printr = 0;																	// total customers
		string receipttxt;
		
		// for print ticket
		string printtick = "ticket";
		string printtick2 = "TICKET";
		int printt = 0;
		string tickettxt;
		
		int customer = 1;
		
		double categoryp[5] = {10, 12, 15, 6, 0};	// category price
		double categoryp2[4] = {10, 12, 15, 6};		// category price changes for receipt usage
		double total[4] = {0};						// total based on category
		double discount[2] = {0.80, 0.90};			// discounts
		double discounted;							// discounted price, used in receipt
		double gtotal = 0;							// grand total
		
		// modify double output
		cout << setprecision(2) << fixed;
		
		// need modify more
		cout << "**********************************************************************" << endl;
		cout << "Welcome to the INTI College Penang Movie Day ticket purchasing system!" << endl;
		cout << "**********************************************************************" << endl;
		
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
			cout << "\n======== THE MAIN MENU =========\n" << endl << tdisplay << endl;
			cout << "| " << setw(20) << left << "Go To..." << " | Enter |" << endl  << tdisplay << endl << tdisplay << endl;
			cout << "| " << setw(20) << left << "View Movie List" << " |  'L'  |" << endl  << tdisplay << endl;
			cout << "| " << setw(20) << left << "View Ticket Price" << " |  'T'  |" << endl  << tdisplay << endl;
			cout << "| " << setw(20) << left << "View Available Seats" << " |  'S'  |" << endl  << tdisplay << endl;
			cout << "| " << setw(20) << left << "Buy ticket now!" << " |  'P'  |" << endl  << tdisplay << endl;
			
			cout << "\nPlease enter your selection: ";
			cin >> menu;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// only take first char
            
				// L or T or S or P condition
				switch(menu)
				{	
					// CASE L (100%)
					// COMPLETELY DONE (CORE FUNCTION + DISPLAY + VALIDITY)
					// OUTPUT UI/UX (99%) left proceed part
					
					// display movie list
					case 'l':
					case 'L':   // infinite loop while mdetail < 1 or > 3
								do{
									// additional do while branch is needed
									// prevent false overall output while triggers default case
									do{	
										// movie selection table
										cout << "\n======== MOVIE LIST ========\n" << endl << ldisplay[0] << endl;
										cout << "|   | " << setw(20) << left << "Movie Title" << " |" << endl << ldisplay[0] << endl;
										for(i = 0; i < 3; i++)
											cout << movtable[i] << setw(20) << left << movie[i] << " |" << endl;
										cout << ldisplay[0] << endl;
									
		            					cout << "\nChoose a movie for more details." << endl;
		            					cin >> mdetail;
		            					cin.ignore(numeric_limits<streamsize>::max(), '\n');
		            					
		            					mdetailv = true;
										// movie details
			            				switch(mdetail)
										{
											case 'a':
											case 'A':	cout << ldisplay[1] << setw(15) << left << " Movie" << " : " + movie[0] << endl;
														cout << setw(15) << left << " Language" << " : " + lang[0] << endl;
														cout << setw(15) << left << " Subtitle" << " : " + subt << endl;
														cout << setw(15) << left << " Date" << " : " + date << endl;
														cout << setw(15) << left << " Duration" << " : " + dur << endl;
														cout << setw(15) << left << " Start Time" << " : " + stime << endl;
														cout << setw(15) << left << " End Time" << " : " + etime << endl;
														cout << setw(15) << left << " Seats left" << " : " << ticket[0] << endl << ldisplay[2];
														break;
											case 'b':
											case 'B':   cout << ldisplay[1] << setw(15) << left << " Movie" << " : " + movie[1] << endl;
														cout << setw(15) << left << " Language" << " : " + lang[1] << endl;
														cout << setw(15) << left << " Subtitle" << " : " + subt << endl;
														cout << setw(15) << left << " Date" << " : " + date << endl;
														cout << setw(15) << left << " Duration" << " : " + dur << endl;
														cout << setw(15) << left << " Start Time" << " : " + stime << endl;
														cout << setw(15) << left << " End Time" << " : " + etime << endl;
														cout << setw(15) << left << " Seats left" << " : " << ticket[1] << endl << ldisplay[2];
														break;
											case 'c':
											case 'C':	cout << ldisplay[1] << setw(15) << left << " Movie" << " : " + movie[2] << endl;
														cout << setw(15) << left << " Language" << " : " + lang[2] << endl;
														cout << setw(15) << left << " Subtitle" << " : " + subt << endl;
														cout << setw(15) << left << " Date" << " : " + date << endl;
														cout << setw(15) << left << " Duration" << " : " + dur << endl;
														cout << setw(15) << left << " Start Time" << " : " + stime << endl;
														cout << setw(15) << left << " End Time" << " : " + etime << endl;
														cout << setw(15) << left << " Seats left" << " : " << ticket[2] << endl << ldisplay[2];
														break;
											default:	cout << error[0] << endl;
														mdetailv = false;
										}				
									}
									while(mdetailv == false);
									
									// user can watch movie trailer
									do{
										cout << "\nDo you want to play the movie trailer? Enter 'Y' for yes or 'N' for no." << endl;
										cin >> trailer;
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
															
										if((trailer == 'Y' || trailer == 'y') && mdetail == 'A')
											system(turl1.c_str());
										else if((trailer == 'Y' || trailer == 'y') && mdetail == 'B')
											system(turl2.c_str());
										else if((trailer == 'Y' || trailer == 'y') && mdetail == 'C')
											system(turl3.c_str());
										else if(trailer == 'N')												
											;
										else
											cout << error[0] << endl;
										
										if(trailer == 'Y' || trailer == 'y'){
											cout << "\nMovie trailer had been launched in your browser tab." << endl;
											cout << "Please head over to your browser to watch the movie trailer." << endl;
										}
									}
									while(trailer != 'Y' && trailer != 'y' && trailer != 'N' && trailer != 'n');
										
									// user choose either back to movie list or main menu
									do{
										cout << "\nBack to movie list. Enter 'L'" << endl;
										cout << "Back to main menu. Enter 'M'" << endl;
										cin >> proceed;
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
											
										switch(proceed){
											case 'l':
											case 'L':
											case 'm':
											case 'M':	proceedv = true;
														break;
											default:	cout << error[0] << endl;
														proceedv = false;
										}	
										// force mdetail to loop againn
										if(proceed == 'l' || proceed == 'L')
											mdetailv = false;
									}
									while(proceedv == false);
								}
								while(mdetailv == false);
								
								proceed = 'X';						
								break;
					
					// CASE T (99%)
					// COMPLETELY DONE (CORE FUNCTION + DISPLAY + CALCULATOR + VALIDITY)
					// OUTPUT UI/UX (50%)
					
					// display ticket price 
					case 't':        
					case 'T':	do{
									// display table
									cout << "\n======== TICKET PRICE LIST =========\n" << endl;
									cout << "------------------------------------" << endl;
									cout << "| No. | " << setw(16) << left << "Category"         << setw(2) << " |" << setw(10) << right << "Price  |"	 << endl;
									cout << "------------------------------------" << endl;
									for(i = 0; i < 4; i++)
										cout << tablec[i] << setw(16) << left << category[i] << setw(2) << " |" << setw(7) << right << categoryp[i] << "  |" << endl;
									cout << "------------------------------------" << endl;
									
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
									// enter calculator
									else if(proceed == 'C'){
										// additional do while loop required
										// recall back here if not leaving calculator
										do{
											// infinite loop while false tcat input
											do{
												// display notes
												cout << "\n*ABOUT THE CALCULATOR*" << endl;
												cout << "1. You may use this calculator to calculate a certain amount of ticket price." << endl;
												cout << "2. To reduce amount of tickets, kindly use negative value (-) to deduct." << endl;
												cout << "3. The maximum of tickets can be calculated is hard capped at 150 only." << endl;
												cout << "4. You may select tickets from different category to add into the total." << endl;
												cout << "5. To reset the calculator data, exit and reenter the calculator." << endl;
												
												cout << "\nWhich category would you like to choose?" << endl;
								    			cin >> ccalc;
								    			
									        	if(cin.fail()){
									        		ccalc = 0;					// declare false value to force whole do while to loop again
									        		cin.clear();				// clear input buffer
									        		cin.ignore(INT_MAX, '\n'); 	// ignore last input
												}
								    			if(ccalc < 1 || ccalc > 4)
								    				cout << "Invalid input. Please try again." << endl;
									    	}
									    	while(ccalc < 1 || ccalc > 4);
									    	
									    	// ask user to enter amount of tickets wanted for the specific category
									    	do{
												cout << "\nHow many tickets do you want to purchase for this category?" << endl;
									        	cin >> calct;	        		
									        		
									        	// prevent infinite loop if char entered 
									        	if(cin.fail()){
									        		calct = -999;				// declare false value to force whole do while to loop again
									        		cin.clear();				// clear input buffer
									        		cin.ignore(INT_MAX, '\n'); 	// ignore last input
												}
												
												// enable user to input negative value after first loop
												// validate negative values / minimum
												switch(ccalc){
									           		case  1:	x = calccatamt[0] + calct;
									           					break;
									           		case  2:	x = calccatamt[1] + calct;
									           					break;
									           		case  3:	x = calccatamt[2] + calct;
									           					break;
									           		case  4:	x = calccatamt[3] + calct;
									           					break;
													}
												// add into total
												// validate maximum
													calct2 = calct + calccatamt[0] + calccatamt[1] + calccatamt[2] + calccatamt[3];
													
												// cannot deduct until less than 0
									        	if(x < 0)
									           		cout << "Invalid input. Please try again." << endl;
									           	// prevent user from entering too much tickets
									           	else if(calct2 > 150)
									           		cout << "You had selected too much tickets. Please try again." << endl;
									           	else{
									           		switch(ccalc){
									           			case  1:	calccatamt[0] = calccatamt[0] + calct;
									           						break;
									           			case  2:	calccatamt[1] = calccatamt[1] + calct;
									           						break;
									           			case  3:	calccatamt[2] = calccatamt[2] + calct;
									           						break;
									           			case  4:	calccatamt[3] = calccatamt[3] + calct;
									           						break;
													}
													
									           		// calculator working based on catgories
													calccattot[0] = calccatamt[0] * categoryp[0];		// INTI Student
													if(calccatamt[0] > 5)
														calccattot[0] = calccattot[0] * discount[0];
														
													calccattot[1] = calccatamt[1] * categoryp[1];		// INTI Staff
													if(calccatamt[1] > 5)
														calccattot[1] = calccattot[1] * discount[1];
														
													calccattot[2] = calccatamt[2] * categoryp[2];		// Adult
													
													calccattot[3] = calccatamt[3] * categoryp[3];		// Child
													
													// add into total
													tcalc = calccattot[0] + calccattot[1] + calccattot[2] + calccattot[3];
													
													// display table
													cout << "\n============== PURCHASE LIST SIMULATOR ===============" << endl << endl;
													cout << "------------------------------------------------------" << endl;
													// first line of table
													cout << "|     | " << setw(16) << left << "Category"         << setw(2) << " | " << setw(5) << right << "Price" 
														 << setw(2) << " | " << setw(6) << right << "Amount" << setw(2) << " |" << setw(11) << "Total  |"	 << endl;
													cout << "------------------------------------------------------" << endl;
													
													for(i = 0; i < 4; i++)
														cout << tablec[i] << setw(16) << left << category[i] << setw(2) << " | " << setw(5) << right << categoryp[i]
															 << setw(2) << " | "  << setw(6) << right << calccatamt[i] << setw(2) << " |" << setw(8) << calccattot[i] << "  |" << endl;
													cout << "------------------------------------------------------" << endl;
													// grand total
													cout << setw(32) << left << "| Grand Total" << setw(2) << " | " << setw(6) << right << calct2 
														 << setw(2) << " |" << setw(8) << tcalc << "  |" << endl;
													cout << "------------------------------------------------------" << endl;
													
													cout << "\n*NOTES*" << endl;
													cout << "1. A 20% discount will be given for INTI Student category with more than 5 tickets in one purchase." << endl;
													cout << "2. A 10% discount will be given for INTI Staff category with more than 5 tickets in one purchase." << endl;
												   }
									   		}
									    	while(x < 0 || calct2 > 150);
									    	
									    	// user can stop calculation here
									    	while(stopcalc != 'Y' && stopcalc != 'N'){
									    		cout << "\nDo you still want to edit tickets and calculate price? " << endl;
									    		cout << "Calculation data will be erased if you leave this session." << endl;
									    		cout << "\nEnter 'Y' to contiue calculate or 'N' to exit calculator." << endl;
									    		cin >> stopcalc;
									    		cin.ignore(numeric_limits<streamsize>::max(), '\n');
									    		
									    		if(stopcalc != 'Y' && stopcalc != 'N')
									    			cout << "Invalid input. Please try again." << endl;
									    		// let ccalc to loop again
									    		if(stopcalc == 'Y')
									    			ccalc = 0;
									    		else{
									    			proceed = 'X';
									    			
									    			// erase all calculation data to default if exits calculator session
													calct = 0, calct2 = 0;
													calccatamt[4] = {0};
													calccattot[4] = {0};
													tcalc = 0;
												}
											}
											// reset stopcalc to false char after leaving do-while loop
											// prevent it to directly skip this section during upcoming loops
											stopcalc = 'X';
										}
										while(ccalc < 1 || ccalc > 4);
									}
								}
								while(proceed != 'M' && proceed != 'C');
										
								// reset proceed data to X
								proceed = 'X';
								
								break;   
					
					// CASE S (99%)
					// COMPLETELY DONE (CORE DISPLAY + VALIDITY)
					// OUTPUT UI/UX (99%)
					
					// display available seats left
					case 's':
					case 'S':	// display table
								// movie table
								cout << "\n============ CHECK AVAILABILITY ==============\n" << endl;
								cout << "----------------------------------------------" << endl;
								cout << "|   | " << setw(20) << left << "Movie Title" << " | Available Seats |" << endl;
								cout << "----------------------------------------------" << endl;
								for(i = 0; i < 3; i++)
									cout << movtable[i] << setw(20) << left << movie[i] << " | " << setw(15) << right << ticket[i] << " |" << endl;
								cout << "---------------------------------------------" << endl;
								
								// additional description
								if(ticket[0] == 0 && ticket[1] == 0)
									cout << "\nOnly " << movie[2] << " is still available at this moment." << endl;
								else if(ticket[0] == 0 && ticket[2] == 0)
									cout << "\nOnly " << movie[1] << " is still available at this moment." << endl;
								else if(ticket[1] == 0 && ticket[2] == 0)
									cout << "\nOnly " << movie[0] << " is still available at this moment." << endl;
								else if(ticket[0] == 0)
									cout << "\nOnly " << movie[1] << " and " << movie[2] << " are still available at this moment." << endl;
								else if(ticket[1] == 0)
									cout << "\nOnly " << movie[0] << " and " << movie[2] << " are still available at this moment." << endl;
								else if(ticket[2] == 0)
									cout << "\nOnly " << movie[0] << " and " << movie[1] << " are still available at this moment." << endl;
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
								}
								while(proceed != 'M');
										
								// reset proceed data to null
								proceed = 'X';
								menu = 'X';
								
								break;
					
					// CASE P (99%)
					// COMPLETELY DONE (CORE FUNCTION + DISPLAY + DEDUCT TICKETS + PAYMENT + RECEIPT + TICKETS)
					// **NEED TEST ON VALIDATIONS
					
					// purchase section
					case 'p':
					case 'P':	for(i = 0; i < 3; i++)
									ticket2[i] = ticket[i];
									
								// loop if proceed = 'T'
								do{	
									// choose movie
									do{
										// movie table
										cout << "\n----------------------------" << endl;
										cout << "|   | " << setw(20) << left << "Movie Title" << " |" << endl;
										cout << "----------------------------" << endl;
										for(i = 0; i < 3; i++)
											cout << movtable[i] << setw(20) << left << movie[i] << " |" << endl;
										cout << "----------------------------" << endl;
											
										cout << "\nPlease select a movie to add tickets into your purchase list: ";
										cin >> mov;
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										
										if(mov != 'A' && mov != 'B' && mov != 'C')
											cout << "Invalid Input. Please try again.\n" << endl;
										
										if	   (mov == 'A' && ticket2[0] <= 0)
											finish = true;
										else if(mov == 'A' && ticket2[0] < 10)
											alert  = true;
										else if(mov == 'B' && ticket2[1] <= 0)
											finish = true;
										else if(mov == 'B' && ticket2[1] < 10)
											alert  = true;
										else if(mov == 'C' && ticket2[2] <= 0)
											finish = true;
										else if(mov == 'C' && ticket2[2] < 10)
											alert  = true;
										
										while(finish == true){
											cout << "Unfortunately there is no seat left for this movie." << endl;
											cout << "Please choose other movie to proceed.\n" << endl;
											finish = false;
											mov = 'X';
										}
										
										while(alert == true){
											cout << "Hurry up! The available seats are running out soon!\n" << endl;
											alert = false;
										}	
									}
									while(mov != 'A' && mov != 'B' && mov != 'C');
									
									// choose category
									do{
										// display category table
										cout << "\n------------------------------------" << endl;
										cout << "| No. | " << setw(18) << left << "Category List" << " | " << setw(5) << right << "Price" << " |"<< endl;
										cout << "------------------------------------" << endl;
										for(i = 0; i < 4; i++)
											cout << tablec[i] << setw(18) << left << category[i] << " | " << setw(5) << right << categoryp[i] << " |" << endl;
										cout << "------------------------------------" << endl;
										
										cout << "\nPlease select a category to add tickets into your purchase list: ";
										cin >> cat;
										
										// prevent infinite loop if char entered 
									    if(cin.fail()){
									        cin.clear();				// clear input buffer
									        cin.ignore(INT_MAX, '\n'); 	// ignore last input
										}
										
										if(cat < 1 || cat > 4)
											cout << "Invalid Input. Please try again.\n" << endl;
									}
									while(cat < 1 || cat > 4);
									
									// input amount of tickets
									switch(mov){
										case 'A':	
													for(i = 0; i < 4; i++){
														if(cat == (i + 1))
															do{
																cout << "\nPlease insert the ticket amount for this category: ";
																cin >> ticketamt2;
																
																// prevent infinite loop if char entered 
															    if(cin.fail()){
															    	ticketamt2 = -1;
															        cin.clear();				// clear input buffer
															        cin.ignore(INT_MAX, '\n'); 	// ignore last input
																}
																
																if(ticketamt2 < 0)
																	cout << "Invalid Input. Please try again.\n" << endl;
																else{
																	if(ticket2[0] - ticketamt2 >= 0)
																		ticketamt[i][0] += ticketamt2;
																	else
																		ticketamt2 = -1;
																}
															}
															while(ticketamt2 < 0);
													}
													break;
										case 'B':	
													for(i = 0; i < 4; i++){
														if(cat == (i + 1))
															do{
																cout << "\nPlease insert the ticket amount for this category: ";
																cin >> ticketamt2;
																
																// prevent infinite loop if char entered 
															    if(cin.fail()){
															    	ticketamt2 = -1;
															        cin.clear();				// clear input buffer
															        cin.ignore(INT_MAX, '\n'); 	// ignore last input
																}
																
																if(ticketamt2 < 0)
																	cout << "Invalid Input. Please try again.\n" << endl;
																else{
																	if(ticket2[1] - ticketamt2 >= 0)
																		ticketamt[i][1] += ticketamt2;
																	else
																		ticketamt2 = -1;
																}
															}
															while(ticketamt2 < 0);
													}
													break;
										case 'C':	
													for(i = 0; i < 4; i++){
														if(cat == (i + 1))
															do{
																cout << "\nPlease insert the ticket amount for this category: ";
																cin >> ticketamt2;
																
																// prevent infinite loop if char entered 
															    if(cin.fail()){
															    	ticketamt2 = -1;
															        cin.clear();				// clear input buffer
															        cin.ignore(INT_MAX, '\n'); 	// ignore last input
																}
																
																if(ticketamt2 < 0)
																	cout << "Invalid Input. Please try again.\n" << endl;
																else{
																	if(ticket2[2] - ticketamt2 >= 0)
																		ticketamt[i][2] += ticketamt2;
																	else
																		ticketamt2 = -1;
																}
															}
															while(ticketamt2 < 0);
													}
													break;
									}
									// prevent stacking after first loop
									// after declaring all to zero
									// it will recalculate new total in the for loop below
									for(i = 0; i < 4; i++){
										tickett = 0;
										categoryt[i] = 0;
										moviet[i] = 0;
									}
								
									for(i = 0; i < 4; i++){
										
										for(j = 0; j < 3; j++){
											// calculate total tickets selected
											tickett += ticketamt[i][j];
											// calculate total tickets selected per category
											categoryt[i] += ticketamt[i][j];
											// calculate total tickets for the movie
											moviet[j] += ticketamt[i][j];
										}
									}
										
									// display purchase list table
									cout << "\n============== YOUR PURCHASE LIST ==============" << endl;
									cout << "\n------------------------------------------------" << endl;
									cout << "| Category / Movie |  A  |  B  |  C  |  Total  |" << endl;
									cout << "------------------------------------------------" << endl;
									
									for(i = 0; i < 4; i++){
										cout << "| " << setw(16) << left << category[i] << " | ";
											for(j = 0; j < 3; j++)
												cout << setw(2) << right << ticketamt[i][j] << "  | ";
										cout << setw(6) << categoryt[i] << "  |" << endl;
									}
									cout << "------------------------------------------------" << endl;
									cout << "| Total Tickets    | " << setw(2) << moviet[0] << "  | " << setw(2) << moviet[1] <<
										 	"  | " << setw(2) << moviet[2] << "  | " << setw(6) << tickett << "  |"<< endl;
									cout << "------------------------------------------------" << endl;
									
									// INTI Student discount
									if(categoryt[0] < 6 && categoryt[0] != 0){
										moret = 6 - categoryt[0];
										cout << "\nYou will get a 20% discount if you purchase another " << moret << " tickets from INTI Student category." << endl;
									}
									else if(categoryt[0] > 5)
										cout << "\nYou are eligible for the 20% discount for the INTI Student category tickets." << endl;
									
									// INTI Staff discount
									if(categoryt[1] < 6 && categoryt[1] != 0){
										moret = 6 - categoryt[1];
										cout << "\nYou will get a 10% discount if you purchase another " << moret << " tickets from INTI Staff category." << endl;
									}
									else if(categoryt[1] > 5)
										cout << "\nYou are eligible for the 10% discount for the INTI Staff category tickets." << endl;
										
									do{
										do{
											// block this output if no ticket left
											if(block == false)
											cout << "\nDo you still want to purchase more tickets for this movie? Enter 'T'" << endl;
											cout << "Addeed too much ticket to your purchase list? Edit. Enter 'E'" << endl;
											cout << "Proceed to payment. Enter 'P'" << endl;
											cin >> proceed;	
											
											// 
											while(proceed == 'P' && confirm == false){
												cout << "\nYou cannot make any further changes in your purchase list if you proceed to payment." << endl;
												cout << "Confirm? Enter 'Y' or 'N'" << endl;
												cin >> cfm;
												
											if(cfm == 'Y')
												confirm = true;
											else
												proceed = 'X';
											}
										}
										while(proceed != 'T' && proceed != 'E' && proceed != 'P');
										
										if(proceed == 'T'){
											for(i = 0; i < 3; i++)
												ticket2[i] -= moviet[i];
												
												cout << ticket2[0] << " " << ticket2[1] << " " << ticket2[2] << endl;
										}	
									
										while(proceed == 'E'){
											
											// display purchase list table
											cout << "\n============== YOUR PURCHASE LIST ==============" << endl;
											cout << "\n------------------------------------------------" << endl;
											cout << "| Category / Movie |  A  |  B  |  C  |  Total  |" << endl;
											cout << "------------------------------------------------" << endl;
											
											for(i = 0; i < 4; i++){
											
												cout << "| " << setw(16) << left << category[i] << " | ";
												
													for(j = 0; j < 3; j++)
														cout << setw(2) << right << ticketamt[i][j] << "  | ";
												
												cout << setw(6) << categoryt[i] << "  |" << endl;
											}
											cout << "------------------------------------------------" << endl;
											cout << "| Total Tickets    | " << setw(2) << moviet[0] << "  | " << setw(2) << moviet[1] <<
												 	"  | " << setw(2) << moviet[2] << "  | " << setw(6) << tickett << "  |"<< endl;
											cout << "------------------------------------------------" << endl;
											
											// display notes
											cout << "\n*NOTES*" << endl;
											cout << "1. The list above shows your current purchase list status." << endl;
											cout << "2. You may only deduct additional ticket/s added in this section." << endl;
											
											deduct = true;
											
											// edit input
											while(deduct == true){
												do{
													cout << "\nPlease enter the row(category) that you wish to deduct the amount." << endl;
													cin >> row;
												
													// validate input
													if(row < 1 || row > 4)
														cout << "Invalid input. Please try again." << endl;
												}
												while(row < 1 || row > 4);
												
												i = row;
												
												do{
													cout << "\nPlease enter the column(movie) that you wish to deduct the amount." << endl;
													cin >> col;
												
													// validate input
													if(col < 1 || col > 3)
														cout << "Invalid input. Please try again." << endl;
												}
												while(col < 1 || col > 3);
												
												j = col;
												
												// validate availability
												if(ticketamt[i - 1][j - 1] == 0){
													cout << "No ticket to deduct for this section. Please choose other movie/category and try again." << endl;
													}
												else if(ticketamt[i - 1][j - 1] > 0){
													do{
														cout << "Enter the amount of ticket that you wish to deduct: ";
														cin >> tdeduct;
														
														if(tdeduct < 0)
															cout << "Invalid Input. Please try again." << endl;
														else if(ticketamt[i - 1][j - 1] - tdeduct < 0){
															cout << "You cannot deduct exceed the amount you had chosen. Please try again." << endl;
															tdeduct = -1;
														}
														else{
															ticketamt[i - 1][j - 1] -= tdeduct;
															categoryt[i - 1] -= tdeduct;
															moviet [j - 1] -= tdeduct;
															
															tickett = 0;
															
															for(i = 0; i < 4; i++)
																for(j = 0; j < 3; j++)
																// calculate total tickets selected after deduction
																	tickett += ticketamt[i][j];
															
															// table header
															cout << setw(20) << left << "Category" << endl;
															// table data
															for(i = 0; i < 4; i++){
															
																cout << setw(20) << category[i];
																
																	for(j = 0; j < 3; j++)
																		cout << ticketamt[i][j] << "  ";
																
																cout << categoryt[i] << endl;
															}
															// display total
															cout << endl << tickett << endl;
															
															if(tickett > 0)
																con = true;
															
															while(con == true){
																do{
																	cout << "\nContinue to make changes. Enter 'C'" << endl;
																	cout << "Nothing else to make changes. Enter 'N'" << endl;
																	cin >> proceed;
																		
																	if(proceed != 'C' && proceed != 'N')
																		cout << "Invalid input. Please try again." << endl;
																}
																while(proceed != 'C' && proceed != 'N');
																
																// throw in a false char to trigger while deduct loop
																if(proceed == 'C')
																	deduct = true;
																else
																	deduct = false;
																	
																con = false;
															}
															if(tickett == 0)
																deduct = false;
														}
													}
													while(tdeduct < 0);
												}
											}
											proceed = 'X';
										}
										
										// enter payment area
										while(confirm == true){
											
											// update tickets left to main ticket array
											for(i = 0; i < 3; i++)
												ticket[i] -= moviet[i];
											
											// calculate total for every category		
											for(i = 0; i < 4; i++)
												total[i] = categoryt[i] * categoryp[i];
											if	   (categoryt[0] > 5)
												total[0] *= discount[0];
											else if(categoryt[1] > 5)
												total[1] *= discount[1];
													
											for(i = 0; i < 4; i++)
												gtotal += total[i];
											
											// display payment list table
											cout << "\n======================= YOUR PAYMENT STATEMENT ==========================" << endl;
											cout << "\n-------------------------------------------------------------------------" << endl;
											cout << "| Category / Movie |  A  |  B  |  C  | Amount | Price(RM) |  Total(RM)  |" << endl;
											cout << "-------------------------------------------------------------------------" << endl;				
											for(i = 0; i < 4; i++){			
												cout << "| " << setw(16) << left << category[i] << " | ";
																
												for(j = 0; j < 3; j++)
													cout << setw(2) << right << ticketamt[i][j] << "  | ";		
													cout << setw(6) << categoryt[i] << " | ";
													cout << setw(9) << categoryp[i] << " | ";
													cout << setw(10) << total[i] << "  |" << endl;
											}
											cout << "-------------------------------------------------------------------------" << endl;
											cout << "| Grand Total      | " << setw(2) << moviet[0] << "  | " << setw(2) << moviet[1] << "  | " << setw(2) 
												 << moviet[2] << "  | " << setw(6) << tickett << " |           | " << setw(10) << gtotal << "  |" << endl;
											cout << "-------------------------------------------------------------------------" << endl;
											
											cout << "\nThe total amount that you need to pay for " << tickett << " tickets is: RM" << gtotal << endl;
											
											// user choose payment method
											// will not run payment details validation
											do{
												cout << "\n======= PAYMENT METHOD =======\n" << endl;
												cout << "------------------------------" << endl;
												cout << "| No. | Method               |" << endl;
												cout << "------------------------------" << endl;
												for(i = 0; i < 5; i++)
													cout << tablec[i] << setw(20) << left << paym[i] << " |" << endl;
												cout << "------------------------------" << endl;
												
												cout << "\nPlease choose a payment method to proceed: ";
												cin >> pmethod;
												
												// prevent infinite loop if char entered 
												if(cin.fail()){
													cin.clear();				// clear input buffer
													cin.ignore(INT_MAX, '\n'); 	// ignore last input
												}
												if(pmethod < 1 || pmethod > 5)
													cout << "Invalid Input. Please try again.\n" << endl;
											}
											while(pmethod < 1 || pmethod > 5);	
											
											while(psuc == 'N'){
												cout << "\nPayment successful? 'Y' or 'N'" << endl;
												cin >> psuc;
												
												if(psuc != 'Y' && psuc != 'N')
													cout << "Invalid Input. Please try again.\n" << endl;
												else if(psuc == 'N')
													cout << "Please make your payment." << endl;
											}
											// combine receipt name with count
											// prevent same file name created
											// can differenciate based on customer count
											receipttxt = receipt + to_string(printr + customer) + ".txt";
											// create receipt
											ofstream fout(receipttxt);
											// modify file output
											fout << setprecision(2) << fixed;
											
											fout << "================================ RECEIPT ==================================" << endl << endl;
											fout << "====================== INTI COLLEGE PENANG MOVIE DAY ======================" << endl << endl;
											fout << "___________________________________________________________________________" << endl << endl;
											fout << "\n------------------------------ Purchase List ------------------------------" << endl << endl;
											fout << "---------------------------------------------------------------------------" << endl;
											fout << "| Details     		 	     | Quantity |  Price(RM)  |  Total(RM)  |" << endl;
											fout << "---------------------------------------------------------------------------" << endl;
											
											for(j = 0; j < 3; j++){
												for(i = 0; i < 4; i++){
													if(ticketamt[i][j] != 0){
														if(categoryt[i] > 5 && i < 2)
															categoryp2[i] *= discount[i];
														fout << "| " << setw(32) << left << movie[j] + " - " + category[i] << " | " << setw(8) << right << ticketamt[i][j]
															 << " | " << setw(10) << categoryp2[i] << "  | " << setw(10) << total[i] * ticketamt[i][j] / categoryt[i] << "  |" << endl;
														// reset categoryp value back to initial
														// prevent overwrite	
														if(categoryt[i] > 5 && i < 2)
															categoryp2[i] /= discount[i];
													}
												}
											}
											fout << "|                                                                         |" << endl;
											fout << "---------------------------------------------------------------------------" << endl;
											fout << "| " << setw(32) << left << "Grand Total" << " | " << setw(8) << right 
												 << tickett << " |             | " << setw(10) << gtotal << "  |" << endl;
											fout << "---------------------------------------------------------------------------" << endl;
											fout << "\n\n";
											fout << "Payment made at " << dt << endl;
											fout << "Payment method: " << paym[pmethod - 1] << endl;
											fout << "\n\n";
											fout << ">>>>>>>>>>>>>>>>>>>>>> THANK YOU FOR YOUR PURCHASE! <<<<<<<<<<<<<<<<<<<<<<<" << endl;
											fout << ">>>>>>>>>>>>>>>>>>>>> HOPE YOU ENJOY YOUR MOVIE DAY! <<<<<<<<<<<<<<<<<<<<<<" << endl;
											// end of receipt
											
											// create tickets
											for(i = 0; i < 4; i++)
												for(j = 0; j < 3; j++)
													if(ticketamt[i][j] > 0)
														for(k = ticketamt[i][j]; k > 0; k--){
															printt++;
															// combine ticket name with count
															// prevent same file name created
															// can differenciate based on customer count
															tickettxt = printtick + to_string(printt) + ".txt";
															
															// create ticket
															ofstream fout(tickettxt);
															
															fout << setprecision(2) << fixed;
															for(l = 0; l < 2; l++){
																for(m = 0; m < 56; m++)
																	fout << "=";
																fout << endl;
															}
															fout << "\n";
															fout << "  TICKET   FOR   INTI   COLLEGE   PENANG   MOVIE   DAY";
															fout << "\n\n";
															for(l = 0; l < 56; l++)
																fout << "=";
															fout << "\n\n";
															
															fout << setw(20) << left << "Ticket ID" << " : " + printtick2 + to_string(printt) << endl;
															fout << setw(20) << left << "Movie Name" << " : " + movie[j] << endl;
															fout << setw(20) << left << "Movie Subtitle" << " : " + subt << endl;
															fout << setw(20) << left << "Movie language" << " : " + lang[i] << endl;
															fout << setw(20) << left << "Date" << " : " + date << endl;
															fout << setw(20) << left << "Movie Duration" << " : " + dur << endl;
															fout << setw(20) << left << "Start time" << " : " + stime << endl;
															fout << setw(20) << left << "End time" << " : " + etime << endl;
															fout << setw(20) << left << "Category" << " : " + category[i] << endl;
															fout << setw(20) << left << "Price per Ticket" << " : RM " << categoryp[i] << endl;
															fout << "\n\n";
															for(l = 0; l < 2; l++){
																for(m = 0; m < 56; m++)
																	fout << "=";
																fout << endl;
															}
														}
											cout << "\nYour receipt (" << receipttxt << ") had been generated.\n" << endl;
											cout << "All of your " << tickett << " tickets had been generated.";
											
											// escape while loop
											confirm = false;
											for(i = 0; i < 4; i++){
												categoryt[i] = 0;
												for(j = 0; j < 3; j++){
													ticketamt[i][j] = 0;
													moviet[j] = 0;
												}
											}
											tickett = 0;
											gtotal = 0;
											pmethod = 0;
											customer++;
										}
									}
									while(proceed != 'T' && proceed != 'E' && proceed != 'P');
								}
								while(proceed == 'T' && proceed != 'E' && proceed != 'P');
								
								proceed = 'X';
								
								break;
					default:	cout << "Invalid input. Please try again." << endl;
				}
				menuv = false;
		}  
		while(menuv == false);
		
		return 0; 
}
