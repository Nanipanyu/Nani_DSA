#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> 
using namespace std;
//Q) place N queen in N X N chessboard safely, find all the possible sequence
//The solution is basically each row will have one queen we just need to find its safe position, and this sequence will be our result sequence

bool issafe(int x,int y,vector<vector<int>> queenseq,int n){
	bool check=true;
	for(int i=0;i<n;i++){ //check if there is any queens in the same row or same columns of [x][y], 
		for(int j=0;j<n;j++){ //iterating through all squares in chessboard
			if(i==x || j==y){
				if(queenseq[i][j]==1){
					check =false; //if there is that means it is unsafe to place the queen
					break;
				}
			}
		}
		if(check==false){
			break;
		}
	}
	if(check==true){ //if columns and rows are free , check for diagonals
		for(int i=1;i<=n;i++){
			if((x+i>=0 && x+i<n) && (y+i>=0 && y+i<n) && queenseq[x+i][y+i]==1){//if there is queen in lower right diagonal, then it is unsafe
				check=false;
			}
			if((x-i>=0 && x-i<n)&& (y+i>=0 && y+i<n)&&queenseq[x-i][y+i]==1){//if there is queen in upper right diagonal, then it is unsafe
				check=false;
			}
			if((x-i>=0 && x-i<n)&& (y-i>=0 && y-i<n)&&queenseq[x-i][y-i]==1){//if there is queen in upper left diagonal, then it is unsafe
				check=false;
			}
			if((x+i>=0 && x+i<n)&& (y-i>=0 && y-i<n)&&queenseq[x+i][y-i]==1){//if there is queen in lower left diagonal, then it is unsafe
				check=false;
			}
		}
	}
	return check; //return if it is safe or not
}

void solve(int x, int y,vector<vector<int>> queenseq,int n,vector<vector<int>> &morse){
	if (x == n) { //if it has crossed the nth row(i.e the chessboard) means it is a possible sequence  
        vector<int> solution; //flattening the sequence
        for (auto &row : queenseq) {
            for (int cell : row) {
                solution.push_back(cell);
            }
        }
        morse.push_back(solution);//storing the sequence
        return;
    }
	if (y == n) { //if for a row all column has been checked, that means no possible sequence exist so return to the previous row and try with a new column 
    	return;
	}

	if(issafe(x,y,queenseq,n)){ //check if it is safe to place the queen in [x][y] in chessboard
		queenseq[x][y]=1; //if safe place the queen and mark the box=1
		solve(x+1,0,queenseq,n,morse); // and move to next row and find a safe box for queen in that row
		queenseq[x][y] = 0; //while backtracking , the box where we placed our queen , set it back to zero, so that now we will try in the next column in the same row
	}
	solve(x,y+1,queenseq,n,morse);// if not safe in the current position(col posn) in the present row, move to next col position and check there
}

vector<vector<int>> nQueens(int n)
{
	// Write your code here
	vector<vector<int>> queenseq(n,vector<int>(n,0)); //will store the sequence of queens in nxn chessboard
	vector<vector<int>> morse;//to store all the possible sequences
	solve(0,0,queenseq,n,morse); //getting all the sequences
	return morse;
}