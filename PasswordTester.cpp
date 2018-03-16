#include <iostream>

using namespace std;

int main()
{
	char numbers[10] = {'0','1','2','3','4','5','6','7','8','9'};
	char lowerCase[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char upperCase[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	char specialChar[12] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};
    
    char password[256];
    cout << "Welcome to password strength tester.\nThis program takes a password of up to 256 characters and tests to see if it has:\nAt least 6 characters.\nContains one digit.\nContains one lowercase character.\nContains at least one special character. (!@#$%^&*()-+)\n\n";
    
	cout << "Enter a password:", cin >> password;
    
    
    for(int i = 0; i < 256; i++)
    {
        cout << password[i] << "\n";
    }
    
    return 0;
}
