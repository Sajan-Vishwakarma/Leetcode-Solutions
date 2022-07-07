// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
    bool brainGame(vector<int>nums) {
        
        vector<int> a(1005);
    	for(int i = 2; i<= 1000; i++){
    		for(int j = 2*i; j <= 1000; j+=i)
    			a[j] = max(a[j], 1 + a[i]);
    	}
    	int x = 0;
    	for(int i = 0; i < nums.size(); i++){
    		x = x ^ a[nums[i]];
    	}
    	if(x == 0)
    		return false;
    	return true;
          
    }
};


/*
Very good problem, but the Editorial was not helpful.

Here is my solution.
The first question to answer is whether we care about all factors
or just prime factors. My solution only calculates the number of
prime factors. Let us look at 36, for example. It has four prime
factors: 2, 2, 3, 3. If a player chooses this number, he can
reduce the number to 12 or 18 (3 prime factors), 4 or 6 or 9 (2 prime
factors) or 2 or 3 (1 prime factor). So 36 starts with 4 prime factors
and eventually, it will go down to 1 prime factor. Once the number
is prime, you can never choose it again.

Note that if we start with all numbers prime, player A will lose.
If we start with 1 non prime number, player A, will remove
all of its prime factors except one and make it prime. So
if we start, with 36, player A will change it to either 2 or 3 and win.
If we start with 2 non prime numbers, it will depend if the 2 numbers
have the same number of prime factors. If they have the same
number of prime factors, player B will win by copying the same
moves player A makes, but on the other number. For example,
16 and 81 both have 4 prime factors. If Player A takes away
2 prime factors from 81 (making it 9), Player B will take away
2 prime factors from 16 (making it 4). Now Player A can choose
either 4 or 9, remove one prime factor and Player B will choose
the other number, remove one prime factor and Player B will win.
So two numbers with the same number of prime factors will cancel
each other out. If we start with 2 non prime numbers, and they have
a different number of prime factors, then Player A will choose the
number with the greater number of prime factors, remove enough
prime factors so it will have the same number of prime factors as
the other number, and now these two numbers cancel each other
out, but now Player A wins because it will be Player B's turn.

The first thing my algorithm did was to calculate the number of prime
factors for all the numbers from 1 to 1000. Since the biggest number
is only 1000, the most prime factors a number can have is 9. (There
are 2 numbers, 512 = 2 ^9 and 768 = 3 * 2^8 with 9 prime factors.)

Now I read the n numbers. If the number is prime, I skip it because
it can never be chosen by Player A or B. All other numbers will have
between 2 to 9 prime factors, so if the number has (for example) 4
prime factors, I will increment arr[4] by 1. After reading all the numbers,
if there are an even number of numbers with x prime factors, these
will cancel each other out, so I disregard them. So for example, if we
have 7 numbers, 17, 21, 77, 15, 64, 30, 105.
17 is prime so skip it
21 has 2 prime factors
77 has 2 prime factors
15 has 2 prime factors
64 has 6 prime factors
30 has 3 prime factors
105 has 3 prime factors

So we have 3 numbers with 2 prime factors and 1 number with 6 prime factors.
For the 3 numbers with 2 prime factors, two will cancel each other so we
are left with 1 number with 2 prime factors. Similarly, the 2 numbers with
3 prime factors cancel each other out. We also have 1 number with 6 prime
factors. After getting rid of the numbers that do not matter we are left with
15 (2 prime factors) and 64 (6 prime factors). Player A will pick 64 and
change it to 4 (which has 2 prime factors). Player B can pick either 15 or 4,
reduce it to a prime and Player will pick the other number and reduce it
to a prime. Finally, Player B will not have any moves, so Player A wins.

So each non prime number can have either 2, 3, 4, 5, 6, 7, 8 or 9 prime
factors. Since there are only 8 different values, there are only 2^8 = 256
possible states to determine if Player A or B wins. Now we can make this
into a number. The number will have 8 bits. The lowest bit will be 1 if
there are an odd number of numbers with 2 prime factors and 0 otherwise.
The next lowest bit will be 1 if there are an odd number of numbers with
3 prime factors and 0 otherwise. So in the example above, our
8 bit number is 0001 0001 (in binary) or 17 (in decimal). Since Player A
wins, I stored 0 in an ans array. The tough part is calculating the ans for
all 256 8 bit numbers.

If the 8 bit number has 0 bits (decimal 0), then Player A can not move
and Player B wins. If the 8 bit number has only 1 bit (decimal 1, 2, 4, 8, 16,
32, 64, or 128) then Player A will win. If the 8 bit number has 2 bits (for
example 3, 5, 6, 9, 10, 12, 17, etc), then Player A will win. Now the smallest
8 bit number with 3 bits is 7, which would correspond a test case like
4, 8 and 16. Player A will try all possible moves, and if he can leave
Player B with a lost position, then Player A will win, but if each move
leaves Player B with a won position, then Player B will win. In this case
with the 8 bit number equal to 7, Player B will win. Here are all possible moves

{ 16, 8, 4 } Player A picks 4 and changes it to 2
{ 16, 8 } Player B picks 16 and changes it to 8, B wins

{ 16, 8, 4 } Player A picks 8 and changes it to 4
{ 16 } Player B picks 16 and changes it to 2 B wins

{ 16, 8, 4 } Player A picks 8 and changes it to 2
{ 16, 4 } Player B picks 16 and changes it to 4 B wins

{ 16, 8, 4 } Player A picks 16 and changes it to 8
{ 4 } Player B picks 4 and changes it to 2 B wins

{ 16, 8, 4 } Player A picks 16 and changes it to 4
{ 8 } Player B picks 8 and changes it to 2 B wins

{ 16, 8, 4 } Player A picks 16 and changes it to 2
{ 8, 4 } Player B picks 8 and changes it to 4 B wins

I hope this helps.
*/

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		bool ans = ob.brainGame(nums);
		if(ans)
			cout << "A\n";
		else cout << "B\n";
	}  
	return 0;
}  // } Driver Code Ends