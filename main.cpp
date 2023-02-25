#include <iostream>
#include <stdexcept>
#include "fraction.h"

using namespace std;

int main()
{
    /* Class to manage fractions */

    // Create a fraction
    fraction a(2, 3);

    // Print a fraction
    cout << "My first fraction: " << a << endl;

    // Create a negative fraction
    fraction b(-3, 4), c(3, -4); // both fractions are the same (symbols get fixed automatically)
    cout << "\n\n\nNegative fractions: " << b << " & " << c << endl;
    fraction d(-3, -4); // this will result in a positive fraction
    cout << "Symbols get fixed: " << d << endl;

    // Create a fraction with doubles or floats
    fraction e(2.54); // this will result in 127 / 50
    cout << "\n\n\nCreated from double: " << e << endl;
    a = 0.5;
    cout << "You can also asign a double later: " << a << endl;
    // you can also convert any double to fraction with the fraction object
    cout << "Convert double to fraction: " << e.to_fraction(3.43) << endl; // this returns a new fraction

    // Get the Greatest Common Divisor of two numbers
    fraction f(230, 454);
    cout << "\n\n\nGCD of 230 and 454: " << f.gcd(230, 454) << endl;

    // Simplify the fraction itself
    cout << f << " simplified is: ";
    f.simplify();
    cout << f << endl;

    // Perform calculations
    cout << "\n\n\nPerform Calculations (fraction and fraction)" << endl;
    fraction result;
    result = a + b;
    cout << a << "\t  +\t" << b << "\t   =\t" << result << endl;
    result = a - b;
    cout << a << "\t  -\t" << b << "\t   =\t" << result << endl;
    result = a * b;
    cout << a << "\t  *\t" << b << "\t   =\t" << result << endl;
    result = a / b;
    cout << a << "\t  /\t" << b << "\t   =\t" << result << endl;

    cout << "\nYou can also perform calculations with doubles (fraction and double)" << endl;
    double example = 2.476;
    result = a + example;
    cout << a << "\t  +\t" << example << "\t   =\t" << result << endl;
    result = a - example;
    cout << a << "\t  -\t" << example << "\t   =\t" << result << endl;
    result = a * example;
    cout << a << "\t  *\t" << example << "\t   =\t" << result << endl;
    result = a / example;
    cout << a << "\t  /\t" << example << "\t   =\t" << result << endl;

    cout << "\nOr the other way around (double and fraction)" << endl;
    result = example + a;
    cout << example << "\t  +\t" << a << "\t   =\t" << result << endl;
    result = example - a;
    cout << example << "\t  -\t" << a << "\t   =\t" << result << endl;
    result = example * a;
    cout << example << "\t  *\t" << a << "\t   =\t" << result << endl;
    result = example / a;
    cout << example << "\t  /\t" << a << "\t   =\t" << result << endl;

    cout << "\nPerform calculations with assignment operators (fraction and fraction)" << endl;
    cout << "`a` is its own value: " << a << "\t  +\t" << b << " resulting in: ";
    a += b;
    cout << a << endl;
    cout << "`a` is its own value: " << a << "\t  -\t" << b << " resulting in: ";
    a -= b;
    cout << a << endl;
    cout << "`a` is its own value: " << a << "\t  *\t" << b << " resulting in: ";
    a *= b;
    cout << a << endl;
    cout << "`a` is its own value: " << a << "\t  /\t" << b << " resulting in: ";
    a /= b;
    cout << a << endl;

    cout << "\nYou can also do it with doubles (fraction and double)" << endl;
    cout << "`a` is its own value: " << a << "\t  +\t" << example << " resulting in: ";
    a += example;
    cout << a << endl;
    cout << "`a` is its own value: " << a << "\t  -\t" << example << " resulting in: ";
    a -= example;
    cout << a << endl;
    cout << "`a` is its own value: " << a << "\t  *\t" << example << " resulting in: ";
    a *= example;
    cout << a << endl;
    cout << "`a` is its own value: " << a << "\t  /\t" << example << " resulting in: ";
    a /= example;
    cout << a << endl;

    cout << "\nOr the other way around (double and fraction)" << endl;
    cout << "`example` is its own value: " << example << "\t  +\t" << a << " resulting in: ";
    example += a;
    cout << example << endl;
    cout << "`example` is its own value: " << example << "\t  -\t" << a << " resulting in: ";
    example -= a;
    cout << example << endl;
    cout << "`example` is its own value: " << example << "\t  *\t" << a << " resulting in: ";
    example *= a;
    cout << example << endl;
    cout << "`example` is its own value: " << example << "\t  /\t" << a << " resulting in: ";
    example /= a;
    cout << example << endl;

    cout << "\nWhen you perform calculations with a double on the left side of the operator" << endl;
    cout << "the fraction is converted into a double automatically, but you can do this yourself" << endl;
    cout << "by calling the to_double method" << endl;
    cout << "fraction " << a << " converted to double is: " << a.to_double() << endl;
    cout << "you also have a to_float method" << endl;
    cout << "fraction " << a << " converted to float is: " << a.to_float() << endl;

    cout << "\n\nYou can also compare fractions" << endl;
    if (a == b)
    {
        cout << a << " is equal to " << b << endl;
    }
    if (a != b)
    {
        cout << a << " is different than " << b << endl;
    }
    if (a < b)
    {
        cout << b << " is greater than " << a << endl;
    }
    if (a > b)
    {
        cout << a << " is greater than " << b << endl;
    }
    if (a <= b)
    {
        cout << b << " is greater than or equal to " << a << endl;
    }
    if (a >= b)
    {
        cout << a << " is greater than or equal to " << b << endl;
    }

    cout<<"\nAll the operations we\'ve done so far with double and fraction you can also"<<endl;
    cout<<"do them with type \'float\' and \'int\'"<<endl;
    
    cout<<"\nYou can also use the assignment operator with all these types"<<endl;
		fraction convert_to_types(10, 3);
		double example_d = 2.456;
		float example_f = 2.5;
		int example_i = 2;
		
		example_d = convert_to_types;
		cout<<convert_to_types<<" stored in a double is: "<<example_d<<endl;
		example_f = convert_to_types;
		cout<<convert_to_types<<" stored in a float is: "<<example_f<<endl;
		example_i = convert_to_types;
		cout<<convert_to_types<<" stored in an int is: "<<example_i<<endl;
    
    
    // Handle exceptions
    try
    {
        fraction error(1, 0);
    }
    catch (invalid_argument &e)
    {
        cout << endl;
        cout << e.what() << endl;
        return 1;
    }
    return 0;
}
