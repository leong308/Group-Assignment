#include <iostream> 
#include <iomanip> 
using namespace std; 

int main() 
{ 
        // declare variables
		char mlist, proceed, mdetail;
        unsigned int space;
        string movA, movB, movC;
        
        // declare values into var
    	movA = "Movie A";
    	movB = "Movie B";
    	movC = "Movie C";

        // infinite loop while not Y or N
        do{
            cout << "Movie list? Y or N" << endl;
            cin >> mlist;  

            if(mlist != 'Y' && mlist != 'N')
                cout << "Invalid input. Please try again.\n" << endl;
            
				// Y or N condition    
	            switch(mlist)
	        	{
	        		// display movie list
		            case 'Y':   cout << "1. " << movA << endl;
		            			cout << "2. " << movB << endl;
		            			cout << "3. " << movC << endl;
		            			
			            			do{
			            				cout << "Enter the number of a movie for more details." << endl;
			            				cin >> mdetail;
									}
									while(mdetail < 1 && mdetail > 3);
								
										switch(mdetail)
										{
											case 1:		cout << "1. " << movA << endl;
														cout << "Date : 12//12//2022" << endl;
														cout << "Start time: 19:00" << (space = 20) << "End time: 21:00" << endl;
														break;
										}
		                        break;
		            
					// ask whether user want to proceed or back to selection           
		            case 'N':	do{
		            				cout << "\nPress P if you want to proceed to payment.\nor" << endl;
		            				cout << "Press B if you want to go back." << endl;
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
