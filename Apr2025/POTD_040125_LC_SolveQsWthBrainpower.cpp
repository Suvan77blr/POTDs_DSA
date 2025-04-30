
// 010425
/*
   2140. Solving Questions With Brainpower.

   Given a questions[][] -> questions[i] = [points(i), brainpower(i)].

   The array describes the Qs of an exams, where the questions have to be processed 'in order' & make a decision on whether to SOLVE or SKIP each question.
   Solving ith 'Q' => earns POINTS(i), but you will be 'unable' to solve each of the next BRAINPOWER(i) no of questions. 
   Skipping the ith Q => we get to make the decision on the next question.

   Return the maximum points which can be earned.
*/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Solution {
	public:
		long long mostPoints(vector<vector<int>>& questions);
		void recFunc(int idx, long long &maxScore, long long &score, int brFrzeIdx, vector<vector<int>>& questions);
		long long dpSoln( int idx, vector<long long>& dp, vector<vector<int>>& questions);
};


long long Solution :: mostPoints(vector<vector<int>>& questions)
{
	long long score = 0;
	long long maxScore = 0;
	int brFrzeIdx = -1;

	int n=questions.size();
	
	vector<long long> dp (n, 0);
	dp[n-1] = questions[n-1][0];
	// for(int i=0; i<n; i++) {
	// 	dp[i] = questions[i][0];
	// }

	// dp[0] = dpSoln(0, dp, questions);

	// for(int i=n-1; i>=0; i--){
	// 	cout << "STARTING FROM " << i << " .. now : " << endl;
	// 	dp[i] = dpSoln(i, dp, brFrzeIdx, questions);
	// 	cout << "FINISHED FOR " << i << " .. curr Value : [";
	// 	for(int ele : dp) cout << ele << " "; cout << "]\n\n";
		
	// }

	// int brFrzeIdx = 0;

	//recFunc(idx, score, brFrzeIdx, questions);
	// recFunc(0, maxScore, score, brFrzeIdx, questions);
	// dpSoln(0, dp, brFrzeIdx, questions, maxScore);

	for(int ele : dp) {
		// cout << ele << endl;
		if(maxScore < ele){
			maxScore = ele;
		}
	}
	return maxScore;
}

long long Solution :: dpSoln( int idx, vector<long long>& dp, vector<vector<int>>& questions)
{
	if(idx > questions.size()) {
		// return questions[idx][0];
		return 0;
	}
	
	// if(dp[idx] != -1){
	// 	cout << "  Found value dp[" << idx << "] = " << dp[idx] << endl;
	// 	return dp[idx];
	// }

	int solve = 0, skipped=0;
	// if(idx > brFrzeIdx){
		// solve = questions[idx][0] + dpSoln(idx+1, dp, idx+questions[idx][1], questions);
		solve = questions[idx][0] + dpSoln(idx+questions[idx][1], dp, questions);
	// }
	skipped = dpSoln(idx+1, dp, questions);

	cout << "For Q" << idx << "{ " << solve <<" , " << skipped << "}" << endl;
	dp[idx] = max(solve, skipped);
	return max(solve, skipped);
}

void Solution :: recFunc(int idx, long long &maxScore, long long &score, int brFrzeIdx, vector<vector<int>>& questions)
{
	if(idx == questions.size())
	{
		cout << "\tCurr score : " << score << endl;
		maxScore = max(maxScore, score);
		return;
	}

	if(idx > brFrzeIdx)
	{
		// Solves.
		score += questions[idx][0];
		cout << "Solves " << idx << ", so can't solve till " << idx+questions[idx][1] << "..and has " << score << endl;
		recFunc(idx+1, maxScore, score, idx+questions[idx][1], questions);

		// Not solves.
		score -= questions[idx][0];
		cout << "Unsolves " << idx << ", so curr brFrzeIdx : " << brFrzeIdx << "..and has " << score << endl;
		// recFunc(idx+1, maxScore, score, brFrzeIdx, questions);
	}
	recFunc(idx+1, maxScore, score, brFrzeIdx, questions);
}

int main(void)
{
	// ifstream fin("../input.txt");
	// ofstream fout("../output.txt");

	int n;
	// cout << "Enter the number of questions : ";
	cin >> n;
	// fin >> n;

	vector<vector<int>> questions (n, vector<int>(2) );
	// cout << "Enter the POINTS & BRAINPOWER for each of the " << n << " questions : ";
	for(int i=0; i<n; i++) {
		cin >> questions[i][0] >> questions[i][1];
		// fin >> questions[i][0] >> questions[i][1];
	}

	int maxScore = Solution().mostPoints(questions);
	cout << "Maximum points : " << maxScore << endl;
	// fout << "Maximum points : " << maxScore << endl;

//	for(int i=0; i<n; i++) {
//		fout << "Question " << i+1 << " : { " << questions[i].first << ", " << questions[i][1] << " }\n";
//	}

	cout << "\nEOP!\n";
	// fout << "\nEOP!\n";

	return 0;
}

/*
int Solution :: dpSoln( int idx, vector<int>& dp, int brFrzeIdx, vector<vector<int>>& questions, long long& maxScore)
{
	if(idx >= questions.size())
		return 0;

	if(dp[idx] != -1){
		return dp[idx];
	}

	int solvedThis=0, skippedThis=0;
	if(idx > brFrzeIdx){
		cout << "Solves " << idx << ", so can't solve till " << idx+questions[idx][1] << "..and has " << dp[idx] << endl;
		dp[idx] = questions[idx][0];
		solvedThis = dpSoln(idx+1, dp, brFrzeIdx, questions, maxScore);
	}
	{
		cout << "Unsolves " << idx << ", so curr brFrzeIdx : " << brFrzeIdx << "..and has " << dp[idx] << endl;
		skippedThis = questions[idx][0]+dpSoln(idx+1, dp, idx+questions[idx][1], questions, maxScore);
	}
	dp[idx] = max(solvedThis, skippedThis);

	return dp[idx];
}

*/