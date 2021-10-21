#include <iostream> 
#include <sstream>
#include <boost/lexical_cast.hpp>// for lexical_cast() 
#include <string> // for string  
using namespace std; 
  
int main() 
{   
    //String to Number Conversion
    string s = "12345"; 
    
    //Using stringstream 
    // object from the class stringstream 
    stringstream geek(s); 
  
    // The object has the value 12345 and stream 
    // it to the integer x 
    int x1 = 0; 
    geek >> x1; 
  
    // Now the variable x holds the value 12345 
    cout << "\nValue of x : " << x1 << "\n"; 

    //Using sscanf 
    const char *str = "12345"; 
    int x2; 
    sscanf(str, "%d", &x2); 
    printf("\nThe value of x : %d\n\n", x2);

    //Using stoi()
    string str1 = "45"; 
    string str2 = "3.14159"; 
    string str3 = "31337 geek"; 
  
    int myint1 = stoi(str1); 
    int myint2 = stoi(str2); 
    int myint3 = stoi(str3); 
  
    cout << "stoi(\"" << str1 << "\") is "<< myint1 << '\n'; 
    cout << "stoi(\"" << str2 << "\") is "<< myint2 << '\n'; 
    cout << "stoi(\"" << str3 << "\") is "<< myint3 << "\n\n";

    //Using atoi()
    const char *str4 = "42"; 
    const char *str5 = "3.14159"; 
    const char *str6 = "31337 geek"; 
     
    int num1 = atoi(str4); 
    int num2 = atoi(str5); 
    int num3 = atoi(str6); 
    
    cout << "atoi(\"" << str4  << "\") is " << num1 << '\n'; 
    cout << "atoi(\"" << str5  << "\") is " << num2 << '\n'; 
    cout << "atoi(\"" << str6  << "\") is " << num3 << "\n\n";
  

     //Using boost lexical cast
    string str_i = "5"; 
    string str_f = "6.5"; 
  
    // Initializing f_value with casted float 
    // f_value is 6.5 
    float f_value = boost::lexical_cast<float>(str_f); 
  
    // Initializing i_value with casted int 
    // i_value is 5 
    int i_value = boost::lexical_cast<int>(str_i); 
  
    //Displaying casted values 
    cout << "The float value after casting is : "; 
    cout << f_value << "\n" <<endl; 
    cout << "The int value after casting is : "; 
    cout << i_value << "\n" <<endl;


    //Number to String Conversion

    //Using string streams
     int num = 2016; 
  
    // declaring output string stream 
    ostringstream str10; 
  
    // Sending a number as a stream into output 
    // string 
    str10 << num; 
  
    // the str() coverts number into string 
    string geek1 = str10.str(); 
  
    // Displaying the string 
    cout << "The newly formed string from number is : "; 
    cout << geek1 << "\n" << endl;


    //Using to_string()
    
    int i_val1 = 20; // Declaring integer 
   
    float f_val1 = 30.50; // Declaring float
   
    string stri1 = to_string(i_val1); 
  
    string strf1 = to_string(f_val1); 
  
    // Displaying the converted strings 
    cout << "The integer in string is : "; 
    cout << stri1 << "\n" << endl; 
    cout << "The float in string is : "; 
    cout << strf1 << "\n" << endl;

    //Using Lexical_Cast

   float f_val2 = 10.5;  // Declaring float 
  
   int i_val2 = 17;    // Declaring int 
     
   // lexical_cast() converts a float into string 
   string strf2 = boost::lexical_cast<string>(f_val2);  
     
   // lexical_cast() converts a int into string 
   string stri2 = boost::lexical_cast<string>(i_val2);  
     
   // Displaying string converted numbers 
   cout << "The float value in string is : "; 
   cout << strf2 << "\n" << endl; 
   cout << "The int value in string is : "; 
   cout << stri2 << "\n" << endl; 

    return 0; 
}