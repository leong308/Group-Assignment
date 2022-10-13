#include <iostream> 
#include <iomanip> 
using namespace std; 

int main() 
{ 
        char mlist;
        unsigned int space;

        // infinite loop while not Y or N
        do{
            cout << "Movie list?" << endl;
            cin >> mlist;  

            if(mlist != 'Y' && mlist != 'N')
                cout << "Invalid input. Please try again.\n" << endl;
        }  
        while(mlist != 'Y' && mlist != 'N');
          
        switch(mlist)
        {
            case 'Y':   
                        break;
            case 'N':
                        break;
        }


        return 0; 
          
}
