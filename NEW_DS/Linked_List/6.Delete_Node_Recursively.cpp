/*
Problem Statement: 
Given a singly linked list of integers and position 'i', delete the node present at the 'i-th' position in the linked list recursively.

Input Format: 
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains a single integer depicting the value of 'i'.

Output Format: 
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.

Constraints: 
1 <= t <= 10^2
0 <= M <= 10^5
Where M is the size of the singly linked list.
0 <= i < M

Time Limit:  1sec

Sample Input1:
1
3 4 5 2 6 1 9 -1
3 

Sample Output1: 
3 4 5 6 1 9

Sample Input1: 
2
30 -1
0
10 20 30 50 60 -1
4

Sample Output2: 
10 20 30 50 
*/ 

