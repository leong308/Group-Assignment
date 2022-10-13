#include <iostream> 
#include <iomanip> 
#include <string>
using namespace std; 

int main() 
{ 
        // declare variables
		char mlist, proceed;
        string movA, movB, movC, date, stime, etime;
        unsigned int space;
        int mdetail, ticket1, ticket2, ticket3;
        
        // declare values into var
    	movA = "Movie A";
    	movB = "Movie B";
    	movC = "Movie C";
    	date = "Date: 12/12/2022";
    	stime = "Start time: 19:00";
    	etime = "End time: 21:30" ;
		ticket1 = 100, ticket2 = 100, ticket3 = 100;
		
		cout << "Welcome!" << endl;
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
			            					
			            				switch(mdetail)
										{
											case  1:	cout << endl << movA << endl << date << endl;			// movieA name and date
														cout << stime << setw(space = 20) << etime << endl;		// start and end time
														cout << "Seats left: " << ticket1 << endl;				// seats left
														break;
											case  2:    cout << endl << movB << endl << date << endl;			// movieB name and date
														cout << stime << setw(space = 20) << etime << endl;		// start and end time
														cout << "Seats left: " << ticket2 << endl;				// seats left
														break;
											case  3:	cout << endl << movC << endl << date << endl;			// movieB name and date
														cout << stime << setw(space = 20) << etime << endl;		// start and end time
														cout << "Seats left: " << ticket3 << endl;				// seats left
														break;
											default:	cout << "\nInvalid input. Please try again." << endl;
														break;
										}	
										
										// infinite loop if proceed != P or B
										do{
		            						cout << "\nPress P if you want to proceed to payment." << endl;
		            						cout << "Press B if you want to go back to menu." << endl;
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
		            				cout << "\nPress P if you want to proceed to payment." << endl;
		            				cout << "Press B if you want to go back to menu." << endl;
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

        return 0; 
          
}
