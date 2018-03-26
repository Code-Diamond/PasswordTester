#include <iostream>

using namespace std;

int main()
{
    char continuation = 'y';

    while(continuation == 'y' || continuation == 'Y')
    {
        //Create character arrays
        char numbers[10] = {'0','1','2','3','4','5','6','7','8','9'};
        char lowerCase[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        char upperCase[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
        char specialChar[12] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};

        //Create an array that will be deleted after determining password length;
        char *password = new char[1000];

        //Set every element to escape sequence first
        for(int i = 0; i < 1000; i++)
        {
            password[i] = '\n';
        }

        //Prompt user for valid entry
        cout << "Welcome to password strength tester.\n  This program takes a password of up to \n    1000 characters and tests to see if it has:\n\n -At least 12 characters.\n -Contains one digit.\n -Contains one lowercase character.\n -Contains one uppercase character.\n -Contains at least one special character. (!@#$%^&*()-+)\n\n";
        //Change the password char array to have each
        cout << "Enter a password:", cin >> password;


        //The following yields the array size + 1, so start at 0 then subtract afterwards
        int size = 0;
        while(password[size] != '\n')
        {
            size++;
        }

        //Get the real size by subtracting 1
        size--;

        cout << "The length of the password is: " << size << "." << endl;

        //Create a new password array
        char realPassword[size];
        for(int i =0; i < size; i++)
        {
            realPassword[i] = password[i];
        }

        //Free the space created from the password array
        delete[] password;

        /*UNCOMMENT FOR FUNCTIONALITY/TESTING
            //Test the password array to ensure it is destroyed
            for(int i =0; i < 1000; i++)
            {
                    cout << password[i] << endl;
            }
        */

        /*UNCOMMENT FOR FUNCTIONALITY/TESTING
            //Print out new password array
            for(int i =0; i < size; i++)
            {
                cout << "You entered: " << realPassword[i] << "." << endl;
            }
        */

        //Create a boolean to represent strength
            //0 - size , 1 - one digit, 2 - lowercase, 3 - uppercase, 4 - special character
        bool strength[5] = {false, false, false, false, false};

        //Check to see if the password is at least 12 characters long
        if(size >= 12)
        {
            strength[0] = true;
        }

        //Check to see if the password has a number/digit in it
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if(realPassword[i] == numbers[j])
                {
                    strength[1] = true;
                }
            }
        }

        //Check password for a lowercase character
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                if(realPassword[i] == lowerCase[j])
                {
                    strength[2] = true;
                }
            }
        }

        //Check password for an uppercase character
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                if(realPassword[i] == upperCase[j])
                {
                    strength[3] = true;
                }
            }
        }

        //Check password for a special character
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < 12; j++)
            {
                if(realPassword[i] == specialChar[j])
                {
                    strength[4] = true;
                }
            }
        }

        //Inform user based on missing criteria
        if(!strength[0])
        {
            cout << "-Your password is less than 12 characters long!" << endl;
        }
        if(!strength[1])
        {
            cout << "-Your password does not have a number in it!" << endl;
        }
        if(!strength[2])
        {
            cout << "-Your password does not have a lowercase character in it!" << endl;
        }
        if(!strength[3])
        {
            cout << "-Your password does not have an uppercase character in it!" << endl;
        }
        if(!strength[4])
        {
            cout << "-Your password does not have a special character in it!" << endl;
        }

        //If user has met all criteria, inform user the password is strong.
        if(strength[0] && strength[1] && strength[2] && strength[3] && strength[4])
        {
            cout << "\nYour password meets all strength criteria, good job!\n" << endl;
        }

        cout << "\nWould you like to continue? (y/n): ", cin >> continuation, cout << "\n\n\n\n\n";


    }//End of while loop


    return 0;
}
