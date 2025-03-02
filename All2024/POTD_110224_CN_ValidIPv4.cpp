
// 021124
// Valid IPv4 address or not. (need to check and update the code.)

#include <iostream>
using namespace std;

int getDigit(string num)
{
	int digit = 0;
	//for(int i=num.length()-1; i>=0; i--)
	for(int i=0; i<num.length(); i++)
	{
		digit = (digit*10) + (int)(num[i] - '0');
	}
	return digit;
}

bool isValidIPv4(string ipAddress) {

    ipAddress += '.';
    int len = ipAddress.length();

	int decimal_count = 0;

    string str;
    for(int i = 0; i<len; i++)
    {
        if(ipAddress[i] != '.'){
            str += ipAddress[i];
        }
        else{
			decimal_count++;
			if(decimal_count > 4)
				return false;

            // First checking if it is not a digit.
            for(int j = 0; j<str.length(); j++)
            {
                if( !(str[j] >= '0' and str[j] <= '9'))
                    return false;
            }

            //Getting the digit.
            int num = getDigit(str);

            // Checking if it is in the range.
            if( !(num >=0 && num<=255))
                return false;

			str = "";
        }
	}

	if(decimal_count != 4)
		return false;
    return true;
}


bool isDigit(string str)
{
	for(int i = 0; i<str.length(); i++)
	{
		if (!(str[i] >= '0' and str[i] <='9') )
			return false;
	}
	return true;
}

int main(void)
{

	int n;
	cout << "Test case Count : ";
	cin >> n;
	string *ips = new string[n];

	for(int i=0; i<n; i++)
	{
		cout << "Case " << i+1 << " : ";
		cin >> ips[i];
	}

	bool result;
	for(int i=0; i<n; i++)
	{
		result = isValidIPv4(ips[i]);
		cout << (result ? "True\n" : "False\n");
	}

	/*
	string ipv4 = "10.10.10.10";
	bool result = isValidIPv4(ipv4);
	cout << result << endl;
	//*/

//	cout << ascii_to_num("10") << endl;

//	cout << isDigit("41r1") << endl;
}
