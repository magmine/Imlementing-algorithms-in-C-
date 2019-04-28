#include <bits/stdc++.h>
using namespace std;
 
vector<vector<bool> > visited(8,vector<bool>(8,false));
 
bool is_valid(int i, int j){
	if(i < 0 || j < 0 || i > 7 || j > 7)
		return (false);
	return (true);
}
 
bool	is_possible(vector<vector<int> > &board, int i, int j)
{
	int		diag;
 
	if(!is_valid(i, j))
		return (false);
	//row validity;
	for (int col = 0; col < 8; col++)
		if(board[i][col])
			return (false);
	//col validity
	for (int row = 0; row < 8; row++)
		if(board[row][j])
			return (false);
	//first diagonal validity down;
	diag = 0;
	while (is_valid(i + diag, j + diag))
	{
		if(board[i + diag][j + diag])
			return (false);
		diag++;
	}
	//first diagonal validity up;
	diag = 0;
	while (is_valid(i - diag, j - diag))
	{
		if(board[i - diag][j - diag])
			return (false);
		diag++;
	}
	//second diagonal validity down
	diag = 0;
	while (is_valid(i + diag, j - diag))
	{
		if(board[i + diag][j - diag])
			return (false);
		diag++;
	}
	//second diagonal validity up;
	diag = 0;
	while (is_valid(i - diag, j + diag))
	{
		if(board[i - diag][j + diag])
			return (false);
		diag++;
	}
	return (true);
}
 
void	print_board(vector<vector<int> > &board)
{
	for(int i=0 ;i < 8; i++){
		for(int j=0;j < 8; j++){
			printf("| %d |",board[i][j]);
		}
		printf("\n");
	}
	printf("\n-----------------------------------------\n\n");
}
void	solve(vector<vector<int> > &board, int &nb_possi, int n_q)
{
	//printf("I am in solve\n");
	if (n_q == 8 )
	{
		nb_possi++;
		print_board(board);	
	}	
	else
	{
		for(int i = 0; i < 8; i++)
		{
				if(is_possible(board, i, n_q))
				{
					board[i][n_q] = 1;
					solve(board, nb_possi, n_q + 1);
					board[i][n_q] = 0;
				}
		}
	}
}
 
int		valid_eight_qweens(void)
{
	int		nb_possi;
	vector<vector<int> > board(8,vector <int>(8,0));
 
	nb_possi = 0;
	solve(board, nb_possi, 0);
	return (nb_possi);
}
 
int		main(int argc, char *argv[])
{
	printf("%d\n", valid_eight_qweens());
	return (0);
}
