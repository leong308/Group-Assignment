// CASE L (Movie List)  	100% DONE (CORE FUNCTION + DISPLAY + VALIDITY)
//							100% DONE (OUTPUT UI/UX)
// CASE T (Ticket price) 	100% DONE (CORE FUNCTION + DISPLAY + CALCULATOR + VALIDITY)
//							100% DONE (OUTPUT UI/UX)
// CASE S (Seats left)  	100% DONE (CORE DISPLAY + VALIDITY)
//							100% DONE (OUTPUT UI/UX)
// CASE P (Purchase)     	100% DONE (CORE FUNCTION + DISPLAY + DEDUCT TICKETS + PAYMENT + RECEIPT + TICKETS)
//							100% DONE (OUTPUT UI/UX)
// CASE A (Administrator)   100% DONE (CORE FUNCTION + DISPLAY + PRINT COPY)
//							100% DONE (OUTPUT UI/UX)

#include <iostream> 
#include <iomanip>	// manipulate output
#include <limits>	// for numeric limits
#include <fstream>	// for file access
using namespace std;

int main() 
{
	// counters
	int i, j, k, l, m;
	
	// validation error msg
	string error[6] = {"Invalid Input. Please try again."														   ,
					   "You had selected too much tickets. Please try again."									   ,
					   "No ticket to deduct for this section. Please choose other movie/category and try again."   ,
					   "You cannot deduct exceed the amount you had chosen. Please try again."					   ,
					   "Please make your payment."																   ,
					   "Invalid Password."																			};
					   
	// proceed table
	string pdisplay = "---------------------------------------------------------";					// table designation
	string proceedm[9] = {"Back to Main Menu"			   , "Back to Movie List"			   ,	// proceed options
						  "Open Calculator"				   , "Purchase More Tickets"		   ,
						  "Addeed Too Much Ticket? Edit."  , "Proceed to Payment"			   ,
						  "Continue to Make Changes."	   , "Nothing Else to Make Changes."   ,
						  "Retry Password."														};
						  
	// main menu part
	char menu;												// take menu input
	string tdisplay = "--------------------------------";	// table designation
	string pass;											// input password
	bool menuv, welcome, passv;									// validate menu input, welcome swtich, password validation
	
	// case l part
	char mdetail, trailer;														// movie detail input, movie trailer decision
	char proceed;																// proceed to next part
	string movtable[3] = {"| A | ", "| B | ", "| C | "};						// table designations 
	string ldisplay[3] = {"----------------------------"				   ,
						  "\n========================================\n\n" ,
						  "\n========================================\n"	};	
	string movie[3] = {"Detective Pikachu", "Paskal", "The Climbers"};			// movies
	string lang[3] = {"EN", "BM", "CN"};										// languages
	string subt = "EN & BM & CN";												// subtitles
	string date = "12/12/2022";													// date
	string dur = "2 hours 30 minutes";											// duration
	string stime = "19:00", etime = "21:30";									// start time, end time
	string turl[3] = {"start https://www.youtube.com/watch?v=1roy4o4tqQM",		// movie trailer url
					  "start https://www.youtube.com/watch?v=rA4l9M7bWv8",
					  "start https://www.youtube.com/watch?v=LN0e-Xlu9hA"};
	bool mdetailv, proceedv;													// validate movie detail input, proceed validation
	
	// case t part
	char stopcalc;																		// stop calculation input
	const double categoryp[5] = {10, 12, 15, 6, 0};										// category price (fixed single price)
	double discount[2] = {0.80, 0.90};													// discounts (specific category)
	string category[4] = {"INTI Student", "INTI Staff", "Adult", "Child (Below 18)"};	// category
	string tablec[5] = {"|  1. | ", "|  2. | ", "|  3. | ", "|  4. | ", "|  5. | "};	// table count
	string adisplay[2] = {"------------------------------------"				 ,		// table designation
						  "------------------------------------------------------"};
	int ccalc, calct, calct2, x;														// inputs validations
	int calccatamt[4] = {0};															// tickets amount per category
	double calccattot[4] = {0};															// tickets per category total price
	double tcalc;																		// grand total after add up
	bool stopcalcv;																		// validate stop calculation input
	
	// case s part
	int ticket[3] = {50, 50, 50};											// available seats
	string sdisplay = "----------------------------------------------";		// table designation
		
	// case p part
	char mov, cfm, psuc;						// choose movie, user confirm proceed to payment, input payment status
	string pldisplay[3] = {"------------------------------------------------"						  ,	// table designation
						   "-------------------------------------------------------------------------",
						   "------------------------------"											  };
	string paym[5] = {"Cash", "Credit/Debit Card", "Touch N Go E-Wallet", "Paypal", "Bitcoin"};			// payment method
	int ticket2[3] = {0};								// available seats (for temporary use)
	int cat = 0;										// choose category
	int ticketamt[4][3] = {0};							// ticket amount for category - movie
	int ticketamt2;										// input ticket amount
	int tickett = 0;									// total tickets
	int categoryt[4] = {0}, moviet[3] = {0};			// total tickets - category, total tickets - movie
	int moret, tdeduct;									// another x tickets to discount, input tickets amount to deduct
	int row, col;										// input row & column to edit
	int pmethod;										// choose payment method
	double total[4] = {0}, gtotal = 0;					// total based on category, grand total
	bool block = false, block2 = false, movv = true;	// block output, validate choose movie
	bool finish = false, alert = false;					// ticket finish, lack of ticket alert
	bool confirm = false, deduct = true;				// confirm to payment, enter edit ticket if true
	bool con, psucv;									// validate whether to continue, validate payment status
		
	// receipt
	string receipt = "receipt";					// receipt base file name
	string receipttxt;							// generated receipt file name
	int customer = 1;							// total customers counter and receipt counter
	double categoryp2[4] = {10, 12, 15, 6};		// category price changes for receipt usage
	double discounted;							// discounted base price, used in receipt output
		
	// for print ticket
	string printtick = "ticket";	// ticket base file name
	string tickettxt;				// generated ticket file name
	string printtick2 = "TICKET";	// generated base ticket ID
	int printt = 0;					// ticket counter
	
	// case a part
	double acctotal;				// accumulated total
	int acccategoryt[4] = {0};		// accumulated category tickets
	int accmoviet[3] = {0};			// accumulated movie tickets
	int accticketamt[4][3] = {0};	// accumulated ticket amount for category - movie
	int copy = 0;					// admin-copy counter
	char pcopy;						// admin decide to print admin-copy
	string copytxt;					// generated admin-copy file name
	bool pcopyv;					// valdate pcopy input
		
	// modify all double output to 2 dp
	cout << setprecision(2) << fixed;
	do{
		welcome = false;
		cout << " ********************************************************************** \n\n";		// welcome notes
		cout << " Welcome To The INTI College Penang Movie Day Ticket Purchasing System! \n\n";
		cout << "          The Movie Day Will Be Held During 12th December 2022          \n";
		cout << "                         At INTI College Penang                         \n\n";
		cout << " !!!!!!!!!!!!!!!!!!!!!!!!!!!!! ATTENTION !!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n";
		cout << "    There Will Be Juicy Discounts Given For INTI Students And Staffs    \n";
		cout << "            For A Decent Amount Of Tickets In One Purchase!             \n\n";
		cout << "                          GRAB YOUR TICKET NOW!                         \n\n";
		cout << " ********************************************************************** \n";
		
		// main menu loop
		do{
			cout << "\n======== THE MAIN MENU =========\n" << endl << tdisplay << endl;
			cout << "| " << setw(20) << left << "Go To..." 				<< " | Enter |" << endl << tdisplay << endl << tdisplay << endl;
			cout << "| " << setw(20) << left << "View Movie List" 		<< " |  'L'  |" << endl << tdisplay << endl;
			cout << "| " << setw(20) << left << "View Ticket Price" 	<< " |  'T'  |" << endl << tdisplay << endl;
			cout << "| " << setw(20) << left << "View Available Seats" 	<< " |  'S'  |" << endl << tdisplay << endl;
			cout << "| " << setw(20) << left << "Buy ticket now!" 		<< " |  'P'  |" << endl << tdisplay << endl;
			cout << "| " << setw(20) << left << "Administrator Login" 	<< " |  'A'  |" << endl << tdisplay << endl;
			cout << "\nPlease enter your selection: ";
			cin >> menu;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');	// read all input, only take first char
			
			// admin validation gate
			if(menu == 'A' || menu == 'a'){
				do{
					cout << "\nPlease enter password: ";
					cin >> pass;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					
					if(pass == "$pass$")
						passv = true;
					else{
						cout << error[5] << endl;
						do{
							cout << "\n======================= PROCEED =========================\n" << endl << pdisplay << endl;
							cout << "| " << setw(45) << left << "Proceed To..." << " | Enter |" << endl << pdisplay << endl << pdisplay << endl;
							cout << "| " << setw(45) << left << proceedm[8] << " |  'R'  |" << endl << pdisplay << endl;
							cout << "| " << setw(45) << left << proceedm[0] << " |  'M'  |" << endl << pdisplay << endl;
							cout << "\nPlease enter your selection: ";
							cin >> proceed;
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
											
							switch(proceed){
								case 'r':
								case 'R':	passv = false;
											proceedv = true;
											break;
								// if user choose back to main menu, erase menu char to force back
								// set all gate to true to escape do-while loops
								case 'm':
								case 'M':	menu = 'X';
											proceedv = true;
											passv = true;
											break;
								default:	cout << error[0] << endl;
											proceedv = false;
							}	
						}
						while(proceedv == false);
					}
				}
				while(passv == false);
			}
            
				// proceed into selections
				switch(menu)
				{	// display movie list
					case 'l':
					case 'L':   do{
									do{	
										// choose to view details
										cout << "\n======== MOVIE LIST ========\n" << endl << ldisplay[0] << endl;
										cout << "|   | " << setw(20) << left << "Movie Title" << " |" << endl << ldisplay[0] << endl;
										for(i = 0; i < 3; i++)
											cout << movtable[i] << setw(20) << left << movie[i] << " |" << endl;
										cout << ldisplay[0] << endl;
									
		            					cout << "\nChoose a movie for more details." << endl;
		            					cin >> mdetail;
		            					cin.ignore(numeric_limits<streamsize>::max(), '\n');
		            					
		            					mdetailv = true;
			            				switch(mdetail)
										{
											case 'a':
											case 'A':	j = 0;
														break;
											case 'b':
											case 'B':   j = 1;
														break;
											case 'c':
											case 'C':	j = 2;
														break;
											default:	cout << error[0] << endl;
														mdetailv = false;
										}				
									}
									while(mdetailv == false);
									
									// display movie details
									for(i = 0; i < 3; i++){
										if(i == j){
											cout << ldisplay[1] << setw(15) << left << " Movie" << " : " + movie[i] << endl;
											cout << setw(15) << left << " Language" << " : " + lang[i] << endl;
											cout << setw(15) << left << " Subtitle" << " : " + subt << endl;
											cout << setw(15) << left << " Date" << " : " + date << endl;
											cout << setw(15) << left << " Duration" << " : " + dur << endl;
											cout << setw(15) << left << " Start Time" << " : " + stime << endl;
											cout << setw(15) << left << " End Time" << " : " + etime << endl;
											cout << setw(15) << left << " Seats left" << " : " << ticket[i] << endl << ldisplay[2];
											}	
									}
									// user can watch movie trailer
									do{
										cout << "\nDo you want to play the movie trailer? Enter 'Y' for yes or 'N' for no." << endl;
										cin >> trailer;
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										
										if(trailer == 'Y' || trailer == 'y'){
											for(i = 0; i < 3; i++)
												if(i == j){
													system(turl[i].c_str());
													cout << "\nMovie trailer had been launched in your browser tab." << endl;
													cout << "Please head over to your browser to watch the movie trailer." << endl;
												}
										}
										else if(trailer == 'N' || trailer == 'n')
											;
										else
											cout << error[0] << endl;
									}
									while(trailer != 'Y' && trailer != 'y' && trailer != 'N' && trailer != 'n');
										
									// user choose either back to movie list or main menu
									do{
										cout << "\n======================= PROCEED =========================\n" << endl << pdisplay << endl;
										cout << "| " << setw(45) << left << "Proceed To..." << " | Enter |" << endl << pdisplay << endl << pdisplay << endl;
										cout << "| " << setw(45) << left << proceedm[1] << " |  'L'  |" << endl << pdisplay << endl;
										cout << "| " << setw(45) << left << proceedm[0] << " |  'M'  |" << endl << pdisplay << endl;
										
										cout << "\nPlease enter your selection: ";
										cin >> proceed;
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
											
										switch(proceed){
											case 'l':
											case 'L':	mdetailv = false;
											case 'm':
											case 'M':	proceedv = true;
														break;
											default:	cout << error[0] << endl;
														proceedv = false;
										}	
									}
									while(proceedv == false);
								}
								while(mdetailv == false);
								
								proceed = 'X';						
								break;
					// display ticket price + calculator
					case 't':        
					case 'T':	do{
									// ticket price table
									cout << "\n======== TICKET PRICE LIST =========\n" << endl << adisplay[0] << endl;
									cout << "| No. | " << setw(16) << left << "Category" << setw(2) << " |" 
										 << setw(10) << right << "Price  |" << endl << adisplay[0] << endl;
									for(i = 0; i < 4; i++)
										cout << tablec[i] << setw(16) << left << category[i] << setw(2) << " |" 
											 << setw(7) << right << categoryp[i] << "  |" << endl;
									cout << adisplay[0] << endl;
									// display notes
									cout << "\n*NOTES*" << endl;
									cout << "1. You may purchase more than 1 ticket at once." << endl;
									cout << "2. You may purchase from different categories at once." << endl;
									cout << "3. A 20% discount will be given for INTI Student category with more than 5 tickets in one purchase." << endl;
									cout << "4. A 10% discount will be given for INTI Staff category with more than 5 tickets in one purchase." << endl;
								
									// user choose either back to main menu or enter calculator
									cout << "\n======================= PROCEED =========================\n" << endl << pdisplay << endl;
									cout << "| " << setw(45) << left << "Proceed To..." << " | Enter |" << endl << pdisplay << endl << pdisplay << endl;
									cout << "| " << setw(45) << left << proceedm[2] << " |  'C'  |" << endl << pdisplay << endl;
									cout << "| " << setw(45) << left << proceedm[0] << " |  'M'  |" << endl << pdisplay << endl;
										
									cout << "\nPlease enter your selection: ";
									cin >> proceed;
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									
									switch(proceed){
										case 'c':
										case 'C':
										case 'm':
										case 'M':	proceedv = true;
													break;
										default:	cout << error[0] << endl;
													proceedv = false;
									}
									
									// enter calculator
									if(proceed == 'C' || proceed == 'c'){
										// recall back here if not leaving calculator
										do{
											do{
												// ticket price table
												cout << "\n======== TICKET PRICE LIST =========\n" << endl << adisplay[0] << endl;
												cout << "| No. | " << setw(16) << left << "Category" << setw(2) << " |" 
													 << setw(10) << right << "Price  |" << endl << adisplay[0] << endl;
												for(i = 0; i < 4; i++)
													cout << tablec[i] << setw(16) << left << category[i] << setw(2) << " |" 
														 << setw(7) << right << categoryp[i] << "  |" << endl;
												cout << adisplay[0] << endl;
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
								    				cout << error[0] << endl;
									    	}
									    	while(ccalc < 1 || ccalc > 4);
									    	
									    	// ask user to enter amount of tickets wanted for the specific category
									    	do{
												cout << "\nHow many tickets do you want to purchase for this category?" << endl;
									        	cin >> calct;
									        	
									        	if(cin.fail()){
									        		calct = -999;				// declare false value to force whole do while to loop again
									        		cin.clear();				// clear input buffer
									        		cin.ignore(INT_MAX, '\n'); 	// ignore last input
												}
												// enable user to input negative value after first loop
												// validate negative values / minimum
												for(i = 1; i < 5; i++)
													if(ccalc == i)
														x = calccatamt[i - 1] + calct;
												// add into total
												// validate maximum
													calct2 = calct + calccatamt[0] + calccatamt[1] + calccatamt[2] + calccatamt[3];
												// cannot deduct until less than 0
									        	if(x < 0)
									           		cout << error[0] << endl;
									           	// prevent user from entering too much tickets
									           	else if(calct2 > 150)
									           		cout << error[1] << endl;
									           	else{
									           		for(i = 0; i < 4; i++)
									           			if(ccalc == i + 1)
									           				calccatamt[i] = calccatamt[i] + calct;
													
									           		// calculator working based on catgories
													calccattot[0] = calccatamt[0] * categoryp[0];		// INTI Student
													if(calccatamt[0] > 5)
														calccattot[0] = calccattot[0] * discount[0];
														
													calccattot[1] = calccatamt[1] * categoryp[1];		// INTI Staff
													if(calccatamt[1] > 5)
														calccattot[1] = calccattot[1] * discount[1];
														
													calccattot[2] = calccatamt[2] * categoryp[2];		// Adult
													
													calccattot[3] = calccatamt[3] * categoryp[3];		// Child
													
													// total
													tcalc = calccattot[0] + calccattot[1] + calccattot[2] + calccattot[3];
													
													// display table
													cout << "\n============== PURCHASE LIST SIMULATOR ===============" << endl << endl << adisplay[1] << endl;
													cout << "|     | " << setw(16) << left << "Category" << setw(2) << " | " << setw(5) << right << "Price" << setw(2) 
														 << " | " << setw(6) << right << "Amount" << setw(2) << " |" << setw(11) << "Total  |" << endl;
														cout << adisplay[1] << endl;
													
													for(i = 0; i < 4; i++)
														cout << tablec[i] << setw(16) << left << category[i] << setw(2) << " | " << setw(5) << right << categoryp[i]
															 << setw(2) << " | "  << setw(6) << right << calccatamt[i] << setw(2) << " |" << setw(8) << calccattot[i] << "  |" << endl;
													cout << adisplay[1] << endl;
													// grand total
													cout << setw(32) << left << "| Grand Total" << setw(2) << " | " << setw(6) << right << calct2 
														 << setw(2) << " |" << setw(8) << tcalc << "  |" << endl << adisplay[1];
													
													cout << "\n*NOTES*" << endl;
													cout << "1. A 20% discount will be given for INTI Student category with more than 5 tickets in one purchase." << endl;
													cout << "2. A 10% discount will be given for INTI Staff category with more than 5 tickets in one purchase." << endl;
												   }
									   		}
									    	while(x < 0 || calct2 > 150);
									    	
									    	// user can leave or stay in calculator
									    	while(stopcalcv == false){
									    		cout << "Calculation data will be erased if you leave this session." << endl;
												cout << "\nDo you still want to edit tickets and calculate price? " << endl;
									    		cout << "\nEnter 'Y' to contiue calculate or 'N' to exit calculator." << endl;
									    		cin >> stopcalc;
									    		cin.ignore(numeric_limits<streamsize>::max(), '\n');
									    		
									    		switch(stopcalc){
													case 'y':
													case 'Y':
													case 'n':
													case 'N':	stopcalcv = true;
																break;
													default:	cout << error[0] << endl;
																stopcalcv = false;
												}
									    		// let ccalc to loop again
									    		if(stopcalc == 'Y' || stopcalc == 'y')
									    			ccalc = 0;
									    		else if(stopcalc == 'N' || stopcalc == 'n'){
									    			proceedv = false;
									    			
									    			// erase all calculation data to default if exits calculator session
									    			for(i = 0; i < 4; i++){
									    				calccatamt[i] = {0};
														calccattot[i] = {0};
													}
													calct = 0, calct2 = 0;
													tcalc = 0;
												}
											}
											stopcalcv = false;
										}
										while(ccalc < 1 || ccalc > 4);
									}
								}
								while(proceedv == false);
										
								// reset proceed data to X
								proceed = 'X';
								
								break;   
					// display available seats left
					case 's':
					case 'S':	// display movie table
								cout << "\n============ CHECK AVAILABILITY ==============\n" << endl << sdisplay << endl;
								cout << "|   | " << setw(20) << left << "Movie Title" << " | Available Seats |" << endl << sdisplay << endl;
								for(i = 0; i < 3; i++)
									cout << movtable[i] << setw(20) << left << movie[i] << " | " << setw(15) << right << ticket[i] << " |" << endl;
								cout << sdisplay << endl;
								
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
								else
									cout << "\nAll 3 movies are still available at this moment." << endl;
								// ignore all == 0 output --> program ends if no tickets left
									
								// user must to return back to main menu
								do{
									cout << "\n======================= PROCEED =========================\n" << endl << pdisplay << endl;
									cout << "| " << setw(45) << left << "Proceed To..." << " | Enter |" << endl << pdisplay << endl << pdisplay << endl;
									cout << "| " << setw(45) << left << proceedm[0] << " |  'M'  |" << endl << pdisplay << endl;
										
									cout << "\nPlease enter your selection: ";
									cin >> proceed;
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									
									if(proceed != 'M' && proceed != 'm')
										cout << error[0] << endl;
								}
								while(proceed != 'M' && proceed != 'm');
								// reset proceed data to X
								proceed = 'X';
								
								break;
					// purchase section
					case 'p':
					case 'P':	for(i = 0; i < 3; i++)
									ticket2[i] = ticket[i];
								// loop back if proceed = 'T'
								do{	
									// choose movie
									do{
										// movie selection table
										cout << "\n======== MOVIE LIST ========\n" << endl << ldisplay[0] << endl;
										cout << "|   | " << setw(20) << left << "Movie Title" << " |" << endl << ldisplay[0] << endl;
										for(i = 0; i < 3; i++)
											cout << movtable[i] << setw(20) << left << movie[i] << " |" << endl;
										cout << ldisplay[0] << endl;
											
										cout << "\nPlease select a movie to add tickets into your purchase list: ";
										cin >> mov;
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										
										movv = true;
										switch(mov){
											case 'a':
											case 'A':	j = 0;
														break;
											case 'b':
											case 'B':	j = 1;
														break;
											case 'c':
											case 'C':	j = 2;
														break;
											default:	movv = false;
														cout << error[0] << endl;
										}
										if(movv == true)
											for(i = 0; i < 3; i++)
												if(i == j){
													if(ticket2[i] == 0)
														finish = true;
													else if(ticket2[i] > 0 && ticket2[i] < 10)
														alert = true;
												}
										if(finish == true && movv == true){
											cout << "Unfortunately there is no seat left for this movie." << endl;
											cout << "Please choose other movie to proceed.\n" << endl;
											finish = false;
											movv = false;
										}
										else if(alert == true && movv == true){
											cout << "Hurry up! The available seats are running out soon!\n" << endl;
											alert = false;
										}	
									}
									while(movv == false);
									
									// choose category
									do{
										cout << "\n======== TICKET PRICE LIST =========\n" << endl << adisplay[0] << endl;
										cout << "| No. | " << setw(16) << left << "Category" << setw(2) << " |" 
											 << setw(10) << right << "Price  |" << endl << adisplay[0] << endl;
										for(i = 0; i < 4; i++)
											cout << tablec[i] << setw(16) << left << category[i] << setw(2) << " |" 
												 << setw(7) << right << categoryp[i] << "  |" << endl;
										cout << adisplay[0] << endl;
										// display notes
										cout << "\n*NOTES*" << endl;
										cout << "1. You may purchase more than 1 ticket at once." << endl;
										cout << "2. You may purchase from different categories at once." << endl;
										cout << "3. A 20% discount will be given for INTI Student category with more than 5 tickets in one purchase." << endl;
										cout << "4. A 10% discount will be given for INTI Staff category with more than 5 tickets in one purchase." << endl;
										
										cout << "\nPlease select a category to add tickets into your purchase list: ";
										cin >> cat;
										
									    if(cin.fail()){
									    	cat = 0;
									        cin.clear();				// clear input buffer
									        cin.ignore(INT_MAX, '\n'); 	// ignore last input
										}
										if(cat < 1 || cat > 4)
											cout << error[0] << endl;
									}
									while(cat < 1 || cat > 4);
									
									switch(mov){
										case 'a':
										case 'A':	k = 0;
													break;
										case 'b':
										case 'B':	k = 1;
													break;
										case 'c':
										case 'C':	k = 2;
													break;
									}
									// avoid bunch of duiplicated codes in switch case
									for(j = 0; j < 3; j++)
										if(j == k)
											for(i = 0; i < 4; i++){
												if(cat == (i + 1))
													do{
														cout << "\nPlease insert the ticket amount for this category: ";
														cin >> ticketamt2;
														
														if(cin.fail()){
															ticketamt2 = -1;
															cin.clear();				// clear input buffer
															cin.ignore(INT_MAX, '\n'); 	// ignore last input
														}			
														if(ticketamt2 < 0)
															cout << error[0] << endl;
														else{
															if(ticket2[k] - ticketamt2 >= 0)
																ticketamt[i][k] += ticketamt2;
															else{
																cout << error[0] << endl;
																ticketamt2 = -1;
															}				
														}
													}
													while(ticketamt2 < 0);
											}
									// prevent stacking after first loop after declaring all to zero
									// will recalculate new total in the for loop below
									for(i = 0; i < 4; i++){
										tickett = 0;
										categoryt[i] = 0;
										moviet[i] = 0;
									}
									for(i = 0; i < 4; i++)
										for(j = 0; j < 3; j++){
											tickett += ticketamt[i][j];			// calculate total tickets selected
											categoryt[i] += ticketamt[i][j];	// calculate total tickets selected per category
											moviet[j] += ticketamt[i][j];		// calculate total tickets for the movie
										}
										
									// display purchase list table
									cout << "\n============== YOUR PURCHASE LIST ==============\n" << endl << pldisplay[0] << endl;
									cout << "| Category / Movie |  A  |  B  |  C  |  Total  |" << endl << pldisplay[0] << endl;
									
									for(i = 0; i < 4; i++){
										cout << "| " << setw(16) << left << category[i] << " | ";
											for(j = 0; j < 3; j++)
												cout << setw(2) << right << ticketamt[i][j] << "  | ";
										cout << setw(6) << categoryt[i] << "  |" << endl;
									}
									cout << pldisplay[0] << endl << "| Total Tickets    | " << setw(2) << moviet[0] << "  | " << setw(2) << moviet[1]
										 << "  | " << setw(2) << moviet[2] << "  | " << setw(6) << tickett << "  |" << endl << pldisplay[0] << endl;
									
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
									
									// update temporary available seats left
									for(i = 0; i < 3; i++){
										// prevent over deduct based on movie total
										// update both moviet[] and ticket2[] at the same time
										/*	
											ticket2[i] = 10, moviet = 40 + 9, ticket[i] = 50
										
											Example (fail):		-39 = 10 - 49
											Example (succeed):	9 = 10 - (50 - 49)	--	9 will be the newest added tickets
																1 = 10 - 9			--  1 will be the temporary remainder for tickets	
										*/
										moviet[i] = ticket2[i] - (ticket[i] - moviet[i]);
										ticket2[i] -= moviet[i];
									}	
									if(ticket2[0] == 0 && ticket2[1] == 0 && ticket2[2] == 0)
										block = true;
									do{
										do{
											// user choose either add more tickets into purchase list
											//					  edit tickets amount
											//					  make payment
											cout << "\n======================= PROCEED =========================\n" << endl << pdisplay << endl;
											cout << "| " << setw(45) << left << "Proceed To..." << " | Enter |" << endl << pdisplay << endl << pdisplay << endl;
											// block this output if no ticket left
											if(block == false)
												cout << "| " << setw(45) << left << proceedm[3] << " |  'T'  |" << endl << pdisplay << endl;
											// block this output if no ticket left to deduct
											if(block2 == false)
												cout << "| " << setw(45) << left << proceedm[4] << " |  'E'  |" << endl << pdisplay << endl;
											cout << "| " << setw(45) << left << proceedm[5] << " |  'P'  |" << endl << pdisplay << endl;
											
											cout << "\nPlease enter your selection: ";
											cin >> proceed;	
											cin.ignore(numeric_limits<streamsize>::max(), '\n');
											
											switch(proceed){
												case 'p':
												case 'P':	while(confirm == false){
																cout << "\nYou cannot make any further changes in your purchase list if you confirm to proceed." << endl;
																cout << "Are you sure? Enter 'Y' for yes or 'N' for no" << endl;
																cin >> cfm;
																cin.ignore(numeric_limits<streamsize>::max(), '\n');
																
																switch(cfm){
																	case 'y':
																	case 'Y':	confirm = true;
																				break;
																	case 'n':
																	case 'N':	proceedv = false;
																				proceed = 'X';
																				break;
																	default:	confirm = false;
																				cout << error[0] << endl;
																}
															}
															break;
												case 't':
												case 'T':	if(block == true){
																cout << error[0] << endl;
																proceedv = false;
															}
															else
																proceedv = true;
															break;
												case 'e':
												case 'E':	if(block2 == true){
																cout << error[0] << endl;
																proceedv = false;
															}
															else
																proceedv = true;
															break;
												default:	proceedv = false;
															cout << error[0] << endl;
											}
										}
										while(proceedv == false);  
										block = false;
										block2 = false;
										
										while(proceed == 'E' || proceed == 'e'){
											// prevent stacking after first loop after declaring all to zero
											// will recalculate new total in the for loop below
											for(i = 0; i < 4; i++){
												tickett = 0;
												categoryt[i] = 0;
												moviet[i] = 0;
											}
											for(i = 0; i < 4; i++)
												for(j = 0; j < 3; j++){
													tickett += ticketamt[i][j];			// calculate total tickets selected
													categoryt[i] += ticketamt[i][j];	// calculate total tickets selected per category
													moviet[j] += ticketamt[i][j];		// calculate total tickets for the movie
												}
											// display purchase list table
											cout << "\n============== YOUR PURCHASE LIST ==============\n" << endl << pldisplay[0] << endl;
											cout << "| Category / Movie |  A  |  B  |  C  |  Total  |" << endl << pldisplay[0] << endl;
											for(i = 0; i < 4; i++){
												cout << "| " << setw(16) << left << category[i] << " | ";
													for(j = 0; j < 3; j++)
														cout << setw(2) << right << ticketamt[i][j] << "  | ";
												cout << setw(6) << categoryt[i] << "  |" << endl;
											}
											cout << pldisplay[0] << endl << "| Total Tickets    | " << setw(2) << moviet[0] << "  | " << setw(2) << moviet[1]
												 << "  | " << setw(2) << moviet[2] << "  | " << setw(6) << tickett << "  |" << endl << pldisplay[0] << endl;
											
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
												
													if(cin.fail()){
														row = 0;
														cin.clear();				// clear input buffer
														cin.ignore(INT_MAX, '\n'); 	// ignore last input
													}
													// validate input
													if(row < 1 || row > 4)
														cout << error[0] << endl;
												}
												while(row < 1 || row > 4);
												// record row
												i = row;
												
												do{
													cout << "\nPlease enter the column(movie) that you wish to deduct the amount." << endl;
													cin >> col;
													
													if(cin.fail()){
														col = 0;
														cin.clear();				// clear input buffer
														cin.ignore(INT_MAX, '\n'); 	// ignore last input
													}
													// validate input
													if(col < 1 || col > 3)
														cout << error[0] << endl;
												}
												while(col < 1 || col > 3);
												// record column
												j = col;
												
												// validate availability
												if(ticketamt[i - 1][j - 1] == 0){
													cout << error[2] << endl;
													}
												else if(ticketamt[i - 1][j - 1] > 0){
													do{
														cout << "Enter the amount of ticket that you wish to deduct: ";
														cin >> tdeduct;
														
														if(cin.fail()){
															tdeduct = -1;
															cin.clear();				// clear input buffer
															cin.ignore(INT_MAX, '\n'); 	// ignore last input
														}
														if(tdeduct < 0)
															cout << error[0] << endl;
														else if(ticketamt[i - 1][j - 1] - tdeduct < 0){
															cout << error[3] << endl;
															tdeduct = -1;
														}
														else{
															ticketamt[i - 1][j - 1] -= tdeduct;
															categoryt[i - 1] -= tdeduct;
															moviet[j - 1] -= tdeduct;
															ticket2[j] += tdeduct;
															
															// prevent overwrite
															tickett = 0;
															for(i = 0; i < 4; i++)
																for(j = 0; j < 3; j++)
																	tickett += ticketamt[i][j];		// calculate total tickets selected after deduction
															
															// display purchase list table
															cout << "\n============== YOUR PURCHASE LIST ==============\n" << endl << pldisplay[0] << endl;
															cout << "| Category / Movie |  A  |  B  |  C  |  Total  |" << endl << pldisplay[0] << endl;
															
															for(i = 0; i < 4; i++){
																cout << "| " << setw(16) << left << category[i] << " | ";
																	for(j = 0; j < 3; j++)
																		cout << setw(2) << right << ticketamt[i][j] << "  | ";
																cout << setw(6) << categoryt[i] << "  |" << endl;
															}
															cout << pldisplay[0] << endl << "| Total Tickets    | " << setw(2) << moviet[0] << "  | " << setw(2) << moviet[1]
																 << "  | " << setw(2) << moviet[2] << "  | " << setw(6) << tickett << "  |" << endl << pldisplay[0] << endl;
															
															if(tickett > 0){
																do{
																	// user choose either back to main menu or enter calculator
																	cout << "\n======================= PROCEED =========================\n" << endl << pdisplay << endl;
																	cout << "| " << setw(45) << left << "Proceed To..." << " | Enter |" << endl << pdisplay << endl << pdisplay << endl;
																	cout << "| " << setw(45) << left << proceedm[6] << " |  'C'  |" << endl << pdisplay << endl;
																	cout << "| " << setw(45) << left << proceedm[7] << " |  'N'  |" << endl << pdisplay << endl;
																	
																	cout << "\nPlease enter your selection: ";	
																	cin >> proceed;
																	cin.ignore(numeric_limits<streamsize>::max(), '\n');
																		
																	switch(proceed){
																		case 'c':
																		case 'C':	deduct = true;
																					con = true;
																					break;
																		case 'n':
																		case 'N':	deduct = false;
																					con = true;
																					break;
																		default:	cout << error[0] << endl;
																					con = false;
																	}
																}
																while(con == false);
															}
															else if(tickett == 0){
																deduct = false;
																proceed = 'X';
																block2 = true;
															}
														}
													}
													while(tdeduct < 0);
												}
											}
											// force back to ask for proceed
											proceedv = false;
										}
									}
									while(proceedv == false);
								}
								while(proceed == 'T' || proceed == 't');
										
									// enter payment area
									while(confirm == true){
											// recalculate to prevent ovrwrite
											for(i = 0; i < 4; i++){
												tickett = 0;
												categoryt[i] = 0;
												moviet[i] = 0;
											}
											for(i = 0; i < 4; i++)
												for(j = 0; j < 3; j++){
													tickett += ticketamt[i][j];			// calculate total tickets selected
													categoryt[i] += ticketamt[i][j];	// calculate total tickets selected per category
													moviet[j] += ticketamt[i][j];		// calculate total tickets for the movie
												}
										// update tickets left to main ticket array
										for(i = 0; i < 3; i++)
											ticket[i] -= moviet[i];
											
										// calculate total for every category		
										for(i = 0; i < 4; i++)
											total[i] = categoryt[i] * categoryp[i];
										if(categoryt[0] > 5)
											total[0] *= discount[0];
										else if(categoryt[1] > 5)
											total[1] *= discount[1];
													
										for(i = 0; i < 4; i++)
											gtotal += total[i];
										
										// display payment statement table
										cout << "\n======================= YOUR PAYMENT STATEMENT ==========================\n" << endl << pldisplay[1] << endl;
										cout << "| Category / Movie |  A  |  B  |  C  | Amount | Price(RM) |  Total(RM)  |" << endl << pldisplay[1] << endl;				
										for(i = 0; i < 4; i++){			
											cout << "| " << setw(16) << left << category[i] << " | ";
											for(j = 0; j < 3; j++)
												cout << setw(2) << right << ticketamt[i][j] << "  | ";		
												cout << setw(6) << categoryt[i] << " | ";
												cout << setw(9) << categoryp[i] << " | ";
												cout << setw(10) << total[i] << "  |" << endl;
										}
										cout << pldisplay[1] << endl << "| Grand Total      | " << setw(2) << moviet[0] << "  | " << setw(2) << moviet[1] << "  | " << setw(2)
											 << moviet[2] << "  | " << setw(6) << tickett << " |           | " << setw(10) << gtotal << "  |" << endl << pldisplay[1] << endl;
										cout << "\nThe total amount that you need to pay for " << tickett << " tickets is: RM " << gtotal << endl;
											
										// user choose payment method
										// will not run payment details validation
										do{
											cout << "\n======= PAYMENT METHOD =======\n" << endl << pldisplay[2] << endl;
											cout << "| No. | Method               |" << endl << pldisplay[2] << endl;
											for(i = 0; i < 5; i++)
												cout << tablec[i] << setw(20) << left << paym[i] << " |" << endl;
											cout << pldisplay[2] << endl;
												
											cout << "\nPlease choose a payment method to proceed: ";
											cin >> pmethod;
												
											// prevent infinite loop if char entered 
											if(cin.fail()){
												pmethod = 0;
												cin.clear();				// clear input buffer
												cin.ignore(INT_MAX, '\n'); 	// ignore last input
											}
											if(pmethod < 1 || pmethod > 5)
												cout << error[0] << endl;
										}
										while(pmethod < 1 || pmethod > 5);	
										
										// will not validate specifically here	
										do{
											cout << "\nPayment successful? 'Y' or 'N'" << endl;
											cin >> psuc;
											cin.ignore(numeric_limits<streamsize>::max(), '\n');
											
											switch(psuc){
												case 'y':
												case 'Y':	psucv = true;
															break;
												case 'n':
												case 'N':	cout << error[4] << endl;
															psucv = false;
															break;
												default:	cout << error[0] << endl;
															psucv = false;
											}
										}
										while(psucv == false);
										
										// create receipt
										receipttxt = receipt + to_string(customer) + ".txt";
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
										fout << "---------------------------------------------------------------------------\n\n\n";
										// fetch current date/time based on current system for receipt
										time_t currentt = time(0);
										// convert currentt to string form
										char* dt = ctime(&currentt);
										fout << "Payment made at " << dt << endl;
										fout << "Payment method: " << paym[pmethod - 1] << "\n\n\n";
										fout << ">>>>>>>>>>>>>>>>>>>>>> THANK YOU FOR YOUR PURCHASE! <<<<<<<<<<<<<<<<<<<<<<<" << endl;
										fout << ">>>>>>>>>>>>>>>>>>>>> HOPE YOU ENJOY YOUR MOVIE DAY! <<<<<<<<<<<<<<<<<<<<<<" << endl;	// end of receipt
											
										for(i = 0; i < 4; i++)
											for(j = 0; j < 3; j++)
												if(ticketamt[i][j] > 0)
													for(k = ticketamt[i][j]; k > 0; k--){
														printt++;
														// able to print multiple tickets
														tickettxt = printtick + to_string(printt) + ".txt";
														// create ticket
														ofstream fout(tickettxt);
														fout << setprecision(2) << fixed;
														for(l = 0; l < 2; l++){
															for(m = 0; m < 56; m++)
																fout << "=";
															fout << endl;
														}
														fout << "\n  TICKET   FOR   INTI   COLLEGE   PENANG   MOVIE   DAY\n\n";
														for(l = 0; l < 56; l++)
															fout << "=";
														fout << "\n\n" << setw(20) << left << "Ticket ID" << " : " + printtick2 + to_string(printt) << endl;
														fout << setw(20) << left << "Movie Name" << " : " + movie[j] << endl;
														fout << setw(20) << left << "Movie Subtitle" << " : " + subt << endl;
														fout << setw(20) << left << "Movie language" << " : " + lang[i] << endl;
														fout << setw(20) << left << "Date" << " : " + date << endl;
														fout << setw(20) << left << "Movie Duration" << " : " + dur << endl;
														fout << setw(20) << left << "Start time" << " : " + stime << endl;
														fout << setw(20) << left << "End time" << " : " + etime << endl;
														fout << setw(20) << left << "Category" << " : " + category[i] << endl;
														fout << setw(20) << left << "Price per Ticket" << " : RM " << categoryp[i] << "\n\n";
														for(l = 0; l < 2; l++){
															for(m = 0; m < 56; m++)
																fout << "=";
															fout << endl;
														}
													}
										cout << "\nYour receipt (" << receipttxt << ") had been generated.\n" << endl;
										cout << "All of your " << tickett << " tickets had been generated.\n" << endl;
										cout << "Thank you for visiting and enjoy your movie day!\n" << endl;
										welcome = true;
											
										// escape while loop
										confirm = false;
										for(i = 0; i < 4; i++){
											acccategoryt[i] += categoryt[i];
											categoryt[i] = 0;
											for(j = 0; j < 3; j++){
												accticketamt[i][j] += ticketamt[i][j];
												accmoviet[j] += moviet[j];
												ticketamt[i][j] = 0;
												moviet[j] = 0;
											}
										}
										tickett = 0;
										acctotal += gtotal;	// update accumulated total
										gtotal = 0;
										pmethod = 0;
										customer++;
									}
								proceed = 'X';
								break;		
					case 'a':
					case 'A':	cout << "\n================ ADMINISTRATOR =================\n" << endl << pldisplay[0] << endl;
								cout << setw(33) << left << "| Total Customers: " << " | " << setw(10) << right << customer - 1 << " |\n" << pldisplay[0] << endl;
								cout << setw(33) << left << "| Total Earnings (RM): " << " | " << setw(10) << right << acctotal << " |\n" << pldisplay[0] << endl;
								cout << "\n-------------- TOTAL TICKETS SOLD --------------\n" << pldisplay[0] << endl;
								cout << "| Category / Movie |  A  |  B  |  C  |  Total  |" << endl << pldisplay[0] << endl;
								for(i = 0; i < 4; i++){
									cout << "| " << setw(16) << left << category[i] << " | ";
									for(j = 0; j < 3; j++)
										cout << setw(2) << right << accticketamt[i][j] << "  | ";
										cout << setw(6) << acccategoryt[i] << "  |" << endl;
								}
								cout << pldisplay[0] << endl << "| Total Tickets    | ";
								for(i = 0; i < 3; i++)
									cout << setw(2) << right << accmoviet[i] << "  | ";
								cout << setw(6) << accmoviet[0] + accmoviet[1] + accmoviet[2] << "  |" << endl << pldisplay[0] << endl;
								
								do{
									cout << "\nDo you want to print a copy? Enter 'Y' or 'N'" << endl;
									cin >> pcopy;
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									
									switch(pcopy){
										case 'Y':
										case 'y':
										case 'N':
										case 'n':	pcopyv = true;
													break;
										default :	cout << error[0] << endl;
													pcopyv = false;
									}
								}
								while(pcopyv == false);
								welcome = true;
								break;
					default:	cout << error[0] << endl;
				}
				menuv = false;
				
				if(ticket[0] == 0 && ticket[1] == 0 && ticket[2] == 0)
					menuv = true;
				// print while admin want a copy or system end
				if(pcopy == 'Y' || pcopy == 'y' || (ticket[0] == 0 && ticket[1] == 0 && ticket[2] == 0)){
					copy++;
					copytxt = "AdminCopy"+ to_string(copy) + ".txt";
					ofstream fout(copytxt);
					fout << setprecision(2) << fixed;
					fout << "\n================ ADMINISTRATOR =================\n" << endl << pldisplay[0] << endl;
					fout << setw(33) << left << "| Total Customers: " << " | " << setw(10) << right << customer - 1 << " |\n" << pldisplay[0] << endl;
					fout << setw(33) << left << "| Total Earnings (RM): " << " | " << setw(10) << right << acctotal << " |\n" << pldisplay[0] << endl;
					fout << "\n-------------- TOTAL TICKETS SOLD --------------\n" << pldisplay[0] << endl;
					fout << "| Category / Movie |  A  |  B  |  C  |  Total  |" << endl << pldisplay[0] << endl;
					for(i = 0; i < 4; i++){
						fout << "| " << setw(16) << left << category[i] << " | ";
						for(j = 0; j < 3; j++)
							fout << setw(2) << right << accticketamt[i][j] << "  | ";
							fout << setw(6) << acccategoryt[i] << "  |" << endl;
					}
					fout << pldisplay[0] << endl << "| Total Tickets    | ";
					for(i = 0; i < 3; i++)
						fout << setw(2) << right << accmoviet[i] << "  | ";
					fout << setw(6) << accmoviet[0] + accmoviet[1] + accmoviet[2] << "  |" << endl << pldisplay[0] << endl;
					
					cout << "\nYour copy (" << copytxt << ") had been generated.\n" << endl;
				}
		}  
		while(menuv == false && welcome == false);
	// always redirect back to welcome page if previous customer had done a payment
	}
	while(menuv == false && welcome == true);
	
	// final output while all tickets sold out
	cout << "\n\n";
	cout << " ******************************************************************************************* \n";
	cout << "                     Unfortunately All Tickets Had Been Sold Out !                           \n";
	cout << "                                                                                             \n";
	cout << "  Thank You for Approaching to the INTI College Penang Movie Day Ticket Purchasing System !  \n";
	cout << " ******************************************************************************************* \n";
		
	return 0; 
}
