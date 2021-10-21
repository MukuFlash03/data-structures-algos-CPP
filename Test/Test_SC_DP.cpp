int t[1024]; 

int help(int arr[], int n, int digit) 
{ 
	if (digit == 0) 		return 0; 
	if (t[digit] != -1)    return t[digit]; 

	for (int i = 0; i < n; i++) {  
        
        int temp = arr[i];
        int mask = 0; 
        while (temp) { 
            int rem = temp % 10; 
            mask |= (1 << rem); 
            temp /= 10; 
        }

		if ((mask | digit) == digit)
        { 
			t[digit] = max(max(0,t[digit ^ mask]) + arr[i], t[digit]); 
		} 
	} 

	return t[digit]; 
} 


int solve(int arr[], int n) 
{ 
	memset(t, -1, sizeof(t)); 

	int ans = 0; 

	for (int i = 0; i < (1 << 10); i++) { 
		ans = max(ans, help(arr, n, i)); 
	} 

	return ans; 
}