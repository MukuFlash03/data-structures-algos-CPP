
            if (k == 0 || k == 2 * i - 2) 
                cout << "#"; 
            else
                cout << " "; 
            k++; 
            ; 
        } 
		k = 0; 
		cout << endl;
	} 
	
	for (j = 1; i < 2*n-1; j++) // Print last row 
		cout << "*";
}

int main()
{
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    printPattern(n);
}